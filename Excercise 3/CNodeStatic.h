#include <iostream>
#include<string>
#include<vector>


using namespace std;

class CNodeStatic
{
public:
	CNodeStatic();
	~CNodeStatic();
	void vSetValue(int iNewVal);
	int iGetChildrenNumber();
	void vAddNewChild();
	CNodeStatic* pcGetChild(int iChildOffset);
	CNodeStatic* pcGetParent();
	void vPrint();
	void vPrintAllBelow();
	void vPrintUp();
	void vAddNewChild(CNodeStatic c_toAdd);
	void remove(CNodeStatic* pcChildToRemove);
	void setParent(CNodeStatic* newParent);
	void repairParents(CNodeStatic* parent);
	CNodeStatic* findNode(int i);
private:
	vector<CNodeStatic> v_children;
	CNodeStatic* pc_parent_node;
	int i_val;
};

