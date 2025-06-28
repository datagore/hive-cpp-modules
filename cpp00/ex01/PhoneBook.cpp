#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
	: contactsAdded(0)
{
}

PhoneBook::~PhoneBook()
{
}

PhoneBook::PhoneBook(const PhoneBook& other)
	: contactsAdded(other.contactsAdded)
{
	for (size_t i = 0; i < MAX_CONTACTS; i++)
		contacts[i] = other.contacts[i];
}

PhoneBook& PhoneBook::operator=(const PhoneBook& other)
{
	if (this != &other) {
		contactsAdded = other.contactsAdded;
		for (size_t i = 0; i < MAX_CONTACTS; i++)
			contacts[i] = other.contacts[i];
	}
	return *this;
}

void PhoneBook::addContact(const Contact &contact)
{
	contacts[contactsAdded++ % MAX_CONTACTS] = contact;
}

const Contact& PhoneBook::getContact(size_t index) const
{
	return contacts[index - 1];
}
