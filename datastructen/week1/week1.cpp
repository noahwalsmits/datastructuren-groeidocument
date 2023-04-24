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
	std::string enteredString;
	char enteredKey;

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


// Return true if substr is the prefix for cardNumber
bool startsWith(const std::string& cardNumber, const std::string& substr)
{
	return cardNumber.find(substr) == 0;
}

// Return this number if it is a single digit, otherwise,
// return the sum of the two digits
int getDigit(int number)
{
	if (number < 10)
	{
		return number;
	}
	return (number / 10) + (number % 10);
}

// Get the result from Step 2
int sumOfDoubleEvenPlace(const std::string& cardNumber)
{
	int steps = 1;
	int sum = 0;
	for (int i = cardNumber.length() - 1; i >= 0; i--)
	{
		if ((steps % 2) == 0)
		{
			sum += getDigit((cardNumber[i] - '0') * 2);
		}
		steps++;
	}
	return sum;
}

// Return sum of odd-place digits in the card number
int sumOfOddPlace(const std::string& cardNumber)
{
	int steps = 1;
	int sum = 0;
	for (int i = cardNumber.length() - 1; i >= 0; i--)
	{
		if ((steps % 2) != 0)
		{
			sum += (cardNumber[i] - '0');
		}
		steps++;
	}
	return sum;
}

// Return true if the card number is valid
bool isValid(const std::string& cardNumber)
{
	if (cardNumber.length() < 13 || cardNumber.length() > 16)
	{
		return false;
	}

	if (!(startsWith(cardNumber, "4") || startsWith(cardNumber, "5") || startsWith(cardNumber, "37") || startsWith(cardNumber, "6")))
	{
		return false;
	}

	std::cout << "double even: " << sumOfDoubleEvenPlace(cardNumber) << std::endl;//
	std::cout << "odd: " << sumOfOddPlace(cardNumber) << std::endl;//
	if (((sumOfDoubleEvenPlace(cardNumber) + sumOfOddPlace(cardNumber)) % 10) != 0)
	{
		return false;
	}

	return true;
}

void exercise1_2()
{
	std::string enteredString;
	std::cout << "enter a card number:" << std::endl;
	std::cin >> enteredString;
	if (isValid(enteredString))
	{
		std::cout << "card number is valid" << std::endl;
	}
	else
	{
		std::cout << "card number is invalid" << std::endl;
	}
}


void count(const char s[], int counts[])
{
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < alphabet.length(); i++)
	{
		int count = 0;
		for (int j = 0; j < sizeof(s) / sizeof(char); j++) //decayed array ruins this
		{
			if (s[j] == alphabet[i])
			{
				count++;
			}
		}
		counts[i] = count;
	}
}

void exercise1_3()
{
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
	std::string enteredString;
	int results[26];
	std::cout << "enter a string:" << std::endl;
	std::cin >> enteredString;
	count(enteredString.c_str(), results);

	for (int i = 0; i < alphabet.length(); i++)
	{
		if (results[i] > 0)
		{
			std::cout << alphabet[i] << ": " << results[i] << std::endl;
		}
	}
}


int main()
{
	//exercise1_1();
	//exercise1_2();
	exercise1_3();
}
