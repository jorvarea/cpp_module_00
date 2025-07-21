#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : index(0), totalContacts(0) {}

void PhoneBook::addContact(Contact contact) {
    contacts[index % 8] = contact;
    index = (index + 1) % 8;
    if (totalContacts < 8)
        totalContacts++;
}

Contact PhoneBook::getContact(int idx) const {
    if (idx < 0 || idx >= totalContacts)
        throw std::out_of_range("Invalid index");
    return contacts[idx];
}


std::string PhoneBook::formatField(const std::string& str) const {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    else
        return str;
}

void PhoneBook::printContacts() const {
    std::cout << std::right;
    std::cout << std::setw(10) << formatField("Index")     << "|"
              << std::setw(10) << formatField("First Name")<< "|"
              << std::setw(10) << formatField("Last Name") << "|"
              << std::setw(10) << formatField("Nickname")  << std::endl;

    for (int i = 0; i < totalContacts; ++i) {
        std::cout << std::setw(10) << i                                            << "|"
                  << std::setw(10) << formatField(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << formatField(contacts[i].getLastName())  << "|"
                  << std::setw(10) << formatField(contacts[i].getNickname())  << std::endl;
    }
}
