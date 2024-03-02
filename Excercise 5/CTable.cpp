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


CTable::CTable(CTable&& pcOther) {
	s_name = pcOther.s_name + "_move";
	i_table_len = pcOther.i_table_len;
	c_Tab = new int[i_table_len];
	for (int i = 0; i < i_table_len; i++) {
		c_Tab[i] = pcOther.c_Tab[i];
	}
	delete[] pcOther.c_Tab;
	std::cout << ("MOVE " + s_name) << std::endl;
}


//CTable::~CTable() {
	//delete[] c_Tab;
//}
CTable::CTable(CTable& pcOther) {
	s_name = pcOther.s_name + "_copy";
	i_table_len = pcOther.i_table_len;
	c_Tab = new int[i_table_len];
	for (int i = 0; i < i_table_len; i++) {
		c_Tab[i] = pcOther.c_Tab[i];
	}
	std::cout << "Konstruktor kopiujacy: " + s_name << std::endl;
}

void CTable::vSetValueAt(int iOffset, int iNewValue) {
	if (iOffset<0 || iOffset>i_table_len - 1) {
		std::cout << "Z³y offset" << std::endl;
	}
	else {
		c_Tab[iOffset] = iNewValue;
	}
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

CTable CTable::operator+(const CTable& pcOther) {
	int* newTable;
	newTable = new int[i_table_len+pcOther.i_table_len];

	for (int ii = 0; ii < i_table_len; ii++) {
		newTable[ii] = c_Tab[ii];
	}
	for (int ii = 0; ii < pcOther.i_table_len; ii++) {
		newTable[i_table_len + ii] = pcOther.c_Tab[ii];
	}

	CTable c_returnValue("append", i_table_len + pcOther.i_table_len);
	delete[] c_returnValue.c_Tab;
	c_returnValue.c_Tab = newTable;

	return std::move(c_returnValue);
}

void CTable::operator=(const CTable& pcOther)
{
	c_Tab = pcOther.c_Tab;
	i_table_len = pcOther.i_table_len;
}

CTable CTable::operator=(CTable&& pcOther) {
	std::cout << "= semantics" << std::endl;
	if (c_Tab != pcOther.c_Tab) {
		delete c_Tab;
		c_Tab = pcOther.c_Tab;
		i_table_len = pcOther.i_table_len;
		pcOther.c_Tab = nullptr;
	}
	return *this;
}

void CTable::vPrint() {
	std::cout << "Tablica obiektu: " + s_name << std::endl;
	for (int ii = 0; ii < i_table_len; ii++) {
		std::cout << c_Tab[ii] << std::endl;
	}
}