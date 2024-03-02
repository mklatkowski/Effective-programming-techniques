#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "CKnapsackProblem.h"

using namespace std;

bool checkData(vector<float> pi_values, vector<float> pi_weights, int i_size) {
	if (pi_values.size() != pi_weights.size()) {
		cout << "Problem nie zainicjalizowany. Roznica w wielkosciach tablic rozmiarow i wartosci" << endl;
		return false;
	}
	else {
		int error = 0;
		for (int ii = 0; ii < pi_values.size(); ii++) {
			if (pi_values.at(ii) < 0 || pi_weights.at(ii) < 0) {
				cout << "Problem nie zainicjalizowany. Wartosc/rozmiar mniejszy od 0" << endl;
				error = 1;
				return false;
			}
		}
		if (error == 0) {
			return true;
		}
	}
}


CKnapsackProblem::CKnapsackProblem(vector<float> pi_values,vector<float> pi_weights, int i_size) {
	if (checkData(pi_values, pi_weights, i_size)) {
		piValues = pi_values;
		piWeights = pi_weights;
		iSize = i_size;
	}
}

CKnapsackProblem::CKnapsackProblem(string fileName) {
	fromFile(fileName);
}

CKnapsackProblem::~CKnapsackProblem() {
}


int CKnapsackProblem::fitnessRate(vector<int> fitness) {
	if (fitness.size() != piValues.size()) {
		cout << "Z³e dane" << endl;
		return -1;
	}
	else {
		int result = 0;
		for (int ii = 0; ii < fitness.size(); ii++) {
			if (fitness.at(ii) == 1) {
				result = result + piValues.at(ii);
			}
		}
		if (result <= iSize) {
			return result;
		}
		else return 0;
	}
}

//GETTERS

vector<float> CKnapsackProblem::getValues() {
	return piValues;
}

vector<float> CKnapsackProblem::getWeights() {
	return piWeights;
}

int CKnapsackProblem::getSize() {
	return iSize;
}

void CKnapsackProblem::fromFile(string name) {
	fstream file(name, std::ios::in);
	string values;
	string weights;
	string size;


	if (file.good()) {
		getline(file, values);
		getline(file, weights);
		getline(file, size);
		file.close();
	}

	char separator = ' ';
	int i = 0;
	vector<string> resultValues;
	vector<string> resultWeights;


	string s;
	while (values[i] != '\0') {
		if (values[i] != separator) {
			s += values[i];
		}
		else {
			resultValues.push_back(s);
			s.clear();
		}
		i++;
	}
	
	i = 0;
	while (weights[i] != '\0') {
		if (weights[i] != separator) {
			s += weights[i];
		}
		else {
			resultWeights.push_back(s);
			s.clear();
		}
		i++;
	}

	vector<float> resultValuesInt;
	vector<float> resultWeightsInt;


	for (int i = 0; i < resultValues.size(); i++) {
		resultValuesInt.push_back(stoi(resultValues.at(i)));
	}
	for (int i = 0; i < resultWeights.size(); i++) {
		resultWeightsInt.push_back(stoi(resultWeights.at(i)));
	}

	if (checkData(resultValuesInt, resultWeightsInt, stoi(size))) {
		piValues = resultValuesInt;
		piWeights = resultWeightsInt;
		iSize = stoi(size);
	}

}


