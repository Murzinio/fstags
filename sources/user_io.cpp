// Std
#include <iostream>

// Program
#include "user_io.hpp"
#include "logger.hpp"

/*
    Public
*/

User_io::User_io(const Raw_arg_count argc, const Raw_args& args)
{
    if (argc.get() < 2)
    {
        print_usage();
    }
    else
    {
        fill_supported_args();        
        parse_args(argc, args);
    }
}

/*
    Private
*/

void User_io::fill_supported_args()
{
    m_supported_args = std::array<User_io::Cli_arg_wrapper, supported_args_count>{
        {"tag", "t", "Tags specified path.", Cli_arg::Tag}
    };
}

void User_io::parse_args(const Raw_arg_count argc, const Raw_args& args)
{
    for (auto i{ 0 }; i < argc.get(); ++i)
    {
        const auto& arg{ args.get()[i] };

        for (const auto& match : m_supported_args)
        {
            if (arg == match.name)
            {
                m_args.push_back(match);

                logger::debug_log(logger::Message("tag parsed"));
            }
        }
        
    }
}

void User_io::print_usage() const
{
    std::cout <<
R"(--------------------------
--- fstags by Murzinio ---
--------------------------

--- Usage ---

--path="directory path")";
}