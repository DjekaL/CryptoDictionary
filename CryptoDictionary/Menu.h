#pragma once
#include <iostream>
#include <vector>
#include "Dictionary.h"

enum class InputTipe {
	MANUAL = 0,
	FILE = 1
};

enum class Choice {
	NO = 0,
	YES = 1
 };

enum class CodingType {
	DECRYPT = 0,
	ENCRYPT = 1
};

class Menu {
public:

	template <typename ElementType>
	static ElementType GetInput(void) {
		ElementType input;
		std::cin >> input;
		while (std::cin.fail()) {
			std::cout << "Incorrect input!" << std::endl << "Input: " << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> input;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << std::endl;
		return input;
	}

	void Start(void);
	
	void ManualInput(std::vector<std::string>& text);
	
	void FileSaveWork(std::string data, Dictionary dic = Dictionary());

	void ConsoleOutput(std::vector<std::string> data);

	template <typename AskType>
	static AskType Ask(std::string ask) {
		std::cout << ask << std::endl;
		bool isCorrect{ true };
		auto choice{ static_cast<AskType>(GetInput<int>()) };
		do {
			if (choice == static_cast<AskType>(1) || choice == static_cast<AskType>(0)) {
				return static_cast<AskType>(choice);
			}
			else {
				isCorrect = false;
				std::cout << "Incorrect input!" << std::endl << "Input: ";
				choice = static_cast<AskType>(GetInput<int>());
			}
		} while (!isCorrect);
		return static_cast<AskType>(choice);
	}
private:

};