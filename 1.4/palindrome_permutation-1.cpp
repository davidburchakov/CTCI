#include <iostream>
#include <unordered_map>
#include <string>

bool palindromePermutation(const std::string &str) {
    if(str.empty()) throw std::invalid_argument("input string is empty!");
    std::unordered_map<char, int> hashmap; // char - frequency

    for (const char &chr: str) {
        if(std::isalnum(chr)) {
            hashmap[std::tolower(chr)]++;
        }
    }

    bool odd = false;
    for (auto const &[k, v]: hashmap) {
        if (v % 2 != 0) {
            if (odd) {
                return false;
            }
            odd = true;
        }
    }
    return true;
}