#include <iostream>
#include<string>


class CTable {
public:
	CTable();
	CTable(std::string sName, int iTableLen);
	CTable(CTable& pcOther);
	CTable(CTable&& pcOther);
	void vSetName(std::string sName);
	bool bSetNewSize(int iTableLen);
	CTable* pcClone();
	//~CTable();
    std::string toString();
	void operator=(const CTable& pcOther);
	CTable operator=(CTable&& pcOther);
	void vSetValueAt(int iOffset, int iNewValue);
	CTable operator+(const CTable& pcOther);
	void vPrint();
private:
	std::string s_name;
	int i_table_len;
	int* c_Tab;
};