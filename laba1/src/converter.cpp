#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

std::string convertTo24(const std::string time_12_format) {

    size_t colon_number = time_12_format.find(':');
    size_t space_number = time_12_format.find(' ');

    if (colon_number == std::string::npos || space_number == std::string::npos) {
        return "ERROR";
    }

    int hours = std::stoi(time_12_format.substr(0, colon_number));
    int minutes = std::stoi(time_12_format.substr(colon_number + 1, space_number - colon_number - 1));

    if (hours < 1 || hours > 12 || minutes < 0 || minutes > 59) {
        return "ERROR"; 
    }

    std::string part = time_12_format.substr(space_number + 1);

    if (part != "am" && part != "pm") {
        return "ERROR";
    }

    int time_24_format;

    if (part == "am") {
        if (hours == 12) {
            time_24_format = 0;
        } else {
            time_24_format = hours;
        }
    } else {
        if (hours == 12) {
            time_24_format = 12;
        } else {
            time_24_format = hours + 12;
        }
    }

    std::stringstream result;
    result << std::setw(2) << std::setfill('0') << time_24_format;
    result << std::setw(2) << std::setfill('0') << minutes;

    return result.str();
}
