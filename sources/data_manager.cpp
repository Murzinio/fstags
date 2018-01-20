// Std
#include <stdexcept>

// Program
#include "data_manager.hpp"

/*
    Public
*/

const std::string Data_manager::m_data_path = "fstags.data";

Data_manager::Data_manager()
{
    m_file.open(m_data_path);

    if (!m_file.is_open())
    {
        throw std::runtime_error("Could not open file: " + m_data_path);
    }
}

void Data_manager::set_managed_dir(const Path p)
{
    m_file.seekp(0);
    m_file << p.get().data();
}

/*
    Private
*/

std::string Data_manager::read_managed_dir() const
{
    return "";
}