#pragma once
#include "FileWork.h"

class Tests {

public:

	void MakeTest(void);

private:
	std::vector<std::string> _testingData;
	std::vector<std::string> _answers;
};