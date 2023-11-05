#include "Dictionary.h"
#include <string>
#include <algorithm>

Dictionary::Dictionary(std::string text, int rows) {
	_text = text;
	_chains = std::vector< std::vector<std::string>> (rows, std::vector<std::string>(2));
	_row = rows;
	for (int i{ 128 }; i < 192; i++) {
		if (i == 150 || i == 151  || i == 146 || i == 149 || i == 133 || i == 147 || i == 148) continue;
		std::string str{ "." };
		str[0] = static_cast<unsigned char>(i);
		_codingSymbols.push_back(str);
	}
}

Dictionary::Dictionary(std::string text, std::vector<std::vector<std::string>> dictionary) {
	_text = text;
	_dictionary = dictionary;
	_row = static_cast<int>(dictionary.size());
}

void Dictionary::Sort() {
	std::vector<std::string> tempDictionary (_row);
	std::vector<int> tempCount (_row);
	std::string tempText = _text;
	std::string match{""};
	int empryNests{ _row };

	bool isRedundand{ false };
	int index = 0;
	int curentSize{ 0 };
	while (!isRedundand) {
		curentSize = static_cast<int>(tempText.size());
		//заполнение словаря
		for (int i = index; i < tempDictionary.size(); i++) {
			if (tempDictionary[i].empty()) {
				tempDictionary[i] = tempText[0];
				tempCount[i] += 1;
				tempText.erase(0, 1);
				empryNests--;
			}
			while (tempText.find(tempDictionary[i]) != std::string::npos) {
				tempCount[i] += 1;
				tempText.erase(tempText.find(tempDictionary[i]), tempDictionary[i].size());
			}
			if (i != tempDictionary.size() - 1) {
				if (tempDictionary[i + 1].empty()) {
					break;
				}
			}
		}
		// проверка на чистку словаря
		int average{ 0 };
		if (empryNests < 2) {
			std::vector<int> temp = tempCount;
			std::sort(temp.begin(), temp.end());
			if (temp.size() % 2 == 0) {
				average = (temp[temp.size() / 2] + temp[temp.size() / 2 - 1]) / 2;
			}
			else {
				average = temp[temp.size() / 2];
			}
			if (average != 0) {
				for (int i = 0; i < tempDictionary.size(); i++) {
					if (tempCount[i] < average) {
						tempDictionary[i].clear();
						tempCount[i] = 0;
						empryNests++;
					}
				}
			}
		}
		//укрупнение гнезд
		for (int i = 0; i < tempDictionary.size() - 1; i++) {
			if (tempDictionary[i].empty()) { 
				continue; 
			}
			
			for (int j = i + 1; j < tempDictionary.size(); j++) {
				if (tempDictionary[j].empty()) { 
					continue; 
				}
			
				int following{0};
				std::string tempTempText = _text;
				
				while (tempTempText.find(tempDictionary[i] + tempDictionary[j]) != std::string::npos) {
					following++;
					tempTempText.erase(tempTempText.find(tempDictionary[i] + tempDictionary[j]), tempDictionary[i].size() + tempDictionary[j].size());
				}
					
				if (following != 0 && (tempDictionary[i].size() + tempDictionary[j].size()) * following >= _text.size() / 1200) {
					tempDictionary[j] =	tempDictionary[i] + tempDictionary[j];
					tempDictionary[i].clear();
					tempCount[j] = following;
					tempCount[i] = 0;
					empryNests++;
				}
			}
		}
		index++;
		if (index > _row - 1) {
			index = 0;
		}
		if (tempText.size() == curentSize) isRedundand = true;
	}

	for (int i{ 0 }; i < tempDictionary.size(); i++) {
		if (!tempDictionary[i].empty() && tempDictionary[i].size() > 1) {
			_dictionary.push_back({ tempDictionary[i], "" });
		}
	}
}

void Dictionary::CodingTables() {
	int index{ 0 };
	for (int k{ 0 }; k < _dictionary.size(); k++) {
		bool matches{ false };
		for (int i{ index }; i < _codingSymbols.size(); i++) {
			matches = false;
			//for (int j{ 0 }; j < _dictionary.size(); j++) {
				if(!_text.find(_codingSymbols[i])) {
					matches = true;
				}
			//}
			if (!matches) {
				break;
			}
			else {
				index++;
			}
		}
		if (!matches) {
			_dictionary[k][1] = _codingSymbols[index];
			index++;
		}
	}
}

std::string Dictionary::Replacement() {

	std::string text = _text;
	for (int i{ 0 }; i < _dictionary.size(); i++) {
		while (text.find(_dictionary[i][0]) != std::string::npos) {
			text.replace(text.find(_dictionary[i][0]), _dictionary[i][0].size(), _dictionary[i][1]);
			/*rsize_t position{ text.find(_dictionary[i][0]) };
			text.erase(position + 1, _dictionary[i][0].size() - 1);
			text[position] = _dictionary[i][1][0];*/
		}
	}
	return text;
}