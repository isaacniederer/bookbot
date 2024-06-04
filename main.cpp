#include <iostream>
#include <fstream>

using namespace std;

int main()
{

	fstream file("books/frankenstein.txt", fstream::in);

	try {
		if (!file.is_open()){
			throw 101;
		}
	}
	catch(int num) {
		cout << "Error opening file." << endl << "Make sure file path is correct and you have the correct permissions." << endl;
		return num;
	}

	string word;
	int wordcount = 0;

	while(!file.eof()){
		file >> word;
		wordcount++;
	}

	file.clear();
	file.seekg(0);

	char ch = ' ';
	char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
		'u', 'v', 'w', 'x', 'y', 'z'};
	int count[26] = {0};

	while (file >> noskipws >> ch){
		// character is a capital letter
		if (ch >= 0x41 && ch <= 0x5A) {
			ch += 0x20;
			for (int i = 0; i < 26; i++){
				if (ch == letters[i]){
					count[i]++;
				}
			}
		}
		// character is a lower case letter
		else if (ch >= 0x61 && ch <= 0x7A) {
			for (int i = 0; i < 26; i++){
				if (ch == letters[i]){
					count[i]++;
				}
			}
		}
		// we don't care about any other special characters
	}
/*         //print out to make sure the characters correspond to the correct values
	for (int i = 0; i < 26; i++){
		printf("the character '%c' occurs %d times\n", letters[i], count[i]);
	}
*/
	for (int i = 0; i < 25; i++){
		for (int j = 0; j < (25 - i) ; j++){
			if (count[j] > count[j+1]){
				int temp_int = count[j];
				char temp_char = letters[j];
				count[j] = count[j+1];
				letters[j] = letters[j+1];
				count[j+1] = temp_int;
				letters[j+1] = temp_char;
			}
		}
	}

	cout << "--- Begin report of books/frankenstein.txt ---" << endl;
	cout << wordcount << " words found in the document" << endl << endl;
	for (int i = 25; i >= 0; i--){
		cout << "The '" << letters[i] << "' character was found " << count[i] << " times" << endl;
	}
	cout << "--- End Report ---" << endl;

	file.close();

	return 0;
}
