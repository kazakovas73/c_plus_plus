#pragma once
#include <string>
#include <vector>
#include "person.cpp"
#ifndef PARSER_H
#define PARSER_H

class Parser
{
private:
    std::string filename;
    std::vector<Person> persons_parsed_data;
public:
    Parser(std::string);
    void parse();
    void write_parsed(std::vector<Person>);
    std::string move_file_to_deleted();
    void copy_data_to_deleted(std::string);
};

#endif // PARSER_H


