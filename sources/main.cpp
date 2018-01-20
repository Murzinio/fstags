/*
    fstags by Murzinio
*/

// Std
#include <stdexcept>
#include <iostream>

// Program
#include "program.hpp"
#include "user_io.hpp"

int main(int argc, const char** args)
{
    try
    {
        User_io io{ User_io::Raw_arg_count(argc), User_io::Raw_args(args) };
        Program program{ std::move(io) };
    }
    catch (const std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;

        return 1;
    }
}