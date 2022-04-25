#pragma once
#include <string>
#include <vector>
#include "person.cpp"
#ifndef PARSER_H
#define PARSER_H

//Класс, который реализует логику поставленной задачи
class Parser
{
private:
	//путь до файла, который надо парсить
    std::string filename;
    //данные запаршенных людей из файла
    std::vector<Person> persons_parsed_data;
    //записть в output.txt
    void write_parsed(std::vector<Person>);
    //создание файла в папке to_delete с правильным названием
    std::string move_file_to_deleted();
    //копирование данных из test в to_delete файл
    void copy_data_to_deleted(std::string);
    //удаляет тест файл
    void delete_test();
public:
    Parser(std::string);
    //главный метод, который реализует логику
    void parse();
};

#endif // PARSER_H


