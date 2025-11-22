#include <iostream>
#include <climits>

class Solution {
public:
    int myAtoi(std::string s) {
        bool integerStartPosition = false;
        bool isNegative = false;
        std::string intStr;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ' && integerStartPosition == false)
            {
                continue;
            }
            else if (s[i] == '-' && integerStartPosition == false)
            {
                isNegative = true;
                integerStartPosition = true;
                
            }
            else if (s[i] == '+' && integerStartPosition == false)
            {
                isNegative = false;
                integerStartPosition = true;
                
            }
            else if (s[i] >= 48 && s[i] <= 57)
            {
                integerStartPosition = true;
                intStr.push_back(s[i]);
            }
            else
            {
                std::cout << "break, i = " << i << std::endl;
                break;
            }
        }

        std::cout << "intStr: " << intStr << std::endl;

        if (intStr.size() == 0) {
            return(0);
        }

        int lastLeadingZero = -1;
        for (int i = 0; i < intStr.size() - 1; ++i)
        {
            if (intStr[i] == '0') {
                lastLeadingZero = i;
            }
            else
            {
                break;
            }
        }

        if (lastLeadingZero != - 1) {
            intStr = intStr.substr(lastLeadingZero + 1, intStr.size() - lastLeadingZero);
        }

        std::cout << "intStr eh: " << intStr << std::endl;

        long result = intStr[intStr.size() - 1] - '0';
        long powerOfTen = 10;

        if (intStr.size() >= 2) {
            for (int i = intStr.size() - 2; i >= 0; i--) {
                result += powerOfTen * (intStr[i] - '0');
                if ((result > INT_MAX || powerOfTen > INT_MAX) && !isNegative) {
                    return(INT_MAX);
                } else if ((result > INT_MAX || powerOfTen > INT_MAX) && isNegative) {
                    return(-INT_MAX - 1);
                }

                powerOfTen *= 10;
            }
        }

        if (isNegative) {
            result *= -1;
        }

        return(result);
    }
};

int main(void) {
    Solution sol;
    std::string input("20000000000000000000");
    int result = sol.myAtoi(input);
    std::cout << result << std::endl;

    return(0);
}