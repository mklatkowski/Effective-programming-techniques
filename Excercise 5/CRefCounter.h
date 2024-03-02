#pragma once
#include <iostream>
#include<string>


class CRefCounter
{

private:
	int i_count;

public:
	CRefCounter() { i_count = 0; }
	int iAdd() { return(++i_count); }
	int iDec() { return(--i_count); };
	int iGet() { return(i_count); }
};
