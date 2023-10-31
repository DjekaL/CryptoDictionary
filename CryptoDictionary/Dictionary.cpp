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
	_row = dictionary.size();
}

void Dictionary::Sort() {
	std::vector<std::string> tempDictionary (_row);
	std::vector<int> tempCount (_row);
	int chainsCount{ 0 };
	std::string tempText = _text;
	std::string match{""};
	int empryNests{ _row };

	bool isRedundand{ false };
	int index = 0;
	int curentSize{ 0 };
	while (!isRedundand) {
		curentSize = tempText.size();
		//заполнение словаря
		for (int i = index; i < tempDictionary.size(); i++) {
			if (tempDictionary[i].empty()) {
				tempDictionary[i] = tempText[0];
				tempCount[i] += 1;
				tempText.erase(0, 1);
				empryNests--;
				//break;
			}
			/*for (auto symbol : tempText) {
				std::string s{ symbol };*/
				//for (auto symbol : tempText) {
				//	if (rsize_t length = tempText.find(tempDictionary[i]) != std::string::npos) {
				//		tempCount[i] += 1;
				//		//tempText.erase(std::find(tempText.begin(), tempText.end(), symbol));
				//		//tempText.erase(length, tempDictionary[i].size());
				//		tempText.erase(tempText.find(tempDictionary[i]), tempDictionary[i].size());
				//		//break;
				//	}
				//}
			while (tempText.find(tempDictionary[i]) != std::string::npos) {
				tempCount[i] += 1;
				tempText.erase(tempText.find(tempDictionary[i]), tempDictionary[i].size());
			}
			if (i != tempDictionary.size() - 1) {
				if (tempDictionary[i + 1].empty()) {
					break;
				}
			}
			
				/*if (s == tempDictionary[i]) {
					tempCount[i] += 1;
					tempText.erase(std::find(tempText.begin(), tempText.end(), symbol));
					break;
				}*/
			//}
		}
		// проверка на чистку словаря
		int average{ 0 };
		/*if (empryNests < 2) {
			for (int i = 0; i < tempDictionary.size(); i++) {
				average += tempCount[i];
			}
		}
		average /= tempDictionary.size();*/
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
			
			/*if (_row / empryNests >= static_cast<double>(tempCount[i])) {
				continue;
			}*/
			for (int j = i + 1; j < tempDictionary.size(); j++) {
					if (tempDictionary[j].empty()) { 
						continue; 
					}
				/*if (_row / empryNests >= static_cast<double>(tempCount[j])) {
					continue;
				}*/
				//for (int k = 0; k < _text.length(); k++) {
				//	std::string firstItem{ _text[k] };
				//	std::string secondItem{ _text[k + 1] };
				//	if (firstItem == tempDictionary[i] && secondItem == tempDictionary[j]) following++;
				//	//else following--;
				//}
				//for (int l = 1; l < tempDictionary.size(); l++) {
					int following{0};
					std::string tempTempText = _text;
					rsize_t length = 0;
					//do {
					//	length = tempTempText.find(tempDictionary[i]);

					//	rsize_t nextLength = 0;
					//		//while (nextLength <= length) {
					//		//	nextLength = tempTempText.find(tempDictionary[j]);
					//		//	if (length == std::string::npos || nextLength == std::string::npos) {
					//		//		break;
					//		//	}
					//		//
					//		//	if(nextLength <= length) tempTempText.erase(tempTempText.find(tempDictionary[j]), tempDictionary[j].size());
					//		//	//if (nextLength != std::string::npos && nextLength == length + 1 && length != std::string::npos) {
					//		//	if (tempTempText.find(tempDictionary[i] + tempDictionary[j]) != std::string::npos ) {
					//		//		following++;
					//		//	}
					//		//}
					while (tempTempText.find(tempDictionary[i] + tempDictionary[j]) != std::string::npos) {
						following++;
						tempTempText.erase(tempTempText.find(tempDictionary[i] + tempDictionary[j]), tempDictionary[i].size() + tempDictionary[j].size());
					}
					//	}
					//	/*if (!tempTempText.find(tempDictionary[i]), tempDictionary[i].size() ||
					//		!tempTempText.find(tempDictionary[j]), tempDictionary[j].size()) {
					//		break;
					//	}*/
					//	/*tempTempText.erase(tempTempText.find(tempDictionary[i]), tempDictionary[i].size());
					//	tempTempText.erase(tempTempText.find(tempDictionary[j]), tempDictionary[j].size());*/
					//	try
					//	{
					//		tempTempText.erase(tempTempText.find(tempDictionary[i]), tempDictionary[i].size());
					//		tempTempText.erase(tempTempText.find(tempDictionary[j]), tempDictionary[j].size());
					//	}
					//	catch (const std::exception&)
					//	{
					//		break;
					//	}

					//} while (length != std::string::npos);

					//average = (tempCount[i] + tempCount[j]) / 2;
					//if (average < following) {
					//if ((following >= tempCount[i] / 30 || following >= tempCount[j] / 30) && following != 0) {
					if (following != 0 && (tempDictionary[i].size() + tempDictionary[j].size()) * following >= _text.size() / 1200) {
						//if (average < tempCount[i] || average < tempCount[j]) {
						tempDictionary[j] =	tempDictionary[i] + tempDictionary[j];
						tempDictionary[i].clear();
						tempCount[j] = following;
						//tempCount[i] = following*32;
						tempCount[i] = 0;
						empryNests++;
					}
				//}
				//average = following / 2;
				//average = (tempCount[i] + tempCount[j]) / 2;
				//if (average > following){
				////if (average < tempCount[i] || average < tempCount[j]) {
				//	tempDictionary[i] += tempDictionary[j];
				//	tempDictionary[j].clear();
				//	tempCount[i] = (tempCount[i] + tempCount[j]) / 2;
				//	tempCount[j] = 0;
				//	empryNests++;
				//}
			}
		}
		index++;
		if (index > _row - 1) {
			index = 0;
		}
		if (tempText.size() == curentSize) isRedundand = true;
	}
	int ab{ 0 };

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
		size_t ds = text.find(_dictionary[i][0]);
		while (text.find(_dictionary[i][0]) != std::string::npos) {
			text.replace(text.find(_dictionary[i][0]), _dictionary[i][0].size(), _dictionary[i][1]);
			/*rsize_t position{ text.find(_dictionary[i][0]) };
			text.erase(position + 1, _dictionary[i][0].size() - 1);
			text[position] = _dictionary[i][1][0];*/
		}
	}
	return text;
}