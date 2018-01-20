// Std
#include <experimental/string_view>
#include <experimental/filesystem>
#include <iostream>
#include <fstream>
#include <stdexcept>

// Program

#include "strong_type.hpp"

namespace logger
{

using Message =
    Strong_type<const std::experimental::string_view, struct Message_>;

constexpr const char* log_file_path{ "log.txt" };

void debug_log(const Message m)
{
    std::cout << m.get().data() << std::endl;

    using namespace std::experimental;
    std::ofstream log_file;
    std::string log_file_path{ "log.txt" };

    if (filesystem::exists(log_file_path))
    {
        filesystem::remove(log_file_path);
    }

    log_file.open(log_file_path, std::ofstream::app);

    if (!log_file.is_open())
    {
        throw std::runtime_error("Could not open file: " + log_file_path);
    }

    log_file << m.get().data() << "\n";
}

}
