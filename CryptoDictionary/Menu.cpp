#include "FileWork.h"

void Menu::Start(void) {
	std::cout << "The first lab" << std::endl;
	std::cout << "Created by student of 404th group Kulyaev Evgeny" << std::endl;
	std::cout << "Variant 9" << std::endl;
	std::cout << "In each word of the text, move the vowels to the beginning words, consonants - at the end of the word." << std::endl << std::endl;
}

Choice Menu::ModularTest(void) {
	std::cout << "Do you want to perform tests?" << std::endl;
	std::cout << "1 - Yes | 0 - No" << std::endl;
	return Ask<Choice>();
}

InputTipe Menu::InputAsk(void) {
	std::cout << "How do you want to enter the text?" << std::endl;
	std::cout << "1 - Input from file | 0 - Manual input" << std::endl;
	return Ask<InputTipe>();
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

Choice Menu::SaveInputAsk(void) {
	std::cout << "Do you want to save input data in file?" << std::endl;
	std::cout << "1 - Yes | 0 - No" << std::endl;
	return Ask<Choice>();
}

Choice Menu::RewriteFileAsk(void) {
	std::cout << "Do you want to rewrite file?" << std::endl;
	std::cout << "1 - Yes | 0 - No" << std::endl;
	return Ask<Choice>();
}

void Menu::ConsoleOutput(std::vector<std::string> data) {
	for (auto string : data) {
		std::cout << string << std::endl;
	}
	std::cout << std::endl;
}

Choice Menu::OutputFileAsk(void) {
	std::cout << "Do you want to save sorted text in file?" << std::endl;
	std::cout << "1 - Yes | 0 - No" << std::endl;
	return Ask<Choice>();
}

Choice Menu::RepeatAsk(void) {
	std::cout << "Do you want to repeat programm?" << std::endl;
	std::cout << "1 - Yes | 0 - No" << std::endl;
	return Ask<Choice>();
}