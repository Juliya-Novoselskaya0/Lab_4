/*Full name : Novoselskaya Juliya
group:044691
variant 18
Design
*/
#include <iostream>
#include <string>
#include <windows.h>
#include<algorithm>

class Design
{
protected:
    std::string region, colorSpec;

public:
    Design(std::string n, std::string a)
    {
        std::cout << "costructor base class" << std::endl;
        region = n; colorSpec = a;
    }
    ~Design()
    {
        std::cout << "base class destructor" << std::endl;
    }
    void display()
    {
        std::cout << "Appliction area: " << region << "\tColor spectrum: " << colorSpec << std::endl;
    }
};

class DesignInterior : public Design
{
private:
    std::string what, type;
public:
    DesignInterior(std::string n, std::string a, std::string t, std::string tp) :Design(n, a)
    {
        std::cout << "child class costructor" << std::endl;
        what = t;
        type = tp;
    }
    ~DesignInterior()
    {
        std::cout << "child class destructor" << std::endl;
    }
    void showIntDInfo()
    {
        std::cout << "Appliction area:" << region << "\tColor spectrum: " << colorSpec << "\tPremises: " << what << "\tSyle: " << type << std::endl;
    }
};

class ClothingDesign : public Design
{
private:
    std::string what,
        season;
public:
    ClothingDesign(std::string n, std::string a, std::string t, std::string tp) :Design(n, a)
    {
        std::cout << "child class costructor" << std::endl;
        what = t;

        season = tp;
    }
    ~ClothingDesign()
    {
        std::cout << "child class destructor" << std::endl;
    }
    void showClothDInfo()
    {
        std::cout << "Appliction area:" << region << "\tColor spectrum: " << colorSpec << "\tName of clothes: " << what << "\tSeason: " <<
            season << std::endl;
    }
};

class WebDesign : public Design
{
private:
    std::string what, type;
public:
    WebDesign(std::string n, std::string a, std::string t, std::string tp) :Design(n, a)
    {
        std::cout << "child class costructor" << std::endl;
        what = t;
        type = tp;
    }
    ~WebDesign()
    {
        std::cout << "child class destructor" << std::endl;
    }
    void showWebDInfo()
    {
        std::cout << "Appliction area:" << region << "\tColor spectrum: " << colorSpec << "\tDesign of wich resource: " << what << "\tSyle: " << type << std::endl;
    }
};

bool check(std::string str)
{
    std::transform(str.begin(), str.end(),str.begin(), tolower);
   /* char *st=new char[str.length()];
    for (int i = 0; i < str.length(); i++)
    {
        st[i] = str[i];
    }*/
    char alf[] = "abcdefghijklmnopqrstuvwxyz";
    int l = 0;
    bool rez = false;
    char* v = NULL;
   /* while (st)
    {
        char* p = strtok_s(st, " ",&v );*/
       // for (int i = 0; i < strlen(p); i++)
            for (int i = 0; i < str.length(); i++)
        {
            for (int j = 0; j < strlen(alf); j++)
            {
                if (str[i] == alf[j])
                {
                    l++;
                    break;
                }

            }
        }
    
    if (str.length() == l && l>2)
    {
        return true;
    }
    else {
        return false;
    }
    
}

int main()
{
    // setlocale(LC_ALL, "Russian");
    std::string reg, col;
    std::cout << "D E S I G N " << std::endl;
    std::cout << "ENTER Appliction area:" << std::endl;
    std::getline(std::cin,reg);
    while (check(reg) == false)
    {
        std::cout << "ENTER Appliction area:" << std::endl;
        std::cin >> reg;
    }
    std::cout << "ENTER Color spectrum:" << std::endl;
    std::cin >> col;
    while (check(col)==false)
    {
        std::cout << "ENTER Color spectrum:" << std::endl;
        std::cin >> col;
    }
    int ch = 0;
    std::cout << "1 Base design class \n2 Web-design \n3 Interior design \n4 Clothing design\n" << std::endl;
    std::cin >> ch;
   while(ch!=1 && ch!=2 && ch!=3 && ch!=4)
    {
        std::cout << "1 Base design class \n2 Web-design \n3 Interior design \n4 Clothing design\n" << std::endl;
        std::cin >> ch;        
    }
   /* while (check())
    {
        std::cout << "1 Base design class \n2 Web-design \n3 Interior design \n4 Clothing design\n" << std::endl;
        std::cin >> ch;
    }*/
    switch (ch)
    {
    case 1:
    { Design d(reg, col);
    d.display();
    }
    break;
    case 2:
    { std::string w, s;
    std::cout << "ENTER Design of wich resource:" << std::endl;
    std::cin >> w;
    while (check(w) == false)
    {
        std::cout << "ENTER Design of wich resource:" << std::endl;
        std::cin >> w;
    }
    std::cout << "ENTER Style:" << std::endl;
    std::cin >> s;
    while (check(s) == false)
    {
        std::cout << "ENTER Style:" << std::endl;
        std::cin >> s;
    }
    WebDesign wd(reg, col, w, s);
    wd.showWebDInfo(); }
    break;
    case 3:
    {std::string po, st;
    std::cout << "ENTER Premises:" << std::endl;
    std::cin >> po;
    while (check(po) == false)
    {
        std::cout << "ENTER Premises:" << std::endl;
        std::cin >> po;
    }
    std::cout << "ENTER Style:" << std::endl;
    std::cin >> st;
    while (check(st) == false)
    {
        std::cout << "ENTER Style:" << std::endl;
        std::cin >> st;
    }
    DesignInterior di(reg, col, po, st);
    di.showIntDInfo(); }
    break;
    case 4:
    { std::string wc, sea;
    std::cout << "ENTER Name of clothes:" << std::endl;
    std::cin >> wc;
    while (check(wc) == false)
    {
        std::cout << "ENTER Name of clothes:" << std::endl;
        std::cin >> wc;
    }
    std::cout << "ENTER Season:" << std::endl;
    std::cin >> sea;
    while (check(sea) == false)
    {
        std::cout << "ENTER Season:" << std::endl;
        std::cin >> sea;
    }
    ClothingDesign cd(reg, col, wc, sea);
    cd.showClothDInfo(); }
    break;
    /*   default:
           break;*/
    }
    return 0;
}