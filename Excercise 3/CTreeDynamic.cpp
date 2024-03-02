#include <iostream>
#include<string>
#include<vector>

#include"CTreeDynamic.h"

using namespace std;

class CNodeDynamic;

CTreeDynamic::CTreeDynamic() {
	pc_root = new CNodeDynamic;
}

void CNodeDynamic::setParent(CNodeDynamic* newParent) {
	//delete pc_parent_node;
	pc_parent_node = newParent;
}

CTreeDynamic::~CTreeDynamic() {
	delete pc_root;
}

CNodeDynamic* CTreeDynamic::pcGetRoot() {
	return pc_root;
}

void CTreeDynamic::vSetRoot(CNodeDynamic& pc_new_root) {
	*pc_root = pc_new_root;
}


bool CTreeDynamic::bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode) {
	if (pcNewChildNode == NULL) return false;
	if (pcNewChildNode->pcGetParent() != NULL) pcNewChildNode->pcGetParent()->remove(pcNewChildNode);
	pcNewChildNode->setParent(pcParentNode);
	if (pcParentNode != NULL) pcParentNode->vAddNewChild(pcNewChildNode);
	return true;
}


void CTreeDynamic::vPrintTree() {
	pc_root->vPrintAllBelow();
}



CNodeDynamic::CNodeDynamic()
{
	i_val = 0;
	pc_parent_node = NULL;
}

CNodeDynamic::~CNodeDynamic() {
	for (int i = 0; i < v_children.size(); i++) {
		delete v_children.at(i);
	}
	v_children.clear();
}

void CNodeDynamic::vSetValue(int iNewVal) {
	i_val = iNewVal;
}

int CNodeDynamic::iGetChildrenNumber() {
	return(v_children.size());
}

void CNodeDynamic::vAddNewChild() {
	CNodeDynamic* c_toAdd = new CNodeDynamic;

	c_toAdd->pc_parent_node = this;
	v_children.push_back(c_toAdd);
}

void CNodeDynamic::vAddNewChild(CNodeDynamic *pcNewChild) {
	v_children.push_back(pcNewChild);
}

CNodeDynamic* CNodeDynamic::pcGetChild(int iChildOffset) {
	if (iChildOffset < 0 || iChildOffset >= iGetChildrenNumber()) {
		return NULL;
	}
	return v_children.at(iChildOffset);
}

CNodeDynamic* CNodeDynamic::pcGetParent() {
	return pc_parent_node;
}

void CNodeDynamic::vPrint() {
	cout << " " << i_val << endl;
}

void CNodeDynamic::vPrintAllBelow() {
	vPrint();
	for (int i = 0; i < v_children.size(); i++) {
		v_children.at(i)->vPrintAllBelow();
	}
}

void CNodeDynamic::vPrintUp() {
	vPrint();
	if (pc_parent_node != NULL) {
		pc_parent_node->vPrintUp();
	}
}

bool CNodeDynamic::remove(CNodeDynamic* pcChildToRemove) {
	for (int i = 0; i < iGetChildrenNumber(); i++) {
		if (v_children.at(i) == pcChildToRemove) {
			v_children.erase(v_children.begin() + i);
			return true;
		}
	}
	return false;
}

