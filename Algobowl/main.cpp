#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <time.h>
#include "Subset.h"


using namespace std;

int bestWeight;
int n;
int m;
set<int> U;
map < set<int>, Subset> subsets;
vector<int> solutionIDs;

void ReadInputs(string filename);
void ReadSolution(string filename);
void WriteSolution();
void SolutionChecker();
void WriteInputFile();

int main() {
    cout << "Hello World!\n";
	ReadInputs("test.txt");

    for (auto iterator = subsets.begin(); iterator != subsets.end(); iterator++) {
        cout << iterator->second.ToString() << endl;
        // Repeat if you also want to iterate through the second map.
    }

    //WriteInputFile(); //only run if you want to recreate the input file
    return 0;
}

void ReadInputs(string filename) {
	ifstream inputs(filename);
	string input;
	inputs >> input;
	n = stoi(input);		//Size of universal set
	//cout << n << endl;
	for (int i = 1; i <= n; i++) {		//Construct Universal set
		U.insert(i);
	}
	inputs >> input;
	m = stoi(input);		//Number of subsets
	//cout << m << endl;

    int idCount = 1;
	while (!inputs.eof()) {
        Subset temp;
        // set the id 
        temp.id = "S" + to_string(idCount);

        //set<int> temp;
		do {										//Build subset
			inputs >> input;
			temp.set.insert(stoi(input));
		} while (inputs.peek() != '\n');
        // get the weight of the subset
        inputs >> input;
        temp.weight = stoi(input);
		//subsets.push_back(temp);				//Add subset to vector
		//inputs >> input;
		//weights.push_back(stoi(input));			//Add weight to vector at same index. This links their index as a pseudo-ID
        idCount++; //increment id count
        //cout << temp.ToString();

        auto found = subsets.find(temp.set);
        if ( found == subsets.end()) {
            subsets[temp.set]=temp;
        }
        else {
            //if current value is less than the one in the map, replace it
            if (subsets.at(temp.set).weight > temp.weight) {
                subsets.at(temp.set) = temp;
            }

        }



	}


	inputs.close();
}

void ReadSolution(string filename) {

}

void WriteSolution() {
    /*
	ofstream outputs("ourSolution.txt");
	outputs << bestWeight << endl;
	for (int i = 0; i < solutionIDs.size(); i++) {
		outputs << solutionIDs.at(i) << " ";
	}
	outputs.close();
    */
}

void WriteInputFile() {
    // initialize random
    srand(time(NULL));

    int FileSize = 200;
    int SetSize = 45;
    ofstream out("input.txt");
    out << SetSize << endl;
    for (int i = 0; i < FileSize; i++) {
        //print out weight between 30 and 90
        out << rand() % 60 + 30 << endl;

        for (int i = 0; i < rand() % 90 + 1; i++)
        {
            out << rand() % SetSize + 1 << " ";
        }
        out << endl;
    }
}

void SolutionChecker() {
	ReadInputs("ourInput.txt");

}