#include <stdio.h>
#include <fstream>
#include <sstream>
#include "NumberWithUnits.hpp"
#include "doctest.h"

using namespace ariel;
using namespace std;

TEST_CASE ("Init units.txt") {
    ifstream units_file{"units.txt"};
    if (!units_file.is_open()) {
        cout << "Failed open file!" << endl;
    }
}

TEST_CASE("basic"){
    NumberWithUnits km7(7, "km");
    NumberWithUnits cm750(750, "cm");
    NumberWithUnits m90 (90, "m");
    NumberWithUnits kg5 (5, "kg");
    CHECK(km7 + m90 ==  NumberWithUnits(7.9, "km"));
    CHECK((km7 < m90) == true);
    CHECK((cm750 < m90) == true);
}

ifstream units_file{"units.txt"};

TEST_CASE("operators "){
    NumberWithUnits::read_units(units_file);
    NumberWithUnits km{5, "km"};
    NumberWithUnits m{50, "m"};
    CHECK_EQ(km + m, NumberWithUnits{5.5, "km"});
    CHECK_EQ(m += km, NumberWithUnits{5050, "m"});
    NumberWithUnits cm{7, "cm"};
    CHECK_EQ(m + cm, NumberWithUnits{50.07, "m"});
    CHECK_EQ(cm += m, NumberWithUnits{5007, "cm"});
    CHECK_EQ(m -= cm, NumberWithUnits{50, "m"});
    NumberWithUnits hour{7, "hour"};
    NumberWithUnits min{8, "min"};
    NumberWithUnits sec{10, "sec"};
    CHECK_EQ(++hour, NumberWithUnits{8, "hour"});
    CHECK_EQ(hour++, NumberWithUnits{8, "hour"});
    CHECK_EQ(hour, NumberWithUnits{9, "hour"});
    CHECK_EQ(--min, NumberWithUnits{7, "min"});
    CHECK_EQ(min, NumberWithUnits{7, "min"});
    CHECK(min != (NumberWithUnits{3, "min"}));
    CHECK(sec-- == (NumberWithUnits{10, "sec"}));
    CHECK_EQ(sec, NumberWithUnits{9, "sec"});
    CHECK(sec != (NumberWithUnits{3, "sec"}));
    NumberWithUnits kg{7, "kg"};
    NumberWithUnits g{2, "g"};
    CHECK_EQ(kg + g, NumberWithUnits{7.002, "kg"});
    CHECK_EQ(g += kg, NumberWithUnits{7002, "g"});
    CHECK_EQ(kg -= g, NumberWithUnits{7, "kg"}); 
}