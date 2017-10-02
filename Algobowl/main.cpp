#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int bestWeight;
vector<int> solutionIDs;

int main() {
    cout << "Hello World!\n";
    return 0;
}

void ReadInputs(string filename) {
	ifstream inputs(filename);

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