#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact() {}

Contact::Contact(std::string firstName, std::string lastName,
                 std::string nickname, std::string phoneNumber,
                 std::string darkestSecret)
    : _firstName(firstName), _lastName(lastName), _nickname(nickname),
      _phoneNumber(phoneNumber), _darkestSecret(darkestSecret) {}

Contact::~Contact() {}

std::string Contact::getFirstName() const { return _firstName; }
std::string Contact::getLastName() const { return _lastName; }
std::string Contact::getNickname() const { return _nickname; }
std::string Contact::getPhoneNumber() const { return _phoneNumber; }
std::string Contact::getDarkestSecret() const { return _darkestSecret; }

bool Contact::isEmpty() const {
    return _firstName.empty() && _lastName.empty() && _nickname.empty() &&
           _phoneNumber.empty() && _darkestSecret.empty();
}

void Contact::display() const {
    std::cout << "First name: " << _firstName << std::endl;
    std::cout << "Last name: " << _lastName << std::endl;
    std::cout << "Nickname: " << _nickname << std::endl;
    std::cout << "Phone number: " << _phoneNumber << std::endl;
    std::cout << "Darkest secret: " << _darkestSecret << std::endl;
}
