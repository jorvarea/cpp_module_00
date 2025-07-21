#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : _index(0), _totalContacts(0) {}

void PhoneBook::addContact(const Contact &contact) {
    _contacts[_index % 8] = contact;
    _index = (_index + 1) % 8;
    if (_totalContacts < 8)
        _totalContacts++;
}

Contact PhoneBook::getContact(int idx) const {
    if (idx < 0 || idx >= _totalContacts)
        throw std::out_of_range("Invalid index");
    return _contacts[idx];
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

    for (int i = 0; i < _totalContacts; ++i) {
        std::cout << std::setw(10) << i                                            << "|"
                  << std::setw(10) << formatField(_contacts[i].getFirstName()) << "|"
                  << std::setw(10) << formatField(_contacts[i].getLastName())  << "|"
                  << std::setw(10) << formatField(_contacts[i].getNickname())  << std::endl;
    }
}
