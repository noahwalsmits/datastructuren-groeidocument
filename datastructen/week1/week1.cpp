#include <iostream>

bool search(std::string& s, char& key)
{
	if (s.find(key) == std::string::npos)
	{
		return false;
	}
	return true;
}

void exercise1_1()
{
	std::string enteredString = "hi";
	char enteredKey = 'o';

	std::cout << "enter a string to search through:" << std::endl;
	std::cin >> enteredString;
	std::cout << "enter a character to search for:" << std::endl;
	std::cin >> enteredKey;

	if (search(enteredString, enteredKey))
	{
		std::cout << enteredKey << " was found in " << enteredString << std::endl;
	}
	else
	{
		std::cout << enteredKey << " was not found in " << enteredString << std::endl;
	}
}

int main()
{
	exercise1_1();
}
