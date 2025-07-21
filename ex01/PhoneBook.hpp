#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
    Contact contacts[8];
    int index;
    int totalContacts;

    std::string formatField(const std::string& str) const;

public:
    PhoneBook();
    void addContact(const Contact &contact);
    void printContacts() const;
    Contact getContact(int index) const;
};

#endif