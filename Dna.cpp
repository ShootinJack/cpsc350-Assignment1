#include "Dna.h"



Dna::Dna()
{
}

Dna::Dna(string l) {
	srand(time(NULL));
	setFilename(l);
	runScript();
}


Dna::~Dna()
{
}

void Dna::runScript() {
	infile.open(filename);
	cout << "Reading...\n";
	do
	{
		getline(infile, current);
		count++;
		for (int j = 0; j < current.length(); ++j) {
			if (islower(current[j])) {
				current[j] = toupper(current[j]);
			}
		}
		length = current.length();
		sum = sum + length;
		if (current.size() != 0) {
			setBigramCount(current);
		}
	} while (infile.good());
	count--;
	mean = double(sum) / double(count);
	setVari(mean);
	stdDev = sqrt(vari);
	setOdds();
	//debugPrints();
	cout << "Printing...\n";
	printReport();
	infile.close();
	promptUser();
}

int Dna::getRandomNum(int n) {
	return (num = rand() % n);
}

void Dna::setFilename(string inFile) {
	filename = inFile;
}

string Dna::getBigramString(int length) {
	string bigram = "", bigramString;
	if (length % 2 == 0) {
		for (int i = 0; i < (length/2); ++i) {
			bigramString = bigramString + getBigram((rand() % 100));
		}
		return bigramString;
	}
	else {
		length = length - 1;
		for (int i = 0; i < (length / 2); ++i) {
			bigramString = bigramString + getBigram((rand() % 100));
		}
		bigramString.push_back(getRandomLetter());
		return bigramString;

	}
	
}

double Dna::getDnaLength() {
	double constant, a, b, d;
	for (int i = 0; i < 2; ++i) {
		if (i == 0) {
			a = double(rand()) / RAND_MAX;
		}
		else {
			b = double(rand()) / RAND_MAX;
		}
	}
	constant = sqrt(-2 * log(a))*cos(2 * PI*b);
	d = round(stdDev*constant + mean);

	return d;
}

char Dna::getRandomLetter() {
	int n = rand() % 3;
	switch (n) {
	case 0:
		return 'A';
		break;
	case 1:
		return 'C';
		break;
	case 2:
		return 'T';
		break;
	case 3:
		return 'G';
		break;
	}
}

void Dna::setVari(double m) {
	double dev, devSquared, sumDs = 0;
	infile.open(filename);
	for (int i = 0; i < count; ++i) {
		getline(infile, current);
		length = current.length();
		dev = length - m;
		devSquared = dev * dev;
		sumDs = sumDs + devSquared;
	}
	vari = sumDs / (count - 1);
}

void Dna::setBigramCount(string inDna) {
	string bigram;
	if ((inDna.length()%2) == 0) {
		for (int i = 0; i < ((inDna.length()) - 1); i = i + 2) {
			//cout << inDna[i] << " + " << inDna[i + 1] << endl;
			bigram.push_back(inDna[i]);
			bigram.push_back(inDna[i + 1]);
			//cout << bigram << endl;
			bigramMatcher(bigram);
			bigram.erase(0);
			++countB;
		}
	}
	else {
		for (int i = 0; i < inDna.length(); i = i + 2){
			if (i == (inDna.length() - 1)) {
				//cout << inDna[i] << " + " << inDna[0] << endl;
				bigram.push_back(inDna[i]);
				bigram.push_back(inDna[0]);
				bigramMatcher(bigram);
				//cout << bigram << endl;
				bigram.erase(0);
				++countB;
			}
			else {
				//cout << inDna[i] << " + " << inDna[i + 1] << endl;
				bigram.push_back(inDna[i]);
				bigram.push_back(inDna[i + 1]);
				bigramMatcher(bigram);
				//cout << bigram << endl;
				bigram.erase(0);
				++countB;
			}
	
		}
	}
}

void Dna::bigramMatcher(string inBigram) {
	if (inBigram == "AA") {
		AAcount++;
	}
	else if (inBigram == "AC") {
		ACcount++;
	}
	else if (inBigram == "AT") {
		ATcount++;
	}
	else if (inBigram == "AG") {
		AGcount++;
	}
	else if (inBigram == "CA") {
		CAcount++;
	}
	else if (inBigram == "CC") {
		CCcount++;
	}
	else if (inBigram == "CT") {
		CTcount++;
	}
	else if (inBigram == "CG") {
		CGcount++;
	}
	else if (inBigram == "TA") {
		TAcount++;
	}
	else if (inBigram == "TC") {
		TCcount++;
	}
	else if (inBigram == "TT") {
		TTcount++;
	}
	else if (inBigram == "TG") {
		TGcount++;
	}
	else if (inBigram == "GA") {
		GAcount++;
	}
	else if (inBigram == "GC") {
		GCcount++;
	}
	else if (inBigram == "GT") {
		GTcount++;
	}
	else if (inBigram == "GG") {
		GGcount++;
	}
}

void Dna::setOdds() {
	double totalpercent = 100;

	AAodds = double(AAcount) / double(countB)*100;
	AAodds = totalpercent - AAodds;
	totalpercent = AAodds;

	ACodds = double(ACcount) / double(countB) * 100;
	ACodds = totalpercent - ACodds;
	totalpercent = ACodds;

	ATodds = double(ATcount) / double(countB) * 100;
	ATodds = totalpercent - ATodds;
	totalpercent = ATodds;

	AGodds = double(AGcount) / double(countB) * 100;
	AGodds = totalpercent - AGodds;
	totalpercent = AGodds;

	CAodds = double(CAcount) / double(countB) * 100;
	CAodds = totalpercent - CAodds;
	totalpercent = CAodds;

	CCodds = double(CCcount) / double(countB) * 100;
	CCodds = totalpercent - CCodds;
	totalpercent = CCodds;

	CTodds = double(CTcount) / double(countB) * 100;
	CTodds = totalpercent - CTodds;
	totalpercent = CTodds;

	CGodds = double(CGcount) / double(countB) * 100;
	CGodds = totalpercent - CGodds;
	totalpercent = CGodds;

	TAodds = double(TAcount) / double(countB) * 100;
	TAodds = totalpercent - TAodds;
	totalpercent = TAodds;

	TCodds = double(TCcount) / double(countB) * 100;
	TCodds = totalpercent - TCodds;
	totalpercent = TCodds;

	TTodds = double(TTcount) / double(countB) * 100;
	TTodds = totalpercent - TTodds;
	totalpercent = TTodds;

	TGodds = double(TGcount) / double(countB) * 100;
	TGodds = totalpercent - TGodds;
	totalpercent = TGodds;

	GAodds = double(GAcount) / double(countB) * 100;
	GAodds = totalpercent - GAodds;
	totalpercent = GAodds;

	GCodds = double(GCcount) / double(countB) * 100;
	GCodds = totalpercent - GCodds;
	totalpercent = GCodds;

	GTodds = double(GTcount) / double(countB) * 100;
	GTodds = totalpercent - GTodds;
	totalpercent = GTodds;

	GGodds = double(GGcount) / double(countB) * 100;
	GGodds = totalpercent - GGodds;
	totalpercent = GGodds;

}

string Dna::getBigram(int num) {

	if (num <= 100 && num >= AAodds) {
		return "AA";
	}
	else if (num < AAodds && num >= ACodds) {
		return "AC";
	}
	else if (num < ACodds && num >= ATodds) {
		return "AT";
	}
	else if (num < ATodds && num >= AGodds) {
		return "AG";
	}
	else if (num < AGodds && num >= CAodds) {
		return "CA";
	}
	else if (num < CAodds && num >= CCodds) {
		return "CC";
	}
	else if (num < CCodds && num >= CTodds) {
		return "CT";
	}
	else if (num < CTodds && num >= CGodds) {
		return "CG";
	}
	else if (num < CGodds && num >= TAodds) {
		return"TA";
	}
	else if (num < TAodds && num >= TCodds) {
		return"TC";
	}
	else if (num < TCodds && num >= TTodds) {
		return "TT";
	}
	else if (num < TTodds && num >= TGodds) {
		return "TG";
	}
	else if (num < TGodds && num >= GAodds) {
		return "GA";
	}
	else if (num < GAodds && num >= GCodds) {
		return "GC";
	}
	else if (num < GCodds && num >= GTodds) {
		return "GT";
	}
	else if (num < GTodds && num >= 0) {
		return "GG";
	}
}

void Dna::printReport() {
	double length;
	if (printCount == 0) {
		outfile.open("TavidTerzian.out");
		outfile << "Tavid Terzian\nChapman ID: 2382712\n\n";
		outfile << "Total DNA strings: " << count << endl;
		outfile << "Sum: " << sum << endl;
		outfile << "Mean: " << mean << endl;
		outfile << "Variance: " << vari << endl;
		outfile << "Standard Deviation: " << stdDev << endl << endl;
		for (int i = 0; i < 1000; ++i) {
			length = getDnaLength();
			outfile << getBigramString(length) << endl;
		}
		outfile.close();
		printCount++;
		cout << "Report Generated.\n";
	}
	else {
		outfile.open("TavidTerzian.out", ios_base::app);
		outfile << "\n\nTotal DNA strings: " << count << endl;
		outfile << "Sum: " << sum << endl;
		outfile << "Mean: " << mean << endl;
		outfile << "Variance: " << vari << endl;
		outfile << "Standard Deviation: " << stdDev << endl << endl;
		for (int i = 0; i < 1000; ++i) {
			length = getDnaLength();
			outfile << getBigramString(length) << endl;
		}
		outfile.close();
		cout << "Report Generated.\n";
	}

}

void Dna::resetStats() {
	int count = 0, length, sum = 0, countB = 0;
	int AAcount = 0, ACcount = 0, ATcount = 0, AGcount = 0;
	int CAcount = 0, CCcount = 0, CTcount = 0, CGcount = 0;
	int TAcount = 0, TCcount = 0, TTcount = 0, TGcount = 0;
	int GAcount = 0, GCcount = 0, GTcount = 0, GGcount = 0;
	double vari = 0, stdDev =0, mean =0, PI = 3.14159;
	double AAodds = 0, ACodds = 0, ATodds = 0, AGodds = 0;
	double CAodds = 0, CCodds = 0, CTodds = 0, CGodds = 0;
	double TAodds = 0, TCodds = 0, TTodds = 0, TGodds = 0;
	double GAodds = 0, GCodds = 0, GTodds = 0, GGodds = 0;
	int num;
}

void Dna::promptUser() {
	char selection;
	string name;
	do {
		cout << "Run another file? (y / n): ";
		cin >> selection;
		if (selection == 'y') {
			do {
				cout << "Enter new file name: ";
				cin >> name;
				setFilename(name);
				infile.open(name);
				if (infile.good() == true) {
					cout << "Called\n";
					//continue;
				}
				else {
					cout << "Invalid filename\n";
				}
			} while (infile.good() != true);
			infile.close();
			runScript();
		}
		else if (selection == 'n')
		{
			cout << "Thank you!\n";
		}
		else {
			cout << "Invalid Selection\n";
		}
	} while (selection != 'y' && selection != 'n');
	
}

void Dna::debugPrints() {
	cout << "Total DNA strings: " << count << endl;
	cout << "Sum of the lengths: " << sum << endl;
	cout << "Mean of the DNA strings: " << mean << endl;
	cout << "Variance: " << vari << endl;
	cout << "Standard Deviation: " << stdDev << endl;
	for (int i = 0; i < 3; ++i) {
		num = getRandomNum(100);
		cout << getBigram(num);
	}
	cout << getDnaLength() << endl;
	cout << "A: " << AAcount << " " << ACcount << " " << ATcount << " " << AGcount << " " << endl;
	cout << "C: " << CAcount << " " << CCcount << " " << CTcount << " " << CGcount << " " << endl;
	cout << "T: " << TAcount << " " << TCcount << " " << TTcount << " " << TGcount << " " << endl;
	cout << "G: " << GAcount << " " << GCcount << " " << GTcount << " " << GGcount << " " << endl;
}