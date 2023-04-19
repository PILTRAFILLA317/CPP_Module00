#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <cctype>

class Contact {
	private:
		std::string first_name_;
		std::string last_name_;
		std::string nickname_;
		std::string darkest_secret_;
		std::string phone_number_;
		int			index_;
	public:
		Contact(std::string first_name, std::string last_name, std::string nickname,
				std::string drk_secret, std::string phone_number, int index)
				: first_name_(first_name), last_name_(last_name), nickname_(nickname),
				darkest_secret_(drk_secret), phone_number_(phone_number), index_(index) {}
		Contact(){};
		~Contact(){};
		void contact_printer_tab(void);
		void contact_printer_line(void);
		void index_updater(void);
};

#endif