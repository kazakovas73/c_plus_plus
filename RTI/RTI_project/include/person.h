#pragma once
#include <string>
#ifndef PERSON_H
#define PERSON_H

//класс для данных человека
class Person
{
private:
    std::string fio;
    std::string date;
    std::string hours_worked;
    std::string car_true;
public:
    Person(std::string,
           std::string,
           std::string,
           std::string);
    std::string get_fio();
    std::string get_date();
    std::string get_hours_worked();
    std::string get_car_true();
};

#endif // PERSON_H
