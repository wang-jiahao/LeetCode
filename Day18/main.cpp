#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool halvesAreAlike(string s) {
    auto isVowel = [](char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O'
               || c == 'U';
    };
    int size = s.size();
    return count_if(s.begin(), s.begin() + size / 2, isVowel) == count_if(
               s.begin() + size / 2, s.end(), isVowel);
}

int josephus(int n, int k) {
    if (n == 1) { return 0; }
    return (josephus(n - 1, k) + k) % n;
}

int findTheWinner(int n, int k) {
    return josephus(n, k) + 1;
}

int main() {
    return 0;
}
