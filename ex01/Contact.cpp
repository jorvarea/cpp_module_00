#include "Contact.hpp"
#include <iostream>

Contact::Contact()
    : firstName(""), lastName(""), nickname(""), phoneNumber(""),
      darkestSecret("") {}

Contact::Contact(std::string firstName, std::string lastName,
                 std::string nickname, std::string phoneNumber,
                 std::string darkestSecret)
    : firstName(firstName), lastName(lastName), nickname(nickname),
      phoneNumber(phoneNumber), darkestSecret(darkestSecret) {}

std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getDarkestSecret() const { return darkestSecret; }

void Contact::printContact() const {
  std::cout << "First Name: " << firstName << std::endl;
  std::cout << "Last Name: " << lastName << std::endl;
  std::cout << "Nickname: " << nickname << std::endl;
  std::cout << "Phone Number: " << phoneNumber << std::endl;
  std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}
