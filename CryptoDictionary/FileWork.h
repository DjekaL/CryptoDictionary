#pragma once
#include "Menu.h"
#include <filesystem>
#include <fstream>
#include <string>
#include <Windows.h>

class FileWork {

public:
	FileWork(std::string path);
	void FileCheck();
	static void Input(std::string& text, std::string path, int rows, std::vector<std::vector<std::string>>& dictionary);
	void Save(std::string data, Dictionary dic);
	void Rename(std::string path);

private:
	std::string _path;
	bool NameCheck();
	bool ReadOnlyCheck();
};