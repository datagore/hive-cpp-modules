#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
public:
	Contact();
	~Contact();
	Contact(const Contact&);
	Contact& operator=(const Contact&);

	void setFirstName(const std::string&);
	void setLastName(const std::string&);
	void setNickname(const std::string&);
	void setPhoneNumber(const std::string&);
	void setDarkestSecret(const std::string&);

	const std::string& getFirstName() const;
	const std::string& getLastName() const;
	const std::string& getNickname() const;
	const std::string& getPhoneNumber() const;
	const std::string& getDarkestSecret() const;

private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
};

#endif // #ifndef CONTACT_HPP
