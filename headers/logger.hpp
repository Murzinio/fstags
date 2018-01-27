// Std
#include <experimental/string_view>
#include <experimental/filesystem>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>


namespace logger
{

constexpr const char* log_file_path{ "log.txt" };

template <typename T>
void debug_log(const T& message)
{
    std::cout << message << std::endl;

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

    log_file << message << "\n";
}

}
