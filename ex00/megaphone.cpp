#include <iostream>
#include <cctype>

int main(int ac, char **av) {
	if (ac > 2 || ac <= 1) {
		std::cout << "Error\n";
		exit(0);
	}
	std::string inputstr(av[1]);
	for (size_t i = 0; i < inputstr.length(); i++) {
		inputstr[i] = toupper(inputstr[i]);
	}
	std::cout << inputstr << "\n";
	return 0; 
}