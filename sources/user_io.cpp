// Std
#include <iostream>
#include <cctype>
#include <algorithm>

// Program
#include "user_io.hpp"
#include "logger.hpp"

/*
    Public
*/

User_io::User_io()
{
    fill_supported_args();
}

/*
    Private
*/

void User_io::fill_supported_args()
{
    m_supported_commands.at(0) = CommandFriendly(
        Name("tag"), Option(""), Description("tags specified path")
    );
}

[[nodiscard]] User_io::Command 
User_io::parse_args(const shared_types::Arg_count argc,
                        const shared_types::Args& args) const
{
    Command command;

    for (auto i{ 1 }; i < argc.get(); ++i) // ignore first arg
    {
        const auto arg{ args.get()[i] };

        for (const auto& match : m_supported_commands)
        {
            if (arg == "--" + match.name)
            {
                if (command.name != "")
                {
                    // command name already parsed
                    throw std::runtime_error("Invalid args");
                }

                command.name = arg;
                command.name.erase(0, 2);
            }
            else if (arg == "-" + std::string(1, match.name.at(0)))
            {
                if (command.name != "")
                {
                    // command name already parsed using short name
                    throw std::runtime_error("Invalid args");
                }

                auto result = std::find_if(
                    std::cbegin(m_supported_commands),
                    std::cend(m_supported_commands),
                    [&](const auto& command)
                        { return command.name.at(0) == arg[1]; }
                );

                if (result != std::cend(m_supported_commands))
                {
                    command.name = result->name;
                }
                else
                {
                    throw std::runtime_error("Invalid args");
                }
            }
            else if (arg[0] != '-')
            {
                if (command.option != "")
                {
                    throw std::runtime_error("Invalid args");
                }
                
                command.option = arg;
            }
        }
    }

    logger::debug_log("command name: " + command.name);
    logger::debug_log("command option: " + command.option);

    return command;
}

void User_io::print_usage() const
{
    std::cout <<
R"(--------------------------
--- fstags by Murzinio ---
--------------------------

--- Usage ---)" << "\n";

    for (const auto& arg : m_supported_commands)
    {
        auto separator{ "    " };
        std::cout << "-" << arg.name.at(0) << separator;
        std::cout << "--" << arg.name << separator;
        std::cout << arg.description << "\n";
    }

    std::cout << std::flush;
}