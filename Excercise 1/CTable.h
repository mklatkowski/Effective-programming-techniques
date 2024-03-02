#include <iostream>
#include<string>


class CTable {
public:
	CTable();
	CTable(std::string sName, int iTableLen);
	CTable(CTable& pcOther);
	~CTable();
	void vSetName(std::string sName);
	bool bSetNewSize(int iTableLen);
	CTable* pcClone();
    std::string toString();

private:
	std::string s_name;
	int i_table_len;
	int* c_Tab;
};