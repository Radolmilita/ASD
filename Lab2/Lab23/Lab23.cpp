#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int main()
{
    std::string str;
    std::cout << "Enter infile name\n";
    std::cin >> str;
    std::ifstream ifs(str.c_str());
    if (!ifs)
    {
        std::cerr << "Can` t open file " << str << '\n';
        return 1;
    }
    while (!ifs.eof())
    {
        if (!ifs.eof())
        {
            std::getline(ifs, str);
            if (str.find(',') == std::string::npos)
                std::cout << str << '\n';
        }
    }
    ifs.close();
    return 0;
}