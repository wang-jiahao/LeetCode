#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <iterator>
using namespace std;

struct person {
    string name;
    int height;
};

bool cmp(person p, person q) {
    return p.height > q.height;
}

int smallestNumber(int n) {
    int i = 0;
    int result = 0;
    while (++i) {
        result = static_cast<int>(pow(2, i)) - 1;
        if (result >= n) { return result; }
    }
    return result;
}

vector<string> sortPeople(vector<string> &names, vector<int> &heights) {
    vector<person> persons;
    for (int i = 0; i < names.size(); ++i) {
        persons.emplace_back(names[i], heights[i]);
    }
    sort(persons.begin(), persons.end(), cmp);
    vector<string> result;
    for (int i = 0; i < persons.size(); ++i) {
        result.push_back(persons[i].name);
    }
    return result;
}

int main() {
    vector<string> names = {"Mary", "John", "Emma"};
    vector<int> heights = {180, 165, 170};
    auto result=sortPeople(names,heights);
    copy(result.begin(),result.end(),ostream_iterator<string>(cout," "));
    return 0;
}
