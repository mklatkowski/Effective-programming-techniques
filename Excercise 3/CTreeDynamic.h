#include <iostream>
#include<string>
#include<vector>

using namespace std;

class CNodeDynamic;
class CTreeDynamic;

class CTreeDynamic
{
public:
	CTreeDynamic();
	~CTreeDynamic();
	CNodeDynamic* pcGetRoot();
	void vPrintTree();
	void vSetRoot(CNodeDynamic &pc_new_root);
	bool bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode);
private:
	CNodeDynamic* pc_root;
};

class CNodeDynamic
{
public:
	CNodeDynamic();
	~CNodeDynamic();
	void vSetValue(int iNewVal);
	int iGetChildrenNumber();
	void vAddNewChild();
	void vAddNewChild(CNodeDynamic *pcNewChild);
	CNodeDynamic* pcGetChild(int iChildOffset);
	CNodeDynamic* pcGetParent();
	void vPrint();
	void vPrintAllBelow();
	bool remove(CNodeDynamic* pcChildToRemove);
	void setParent(CNodeDynamic* newParent);
	void vPrintUp();
	void modPrint(bool flag, CNodeDynamic* node);
private:
	vector<CNodeDynamic*> v_children;
	CNodeDynamic* pc_parent_node;
	int i_val;
};