#include "person.h"
#include <string>

Person::Person(std::string fio_,
               std::string date_,
               std::string hours_worked_,
               std::string car_true_) :
    fio(fio_),
    date(date_),
    hours_worked(hours_worked_),
    car_true(car_true_) {}

std::string Person::get_fio()
{
    return this->fio;
}
std::string Person::get_date()
{
    return this->date;
}
std::string Person::get_hours_worked()
{
    return this->hours_worked;
}
std::string Person::get_car_true()
{
    return this->car_true;
}
