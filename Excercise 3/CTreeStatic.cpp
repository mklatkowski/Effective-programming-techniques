#include <iostream>
#include<string>
#include<vector>
#include"CTreeStatic.h"


using namespace std;


CTreeStatic::CTreeStatic() {
	CNodeStatic c_root_temp;
	c_root = c_root_temp;
}

CTreeStatic::~CTreeStatic() {
}

CNodeStatic* CTreeStatic::pcGetRoot() {
	return(&c_root);
}

void CTreeStatic::vPrintTree() {
	c_root.vPrintAllBelow();
}

bool CTreeStatic::bMoveSubtree(CNodeStatic* pcParentNode, CNodeStatic* pcNewChildNode) {


	if (pcParentNode == NULL || pcNewChildNode == NULL) {
		return false;
	}

	if (pcNewChildNode->pcGetParent() != NULL) {
		pcNewChildNode->pcGetParent()->remove(pcNewChildNode);
	}
	pcParentNode->vAddNewChild(*pcNewChildNode);
	return true;
}

void CTreeStatic::modPrint(bool flag, int nr) {
	if (flag) {
		c_root.findNode(nr)->vPrintUp();
	}
	else {
		c_root.findNode(nr)->vPrintAllBelow();
	}
}