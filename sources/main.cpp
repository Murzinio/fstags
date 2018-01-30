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
        Program program{ shared_types::Arg_count(argc), shared_types::Args(args) };
    }
    catch (const std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;

        return 1;
    }
}