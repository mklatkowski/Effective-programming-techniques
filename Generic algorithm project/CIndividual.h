#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class CIndividual {
public:
	CIndividual(int sizeOfGenotype); //RANDOM GENERATTED GENOTYPE
	CIndividual(vector<int> iGenotype); // INDIVIDUAL WITH GIVEN GENOTYPE
	~CIndividual();
	void mutateGenotype();
	CIndividual* crossIndividuals(CIndividual* parent);
	int randomByte();
	int iFitnessRate(vector<float> weights, vector<float> values, int iSize);
	vector<int> getGenotype();
private:
	vector<int> iGenotype;
};