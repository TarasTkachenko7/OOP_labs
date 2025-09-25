#include <iostream>
#include "include/converter.h"

int main() {
    std::string time_12_format;

    std::cout << "Введите время в 12-часовом формате: ";
    std::getline(std::cin, time_12_format);

    std::string time24 = convertTo24(time_12_format);

    std::cout << "24-часовой формат: " << time24 << std::endl;

    return 0;
}
