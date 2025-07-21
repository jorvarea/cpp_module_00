#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main() {
    std::string command;
    std::string input;
    std::string index_str;
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
            input = "";
            while (input.empty()) {
                std::cout << "First Name: ";
                std::getline(std::cin, input);
            }
            firstName = input;
            input = "";
            while (input.empty()) {
                std::cout << "Last Name: ";
                std::getline(std::cin, input);
            }
            lastName = input;
            input = "";
            while (input.empty()) {
                std::cout << "Nickname: ";
                std::getline(std::cin, input);
            }
            nickname = input;
            input = "";
            while (input.empty()) {
                std::cout << "Phone Number: ";
                std::getline(std::cin, input);
            }
            phoneNumber = input;
            input = "";
            while (input.empty()) {
                std::cout << "Darkest Secret: ";
                std::getline(std::cin, input);
            }
            darkestSecret = input;
            Contact contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
            phoneBook.addContact(contact);
        } else if (command == "SEARCH") {
            phoneBook.printContacts();
            std::cout << "Please enter the index of the contact to search: ";
            std::getline(std::cin, index_str);
            try {
                index = std::stoi(index_str);
                phoneBook.getContact(index).printContact();
            } catch (const std::out_of_range &e) {
                std::cout << "Index out of range" << std::endl;
            } catch (const std::invalid_argument &e) {
                std::cout << "Invalid index" << std::endl;
            }
        }
        std::cout << "-------------------------------------------" << std::endl;
        std::cout << "Please enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        std::cout << "-------------------------------------------" << std::endl;
    }
    if (command == "EXIT") {
        std::cout << "Goodbye!" << std::endl;
    }
    return 0;
}
