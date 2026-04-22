/*
Sam Schneider
Introductory Programming
April 23, 2026
P14-2
*/


#include <iostream>
#include <string>

using namespace std;


/*
Gets the length of the user inputed string
@param char* character - Character Pointer
@return - Length of string
*/
int getLength(char* character) {

	int length = 0;
	
	while (*character != '\0') {
		length++;
		character++;
	}

	return length;

}

/*
Counts the number of instances of a desired characer in string
@param char* ptr - Character Pointer
@param char c - Character to count
@return - Number of instances of a desired characer in string
*/
int charcnt(char* ptr, char c) {

	int length = getLength(ptr);
	int numChar = 0;

	for (int i = 0; i < length; i++) {

		if (*ptr == c) {
			numChar++;
		}

		ptr++;
	}

	return numChar;

}

/*
Counts the number of instances of a group of repeated characters
@param char* ptr - Character Pointer
@return - Number of instances of a group of repeated characters
*/
int repeat(char* ptr) {

	int length = getLength(ptr);
	int numRepeats = 0;

	while (*(ptr + 1) != '\0') {

		if (*ptr == *(ptr + 1) && *ptr != ' ') {
			numRepeats++;

			while (*ptr == *(ptr + 1)) {
				ptr++;
			}

		}

		ptr++;

	}

	return numRepeats;

}

/*
Prints string in reverse
@param char* ptr - Character Pointer
*/
void reverse(char* ptr) {

	int length = getLength(ptr);

	ptr = ptr + length - 1;

	for (int i = 0; i < length; i++) {

		cout << *ptr;
		ptr--;

	}

}


int main() {
	char userString[80];				//Defines a character array with 80 or less characters (as specified in P14-2)
	char repeatChar = 'a';				//Character to be counted using charcnt
	char* ptr = userString;				//Character pointer

	//Fills the userString array with '\0'
	for (int i = 0; i < 80; i++) {
		*ptr = '\0';
		ptr++;
	}

	//Resets position of pointer
	ptr = userString;

	//Prompts the user to enter a string
	cout << "Enter a string: ";
	cin.getline(userString, 80);

	//Prompts the user to enter which character they'd like to count
	cout << "Enter a character: ";
	cin.get(repeatChar);

	//Displays results
	cout << "The character '" << repeatChar << "' is repeated " << charcnt(ptr, repeatChar) << " times in the string.\n";
	cout << "There are " << repeat(ptr) << " repeated characters in the string.\n";
	cout << "The reverse of the string is: ";
	reverse(ptr);

	//Ends program
	return 0;
}