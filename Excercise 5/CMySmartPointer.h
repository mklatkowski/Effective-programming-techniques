#pragma once
#include <iostream>
#include<string>
#include "CRefCounter.h"



template<typename T> class CMySmartPointer
{

private:
	CRefCounter* pc_counter;
	T* pc_pointer;

public:

	template<typename T>
	CMySmartPointer(T* pcPointer)
	{
		pc_pointer = pcPointer;
		pc_counter = new CRefCounter();
		pc_counter->iAdd();
	}

	template<typename T>
	CMySmartPointer(const CMySmartPointer<T>& pcOther)
	{
		pc_pointer = pcOther.pc_pointer;
		pc_counter = pcOther.pc_counter;
		pc_counter->iAdd();
	}

	~CMySmartPointer()
	{
		if (pc_counter->iDec() == 0)
		{
			delete pc_pointer;
			delete pc_counter;
		}
	}

	template<typename T>
	T& operator*() { return(*pc_pointer); }
	template<typename T>
	T* operator->() { return(pc_pointer); }

	CMySmartPointer operator=(const CMySmartPointer& cOther) {

		pc_counter->iDec();
		if (pc_counter->iGet() <= 0) {
			delete pc_pointer;
			delete pc_counter;
		}
		pc_counter = cOther.pc_counter;
		pc_pointer = cOther.pc_pointer;
		pc_counter->iAdd();
		return cOther;
	};


	T* getPointer() {
		return pc_pointer;
	}
};
