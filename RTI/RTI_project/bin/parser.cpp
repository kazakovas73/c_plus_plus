#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include "parser.h"
#include "to_delete.cpp"
#include "delete_test_file.cpp"

using boost::property_tree::ptree;

Parser::Parser(std::string filename)
{
    this->filename = filename;
}

void Parser::parse()
{
    ptree pt;
    read_xml(this->filename, pt);
    BOOST_FOREACH(ptree::value_type &child, pt.get_child("Table"))
    {
        if (child.first == "<xmlattr>")
        {
            continue;
        }

        Person tmp(child.second.get<std::string>("name"),
                       child.second.get<std::string>("date"),
                       child.second.get<std::string>("hours-worked"),
                       child.second.get<std::string>("car-true"));

        this->persons_parsed_data.push_back(tmp);
    }

    write_parsed(this->persons_parsed_data);

    std::string last_filename = move_file_to_deleted();

    copy_data_to_deleted(last_filename);

    delete_test_file::delete_test();
}

void Parser::write_parsed(std::vector<Person> person_to_write)
{
    std::ofstream myfile;
    myfile.open("output_data/out.txt", std::ios::out);

    for (auto person: person_to_write)
    {
        myfile << person.get_fio() << std::endl;
        myfile << person.get_date() << std::endl;
        myfile << person.get_hours_worked() << std::endl;
        myfile << person.get_car_true() << std::endl;
        myfile << std::endl;
    }

    myfile.close();
}

std::string Parser::move_file_to_deleted()
{
    to_delete td;
    std::string last_name = td.create_to_delete_file();

    return last_name;
}

void Parser::copy_data_to_deleted(std::string last_filename)
{
    std::ifstream in("input_data/test.xml");
    std::string line;

    std::ofstream to_delete_file;
    to_delete_file.open(last_filename, std::ios::out);

    while (std::getline(in, line))
    {
        to_delete_file << line << std::endl;
    }
    in.close();
    to_delete_file.close();
}

void Parser::delete_test()
{
    std::remove("input_data/test.xml");
}
