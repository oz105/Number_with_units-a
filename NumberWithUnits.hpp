#pragma once

#include <iostream>
#include <string>

namespace ariel
{
    class NumberWithUnits
    {
    private:
        double m_value ;
        std::string m_type ; 
    public:
        NumberWithUnits(const double& value , const std::string& type):m_value(value), m_type(type){}
        NumberWithUnits();
        ~NumberWithUnits() = default ;
        
        /*
         * getters
         */
        double value() const {
            return m_value;
        }
        std::string type() const {
            return m_type;
        }

        static void read_units(std::ifstream& file);

        NumberWithUnits operator-(){
            return NumberWithUnits(-m_value, m_type);
        }

        NumberWithUnits operator+(){
            return NumberWithUnits(+m_value, m_type);
        }

        NumberWithUnits &operator+=(const NumberWithUnits &other);

        NumberWithUnits &operator-=(const NumberWithUnits &other);

        NumberWithUnits& operator*=(const NumberWithUnits& other);

        // prefix
        NumberWithUnits &operator++(){
            m_value ++ ;
            return *this ;
        }

        NumberWithUnits &operator--(){
            m_value -- ;
            return *this ;
        }

        // postfix
        NumberWithUnits operator++(int dummy_flag_for_postfix_increment){
            NumberWithUnits copy = *this ;
            m_value ++ ;
            return copy ;
        }

        NumberWithUnits operator--(int dummy_flag_for_postfix_increment){
            NumberWithUnits copy = *this;
            m_value--;
            return copy;
        }

        friend NumberWithUnits operator+(const NumberWithUnits &num ,const NumberWithUnits &other);

        friend NumberWithUnits operator-(const NumberWithUnits &num, const NumberWithUnits &other) ;

        friend NumberWithUnits operator*(const NumberWithUnits &num, const double n);

        friend NumberWithUnits operator*(const double n, const NumberWithUnits &num);

        friend NumberWithUnits operator*(const NumberWithUnits &num, const int n);

        friend NumberWithUnits operator*(const int n, const NumberWithUnits &num);


        friend bool operator==(const NumberWithUnits &num ,const NumberWithUnits &other) ;

        friend bool operator!=(const NumberWithUnits &num ,const NumberWithUnits &other);

        friend bool operator<(const NumberWithUnits &num ,const NumberWithUnits &other) ;

        friend bool operator>(const NumberWithUnits &num ,const NumberWithUnits &other) ;

        friend bool operator<=(const NumberWithUnits &num ,const NumberWithUnits &other);

        friend bool operator>=(const NumberWithUnits &num ,const NumberWithUnits &other);



        //Input and Output
        friend std::ostream &operator<<(std::ostream &os, const NumberWithUnits &num);

        friend std::istream &operator>>(std::istream &in, NumberWithUnits &num);

    };
} // namespace ariel
