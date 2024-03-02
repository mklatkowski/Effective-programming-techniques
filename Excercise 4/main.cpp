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



void v_tree_test_dynamic_int() {

	CTreeDynamic<int> cTreeDynamic;
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
	cTreeDynamic.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vPrintUp();
	cout << "Koniec print up" << endl;
	cout << endl;
}

void v_tree_test_dynamic_string() {

	CTreeDynamic<string> cTreeDynamic;
	cTreeDynamic.pcGetRoot()->vAddNewChild();
	cTreeDynamic.pcGetRoot()->vAddNewChild();
	cTreeDynamic.pcGetRoot()->pcGetChild(0)->vSetValue("jeden");
	cTreeDynamic.pcGetRoot()->pcGetChild(1)->vSetValue("dwa");
	cTreeDynamic.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	cTreeDynamic.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	cTreeDynamic.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue("jedenascie");
	cTreeDynamic.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue("dwanascie");
	cTreeDynamic.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	cTreeDynamic.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	cTreeDynamic.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue("dwadziescia jeden");
	cTreeDynamic.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue("dwadziescia dwa");


	cTreeDynamic.vPrintTree();
	cout << endl;

	cout << "Print up:" << endl;
	cTreeDynamic.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vPrintUp();
	cout << "Koniec print up" << endl;
	cout << endl;
}

void v_tree_test_dynamic_double() {

	CTreeDynamic<float> cTreeDynamic;
	cTreeDynamic.pcGetRoot()->vAddNewChild();
	cTreeDynamic.pcGetRoot()->vAddNewChild();
	cTreeDynamic.pcGetRoot()->pcGetChild(0)->vSetValue(1.1f);
	cTreeDynamic.pcGetRoot()->pcGetChild(1)->vSetValue(2.2f);
	cTreeDynamic.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	cTreeDynamic.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	cTreeDynamic.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11.11f);
	cTreeDynamic.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12.12f);
	cTreeDynamic.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	cTreeDynamic.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	cTreeDynamic.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21.21f);
	cTreeDynamic.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22.22f);


	cTreeDynamic.vPrintTree();
	cout << endl;

	cout << "Print up:" << endl;
	cTreeDynamic.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vPrintUp();
	cout << "Koniec print up" << endl;
	cout << endl;
}


int main() {
	v_tree_test_dynamic_int();
	v_tree_test_dynamic_string();
	v_tree_test_dynamic_double();
	return 0;
}