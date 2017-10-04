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
vector<Subset>  FindSubset();

int main() {
    cout << "Hello World!\n";
	ReadInputs("test.txt");

    //print each element in map
    cout << "elements in map" << endl;
    for (auto iterator = subsets.begin(); iterator != subsets.end(); iterator++) {
        cout << iterator->second.ToString() << endl;
    }

    
    cout << "solution" << endl;
    vector<Subset> result = FindSubset();

    for (int i = 0; i < result.size(); i++) {
        cout << result[i].ToString() << endl;
    }

    //WriteInputFile(); //only run if you want to recreate the input file
    return 0;
}

vector<Subset>  FindSubset() {
    Subset subset;
    Subset current = Subset(set<int>(), 0, "S_");
    Subset maximum ;
    Subset next;
    vector<Subset> solution;
    for (auto iterator = subsets.begin(); iterator != subsets.end(); iterator++) {
        // clear solution
        solution.clear();

        //get starting elementand add to solution
        subset = iterator->second;
        solution.push_back(subset);

        // initialize maximum
        maximum = Subset(set<int>(), 0, "S_");

        // find set that maximizes the length of the union
        for (auto j = iterator; j != std::prev(subsets.end()); j++) {
            current = j->second;

            //check if the current or the current max makes the union larger
            if (subset.setUnion(current).size > subset.setUnion(maximum).size) {
                maximum = current;
            }
            //if the same, select the one with the lowest weight
            else if (subset.setUnion(current).size = subset.setUnion(maximum).size) {
                if (current.weight < maximum.weight) {
                    maximum = current;
                }
            }
        }
        // find the union with the new maximum
        subset.intSet = subset.setUnion(maximum);
        //add to the solution
        solution.push_back(maximum);

        //check if set has been filled
        if (subset.intSet.size = n) {
            return solution;
        }


    }
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

		do {										//Build subset
			inputs >> input;
			temp.intSet.insert(stoi(input));
		} while (inputs.peek() != '\n');

        // get the weight of the subset
        inputs >> input;
        temp.weight = stoi(input);

        idCount++; //increment id count


        auto found = subsets.find(temp.intSet);
        if ( found == subsets.end()) {
            subsets[temp.intSet]=temp;
        } else {

            //if current value is less than the one in the map, replace it
            if (subsets.at(temp.intSet).weight > temp.weight) {
                subsets.at(temp.intSet) = temp;
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