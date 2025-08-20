#include <iostream>
#include <string>
#include <algorithm>

std::string toBinary(int num) {
    std::string res;
    int factor4 = 0;
    int counter = 0;
    while (num > 0) {
        if (factor4 == 4) {
            res += ' ';
            factor4 = 0;
        }
        if (num % 2 == 0) {
            res += '0';
        } else {
            res += '1';
        }
        num /= 2;
        factor4++;
        counter++;
    }
    while (counter < 32) {
        if (factor4 == 4) {
            res += ' ';
            factor4 = 0;
        }
        res += '0';
        counter++;
        factor4++;
    }
    std::reverse(res.begin(), res.end());
    return res;
}

bool duplicateBitChecker(int num) {
    const int ALPHABET = 'z' - 'a' + 1;
    std::string str = toBinary(num);
    bool flag = false;
    for(const char &chr: str){
        if (chr == '1') {
            if (flag) return false;
            flag = true;
        }
    }
    return true;
}

bool palindromeBitVector(const std::string &string) {
    int checker = 0;
    // 0000 0000 0000 0000 0000 0000 0000 0000  -- 32 bit
    // &
    // 0000 0000 0000 0000 0000 0000 0000 0001
    // tactcoa
    // 0000 0000 0000 0000 0000 0000 0000 0001
    std::string str = string;
    for (char &chr: str) {
        if (std::isalnum(chr)) {
            chr = std::tolower(chr);
            int mask = (1 << (chr - 'a'));
            std::cout << chr << " " << mask << " " << toBinary(mask) << std::endl;
            checker = checker ^ mask;
            std::cout << "checker: " << checker << " " << toBinary(checker) << std::endl;
        }
    }
    std::cout << "result: " << toBinary(checker) << std::endl;
    int opposite = checker - 1;
    std::cout << toBinary(opposite) << std::endl;
    return checker == 0 || ((opposite & checker) == 0);
}
