#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

class Dna

{
private:
	ifstream infile;
	ofstream outfile;
	string current, filename;
	int count = 0, length, sum = 0, countB = 0, printCount = 0;
	int AAcount = 0, ACcount = 0, ATcount = 0, AGcount = 0;
	int CAcount = 0, CCcount = 0, CTcount = 0, CGcount = 0;
	int TAcount = 0, TCcount = 0, TTcount = 0, TGcount = 0;
	int GAcount = 0, GCcount = 0, GTcount = 0, GGcount = 0;
	double vari, stdDev, mean, PI = 3.14159;
	double AAodds = 0, ACodds = 0, ATodds = 0, AGodds = 0;
	double CAodds = 0, CCodds = 0, CTodds = 0, CGodds = 0;
	double TAodds = 0, TCodds = 0, TTodds = 0, TGodds = 0;
	double GAodds = 0, GCodds = 0, GTodds = 0, GGodds = 0;
	int num;
public:
	Dna();
	Dna(string);
	void setFilename(string);
	void setVari(double);
	void setBigramCount(string);
	void bigramMatcher(string);
	void debugPrints();
	void printReport();
	void setOdds();
	double getDnaLength();
	string getBigram(int);
	string getBigramString(int);
	int getRandomNum(int);
	char getRandomLetter();
	void promptUser();
	void resetStats();
	void runScript();




	~Dna();
};

