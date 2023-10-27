#include "FileWork.h"

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Menu menu;

	menu.Start();

	if (menu.ModularTest() == Choice::YES) {
		/*Tests tests;
		tests.MakeTest();*/
	}

	do
	{
		InputTipe inputType{};

		std::string text;
		int rows{ 0 };
		std::vector<std::vector<std::string>> dic;

		switch (menu.InputAsk())
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
			std::cout << "Received text from file:" << std::endl;
			//menu.ConsoleOutput(text);
			break;
		}
		}
		std::cout << "Че с текстом делать?(только из предложенных вводить)" << std::endl;
		std::cout << "1 - закодировать | 2 - раскодировать" << std::endl;
		int ch = Menu::GetInput<int>();
		std::string cryptedText;
		Dictionary dictionary;
		if (ch == 1) {
			dictionary = Dictionary(text, 100);
			dictionary.Sort();
			dictionary.CodingTables();


			cryptedText = dictionary.Replacement();
		}
		else {
			dictionary = Dictionary(text, dic);
			cryptedText = dictionary.Replacement();
		}

		/*std::vector<std::string> sortedText;

		Sort sort;
		sortedText = sort.Sorting(text);
		std::cout << "Sorted text:" << std::endl;
		menu.ConsoleOutput(sortedText);*/

		if (!static_cast<bool>(inputType) && static_cast<bool>(menu.SaveInputAsk())) {
			//menu.FileSaveWork(text);
		}

		if (static_cast<bool>(menu.OutputFileAsk())) {
			menu.FileSaveWork(cryptedText, dictionary);
		}

	} while (menu.RepeatAsk() == Choice::YES);
}