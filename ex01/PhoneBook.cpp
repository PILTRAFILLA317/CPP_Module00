#include "Contact.hpp"
#include "PhoneBook.hpp"


PhoneBook::PhoneBook(void): num_contacts_(0){};
PhoneBook::~PhoneBook(void){};

void PhoneBook::add_contact(void){
	std::string fn;
	std::string ln;
	std::string nick;
	std::string sec;
	std::string num;
	if (num_contacts_ < 8){
		std::cout << "\x1B[2J\x1B[H";
		std::cout << "Insert first name > ";
		getline(std::cin, fn);
		std::cout << "Insert last name > ";
		getline(std::cin, ln);
		std::cout << "Insert nickname > ";
		getline(std::cin, nick);
		std::cout << "Insert darkest secret > ";
		getline(std::cin, sec);
		std::cout << "Insert phone number > ";
		getline(std::cin, num);
		if (fn == "" || ln == "" || nick == "" || sec == "" | num == "")
			std::cout << "\x1B[2J\x1B[H" << "No field can be empty!\n";
		else{
			contacts_[num_contacts_] = Contact (fn, ln, nick, sec, num, (num_contacts_ + 1));
			num_contacts_ ++;
		}
	}
	else {
		int temp_num = 0;
		std::cout << "\x1B[2J\x1B[H";
		std::cout << "Insert first name > ";
		getline(std::cin, fn);
		std::cout << "Insert last name > ";
		getline(std::cin, ln);
		std::cout << "Insert nickname > ";
		getline(std::cin, nick);
		std::cout << "Insert darkest secret > ";
		getline(std::cin, sec);
		std::cout << "Insert phone number > ";
		getline(std::cin, num);
		if (fn == "" || ln == "" || nick == "" || sec == "" | num == "")
			std::cout << "\x1B[2J\x1B[H" << "No field can be empty!\n";
		else{
			while (temp_num < 7)
			{
				contacts_[temp_num] = contacts_[temp_num + 1];
				contacts_[temp_num].index_updater();
				temp_num ++;
			}
			contacts_[7] = Contact (fn, ln, nick, sec, num, 8);
		}
	}
};

void PhoneBook::full_printer(void){
	std::string str_num;
	std::cout << "\x1B[2J\x1B[H";
	std::cout << "Index     |First name|Last name |Nickname  " << std::endl;
	std::cout << "----------|----------|----------|----------" << std::endl;
	for (int i = 0; i < num_contacts_; i++) {
		contacts_[i].contact_printer_tab();
	}
	std::cout << "\nInsert index > ";	
	getline(std::cin, str_num);
	int num;
	if (std::sscanf(str_num.c_str(), "%d", &num) != 1) {
		std::cout << "Error\n";
		return ;
	}
	num = num - 1;
	if (((num + 1) > num_contacts_) || ((num + 1) <= 0)) {
		std::cout << "Error\n";
		return ;
	}
	contacts_[num].contact_printer_line();
}