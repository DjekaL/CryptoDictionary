#include "FileWork.h"

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Menu menu;

	menu.Start();
	std::cout << "" << std::endl;
	std::cout << "" << std::endl;
	if (menu.Ask<Choice>("Do you want to perform tests?\n1 - Yes | 0 - No") == Choice::YES) {
		/*Tests tests;
		tests.MakeTest();*/
	}

	do
	{
		InputTipe inputType{};

		std::string text;
		int rows{ 0 };
		std::vector<std::vector<std::string>> dic;
		switch (menu.Ask<InputTipe>("How do you want to enter the text?\n1 - Input from file | 0 - Manual input"))
		{
		case InputTipe::MANUAL: {
			inputType = InputTipe::MANUAL;
			//menu.ManualInput(text);
			break;
		}
		case InputTipe::FILE: {
			inputType = InputTipe::FILE;
			std::string path;
			bool isExist{ true };
			do {
				std::cout << "Enter path of input file: " << std::endl;
				getline(std::cin, path);
				std::cout << std::endl;
				try {
					if (!std::filesystem::exists(path)) {
						std::cout << "File don't exist!" << std::endl;
						isExist = false;
					}
					else isExist = true;
				}
				catch (std::exception&) {
					std::cout << "Incorrect path!" << std::endl;
					isExist = false;
				}
			} while (!isExist);
			FileWork::Input(text, path, rows, dic);
			//menu.ConsoleOutput(text);
			break;
		}
		}
		CodingType codType{};
		std::string cryptedText;
		Dictionary dictionary;
		if (static_cast<bool>(menu.Ask<CodingType>("What you want to do?\n1 - Encryp text | 2 - Decrypt text"))) {
			codType = CodingType::ENCRYPT;
			dictionary = Dictionary(text, 100);
			dictionary.Sort();
			dictionary.CodingTables();
		}
		else {
			codType = CodingType::DECRYPT;
			dictionary = Dictionary(text, dic);
			cryptedText = dictionary.Replacement();
		}
		/*if (!static_cast<bool>(inputType) && static_cast<bool>(menu.Ask<Choice>("Do you want to save input data in file?\n1 - Yes | 0 - No") == Choice::YES)) {
			if (codType == CodingType::ENCRYPT) {
				menu.FileSaveWork(text);
			}
		}*/

		if (static_cast<bool>(menu.Ask<Choice>("Do you want to save sorted text in file?\n1 - Yes | 0 - No"))) {
			if (codType == CodingType::ENCRYPT) {
				menu.FileSaveWork(cryptedText, dictionary);
			}
			else {
				menu.FileSaveWork(cryptedText);
			}
		}
	} while (menu.Ask<Choice>("Do you want to repeat programm?\n1 - Yes | 0 - No") == Choice::YES);
}