#pragma once

#include <string>
#include <chrono>

class Date
{
public:
private:
};

class DateTime
{
public:

    enum class DateFormat
    {
        YYYYMMDD, //2021-03-23
        DDMMYYYY, //23-03-2021
        YYMMDD,   //21-03-23
        DDMMYY,   //23-03-2021
    };

    DateTime(const DateFormat dt = DateFormat::YYYYMMDD);

    ~DateTime() = default;

    DateTime(DateTime const&) = delete;
    DateTime& operator =(DateTime const&) = delete;
    DateTime(DateTime&&) = delete;
    DateTime& operator=(DateTime&&) = delete;

    std::string getCurrentDateTimeToString();
    std::string getCurrentTimeToString();
    std::string getCurrentDateToString();

    static bool isLeapYear(const unsigned int year);
    static std::chrono::system_clock::time_point addDays(std::chrono::system_clock::time_point date, const int value);

private:
    std::chrono::time_point<std::chrono::system_clock> m_now;
    std::chrono::duration<long, std::ratio<1,1000>> m_ms{};
    std::tm m_bt{};
    std::string m_dateFormat{};
    void loadValues();
    static int64_t currentMSecsSinceEpoch();
};

