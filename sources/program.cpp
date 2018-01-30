// Std
#include <stdexcept>
#include <iostream>
#include <string>

// Program
#include "program.hpp"

/*
    Public
*/

Program::Program(const shared_types::Arg_count argc,
                    const shared_types::Args& args)
{
    if (argc.get() < 2)
    {
        m_io.print_usage();
        return;
    }

    try
    {
        auto command{ m_io.parse_args(argc, args) };        
    }
    catch (const std::runtime_error& e)
    {
        m_io.print_usage();
        return;
    }
}

/*
    Private
*/
