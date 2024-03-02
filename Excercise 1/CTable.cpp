#include "CTable.h";
#include <iostream>;
#include <string>;


CTable::CTable() {
	s_name = "name";
	i_table_len = 0;
	c_Tab = new int[i_table_len];
	std::cout << "bezp: " + s_name << std::endl;
}

CTable::CTable(std::string sName, int iTableLen) {
	s_name = sName;
	i_table_len = iTableLen;
	c_Tab = new int[i_table_len];
	std::cout << "parametr: " + s_name << std::endl;
}

CTable::CTable(CTable& pcOther) {
	s_name = pcOther.s_name + "_copy";
	i_table_len = pcOther.i_table_len;
	c_Tab = new int[i_table_len];
	for (int i = 0; i < i_table_len; i++) {
		c_Tab[i] = pcOther.c_Tab[i];
	}
	std::cout << "Konstruktor kopiuj¹cy: " + s_name << std::endl;
}

CTable::~CTable() {
	delete[] c_Tab;
}

bool CTable::bSetNewSize(int iTableLen) {
	if (iTableLen <= 0)
		return false;
	int* newTable;
	newTable = new int[iTableLen];
	if (iTableLen >= i_table_len) {
		for (int i = 0; i < i_table_len; i++) {
			newTable[i] = c_Tab[i];
		}
	}
	else {
		for (int i = 0; i < iTableLen; i++) {
			newTable[i] = c_Tab[i];
		}
	}
	i_table_len = iTableLen;
	delete[] c_Tab;
	c_Tab = newTable;
	return true;
}

CTable* CTable::pcClone() {
	return new CTable(*this);
}

std::string CTable::toString() {
	return "Nazwa: " + s_name + ", rozmiar: " + std::to_string(i_table_len);
}


void CTable::vSetName(std::string sName) {
	s_name = sName;
}


