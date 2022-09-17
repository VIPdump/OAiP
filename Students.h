#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Students
{
public:
	string fname;
	string name, surname, lastname, initials;
	int year, group, estim[4];
	double est_aver;

	void print(int i);

	double score(int* estimates, int size);

	void data();
	
};