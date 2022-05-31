#include <iostream>
#include <string>

int main()
{
	int i;
	std::string str;

	std::cout << "Please enter an integer value: " << std::endl;
	std::cin >> i;
	std::cout << "The value you entered is " << i << std::endl;

	std::cout << "Press enter to close..." << std::endl;
	std::getline(std::cin, str);
	std::getline(std::cin, str);
	return 0;
}