#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "../utils/WordAggregator"
#include "../utils/src/test.h"

std::string readFile (const char* fname)
{
    std::ifstream f;
    char *buffer;

    f.open(fname);
    f.seekg(0, std::ios::end);
    int length = f.tellg();
    f.seekg(0, std::ios::beg);
    buffer = new char[length];
    f.read(buffer,length);
    f.close();

    std::string str(buffer);
    delete[] buffer;
    
    std::cout << str << std::endl;
    return str;
}

int main()
{
    /*! Read in the test data */
    const char* file1 = "aggregatortext.txt";
    const char* file2 = "aggregatortext2.txt";
    std::string str1 = readFile(file1);
    std::string str2 = readFile(file2);

    /*! Instantiate unit tests and aggregator */
    unittest::Test <int> inttest;
    unittest::Test <std::string> strtest;
    std::vector <std::string> wordvector(2,"");
    wordvector[0] = str1;
    wordvector[1] = str2;
    TurnLeft::Utils::FrequencyMap frequencies;
    std::cout << "Instantiating aggregator" << std::endl;
    TurnLeft::Utils::WordAggregator aggregator (wordvector, frequencies);
    std::cout << "...done." << std::endl;

    TurnLeft::Utils::FrequencyIterator iter;
    iter = frequencies.begin();
    while (iter != frequencies.end())
    {
        std::cout << iter->first << ": " << iter->second << std::endl;
        ++iter;
    }

    return 0;
}
