//Ian Fletcher
//This is my own work
#include <iostream>
#include <cstring>
#include <vector>
#include <cctype>

using namespace std;

//Declaring encrypt function
string encrypt(string in, int shift);

//main function
int main()
{
	//asks user for a number for the encryption key
	int shiftVal = 0;
	cout << "Enter a number key: ";
	cin >> shiftVal;
	cout << "" << endl;
	string input = "";
	//creates a vector of strings to hold the encrypted values
	vector<string> encryptVec;
	//creates a boolean called enter to control the while loop
	bool enter = true;
	//prompts the user to enter words and type done when they are finished
	cout << "Enter words to encrypt and type done when you're done." << endl;
	//while loop to fill vector with the user's inputs
	while (enter)
	{
		cin >> input;
		if (input == "done")
		{
			enter = false;
			break;
		}
		else
		{
			encryptVec.push_back(input);
		}
	}
	//runs an if statement that sets the shiftVal to a number between 0 and 26
	if (shiftVal > 26)
	{
		shiftVal = shiftVal % 26;
	}
	//prints out shiftVal
	cout << shiftVal << endl;
	//runs encrypt function given input and shiftVal
	for (int i = 0; i < encryptVec.size(); i++)
	{
		string output = encrypt(encryptVec[i], shiftVal);
		printf("%s\t%10s\n", encryptVec[i].c_str(), output.c_str());
	}
	return 0;
}

//encrypt function
string encrypt(string in, int shiftNum)
{
	//creates a string to hold the value
	string shifted = "";
	//for loop that changes value of every letter in the input
	for (int i = 0; i < in.length(); i++)
	{
		//sets the character at index i to lower case
		shifted[i] = tolower(in[i]);
		//checks if the sum is greater than 122 and finds the remainder if it does
		if (shifted[i] + shiftNum > 122)
		{
			shifted += static_cast<char>((shifted[i] + shiftNum - 122) + 96);
		}
		else
		{
			shifted += static_cast<char>(shifted[i] + shiftNum);
		}
	}
	//returns shifted
	return shifted;
}