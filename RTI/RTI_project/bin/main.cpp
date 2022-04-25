#include <string>
#include "parser.cpp"

int main()
{
    std::string filepath = "input_data/test.xml";
    Parser parser(filepath);
    parser.parse();
    
    return 0;
}

