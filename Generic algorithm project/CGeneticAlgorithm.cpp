#include <string>
#include <iostream>
#include "CKnapsackProblem.h"
#include "CGeneticAlgorithm.h"
#include "CIndividual.h"
#include <vector>

using namespace std;

const int REPEATS = 10;

CGeneticAlgorithm::CGeneticAlgorithm(int i_population, float f_mutationProb, float f_crossingProb, CKnapsackProblem* c_problem) {
	if (i_population < 2 || f_mutationProb>1 || f_mutationProb < 0 || f_crossingProb>1 || f_crossingProb < 0) {
		cout << "Obiekt niezainicjalizowany, z³e dane";
	}
	else{
		iPopulation = i_population;
		fMutationProb = f_mutationProb;
		fCrossingProb = f_crossingProb;
		cProblem = c_problem;
	}
}

CGeneticAlgorithm::~CGeneticAlgorithm() {
}

vector<int> CGeneticAlgorithm::simulate() {
	vector<int> result;
	vector<CIndividual*> population = initializePopulation(cProblem->getValues().size());

	result = bestFitnessRate(population)->getGenotype();
	int valueToCompare = bestFitnessRate(population)->iFitnessRate(cProblem->getWeights(), cProblem->getValues(), cProblem->getSize());


	for (int reps = 0; reps < REPEATS; reps++) {
		int counter = 0;
		vector<CIndividual*> nextGeneration;
		while (counter!=iPopulation) {
			CIndividual* parent1 = initializeParent(population);
			CIndividual* parent2;
;			do {
				parent2 = initializeParent(population);
			} while (parent1 == parent2);

			if (generateRandomValue() <= fCrossingProb) {
				CIndividual* child1 = parent1->crossIndividuals(parent2);
				if (generateRandomValue() <= fMutationProb) {
					child1->mutateGenotype();
				}
				nextGeneration.insert(nextGeneration.begin() + counter, child1);
				counter++;

				if (counter != iPopulation) {
					CIndividual* child2 = parent2->crossIndividuals(parent1);
					if (generateRandomValue() <= fMutationProb) {
						child2->mutateGenotype();
					}
					nextGeneration.insert(nextGeneration.begin() + counter, child2);
					counter++;
				}
			}

			else {
				nextGeneration.insert(nextGeneration.begin() + counter, parent1);
				if (generateRandomValue() <= fMutationProb) {
					parent1->mutateGenotype();
				}
				if (counter != iPopulation) {
					if (generateRandomValue() <= fMutationProb) {
						parent2->mutateGenotype();
					}
					nextGeneration.insert(nextGeneration.begin() + counter, parent2);
				}
			}
		}
		if (valueToCompare
			< bestFitnessRate(nextGeneration)->iFitnessRate(cProblem->getWeights(), cProblem->getValues(), cProblem->getSize())){
			result = bestFitnessRate(nextGeneration)->getGenotype();
			valueToCompare = bestFitnessRate(nextGeneration)->iFitnessRate(cProblem->getWeights(), cProblem->getValues(), cProblem->getSize());
		}
	}
	return result;
}

CIndividual* CGeneticAlgorithm::initializeParent(vector<CIndividual*> population) {
	int random1 = rand() % iPopulation;
	int random2;
	do {
		random2 = rand() % iPopulation;
	} while (random1 != random2);
	if (population.at(random1)->iFitnessRate(cProblem->getWeights(), cProblem->getValues(), cProblem->getSize())
		> population.at(random2)->iFitnessRate(cProblem->getWeights(), cProblem->getValues(), cProblem->getSize())) {
		return population.at(random1);
	}
	return population.at(random2);
}


vector<CIndividual*> CGeneticAlgorithm::initializePopulation(int genotypeSize) {
	vector<CIndividual*> result;
	for (int ii = 0; ii < iPopulation; ii++) {
		CIndividual* toAdd = new CIndividual(genotypeSize);
		toAdd->getGenotype();
		result.insert((result.begin() + ii), toAdd);
	}
	return result;
}

CIndividual* CGeneticAlgorithm::bestFitnessRate(vector<CIndividual*> population) {
	CIndividual* result = population.at(0);
	int valueToComapre = result->iFitnessRate(cProblem->getWeights(), cProblem->getValues(), cProblem->getSize());
	for (int ii = 1; ii < population.size(); ii++) {
		if (int checkedValue = population.at(ii)->iFitnessRate(cProblem->getWeights(), cProblem->getValues(), cProblem->getSize()) > valueToComapre) {
			result = population.at(ii);
			valueToComapre = checkedValue;
		}
	}

	return result;
}

double CGeneticAlgorithm::generateRandomValue() {
	return rand() / double(RAND_MAX);
}
