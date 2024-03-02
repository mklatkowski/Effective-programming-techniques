#include <iostream>
#include<string>
#include "CTab.h"



bool CTab::bSetSize(int iTableLen) {
	if (iTableLen <= 0)
		return false;
	int* newTable;
	newTable = new int[iTableLen];
	if (iTableLen >= i_size) {
		for (int i = 0; i < i_size; i++) {
			newTable[i] = pi_tab[i];
		}
	}
	else {
		for (int i = 0; i < iTableLen; i++) {
			newTable[i] = pi_tab[i];
		}
	}
	i_size = iTableLen;
	delete[] pi_tab;
	pi_tab = newTable;
	return true;
}

CTab::CTab(const CTab& cOther)
{
	v_copy(cOther);
	std::cout << "Copy ";
}//CTab::CTab(const CTab &cOther)
CTab::~CTab()
{
	if (pi_tab != NULL) delete pi_tab;
	std::cout << "Destr ";
}//CTab::~CTab()


CTab CTab::operator=(CTab&& cOther) noexcept{
	if (pi_tab != cOther.pi_tab) {
		delete pi_tab;
	}
	pi_tab = cOther.pi_tab;
	i_size = cOther.i_size;
	cOther.pi_tab = NULL;

	std::cout << "student debilem jest " << std::endl;

	return (*this);
}



void CTab::v_copy(const CTab& cOther)
{
	pi_tab = new int[cOther.i_size];
	i_size = cOther.i_size;
	for (int ii = 0; ii < cOther.i_size; ii++)
		pi_tab[ii] = cOther.pi_tab[ii];
}//void CTab::v_copy(CTab &cOther)

CTab::CTab(CTab&& cOther)
{
	pi_tab = cOther.pi_tab;
	i_size = cOther.i_size;
	cOther.pi_tab = NULL;
	std::cout << "MOVE ";
}//CTab::CTab(CTab &&cOther)

CTab cCreateTab()
{
	CTab c_result;
	c_result.bSetSize(5);
	return(std::move(c_result));
}//CTab cCreateTab(
