#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;
#include "to_delete.h"

std::string to_delete::return_filename(int number)
{
    int remember_number = number;
    if (number == 0)
    {
        return "to_delete/test.xml.0000";
    }

    int counter = 0;
    while (number != 0)
    {
        number /= 10;
        ++counter;
    }
    std::string to_return = "to_delete/test.xml.";
    for (int i = 0; i < 4 - counter; ++i)
    {
        to_return += "0";
    }

    return to_return += std::to_string(remember_number);
}

std::string to_delete::create_to_delete_file()
{
    int size = get_number_of_files();
    std::ofstream to_delete_file;
    std::string filename = return_filename(size);
    to_delete_file.open(filename , std::ios::out);
    to_delete_file.close();

    return filename;
}

int to_delete::get_number_of_files()
{
    int counter = 0;

    for (const auto &entry: fs::directory_iterator("to_delete"))
    {
        //files_to_delete.push_back(entry.path());
        ++counter;
    }

    return counter;
}
