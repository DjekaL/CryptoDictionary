#include "FileWork.h"

FileWork::FileWork(std::string path) {
	this->_path = path;
}

void FileWork::Input(std::string& text, std::string path, int rows, std::vector<std::vector<std::string>>& dictionary) {
	//std::ifstream file;
	std::ifstream file;
	file.open(path);
	std::string line;

	std::string token;
	std::string delimiter{ ":" };
	getline(file, line);
	size_t pos;
	if (line.find("Dictonary size") != std::string::npos) {
		while ((pos = line.find(delimiter)) != std::string::npos) {
			token = line.substr(0, pos);
			line.erase(0, pos + delimiter.length());
		}
		rows = stoi(line);
		delimiter = "=>";
		for (int i{ 0 }; i < rows; i++) {
			getline(file, line);
			while ((pos = line.find(delimiter)) != std::string::npos) {
				std::string str = line.substr(0, pos);
				if (str.find("/n") != std::string::npos) {
					str.replace(str.find("/n"), 2, "\n");
				}
				dictionary.push_back({"", str});
				line.erase(0, pos + delimiter.length());
				dictionary[i][0] = line;
			}
		}
	}
	else {
		text += line + "\n";
	}
	while (getline(file, line)) {
		text += line + "\n";
	}
	file.close();
}

void FileWork::Save(std::string data, Dictionary dic = Dictionary()) {
	std::ofstream file;
	file.open(_path);
	if (!dic._dictionary.empty()) {
		file << "Dictonary size : ";
		file << dic._dictionary.size() << std::endl;
			for (int i{ 0 }; i < dic._dictionary.size(); i++) {
				size_t pos{ 0 };
				if ((pos = dic._dictionary[i][0].find("\n")) != std::string::npos) {
					dic._dictionary[i][0].replace(dic._dictionary[i][0].find("\n"), 1, "/n");/*
					dic._dictionary[i][0].erase(pos, pos + 2);
					dic._dictionary[i][0] += "/n";*/
				}
				file << dic._dictionary[i][0] << "=>" << dic._dictionary[i][1] << std::endl;
			}
	}
	file << data;
	file.close();
	std::cout << "Data is saved!" << std::endl << std::endl;
}

void FileWork::FileCheck() {
	while (!this->NameCheck()) {
		std::cout << "Incorrect path!" << std::endl;
		std::cout << "Enter mew path." << std::endl;
		getline(std::cin, _path);
	}
	if (!std::filesystem::exists(_path)) return;
	if (this->ReadOnlyCheck()) {
		std::cout << "The file is read-only!" << std::endl << "Enter new path" << std::endl;
		getline(std::cin, _path);
		this->FileCheck();
	}
	else {
		if (Menu::Ask<Choice>("Do you want to rewrite file?\n1 - Yes | 0 - No") == Choice::NO) {
			std::cout << "Enter mew path." << std::endl;
			getline(std::cin, _path);
			this->FileCheck();
		}
	}
}

bool FileWork::NameCheck() {
	try {
		auto name = std::filesystem::is_regular_file(_path);
		name = false;
	}
	catch (std::exception&) {
		return false;
	}
	return true;
}

bool FileWork::ReadOnlyCheck() {
	return GetFileAttributesW(std::wstring(_path.begin(), _path.end()).c_str()) & FILE_ATTRIBUTE_READONLY;
}