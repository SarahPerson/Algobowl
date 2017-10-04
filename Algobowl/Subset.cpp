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
    intSet = _set;
    weight = _weight;
    id = _id;
}

string Subset::ToString()
{
    string temp = id + ": ";
    for (int i : intSet) {
        temp = temp+ to_string(i) +" ";
    }
    
    temp = temp + " Weight: " + to_string(weight)+"\n";
    return temp;
}

std::set<int> Subset::setUnion(Subset b) {
    std::set<int> u;
    //add elements in current 
    for (int i : intSet) {
        u.insert(i);
    }
    //add elements in other set
    for (int i : b.intSet) {
        u.insert(i);
    }
    return u;


};