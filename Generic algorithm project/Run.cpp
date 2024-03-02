#include<iostream>
#include "CGeneticAlgorithm.h"
#include "CIndividual.h"
#include "CKnapsackProblem.h"

using namespace std;

vector<float> initializeValues() {
	vector<float> values;
	values.insert(values.begin(), 10.5);
	values.insert(values.begin() + 1, 7);
	values.insert(values.begin() + 2, 1);
	values.insert(values.begin() + 3, 3);
	values.insert(values.begin() + 4, 2);
	return values;
}

vector<float> initializeWeights() {
	vector<float> weights;
	weights.insert(weights.begin(), 9.5);
	weights.insert(weights.begin() + 1, 12);
	weights.insert(weights.begin() + 2, 2);
	weights.insert(weights.begin() + 3, 7);
	weights.insert(weights.begin() + 4, 8);
	return weights;
}

void printVector(CKnapsackProblem* problem, vector<int> toPrint) {
	float fitnessRate = 0;
	cout << "Wartosci: ";
	for (int i = 0; i < toPrint.size(); i++) {
		cout << problem->getValues().at(i) << " ";
		if (toPrint.at(i) == 1) {
			fitnessRate = fitnessRate + problem->getValues().at(i);
		}
	}
	cout << endl;
	cout << "Wagi: ";
	for (int i = 0; i < toPrint.size(); i++) {
		cout << problem->getWeights().at(i) << " ";
	}
	cout << endl;
	cout << "Rozmiar plecaka: " << problem->getSize() << endl;
	cout << "Wynik: ";
	for (int i = 0; i < toPrint.size(); i++) {
		cout << toPrint.at(i) << " ";
	}
	cout << endl;
	cout << "wartosc rozwiazania: " << fitnessRate << endl;


}


int main() {

	srand(time(NULL));

	vector<float> values = initializeValues();
	vector<float> weights = initializeWeights();
	int size = 15;

	CKnapsackProblem* problem = new CKnapsackProblem(values, weights, size);
	//CKnapsackProblem* problem = new CKnapsackProblem("test.txt");
	CGeneticAlgorithm alg = CGeneticAlgorithm(5, 0.15f, 0.3f, problem);

	vector<int> genotype =  alg.simulate();
	printVector(problem, genotype);


	return 0;
}


