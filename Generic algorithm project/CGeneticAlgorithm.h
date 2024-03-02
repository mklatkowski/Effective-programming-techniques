#include <string>
#include <iostream>
#include "CKnapsackProblem.h"
#include "CIndividual.h"

using namespace std;

class CGeneticAlgorithm {
public:
	CGeneticAlgorithm(int i_population, float f_mutationProb, float f_crossingProb, CKnapsackProblem* c_problem);
	~CGeneticAlgorithm();
	vector<int> simulate();
	vector<CIndividual*> initializePopulation(int genotypeSize);
	CIndividual* bestFitnessRate(vector<CIndividual*> population);
	CIndividual* initializeParent(vector<CIndividual*> population);
	double generateRandomValue();

private:
	int iPopulation;
	float fMutationProb;
	float fCrossingProb;
	CKnapsackProblem* cProblem;
};
