#include <unordered_map>
#include <iostream>
#include <string>

bool palindromePermutation2(const std::string &str) {
    std::unordered_map<char, int> hashmap; // char - frequency
    int oddCount = 0;

    for (const char &chr: str) {
        hashmap[chr]++;
        if (hashmap[chr] % 2 == 0) {
            oddCount--;
        } else {
            oddCount++;
        }
    }

    return (oddCount < 2);
}