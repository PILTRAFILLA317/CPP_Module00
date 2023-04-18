#include "PhoneBook.hpp"

int main(int ac, char **av)
{
	std::string input_string;
	std::string exit_string("exit");
	// std::string

	(void)av;
	if (ac > 1){
		std::cout << "Error, too many args\n";
		}
	std::cout << "Wellcome COBook\n";
	while (1){
		std::cout << "> ";
		getline(std::cin, input_string);
		if (!input_string.compare(exit_string))
			exit(1);
	}
}