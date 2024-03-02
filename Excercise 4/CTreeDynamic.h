#include <iostream>
#include<string>
#include<vector>

using namespace std;


template<typename T> class CNodeDynamic
{
public:
	CNodeDynamic();
	~CNodeDynamic();
	void vSetValue(T iNewVal);
	int iGetChildrenNumber();
	void vAddNewChild();
	void vAddNewChild(CNodeDynamic<T>* pcNewChild);
	CNodeDynamic<T>* pcGetChild(int iChildOffset);
	CNodeDynamic<T>* pcGetParent();
	void vPrint();
	void vPrintAllBelow();
	bool remove(CNodeDynamic<T>* pcChildToRemove);
	void setParent(CNodeDynamic<T>* newParent);
	void vPrintUp();

private:
	vector<CNodeDynamic<T>*> v_children;
	CNodeDynamic<T>* pc_parent_node;
	T i_val;
};

template<typename T> class CTreeDynamic
{
public:
	CTreeDynamic();
	~CTreeDynamic();
	CNodeDynamic<T>* pcGetRoot();
	void vPrintTree();
	void vSetRoot(CNodeDynamic<T> &pc_new_root);
	bool bMoveSubtree(CNodeDynamic<T>* pcParentNode, CNodeDynamic<T>* pcNewChildNode);
private:
	CNodeDynamic<T>* pc_root;
};



template<typename T>
CTreeDynamic<T>::CTreeDynamic() {
	pc_root = new CNodeDynamic<T>;
}

template<typename T>
void CNodeDynamic<T>::setParent(CNodeDynamic<T>* newParent) {
	//delete pc_parent_node;
	pc_parent_node = newParent;
}

template<typename T>
CTreeDynamic<T>::~CTreeDynamic() {
	delete pc_root;
}

template<typename T>
CNodeDynamic<T>* CTreeDynamic<T>::pcGetRoot() {
	return pc_root;
}

template<typename T>
void CTreeDynamic<T>::vSetRoot(CNodeDynamic<T>& pc_new_root) {
	*pc_root = pc_new_root;
}

template<typename T>
bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic<T>* pcParentNode, CNodeDynamic<T>* pcNewChildNode) {
	if (pcNewChildNode == NULL) return false;
	if (pcNewChildNode->pcGetParent() != NULL) pcNewChildNode->pcGetParent()->remove(pcNewChildNode);
	pcNewChildNode->setParent(pcParentNode);
	if (pcParentNode != NULL) pcParentNode->vAddNewChild(pcNewChildNode);
	return true;
}

template<typename T>
void CTreeDynamic<T>::vPrintTree() {
	pc_root->vPrintAllBelow();
}


template<typename T>
CNodeDynamic<T>::CNodeDynamic()
{
	i_val = T();
	pc_parent_node = NULL;
}

template<typename T>
CNodeDynamic<T>::~CNodeDynamic() {
	for (int i = 0; i < v_children.size(); i++) {
		delete v_children.at(i);
	}
	v_children.clear();
}

template<typename T>
void CNodeDynamic<T>::vSetValue(T iNewVal) {
	i_val = iNewVal;
}

template<typename T>
int CNodeDynamic<T>::iGetChildrenNumber() {
	return(v_children.size());
}

template<typename T>
void CNodeDynamic<T>::vAddNewChild() {
	CNodeDynamic* c_toAdd = new CNodeDynamic;

	c_toAdd->pc_parent_node = this;
	v_children.push_back(c_toAdd);
}

template<typename T>
void CNodeDynamic<T>::vAddNewChild(CNodeDynamic<T>* pcNewChild) {
	v_children.push_back(pcNewChild);
}

template<typename T>
CNodeDynamic<T>* CNodeDynamic<T>::pcGetChild(int iChildOffset) {
	if (iChildOffset < 0 || iChildOffset >= iGetChildrenNumber()) {
		return NULL;
	}
	return v_children.at(iChildOffset);
}

template<typename T>
CNodeDynamic<T>* CNodeDynamic<T>::pcGetParent() {
	return pc_parent_node;
}

template<typename T>
void CNodeDynamic<T>::vPrint() {
	cout << " " << i_val << endl;
}

template<typename T>
void CNodeDynamic<T>::vPrintAllBelow() {
	vPrint();
	for (int i = 0; i < v_children.size(); i++) {
		v_children.at(i)->vPrintAllBelow();
	}
}

template<typename T>
void CNodeDynamic<T>::vPrintUp() {
	vPrint();
	if (pc_parent_node != NULL) {
		pc_parent_node->vPrintUp();
	}
}

template<typename T>
bool CNodeDynamic<T>::remove(CNodeDynamic<T>* pcChildToRemove) {
	for (int i = 0; i < iGetChildrenNumber(); i++) {
		if (v_children.at(i) == pcChildToRemove) {
			v_children.erase(v_children.begin() + i);
			return true;
		}
	}
	return false;
}