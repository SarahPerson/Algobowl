#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <time.h>
#include <sstream>
#include "Subset.h"


using namespace std;


int n;
int m;
set<int> U;
map < set<int>, Subset> subsets;
vector<int> solutionIDs;
string inputfile = "input_group5.txt";

void ReadInputs(string filename);
void ReadSolution(string filename);
void WriteSolution(vector<Subset> ans);
void SolutionChecker();
void WriteInputFile();
vector<Subset>  FindSubset();

int main() {
    cout << "Hello World!\n";
	ReadInputs(inputfile);
    /*
    //print each element in map
    cout << "elements in map" << endl;
    for (auto iterator = subsets.begin(); iterator != subsets.end(); iterator++) {
        cout << iterator->second.ToString() << endl;
    }
    */

    
    cout << "solution" << endl;
    vector<Subset> result = FindSubset();

    for (int i = 0; i < result.size(); i++) {
        cout << result[i].ToString() << endl;
    }
    


     WriteSolution(result);
     SolutionChecker();
    cout << "DONE!" << endl;
    int temp;
    cin >> temp;
    return 0;
}

vector<Subset>  FindSubset() {
    Subset subset;
    Subset current = Subset(set<int>(), 0, "S_");
    Subset maximum;
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
        for (int count = 0; count < subsets.size(); count++) {
            for (auto j = subsets.begin(); j != std::prev(subsets.end()); j++) {
                current = j->second;

                //check if the current or the current max makes the union larger
                if (subset.setUnion(current).size() > subset.setUnion(maximum).size()) {
                    maximum = current;
                }
                //if the same, select the one with the lowest weight
                else if (subset.setUnion(current).size() == subset.setUnion(maximum).size()) {
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
            if (subset.intSet.size() == n) {
                return solution;
            }
        }


        //check if set has been filled
        if (subset.intSet.size() == n) {
            return solution;
        }


    }
}


void ReadInputs(string filename) {
	ifstream inputs(filename);
   
	string input;
    getline(inputs, input);

	n = stoi(input);		//Size of universal set
	//cout << n << endl;
	//for (int i = 1; i <= n; i++) {		//Construct Universal set
	//	U.insert(i);
	//}
    getline(inputs, input);
	m = stoi(input);		//Number of subsets
	//cout << m << endl;

    int idCount = 1;
	while (idCount<m){
        Subset temp;
        // set the id 
        temp.id = to_string(idCount);
        
        


        // New "building the subset" routine
        string placeholder;                     // bucket to put line of text in        
        getline(inputs, placeholder);           // the goddamn english chanel or some shit

        //cout << "GetLine: " <<placeholder<< endl;
        int start = 0;
        int end = 0;
        for (int i = 0; i < placeholder.size(); i++) {
            if (placeholder[i] == ' ' && i!=0) {
                end = i;
                temp.intSet.insert(stoi(placeholder.substr(start, end - start)));
                start = end;
            }
            if (i == placeholder.size() - 1 && placeholder[i]!=' ')
            {
                end = placeholder.size();
                temp.intSet.insert(stoi(placeholder.substr(start, end - start)));

            }
        }



        // get the weight of the subset
        getline(inputs, input);
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

        //cout << idCount << endl;

	}


	inputs.close();
    cout << "closed" << endl;
}

void ReadSolution(string filename) {

}

void WriteSolution(vector<Subset> ans) {
    
	ofstream outputs("ourSolution.txt");
    int bestWeight = 0;
    for (Subset i : ans)
    {
        bestWeight += i.weight;
    }
    outputs << bestWeight << endl;
	for (Subset i : ans) {
		outputs << i.id << " ";
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
    int solWeight;
    vector<int> solution;

    //read current solution
    string filename = "ourSolution.txt";
    ifstream sol(filename);

    string placeholder;
    getline(sol, placeholder);
    solWeight = stoi(placeholder);

    string temp;
      
    getline(sol, placeholder);           // the goddamn english chanel or some shit

    int start = 0;
    int end = 0;
    for (int i = 0; i < placeholder.size(); i++) {
        if (placeholder[i] == ' ' && i != 0) {
            end = i;
            solution.push_back((stoi(placeholder.substr(start, end - start))));
            start = end;
        }
        if (i == placeholder.size() - 1 && placeholder[i] != ' ')
        {
            end = placeholder.size();
            solution.push_back(stoi(placeholder.substr(start, end - start)));

        }
    }


    sol.close();

    ///////////
    vector<Subset> inputvals;
    filename = inputfile;
    ifstream inputs(filename);

    string input;
    getline(inputs, input);
    n = stoi(input);
    getline(inputs, input);
    m = stoi(input);		//Number of subsets
                            //cout << m << endl;

    int idCount = 1;
    while (idCount<=m) {
        Subset temp;
        // set the id 
        temp.id = to_string(idCount);




        // New "building the subset" routine
        string placeholder;                     // bucket to put line of text in        
        getline(inputs, placeholder);           // the goddamn english chanel or some shit

        int start = 0;
        int end = 0;
        for (int i = 0; i < placeholder.size(); i++) {
            if (placeholder[i] == ' ' && i != 0) {
                end = i;
                temp.intSet.insert(stoi(placeholder.substr(start, end - start)));
                start = end;
            }
            if (i == placeholder.size() - 1 && placeholder[i] != ' ')
            {
                end = placeholder.size();
                temp.intSet.insert(stoi(placeholder.substr(start, end - start)));

            }
        }

        
        // get the weight of the subset
        getline(inputs, input);
        temp.weight = stoi(input);

        idCount++; //increment id count


        
        inputvals.push_back(temp);


    }


    inputs.close();
    cout << "closed" << endl;

    // now actually check the damn solution
    int actualweight=0;
    set<int> unionset;
    for (int i : solution) {
        actualweight += inputvals[i - 1].weight;
        for (int j : inputvals[i - 1].intSet) {
            unionset.insert(j);
        }
    }
    if (actualweight == solWeight) {
        cout << "Weight is equal" << endl;
    }
    else {
        cout << "Weight is not equal" << endl;
    }
    if (unionset.size() == n) {
        cout << "Union is correct" << endl;
    }
    else
    {
        cout << "Union is NOT correct" << endl;
    }

}