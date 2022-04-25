#pragma once
#include <string>
#ifndef TO_DELETE_H
#define TO_DELETE_H

class to_delete
{
private:
    //возвращает имя файла, который будет в папке удаленных
    std::string return_filename(int);
public:
    std::string create_to_delete_file();

    int get_number_of_files();

};

#endif // TO_DELETE_H
