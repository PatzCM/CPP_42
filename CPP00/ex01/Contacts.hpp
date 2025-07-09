#include <iostream>
class Contacts
{
	public:
		Contacts(); // Constructor
		~Contacts(); // Destructor
		Contacts(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret);
		void setFirstName(const std::string firstName);
		void setLastName(const std::string lastName);
		void setNickname(const std::string nickname);
		void setPhoneNumber(const std::string phoneNumber);
		void setDarkestSecret(const std::string darkestSecret);
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
		std::string setString(std::string str);
		std::string setNumber(std::string str);
		std::string trimSpaces(const std::string str);
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
};
