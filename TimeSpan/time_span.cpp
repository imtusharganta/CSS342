#include "time_span.h"
#include <iostream>
#include <math.h>
using namespace std;

// Set default time to zero
TimeSpan::TimeSpan()
{
  set_time(0, 0, 0);
}

/**
 * Every constructor will automatically convert the time when
 * it is passed in.
 */
TimeSpan::TimeSpan(double seconds)
{
  convert(0, 0, seconds);
}

TimeSpan::TimeSpan(double minutes, double seconds)
{
  convert(0, minutes, seconds);
}

TimeSpan::TimeSpan(double hours, double minutes, double seconds)
{
  convert(hours, minutes, seconds);
}
int TimeSpan::hours() const
{
  return hours_;
}

int TimeSpan::minutes() const
{
  return minutes_;
}

int TimeSpan::seconds() const
{
  return seconds_;
}

void TimeSpan::set_hours(double hours)
{
  hours_ = hours;
}

void TimeSpan::set_minutes(double minutes)
{
  minutes_ = minutes;
}

void TimeSpan::set_seconds(double seconds)
{
  seconds_ = seconds;
}

void TimeSpan::set_time(double hours, double minutes, double seconds)
{
  hours_ = hours;
  minutes_ = minutes;
  seconds_ = seconds;
}
/**
 * This will check if the current TimeSpan equals ALL other parts of the TimeSpan we are passing in.
 */
bool TimeSpan::operator==(const TimeSpan &other) const
{
  return (hours_ == other.hours() && minutes_ == other.minutes() && seconds_ == other.seconds());
}

/**
 * This one is will check if any of the parts of the timespan are not equal.
 */
bool TimeSpan::operator!=(const TimeSpan &other) const
{
  return (hours_ != other.hours() || minutes_ != other.minutes() || seconds_ != other.seconds());
}

bool TimeSpan::operator<(const TimeSpan &other) const
{
  if (hours_ < other.hours())
  {
    return true;
  }
  else if (hours_ == other.hours())
  {
    if (minutes_ < other.minutes())
    {
      return true;
    }
    else if (minutes_ == other.minutes())
    {
      if (seconds_ < other.seconds())
      {
        return true;
      }
    }
  }
  return false;
}

bool TimeSpan::operator<=(const TimeSpan &other)
{
  return (hours_ <= other.hours() && minutes_ <= other.minutes() && seconds_ <= other.seconds());
}

bool TimeSpan::operator>(const TimeSpan &other) const
{
  if (hours_ > other.hours())
  {
    return true;
  }
  else if (hours_ == other.hours())
  {
    if (minutes_ > other.minutes())
    {
      return true;
    }
    else if (minutes_ == other.minutes())
    {
      if (seconds_ > other.seconds())
      {
        return true;
      }
    }
  }
  return false;
}

bool TimeSpan::operator>=(const TimeSpan &other)
{
  return (hours_ >= other.hours() && minutes_ >= other.minutes() && seconds_ >= other.seconds());
}

TimeSpan TimeSpan::operator+(const TimeSpan &other) const
{
  TimeSpan temp = *this;
  temp += other;
  return temp;
}

TimeSpan &TimeSpan::operator+=(const TimeSpan &other)
{
  hours_ += other.hours();
  minutes_ += other.minutes();
  seconds_ += other.seconds();
  convert(hours_, minutes_, seconds_);
  return *this;
}

TimeSpan TimeSpan::operator-(const TimeSpan &other) const
{
  TimeSpan temp = *this;
  temp -= other;
  return temp;
}

TimeSpan &TimeSpan::operator-=(const TimeSpan &other)
{
  hours_ -= other.hours();
  minutes_ -= other.minutes();
  seconds_ -= other.seconds();
  convert(hours_, minutes_, seconds_);
  return *this;
}

/**
 * We will initially round all the elements of time to get a cleaner execution
 * we cast to int because some of the calculations needed are not possible if it is a double.
 *
 */
void TimeSpan::convert(double hours, double minutes, double seconds)
{
  int total_seconds = round((minutes * 60) + (hours * 3600) + seconds);
  int total_minutes = total_seconds / 60;
  seconds = total_seconds % 60;
  hours = total_minutes / 60;
  minutes = total_minutes % 60;

  set_time(round(hours), round(minutes), round(seconds));
}

std::ostream &operator<<(std::ostream &stream, const TimeSpan &other)
{
  stream << "hours: " << other.hours() << ", minutes: " << other.minutes() << ",  seconds: " << other.seconds();
  return stream;
}
