#include <iostream>
#include <string>

using namespace std;

int getLength(char* character) {

	int length = 0;
	
	while (*character != '\0') {
		length++;
		character++;
	}

	return length;

}

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

void reverse(char* ptr) {
	int length = getLength(ptr);

	ptr = ptr + length - 1;

	for (int i = 0; i < length; i++) {

		cout << *ptr;
		ptr--;

	}

}






int main() {
	char userString[80];
	char repeatChar = 'a';
	char* ptr = userString;

	for (int i = 0; i < 80; i++) {
		*ptr = '\0';
		ptr++;
	}

	ptr = userString;

	cout << "Enter a string: ";
	cin.getline(userString, 80);

	cout << "Enter a character: ";
	cin.get(repeatChar);

	cout << "The character '" << repeatChar << "' is repeated " << charcnt(ptr, repeatChar) << " times in the string.\n";
	cout << "There are " << repeat(ptr) << " repeated characters in the string.\n";
	cout << "The reverse of the string is: ";
	reverse(ptr);

}