#include <fstream>
#include <iostream>

int main()
{
    std::ifstream f;
    f.open("/usr/include/TurnLeftLib/commonwords.txt");
    std::cout << (f.is_open()) << std::endl;
    while (f)
    {
        std::string l;
        getline(f,l);
        std::cout << l << std::endl;
    }
}
