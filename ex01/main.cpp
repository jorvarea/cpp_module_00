#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main() {
    std::string command;
    int index;
    PhoneBook phoneBook;
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    std::cout << "Welcome to the PhoneBook!" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "Please enter a command (ADD, SEARCH, EXIT): ";
    std::getline(std::cin, command);
    std::cout << "-------------------------------------------" << std::endl;
    while (command != "EXIT") {
        if (command == "ADD") {
            std::cout << "Please enter the contact information: " << std::endl;
            std::cout << "First Name: ";
            std::getline(std::cin, firstName);
            std::cout << "Last Name: ";
            std::getline(std::cin, lastName);
            std::cout << "Nickname: ";
            std::getline(std::cin, nickname);
            std::cout << "Phone Number: ";
            std::getline(std::cin, phoneNumber);
            std::cout << "Darkest Secret: ";
            std::getline(std::cin, darkestSecret);
            Contact contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
            phoneBook.addContact(contact);
        } else if (command == "SEARCH") {
            phoneBook.printContacts();
            std::cout << "Please enter the index of the contact to search: ";
            std::cin >> index;
            try {
                phoneBook.getContact(index).printContact();
            } catch (const std::out_of_range &e) {
                std::cout << "Index out of range" << std::endl;
            }
        }
        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "Please enter a command (ADD, SEARCH, EXIT): ";
        std::cin >> command;
        std::cout << "-------------------------------------------" << std::endl;
    }
    if (command == "EXIT") {
        std::cout << "Goodbye!" << std::endl;
    }
    return 0;
}
