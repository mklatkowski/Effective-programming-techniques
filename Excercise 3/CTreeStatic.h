#include <iostream>
#include<string>
#include<vector>

#include"CNodeStatic.h"


using namespace std;

class CTreeStatic
{
public:
	CTreeStatic();
	~CTreeStatic();
	CNodeStatic* pcGetRoot();
	void vPrintTree();
	bool bMoveSubtree(CNodeStatic* pcParentNode, CNodeStatic* pcNewChildNode);
	void modPrint(bool flag, int val);
private:
	CNodeStatic c_root;
};