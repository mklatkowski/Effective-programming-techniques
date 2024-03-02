#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "CIndividual.h"


using namespace std;

CIndividual::CIndividual(int sizeOfGenotype) {
	if (sizeOfGenotype < 0) {
		cout << "Nie zainicjalizowano obiektu: z³e dane";
	}
	else {
		for (int ii = 0; ii < sizeOfGenotype; ii++) {
			iGenotype.insert(iGenotype.begin() + ii, randomByte());
		}
	}
}

CIndividual::CIndividual(vector<int> i_genotype) {
	iGenotype = i_genotype;
}

CIndividual::~CIndividual() {
}

void CIndividual::mutateGenotype() {
	int pos = rand() % (iGenotype.size());
	if (iGenotype.at(pos) == 0) {
		iGenotype.at(pos) = 1;
	}
	else {
		iGenotype.at(pos) = 0;
	}
}

CIndividual* CIndividual::crossIndividuals(CIndividual* parent) {
	if (iGenotype.size() != parent->iGenotype.size()) {
		cout << "Zle dane";
		return nullptr;
	}
	int pos = rand() % (iGenotype.size());
	vector<int> childGenotype;
	for (int ii = 0; ii < pos; ii++) {
		childGenotype.insert(childGenotype.begin() + ii, iGenotype.at(ii));
	}
	for (int ii = 0; ii < iGenotype.size() - pos; ii++) {
		childGenotype.insert(childGenotype.begin() +pos + ii, parent->iGenotype.at(pos+ii));
	}
	CIndividual* toReturn = new CIndividual(childGenotype);
	return toReturn;
}


int CIndividual::randomByte() {
	return rand() % 2;
}

int CIndividual::iFitnessRate(vector<float> weights, vector<float> values, int iSize) {
	if (weights.size() != iGenotype.size()) {
		return 0;
	}
	float result = 0;
	float weight = 0;
	for (int ii = 0; ii < weights.size(); ii++) {
		if (iGenotype.at(ii) == 1) {
			result = result + values.at(ii);
			weight = weight + weights.at(ii);
		}
	}
	cout << "Waga: " << weight << " Wartosc: " << result;
	if (weight <= iSize) {
		cout << " Zwracam:  " << result << endl;
		return result;
	}
	cout << " Zwracam 0" << endl;
	return 0;
}

vector<int> CIndividual::getGenotype() {
	return iGenotype;
}