#include "Test.h"

void Tests::MakeTest(void) {
	int testQuantity{ 5 };
	int isChecked{ 0 };
	for (int i = 0; i < 5; i++) {

		std::string text;
		int rows{ 0 };
		std::vector<std::vector<std::string>> dic;
		FileWork::Input(text, std::to_string(i) + "test.txt", rows, dic);

		std::string cryptedText;
		Dictionary dictionary(text, 100);
		dictionary.Sort();
		dictionary.CodingTables();
		cryptedText = dictionary.Replacement();

		if (dictionary._dictionary.size() > 0) {
			isChecked++;
		}
		else {
			std::cout << "Test " << i + 1 << " failed!" << std::endl;
		}

		
	}
	if (isChecked == testQuantity) std::cout << "Tests passed!" << std::endl << std::endl;
}