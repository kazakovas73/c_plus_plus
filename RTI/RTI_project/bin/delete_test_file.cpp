#include <iostream>
#include "delete_test_file.h"

void delete_test_file::delete_test()
{
    std::remove("input_data/test.xml");
}
