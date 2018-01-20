// Std
#include <stdexcept>
#include <iostream>
#include <string>

// Program
#include "program.hpp"

Program::Program(User_io&& io)
    : m_io(std::move(io))
{
}

/*
    Private
*/
