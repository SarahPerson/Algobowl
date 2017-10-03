#pragma once

#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

class Subset
{
private:
    
public:
    Subset();
    Subset(unordered_set<int> _set, int _weight, string _id);
    unordered_set<int> set;
    string id;
    double weight;

};