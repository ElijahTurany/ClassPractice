#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Base7Number {
    public:
        int getBase7() {
            return base7;
        }
        Base7Number(int base10In) {
            base10 = base10In;
            base7 = toBase7();
        }
    private:
        int base10;
        int base7 = 0;
        int toBase7() {
            int quotient;
            int remainder;
            vector<int> remainderNums;

            quotient = base10;
            while (true) {
                remainder = (quotient % 7);
                quotient = (quotient / 7);
                remainderNums.push_back(remainder);
                if (quotient == 0) {
                    break;
                }
            }

            for (int i = remainderNums.size() - 1; i >= 0; i--) {
                base7 *= 10;
                base7 += remainderNums[i];
            }

            return base7;
        }
};

int base10ToBase7(int base10In) {
    Base7Number num{ base10In };
    return num.getBase7();
}

