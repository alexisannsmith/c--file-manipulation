#include <iostream>
#include<string>
#include <fstream>


void appendToFile(std::string input) {		// Function appends input to a file
	std::ofstream module5File ("C:\\Users\\alexi\\OneDrive\\Documents\\CSC 450\\CSC450_CT5_mod5.txt", std::ios::app);

	if (module5File.is_open()) {	// Checks if file is open. If so, writes input to file.
		module5File << std::endl << input << std::endl;
		module5File.close();
		std::cout << "Write successful" << std::endl;
	}
	else {
		std::cout << "File not found";
	}
}

void writeNewFile(std::string input) {		// Function writes input to separate file
	std::ofstream inputFile("CSC450_mod5-2.txt");

	if (inputFile.is_open()) {		// Checks if file is open. If so, write to file.
		std::cout << "Writing to new file..." << std::endl;
		inputFile << input << std::endl;
		inputFile.close();
		std::cout << "Write successful" << std::endl;
	}
	else {
		std::cout << "File not found";
	}
}

void reverseText() {		//  Function reverses the contents of CSC450_mod5-2 and writes it to a new file.
	bool reverse = false;	// Boolean used to check if the contents of the file have been successfully reversed.
	std::string fileString;	// Second string to hold the reversed string.
	std::ifstream inputFile("CSC450_mod5-2.txt");

	if (inputFile.is_open()) {		// Checks if file is open. If so, reads the content of the file and reverses it.
		std::cout << "Reversing file..." << std::endl;
		std::getline(inputFile, fileString);
		std::reverse(fileString.begin(), fileString.end());	// Use std::reverse to reverse the string.
		inputFile.close();
		reverse = true;		// Set bool to true as the contents of the file have been successfully reversed.
	}
	else {
		std::cout << "File not found";
	}

	if (reverse) {			// If the contents have been reversed, write the reversed string to the new file.
		std::ofstream reverseFile("CSC450-mod5-reverse.txt");
		reverseFile << fileString << std::endl;
		reverseFile.close();
		std::cout << "Reverse successful";
	}
}

int main() {
	std::string input;	

	std::cout << "Begin Writing..." << std::endl;	// Take user input and call functions in main.
	std::getline(std::cin, input);
	
	appendToFile(input);
	writeNewFile(input);
	reverseText();

	return 0;
}
