#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();
	PhoneBook(const PhoneBook&);
	PhoneBook& operator=(const PhoneBook&);

	void addContact(const Contact& contact);
	const Contact& getContact(size_t index) const;
	enum {MAX_CONTACTS = 8};

private:
	Contact contacts[MAX_CONTACTS];
	size_t contactsAdded;
};

#endif // #ifndef PHONEBOOK_HPP
