#ifndef TIMESPAN_H_
#define TIMESPAN_H_
#include <iostream>

#pragma once

class TimeSpan
{
public:
    // Constructors
    TimeSpan();
    TimeSpan(double seconds);
    TimeSpan(double minutes, double seconds);
    TimeSpan(double hours, double minutes, double seconds);

    // Getters
    int hours() const;
    int minutes() const;
    int seconds() const;

    // Setters
    void set_hours(double hours);
    void set_minutes(double minutes);
    void set_seconds(double seconds);
    void set_time(double hours, double minutes, double seconds);

    // comparison operators
    bool operator==(const TimeSpan &other) const;
    bool operator!=(const TimeSpan &other) const;
    bool operator<(const TimeSpan &other) const;
    bool operator<=(const TimeSpan &other);
    bool operator>(const TimeSpan &other) const;
    bool operator>=(const TimeSpan &other);

    // arithmetic operators
    TimeSpan operator+(const TimeSpan &other) const;
    TimeSpan &operator+=(const TimeSpan &other);
    TimeSpan operator-(const TimeSpan &other) const;
    TimeSpan &operator-=(const TimeSpan &other);
    TimeSpan operator*(const int &number);
    TimeSpan &operator*=(const int &number);

    friend std::ostream &operator<<(std::ostream &stream, const TimeSpan &other);
    friend std::istream &operator>>(std::istream &stream, TimeSpan &other);

    // Methods
    void PrintDetails();

private:
    double seconds_;
    double minutes_;
    double hours_;
    void convert(double hours, double minutes, double seconds);
};

#endif