#pragma once
#include <iostream>
#include <vector>

class Dictionary {

public:

	Dictionary(){}
	Dictionary(std::string text, int rows);
	Dictionary(std::string text, std::vector<std::vector<std::string>> dictionary);

	//~Dictionary();

	void Sort();
	
	void CodingTables();

	std::string Replacement();

	std::vector<std::vector<std::string>> _dictionary;

	int _row{ 0 };

private:


	std::string _text;

	std::vector<std::vector<std::string>> _chains;

	std::vector<std::string> _codingSymbols;


};