#pragma once

// Std
#include <cstdint>

// Programo
#include "user_io.hpp"
#include "shared_types.hpp"


class Program
{
public:
    Program(const shared_types::Arg_count argc,
                const shared_types::Args& args);

    Program(const Program& rhs) = delete;
    Program(Program&& rhs) = delete;

    Program& operator=(const Program& rhs) = delete;
    Program& operator=(Program&& rhs) = delete;

private:
    User_io m_io;
};