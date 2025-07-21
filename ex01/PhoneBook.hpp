#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact _contacts[8];
    int _index;
    int _totalContacts;

    std::string formatField(const std::string& str) const;

public:
    PhoneBook();
    void addContact(const Contact &contact);
    void printContacts() const;
    Contact getContact(int index) const;
};

#endif