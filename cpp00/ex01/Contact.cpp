#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

Contact::Contact(const Contact& other)
	: firstName(other.firstName),
	  lastName(other.lastName),
	  nickname(other.nickname),
	  phoneNumber(other.phoneNumber),
	  darkestSecret(other.darkestSecret)
{
}

Contact& Contact::operator=(const Contact &other)
{
	if (this != &other) {
		firstName = other.firstName;
		lastName = other.lastName;
		nickname = other.nickname;
		phoneNumber = other.phoneNumber;
		darkestSecret = other.darkestSecret;
	}
	return *this;
}

void Contact::setFirstName(const std::string& newFirstName)
{
	firstName = newFirstName;
}

void Contact::setLastName(const std::string& newLastName)
{
	lastName = newLastName;
}

void Contact::setNickname(const std::string& newNickname)
{
	nickname = newNickname;
}

void Contact::setPhoneNumber(const std::string& newPhoneNumber)
{
	phoneNumber = newPhoneNumber;
}

void Contact::setDarkestSecret(const std::string& newDarkestSecret)
{
	darkestSecret = newDarkestSecret;
}

const std::string& Contact::getFirstName() const
{
	return firstName;
}

const std::string& Contact::getLastName() const
{
	return lastName;
}

const std::string& Contact::getNickname() const
{
	return nickname;
}

const std::string& Contact::getPhoneNumber() const
{
	return phoneNumber;
}

const std::string& Contact::getDarkestSecret() const
{
	return darkestSecret;
}
