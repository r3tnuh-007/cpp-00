#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main() {
    PhoneBook phoneBook;
    std::string command;

    std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
    std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, command);

        if (command == "ADD")
            phoneBook.addContact();
        else if (command == "SEARCH")
            phoneBook.searchContacts();
        else if (command == "EXIT") {
            phoneBook.exitPhoneBook();
            break;
        }
        else if (std::cin.eof()) {
            std::cout << std::endl;
            break;
        }
    }
    return 0;
}
