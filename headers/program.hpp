#pragma once

// Std
#include <cstdint>

// Programo
#include "user_io.hpp"


class Program
{
public:
    Program(User_io&&);

    Program(const Program& rhs) = delete;
    Program(Program&& rhs) = delete;

    Program& operator=(const Program& rhs) = delete;
    Program& operator=(Program&& rhs) = delete;

private:
    void print_usage() const;

    User_io m_io;
};