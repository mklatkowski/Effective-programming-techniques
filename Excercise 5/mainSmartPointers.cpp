#include <iostream>
#include<string>
#include "CRefCounter.h"
#include "CMySmartPointer.h"

using namespace std;


int main() {
	int* x;
	x = new int;
	*x = 5;

	int* y;
	y = new int;
	*y = 6;

	CMySmartPointer<int> pointer1(x);
	CMySmartPointer<int> pointer2(y);

	cout << pointer1.getPointer() << endl;
	cout << pointer2.getPointer() << endl;

	
	pointer1 = pointer2;


	cout << pointer1.getPointer() << endl;
	cout << pointer2.getPointer() << endl;
}
