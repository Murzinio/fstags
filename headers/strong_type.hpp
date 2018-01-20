/*
    A strong type wrapper for strongly typed interfaces.
*/
#pragma once


template<typename T, typename Param>
class Strong_type
{
public:
    /**
        Construct without initializing.
    */
    Strong_type() {};

    /**
        Basic constructor, initializes type's value.
    */
    explicit Strong_type(const T& value)
        : m_value(value), m_initialized(true) {}

    /**
        Move constructor, initializes type's value.
    */
    explicit Strong_type(T&& value)
        : m_value(std::move(value)), m_initialized(true) {}

    [[nodiscard]]
    const T& get() const
    { 
        if (!m_initialized)
        {
            throw std::runtime_error("Call to get() before initializing Strong_type."); 
        }

        return m_value;
    }

private:
    T m_value;
    bool m_initialized{ false };
};