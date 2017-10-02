#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

int bestWeight;
int n;
int m;
set<int> U;
vector<int> weights;
vector<set<int>> subsets;
vector<int> solutionIDs;

int main() {
    cout << "Hello World!\n";
    return 0;
}

void ReadInputs(string filename) {
	ifstream inputs(filename);
	string input;
	inputs >> input;
	n = stoi(input);		//Size of universal set
	for (int i = 1; i <= n; i++) {		//Construct Universal set
		U.insert(i);
	}
	inputs >> input;
	m = stoi(input);		//Number of subsets

	while (!inputs.eof()) {
		set<int> temp;
		while (inputs.peek() != '/n') {		//Build subset
			inputs >> input;
			temp.insert(stoi(input));
		}
		subsets.push_back(temp);	//Add subset to vector
		inputs >> input;
		weights.push_back(stoi(input));		//Add weight to vector at same index. This links their index as a pseudo-ID
	}
	inputs.close();
}

void WriteSolution() {
	ofstream outputs("ourSolution.txt");
	outputs << bestWeight << endl;
	for (int i = 0; i < solutionIDs.size(); i++) {
		outputs << solutionIDs.at(i) << " ";
	}
	outputs.close();
}

void SolutionChecker() {
	ReadInputs("ourInput.txt");

}