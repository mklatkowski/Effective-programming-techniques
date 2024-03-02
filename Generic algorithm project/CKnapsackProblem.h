#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class CKnapsackProblem {

public:
	CKnapsackProblem(vector<float> pi_values, vector<float> pi_weights, int i_size);
	~CKnapsackProblem();
	int fitnessRate(vector<int> fitness);
	vector<float> getValues();
	vector<float> getWeights();
	int getSize();
	CKnapsackProblem(string fileName);
	void fromFile(string name);

private:
	vector<float> piValues;
	vector<float> piWeights;
	int iSize;
};

