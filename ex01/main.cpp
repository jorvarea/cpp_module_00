#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>

std::string getInput(const std::string &prompt) {
  std::string input;
  while (input.empty()) {
    std::cout << prompt;
    std::getline(std::cin, input);
  }
  return input;
}

int main() {
    std::string command;
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
            firstName = getInput("First Name: ");
            lastName = getInput("Last Name: ");
            nickname = getInput("Nickname: ");
            phoneNumber = getInput("Phone Number: ");
            darkestSecret = getInput("Darkest Secret: ");
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
