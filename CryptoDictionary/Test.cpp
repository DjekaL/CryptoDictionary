//#include "Test.h"
//
//Tests::Tests() {
//	_testingData.push_back("Prover menya");
//	_testingData.push_back("abobA aga ");
//	_testingData.push_back("Ya yje hz");
//	_testingData.push_back("dA skol'ko blin eje mojno");
//	_testingData.push_back("LADno tak yj и быть \n последний и все");
//
//	_answers.push_back("oePrvr eyamn");
//	_answers.push_back("aoAbb aag ");
//	_answers.push_back("Ya yej hz");
//	_answers.push_back("Ad ooskl'k ibln eej oomjn");
//	_answers.push_back("AoLDn atk yj и ыбть \n оеипслднй и евс");
//}
//
//void Tests::MakeTest(void) {
//	int testQuantity{ 5 };
//	int isChecked{ 0 };
////Sort sort;
//	for (int i = 0; i < 5; i++) {
//		std::vector<std::string> data{ _testingData[i] };
//		//auto answer = sort.Sorting(data);
//		if (answer[0] == _answers[i]) isChecked++;
//		else {
//			std::cout << "Test " << i + 1 << " failed!" << std::endl;
//			std::cout << "Initial data: " << _testingData[i] << std::endl;
//			std::cout << "Expected resualt: " << _answers[i] << std::endl;
//			std::cout << "Obtained resualt: " << answer[0] << std::endl << std::endl;
//		}
//	}
//	if (isChecked == testQuantity) std::cout << "Tests passed!" << std::endl << std::endl;
//}
//
//Tests::~Tests() {}