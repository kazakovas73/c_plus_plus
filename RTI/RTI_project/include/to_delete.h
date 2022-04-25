#pragma once
#include <string>
#ifndef TO_DELETE_H
#define TO_DELETE_H

//
class to_delete
{
private:
    //возвращает имя файла, который будет в папке удаленных
    std::string return_filename(int);
    //возвращает количество файлов в to_delete
    int get_number_of_files();
public:
	//создает новый файл в t0_delete
    std::string create_to_delete_file();
};

#endif // TO_DELETE_H
