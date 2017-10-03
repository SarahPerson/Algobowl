#pragma once

#include <string>
#include <unordered_set>
#include <set>
#include "Subset.h"

using namespace std;

Subset::Subset() {
    id = "";
    weight = 0;
}

Subset::Subset(std::set<int> _set, int _weight, string _id) {
    set = _set;
    weight = _weight;
    id = _id;
}

string Subset::ToString()
{
    string temp = id + ": ";
    for (int i : set) {
        temp = temp+ to_string(i) +" ";
    }
    
    temp = temp + " Weight: " + to_string(weight)+"\n";
    return temp;
}