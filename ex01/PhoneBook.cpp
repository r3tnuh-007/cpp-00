#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>

PhoneBook::PhoneBook() : _numContacts(0), _oldestIndex(0) {}

PhoneBook::~PhoneBook() {}

std::string PhoneBook::truncate(std::string str) const {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void PhoneBook::addContact() {
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

	std::cout << "Enter first name: ";
	std::getline(std::cin, firstName);
	std::cout << "Enter last name: ";
	std::getline(std::cin, lastName);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkestSecret);

	if (firstName.empty() || lastName.empty() || nickname.empty() ||
		phoneNumber.empty() || darkestSecret.empty()) {
		std::cout << "Error: All fields must be filled!" << std::endl;
		return;
	}

	int index = _numContacts < MAX_CONTACTS ? _numContacts : _oldestIndex;
	_contacts[index] = Contact(firstName, lastName, nickname, phoneNumber, darkestSecret);

	if (_numContacts < MAX_CONTACTS)
		_numContacts++;
	else
		_oldestIndex = (_oldestIndex + 1) % MAX_CONTACTS;

	std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::displayContact(int index) const {
	if (index < 0 || index >= _numContacts || _contacts[index].isEmpty()) {
		std::cout << "Invalid index!" << std::endl;
		return;
	}
	_contacts[index].display();
}

void PhoneBook::searchContacts() const {
	if (_numContacts == 0) {
		std::cout << "PhoneBook is empty!" << std::endl;
		return;
	}

	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < _numContacts; i++) {
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << truncate(_contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << truncate(_contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << truncate(_contacts[i].getNickname()) << std::endl;
	}

	std::cout << "Enter index to display: ";
	std::string input;
	std::getline(std::cin, input);

	if (input.empty()) {
		std::cout << "Invalid input!" << std::endl;
		return;
	}

	int index = std::atoi(input.c_str());
	displayContact(index);
}

void PhoneBook::exitPhoneBook() const {
	std::cout << "Exiting PhoneBook. All contacts will be lost forever!" << std::endl;
}
