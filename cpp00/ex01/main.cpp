#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string_view>

#include "PhoneBook.hpp"

std::string promptString(const char *prompt)
{
	std::string input;
	while (input.empty()) {
		std::cout << prompt << ": ";
		std::getline(std::cin, input);
	}
	std::cout << std::endl;
	return input;
}

int promptNumber(const char *prompt, int minValue, int maxValue)
{
	int index = 0;
	while (index < minValue || index > maxValue) {
		std::string input = promptString(prompt);
		index = std::strtol(input.data(), nullptr, 10);
	}
	return index;
}

void addContact(PhoneBook& phoneBook)
{
	Contact newContact;
	newContact.setFirstName(promptString("Please enter a first name"));
	newContact.setLastName(promptString("Please enter a last name"));
	newContact.setNickname(promptString("Please enter a nickname"));
	newContact.setPhoneNumber(promptString("Please enter a phone number"));
	newContact.setDarkestSecret(promptString("Please enter a darkest secret"));
	phoneBook.addContact(newContact);
}

void showField(const std::string& field, const char* end)
{
	if (field.length() <= 10)
		std::cout << std::setw(10) << field << end;
	else
		std::cout << std::string_view(field.data(), 9) << '.' << end;
}

void showAllContacts(const PhoneBook& phoneBook)
{
	for (int i = 1; i <= phoneBook.MAX_CONTACTS; i++) {
		const Contact& contact = phoneBook.getContact(i);
		if (!contact.getFirstName().empty()) {
			std::cout << std::setw(10) << i << " | ";
			showField(contact.getFirstName(), " | ");
			showField(contact.getLastName(), " | ");
			showField(contact.getNickname(), "\n");
		}
	}
}

void showContactDetails(const PhoneBook& phoneBook)
{
	int index = promptNumber("Please enter a number between 1 and 8", 1, 8);
	const Contact& contact = phoneBook.getContact(index);
	std::cout << "First name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
}

int main()
{
	PhoneBook phoneBook;
	std::string input;
	while (input != "EXIT") {
		input = promptString("Please enter ADD, SEARCH, or EXIT");
		if (input == "ADD") {
			addContact(phoneBook);
		} else if (input == "SEARCH") {
			showAllContacts(phoneBook);
			showContactDetails(phoneBook);
		}
	}
}
