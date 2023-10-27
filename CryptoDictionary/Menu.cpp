#include "FileWork.h"

void Menu::Start(void) {
	std::cout << "The first lab" << std::endl;
	std::cout << "Created by student of 404th group Kulyaev Evgeny" << std::endl;
	std::cout << "Variant 9" << std::endl;
	std::cout << "In each word of the text, move the vowels to the beginning words, consonants - at the end of the word." << std::endl << std::endl;
}

void Menu::ManualInput(std::vector<std::string>& text) {
	std::string line;
	std::cout << "Enter your text. If want to end input, enter: '[stop]'" << std::endl;
	do {
		getline(std::cin, line);
		if (text.empty() && line == "[stop]") {
			std::cout << "You must enter text before finishing typing!" << std::endl;
			line.clear();
			continue;
		}
		if (line != "[stop]") {
			text.push_back(line);
		}
	} while (line != "[stop]");
}

void Menu::FileSaveWork(std::string data, Dictionary dic) {
	std::cout << "Enter the file address." << std::endl;
	auto path{ Menu::GetInput<std::string>() };
	FileWork file(path);
	file.FileCheck();
	file.Save(data, dic);
}


void Menu::ConsoleOutput(std::vector<std::string> data) {
	for (auto string : data) {
		std::cout << string << std::endl;
	}
	std::cout << std::endl;
}

