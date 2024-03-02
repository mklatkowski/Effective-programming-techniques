#include <iostream>
#include<string>
#include<vector>

#include"CTreeStatic.h"
#include"CTreeDynamic.h"

void v_tree_test()
{
	CNodeStatic c_root;
	c_root.vAddNewChild();
	c_root.vAddNewChild();
	c_root.pcGetChild(0)->vSetValue(1);
	c_root.pcGetChild(1)->vSetValue(2);
	c_root.pcGetChild(0)->vAddNewChild();
	c_root.pcGetChild(0)->vAddNewChild();
	c_root.pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_root.pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	c_root.pcGetChild(1)->vAddNewChild();
	c_root.pcGetChild(1)->vAddNewChild();
	c_root.pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_root.pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	c_root.pcGetChild(0)->pcGetChild(1)->vPrintUp();
}//void v_tree_test()

void v_tree_test_2() {

	CTreeStatic c_tree;
	c_tree.pcGetRoot()->vAddNewChild();
	c_tree.pcGetRoot()->vAddNewChild();

	c_tree.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	c_tree.pcGetRoot()->pcGetChild(1)->vSetValue(2);
	c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	//c_tree.vPrintTree();


	c_tree.vPrintTree();
	cout << endl;

	c_tree.modPrint(true, 2);

	cout << endl;
	cout << endl;
	cout << endl;

	cout << endl;
	//c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vPrintUp();
}

void v_tree_test3()
{

	CTreeDynamic dynamicTree;

	dynamicTree.pcGetRoot()->vAddNewChild();
	dynamicTree.pcGetRoot()->vAddNewChild();
	dynamicTree.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	dynamicTree.pcGetRoot()->pcGetChild(1)->vSetValue(2);
	dynamicTree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	dynamicTree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	dynamicTree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(21);


	//dynamicTree.vPrintTree();

	//cout << endl;
	//c_root.vPrintAllBelow();
	//c_root.pcGetChild(1)->pcGetChild(0)->pcGetParent()->vPrint();

}


void v_tree_test_dynamic() {

	CTreeDynamic cTreeDynamic;
	cTreeDynamic.pcGetRoot()->vAddNewChild();
	cTreeDynamic.pcGetRoot()->vAddNewChild();
	cTreeDynamic.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	cTreeDynamic.pcGetRoot()->pcGetChild(1)->vSetValue(2);
	cTreeDynamic.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	cTreeDynamic.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	cTreeDynamic.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	cTreeDynamic.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	cTreeDynamic.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	cTreeDynamic.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	cTreeDynamic.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	cTreeDynamic.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);


	cTreeDynamic.vPrintTree();
	cout << endl;

	cout << "Print up:" << endl;

	//cTreeDynamic2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vPrintUp();
	cout << endl;

	//cTreeDynamic.bMoveSubtree(cTreeDynamic.pcGetRoot(), cTreeDynamic2.pcGetRoot()->pcGetChild(1));

	cTreeDynamic.vPrintTree();
	cout << endl;
	//cTreeDynamic2.vPrintTree();
	//cTreeDynamic.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vPrintUp();
}

int main() {
	//v_tree_test();
	v_tree_test_2();
	//v_tree_test_dynamic();
	return 0;
}