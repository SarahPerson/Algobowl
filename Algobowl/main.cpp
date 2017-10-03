#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <time.h>
using namespace std;

int bestWeight;
int n;
int m;
set<int> U;
vector<int> weights;
vector<set<int>> subsets;
vector<int> solutionIDs;

void ReadInputs(string filename);
void ReadSolution(string filename);
void WriteSolution();
void SolutionChecker();
void WriteInputFile();

int main() {
    cout << "Hello World!\n";
	ReadInputs("test.txt");
    WriteInputFile();
    return 0;
}

void ReadInputs(string filename) {
	ifstream inputs(filename);
	string input;
	inputs >> input;
	n = stoi(input);		//Size of universal set
	cout << n << endl;
	for (int i = 1; i <= n; i++) {		//Construct Universal set
		U.insert(i);
	}
	inputs >> input;
	m = stoi(input);		//Number of subsets
	cout << m << endl;
	while (!inputs.eof()) {
		set<int> temp;
		do {										//Build subset
			inputs >> input;
			temp.insert(stoi(input));
		} while (inputs.peek() != '\n');
		subsets.push_back(temp);				//Add subset to vector
		inputs >> input;
		weights.push_back(stoi(input));			//Add weight to vector at same index. This links their index as a pseudo-ID
	}
	inputs.close();
}

void ReadSolution(string filename) {

}

void WriteSolution() {
	ofstream outputs("ourSolution.txt");
	outputs << bestWeight << endl;
	for (int i = 0; i < solutionIDs.size(); i++) {
		outputs << solutionIDs.at(i) << " ";
	}
	outputs.close();
}

void WriteInputFile() {
    // initialize random
    srand(time(NULL));

    int FileSize = 200;
    int SetSize = 45;
    ofstream out("input.txt");
    out << SetSize << endl;
    for (int i = 0; i < FileSize; i++) {
        for (int i = 0; i < rand() % 90 + 1; i++)
        {
            out << rand() % SetSize + 1 << " ";
        }
        out << endl;
		//print out weight between 30 and 90
		out << rand() % 60 + 30 << endl;
    }
}

void SolutionChecker() {
	ReadInputs("ourInput.txt");

}