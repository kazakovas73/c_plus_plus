#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include "parser.cpp"

int main()
{

    std::string filepath = "input_data/test.xml";

    Parser parser(filepath);

    parser.parse();

    
    return 0;
}

