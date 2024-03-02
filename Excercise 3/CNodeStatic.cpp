#include <iostream>
#include<string>
#include<vector>
#include"CNodeStatic.h"

using namespace std;

CNodeStatic::CNodeStatic()
{
	i_val = 0;
	pc_parent_node = NULL;
}

CNodeStatic::~CNodeStatic() {
}

void CNodeStatic::vSetValue(int iNewVal) {
	i_val = iNewVal;
}

int CNodeStatic::iGetChildrenNumber() {
	return v_children.size();
}

void CNodeStatic::vAddNewChild() {
	CNodeStatic c_toAdd;
	c_toAdd.pc_parent_node = this;
	v_children.push_back(c_toAdd);
}

void CNodeStatic::vAddNewChild(CNodeStatic newChild) {
	v_children.push_back(newChild);
	newChild.pc_parent_node = this;
	repairParents(newChild.pc_parent_node);
}

void CNodeStatic::repairParents(CNodeStatic* parent) {
	for (int i = 0; i < (*parent).v_children.size(); i++) {
		v_children.at(i).pc_parent_node = parent;
		v_children.at(i).repairParents(&v_children.at(i));
	}
}

void CNodeStatic::setParent(CNodeStatic* newParent) {
	pc_parent_node = newParent;
}

CNodeStatic* CNodeStatic::pcGetParent() {
	return pc_parent_node;
}

CNodeStatic* CNodeStatic::pcGetChild(int iChildOffset) {
	if (iChildOffset < 0 || iChildOffset >= v_children.size()) {
		return NULL;
	}
	return &v_children.at(iChildOffset);
}

void CNodeStatic::vPrint() {
	cout << " " << i_val;
}

void CNodeStatic::remove(CNodeStatic* node) {
	for (int i = 0; i < v_children.size(); i++) {
		if (node == &v_children.at(i)) v_children.erase(v_children.begin() + i);
	}
}

void CNodeStatic::vPrintAllBelow() {
	vPrint();
	for (int i = 0; i < v_children.size(); i++) {
		v_children.at(i).vPrintAllBelow();
	}
}

void CNodeStatic::vPrintUp() {
	vPrint();
	if (pc_parent_node != NULL) {
		pc_parent_node->vPrintUp();
	}
}


CNodeStatic* CNodeStatic::findNode(int i) {
	if (i_val==i) {
		return this;
	}
	for (int j = 0; j < v_children.size(); j++) {
		CNodeStatic* node = v_children.at(j).findNode(i);
		if (node != NULL) {
			return node;
		}
	}
	return nullptr;
}



