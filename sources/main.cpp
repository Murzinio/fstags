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
        User_io io{ User_io::Arg_count(argc), User_io::Args(args) };
        Program program{ std::move(io) };
    }
    catch (const std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;

        return 1;
    }
}