#pragma once

#include <string>
#include <iostream>
#include <set>

using namespace std;

class Subset
{
private:
    
public:
    Subset();
    Subset(set<int> _set, int _weight, string _id);
    set<int> set;
    string id;
    double weight;
    
    //methods
    string ToString();

};