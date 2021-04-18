#include <iostream>
#include <string>
#include <sstream>
#include "NumberWithUnits.hpp"

using namespace std;

using namespace ariel;

    void NumberWithUnits::read_units(std::ifstream& file){}

    NumberWithUnits& NumberWithUnits::operator+=(const NumberWithUnits& other) {
        return *this;
    }

    NumberWithUnits & NumberWithUnits::operator-=(const NumberWithUnits &other){
        return *this;
    }
    
    NumberWithUnits & NumberWithUnits::operator*=(const NumberWithUnits &other){
        return *this;
    }

    NumberWithUnits ariel::operator+(const NumberWithUnits &num ,const NumberWithUnits &other){
        return num ;
    }

    NumberWithUnits ariel::operator-(const NumberWithUnits &num, const NumberWithUnits &other){
        return num ;
    }

    NumberWithUnits ariel::operator*(const NumberWithUnits &num, const double n){
        return num ;
    }

    NumberWithUnits ariel::operator*(const double n, const NumberWithUnits &num){
        return num ;
    }

    NumberWithUnits ariel::operator*(const NumberWithUnits &num, const int n){
        return num ;
    }

    NumberWithUnits ariel::operator*(const int n, const NumberWithUnits &num){
        return num ;
    }


    bool ariel::operator==(const NumberWithUnits &num ,const NumberWithUnits &other) {
        return true ;
    }

    bool ariel::operator!=(const NumberWithUnits &num ,const NumberWithUnits &other){
        return true ;
    }

    bool ariel::operator<(const NumberWithUnits &num ,const NumberWithUnits &other){
        return true ;
    }

    bool ariel::operator>(const NumberWithUnits &num ,const NumberWithUnits &other) {
        return true ;
    }

    bool ariel::operator<=(const NumberWithUnits &num ,const NumberWithUnits &other){
        return true ;
    }

    bool ariel::operator>=(const NumberWithUnits &num ,const NumberWithUnits &other){
        return true ;
    }

    //Input and Output
    ostream& ariel::operator<<(std::ostream &os, const NumberWithUnits &num){
        return os;
    }

    istream & ariel::operator>>(std::istream &in, NumberWithUnits &num){
        return in;
    }