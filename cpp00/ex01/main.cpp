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
	int index;
	do {
		std::string input = promptString(prompt);
		index = std::strtol(input.data(), nullptr, 10);
	} while (index < minValue || index > maxValue);
	return index;
}

void addContact(PhoneBook& phoneBook)
{
	Contact newContact;
	newContact.setFirstName(promptString("Enter a first name"));
	newContact.setLastName(promptString("Enter a last name"));
	newContact.setNickname(promptString("Enter a nickname"));
	newContact.setPhoneNumber(promptString("Enter a phone number"));
	newContact.setDarkestSecret(promptString("Enter a darkest secret"));
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
	int index = promptNumber("Enter a number between 1 and 8", 1, 8);
	const Contact& contact = phoneBook.getContact(index);
	if (contact.getFirstName().empty()) {
		std::cout << "No such contact!\n";
	} else {
		std::cout << "First name: " << contact.getFirstName() << "\n";
		std::cout << "Last name: " << contact.getLastName() << "\n";
		std::cout << "Nickname: " << contact.getNickname() << "\n";
		std::cout << "Phone number: " << contact.getPhoneNumber() << "\n";
		std::cout << "Darkest secret: " << contact.getDarkestSecret() << "\n";
	}
}

int main()
{
	PhoneBook phoneBook;
	std::string input;
	while (input != "EXIT") {
		input = promptString("Enter ADD, SEARCH, or EXIT");
		if (input == "ADD") {
			addContact(phoneBook);
		} else if (input == "SEARCH") {
			showAllContacts(phoneBook);
			showContactDetails(phoneBook);
		}
	}
}
