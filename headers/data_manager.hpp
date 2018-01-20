#pragma once

// Std
#include <experimental/string_view>
#include <fstream>
#include <string>

// Program
#include "strong_type.hpp"

class Data_manager
{
public:
    using Path =
        Strong_type<const std::experimental::string_view, struct Path_>;

    static const std::string m_data_path;

    /**
        Basic constructor, opens file handle, throws std::runtime_exception on failure.
    */
    Data_manager();
    void set_managed_dir(const Path);

    bool get_managed_dir_set() const { return m_managed_dir_set; }

private:
    std::string read_managed_dir() const;

    std::ofstream m_file;
    bool m_managed_dir_set{ false };
};