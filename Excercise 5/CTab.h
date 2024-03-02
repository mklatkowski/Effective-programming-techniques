#define DEF_TAB_SIZE 10

#include <iostream>
#include<string>


class CTab
{
public:
	CTab() { pi_tab = new int[DEF_TAB_SIZE]; i_size = DEF_TAB_SIZE; }
	CTab(const CTab& cOther);
	CTab(CTab&& cOther);
	CTab operator=(CTab&& cOther) noexcept;
	~CTab();
	bool bSetSize(int iNewSize);
	int iGetSize() { return(i_size); }
private:
	void v_copy(const CTab& cOther);
	int* pi_tab;
	int i_size;
};//class CTab