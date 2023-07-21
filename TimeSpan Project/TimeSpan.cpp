    //
    //  TimeSpan.cpp
    //  TimeSpan Assignment
    // created by Hemza Al-Shamari 
    //
    #include <iomanip>
    #include <iostream>
    #include "TimeSpan.h"

    using namespace std;
    //the following are methods that are declared in my header file
    //initalizing the default constructor 
    TimeSpan::TimeSpan() {
        hour = 0;
        minutes = 0;
        seconds = 0;
    }
    //initializing the parameterized constructor and this one is taking in seconds in double
    TimeSpan::TimeSpan(double s) {
        hour = 0;
        minutes = 0;
        seconds = s;
        this->Simplify();
    }
    //initializing the parameterized constructor and this one is taking in seconds in double, and minutes in double
    //calling function Simplify() to ensure the values of the hours, minutes, and seconds members variables are in a valid range 
    TimeSpan::TimeSpan(double m, double s) {
        hour = 0;
        minutes = m;
        seconds = s;
        this->Simplify();
    }
    //initializing the parameterized constructor and this one is taking in seconds in double, minutes in double, and hours
    //calling function Simplify() to ensure the values of the hours, minutes, and seconds members variables are in a valid range 
    TimeSpan::TimeSpan(double h, double m, double s) {
        hour = h;
        minutes = m;
        seconds = s;
        this->Simplify();
    }
    //initializing constructor
    //copying the values of the hours, minutes, and seconds member variables from the input t object to the corresponding member variables 
    //calling function Simplify() to ensure the values of the hours, minutes, and seconds members variables are in a valid range 
    TimeSpan::TimeSpan(const TimeSpan &t) {
        hour = t.hour;
        minutes = t.minutes;
        seconds = t.seconds;
        this->Simplify();
    }
    //initializing overloaded assignment operator for the TimeSpan class. 
    //it takes as input a constant reference to another TimeSpan object, t.
    //the operator copies the values of the hours, minutes, and seconds member variables from the input t object to the 
    //corresponding member variables of the object on which the operator is called.
    //calling function Simplify() to ensure the values of the hours, minutes, and seconds members variables are in a valid range 
    TimeSpan& TimeSpan::operator=(const TimeSpan &t) {
        hour = t.hour;
        minutes = t.minutes;
        seconds = t.seconds;
        Simplify();
        return *this;
    }
    //initializing an overloaded comparison operator for the TimeSpan class.
    //it takes as input a constant reference to another TimeSpan object, t.
    //the operator compares the values of the hours, minutes, and seconds member variables of the object on which the operator is called 
    //(this) with the corresponding member variables of the input t object.
    //it checks if all three member variables of both objects are equal, if they are it returns true otherwise it returns false.
    bool TimeSpan::operator==(const TimeSpan &t) const {
        if(this->hour == t.hour && this->minutes == t.minutes && this->seconds == t.seconds)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //initializing an overloaded comparison operator for the TimeSpan class.
    //it takes as input a constant reference to another TimeSpan object, t.
    //the operator compares the values of the hours, minutes, and seconds member variables of the object on which the operator is called 
    //(this) with the corresponding member variables of the input t object.
    //will return true if any of the hours, minutes, or seconds member variables of both objects are not equal, otherwise it will return false.
    bool TimeSpan::operator!=(const TimeSpan &t) const {
        if(this->hour != t.hour || this->minutes != t.minutes || this->seconds != t.seconds)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //initializing an overloaded comparison operator for the TimeSpan class.
    //it takes as input a constant reference to another TimeSpan object, t.
    //the operator compares the values of the hours, minutes, and seconds member variables of the object on which the operator is called 
    //(this) with the corresponding member variables of the input t object.
    //will return true if any of the hours, minutes, or seconds member variables of the object on which the operator 
    //is called are greater than their corresponding variables of the input object, otherwise it will return false.
    bool TimeSpan::operator>(const TimeSpan &t) const {
        if(this->hour > t.hour)
        {
            return true;
        }
        else if(this->hour == t.hour && this->minutes > t.minutes)
        {
            return true;
        }
        else if(this->hour == t.hour && this->minutes == t.minutes && this->seconds > t.seconds)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //initializing an overloaded comparison operator for the TimeSpan class.
    //it takes as input a constant reference to another TimeSpan object, t.
    //the operator compares the values of the hours, minutes, and seconds member variables of the object on which the operator is called 
    //(this) with the corresponding member variables of the input t object.
    //will return true if any of the hours, minutes, or seconds member variables of the object on which the operator 
    //is called are greater than their corresponding variables of the input object, otherwise it will return false.
    bool TimeSpan::operator<(const TimeSpan &t) const {
        if(this->hour < t.hour)
        {
            return true;
        }
        else if(this->hour == t.hour && this->minutes < t.minutes)
        {
            return true;
        }
        else if(this->hour == t.hour && this->minutes == t.minutes && this->seconds < t.seconds)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //initializing an overloaded comparison operator for the TimeSpan class.
    //it takes as input a constant reference to another TimeSpan object, t.
    //the operator compares the values of the hours, minutes, and seconds member variables of the object on which the operator is called 
    //(this) with the corresponding member variables of the input t object.
    //checks if any of the three member variables of the object on which the operator is called are greater than or equal to the corresponding member 
    //variables of the input object, if they are it returns true otherwise it returns false.
    bool TimeSpan::operator>=(const TimeSpan &t) const {
        if(this->hour >= t.hour || this->minutes >= t.minutes || this->seconds >= t.seconds)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //initializing an overloaded comparison operator for the TimeSpan class.
    //it takes as input a constant reference to another TimeSpan object, t.
    //the operator compares the values of the hours, minutes, and seconds member variables of the object on which the operator is called 
    //(this) with the corresponding member variables of the input t object.
    //checks if any of the three member variables of the object on which the operator is called are less than or equal to the corresponding member
    //variables of the input object, if they are it returns true otherwise it returns false.
    bool TimeSpan::operator<=(const TimeSpan &t) const {
        if(this->hour <= t.hour || this->minutes <= t.minutes || this->seconds <= t.seconds)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //initializing overloaded addition operator which creates a new TimeSpan object, time, and sets its hour, minutes, and seconds member
    //variables to the sum of the corresponding member variables of the object on which the operator is called (this) and the input t object.
    //calls the Simplify() method on the time object to ensure that the values of the hours, minutes, and seconds members variables are in a valid range.
    //lastly, returns the time object.
    TimeSpan TimeSpan::operator+(const TimeSpan &t) const {
        TimeSpan time;
        time.hour = hour + t.hour;
        time.minutes = minutes + t.minutes;
        time.seconds = seconds + t.seconds;
        time.Simplify();
        return time;
    }
    //initializing overloaded subtraction assignment operator
    //creates a new TimeSpan object, time, and sets its hour, minutes, and seconds member variables to the difference of the corresponding member 
    //variables of the object on which the operator is called (this) and the input t object.
    //calls the Simplify() method on the time object to ensure that the values of the hours, minutes, and seconds members variables are in a valid range.
    //lastly, returns the time object.
    TimeSpan TimeSpan::operator-(const TimeSpan &t) const {
        TimeSpan time;
        time.hour = hour - t.hour;
        time.minutes = minutes - t.minutes;
        time.seconds = seconds - t.seconds;
        time.Simplify();
        return time;
    }
    //initializing overloaded addition assignment operator
    //operator adds the values of the hours, minutes, and seconds member variables of the input t object to the corresponding member variables 
    //of the object on which the operator is called (this).
    //calls the Simplify() method to ensure that the values of the hours, minutes, and seconds members variables are in a valid range.
    //returns a reference to the object on which the operator is called (this).
    TimeSpan& TimeSpan::operator+=(const TimeSpan &t) {
        hour += t.hour;
        minutes += t.minutes;
        seconds += t.seconds;
        Simplify();
        return *this;
    }
    //initializing overloaded subtraction assignment operator
    //operator subtracts the values of the hours, minutes, and seconds member variables of the input t object from the corresponding member variables 
    //of the object on which the operator is called (this).
    //calls the Simplify() method to ensure that the values of the hours, minutes, and seconds members variables are in a valid range.
    //returns a reference to the object on which the operator is called (this).
    TimeSpan& TimeSpan::operator-=(const TimeSpan &t) {
        hour -= t.hour;
        minutes -= t.minutes;
        seconds -= t.seconds;
        Simplify();
        return *this;
    }
    //initializing overloaded multiplication operator
    //operator creates a new TimeSpan object, time, and sets its hour, minutes, and seconds member variables to the product of the corresponding
    //member variables of the object on which the operator is called (this) and the input t object.
    //calls the Simplify() method on the time object to ensure that the values of the hours, minutes, and seconds members variables are in a valid range.
    //lastly, returns the time object.
    TimeSpan TimeSpan::operator*(const TimeSpan &t) const {
        TimeSpan time;
        time.hour = hour * t.hour;
        time.minutes = minutes * t.minutes;
        time.seconds = seconds * t.seconds;
        time.Simplify();
        return time;
        
    }
    //this method converts the hours, minutes and seconds values of the object on which the method is called (this)
    //into total seconds. It does this by multiplying the hours by 3600 (the number of seconds in an hour), 
    //the minutes by 60 (the number of seconds in a minute), and adding the seconds.
    //converts the total seconds back into hours, minutes, and seconds by dividing the total seconds by 3600 to get the number of hours, 
    //then taking the remainder of this division and dividing it by 60 to get the number of minutes, and finally taking the remainder of this division to get the number of seconds.
    //assigns these values back to the hour, minutes, and seconds member variables of the object.
    //lastly, returns a reference to the object on which the method is called (this).
    TimeSpan& TimeSpan::Simplify() {
        int Hour = hour * 3600;
        int Minutes = minutes * 60;
        int Seconds = seconds;
        int totalSeconds = Hour + Minutes + Seconds;
        hour = totalSeconds / 3600;
        int hour = totalSeconds % 3600;
        minutes = hour / 60;
        seconds = hour % 60;
        return *this;
    }
    //accessor methods
    int TimeSpan::getHour() const{
        return hour;
    }
    int TimeSpan::getMinute() const{
        return minutes;
    }
    int TimeSpan::getSecond() const{
        return seconds;
    }
    //initializing overloaded multiplication operator
    //operator creates a new TimeSpan object, temp, and sets its hour, minutes, and seconds member variables to the product of the corresponding
    //member variables of the object on which the operator is called (this) and the input value.
    //calls the Simplify() method on the temp object to ensure that the values of the hours, minutes, and seconds members variables are in a valid range.
    //lastly, returns the temp object.
    TimeSpan TimeSpan::operator*(int value) const {
        TimeSpan temp;
        
        temp.hour = hour * value;
        temp.minutes = minutes * value;
        temp.seconds = seconds * value;
        temp.Simplify();
        return temp;
    }
    //initializing overloaded operator<<
    //operator uses the getHour(), getMinute(), and getSecond() accessor methods of the t object to get the values of the hour, minutes, and seconds, respectively.
    //checks if any of the hour, minutes, or seconds are negative, and if so, it uses the abs() function to get the absolute value of the negative value,
    //and then it uses outStream to output the hour, minutes, and seconds values as a string in the format "HH:MM:SS" where HH, MM, SS are the hour, minutes and seconds.
    //the operator uses the setw() and setfill() manipulators to ensure that the minutes and seconds are always output with two digits.
    //lastly, it returns a reference to the output stream object (outStream) so that multiple << operators can be chained together.
    ostream& operator<<(ostream &outStream, const TimeSpan &t) {
        if(t.getHour() < 0 || t.getMinute() < 0 || t.getSecond() < 0)
        {
            outStream << "-" << abs(t.getHour()) << ":" << setw(2) << setfill('0') <<
            abs(t.getMinute()) << ":" << setw(2) << setfill('0') << abs(t.getSecond());
            return outStream;
        }
        else if(t.getSecond() < 0 || t.getMinute() < 0) 
        {
            outStream << "-" << t.getHour() << ":" << setw(2) << setfill('0') <<
            abs(t.getMinute()) << ":" << setw(2) << setfill('0') << abs(t.getSecond());
            return outStream;
        }
        else{
            outStream << t.getHour() << ":" << setw(2) << setfill('0') <<
            t.getMinute() << ":" << setw(2) << setfill('0') << t.getSecond(); 
            return outStream;
        }
    }