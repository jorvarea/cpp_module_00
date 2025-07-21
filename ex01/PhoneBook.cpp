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

Contact PhoneBook::getContact(int index) const {
    if (index < 0 || index >= 8) {
        throw std::out_of_range("Invalid index");
    }
    return contacts[index];
}


std::string PhoneBook::formatField(const std::string& str) const {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    else
        return str;
}

void PhoneBook::printContacts() const {
    std::cout << std::right;
    std::cout << std::setw(10) << formatField("Index") << "|";
    std::cout << std::setw(10) << formatField("First Name") << "|";
    std::cout << std::setw(10) << formatField("Last Name") << "|";
    std::cout << std::setw(10) << formatField("Nickname");
    std::cout << std::endl;
    
    for (int i = 0; i < totalContacts; i++) {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << formatField(contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << formatField(contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << formatField(contacts[i].getNickname());
        std::cout << std::endl;
    }
}
