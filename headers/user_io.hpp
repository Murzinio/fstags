#pragma once


// Std
#include <vector>
#include <array>
#include <string>

// Program
#include "strong_type.hpp"

static constexpr uint8_t supported_args_count{ 2 };

class User_io
{
private:
    enum class Cli_arg;

public:
    struct Cli_arg_wrapper
    {
        std::string name;
        std::string short_name;
        std::string description;

        Cli_arg enum_val;
    };

    /*
        Strong types.
    */

    using Raw_arg_count =
        Strong_type<int, struct Raw_arg_count_>;

    using Raw_args =
        Strong_type<const char**, struct Raw_args_>;

    User_io(const Raw_arg_count, const Raw_args&);

    /**
     * Prints list of available cli arguments and their description.
    */
    void print_usage() const;

private:
    enum class Cli_arg
    {
        Tag
    };

    void parse_args(const Raw_arg_count, const Raw_args&);
    void fill_supported_args();

    std::vector<Cli_arg_wrapper> m_args;
    
    std::array<Cli_arg_wrapper, supported_args_count> m_supported_args;
};
