#pragma once


// Std
#include <vector>
#include <array>
#include <string>

// Program
#include "strong_type.hpp"
#include "shared_types.hpp"


static constexpr uint8_t supported_args_count{ 1 };

class User_io
{
public:
    /*
        Strong types.
    */

    using Name =
        Strong_type<std::string, struct Name_t>;

    using Option =
        Strong_type<std::string, struct Option_t>;

    using Description =
        Strong_type<std::string, struct Description_t>;

    struct Command
    {
        Command() {};

        Command(Name n, Option o)
            : 
            name(n.get()),
            option(o.get()) {}

        virtual ~Command() {};

        std::string name;
        std::string option;
    };

    struct CommandFriendly : public Command
    {
        CommandFriendly() {};

        CommandFriendly(Name n, Option o, Description d)
            :
            Command(n, o),
            description(d.get()) {}

        std::string description;
    };

    User_io();

    /**
     * Prints list of available cli arguments and their description.
    */
    void print_usage() const;

    [[nodiscard]]
    Command parse_args(const shared_types::Arg_count, const shared_types::Args&) const;

private:
    void fill_supported_args();

    std::array<CommandFriendly, supported_args_count> m_supported_commands;
};
