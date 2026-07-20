#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    static const int MAX_CONTACTS = 8;
    Contact _contacts[MAX_CONTACTS];
    int _numContacts;
    int _oldestIndex;

    std::string truncate(std::string str) const;
    void displayContact(int index) const;

public:
    PhoneBook();
    ~PhoneBook();

    void addContact();
    void searchContacts() const;
    void exitPhoneBook() const;
};

#endif
