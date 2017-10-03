#pragma once

#include <string>
#include <unordered_set>
#include "Subset.h"

using namespace std;

Subset::Subset() {
    id = "";
    weight = 0;
}

Subset::Subset(unordered_set<int> _set, int _weight, string _id) {
    set = _set;
    weight = _weight;
    id = _id;
}