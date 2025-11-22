#include <iostream>
#include <vector>

/*
Fully functional now. Submitted in LeetCode without the comments.
Pay attention to condition in line 82

DP for problem input string

 
     b  a  b  a  d
b    1  1
a       1  1
b          1  1
a             1  1
d                1

*/

class Solution {
public:
    void updateResultIfBetter(int& globalMax, int& left, int& right, int current, int i, int j) {
        if (current >= globalMax)
        {
            globalMax = current;
            std::cout << "globalMax = " << globalMax << ", current = " << current << ", i=" << i << ", j= " << j << std::endl;
            left = i;
            right = j;
        }
    }

    std::string longestPalindrome(std::string s) {
        int size = s.size();
        std::vector<std::vector<int>> dp(size, std::vector<int>(size, 0));
        int globalMax = 1;
        int left = 0;
        int right = 0;

        for (int curLen = 1; curLen <= s.size(); ++curLen)
        {
            std::cout << "curLen= " << curLen << std::endl;

            // no need to fill in lower left diagonal
            for (int i = 0; i < s.size() - curLen + 1; ++i)
            {
                int j = i + curLen - 1;

                std::cout << "i = " << i << ", j = " << j << std::endl;

                if (i == j)
                {
                    dp[i][j] = 1; // string of size one is palindrome
                }
                else if (j == i + 1)
                {
                    if (s[i] == s[j])
                    {
                        dp[i][j] = 2; // For size 2, two characters must be equal
                    }
                    else
                    {
                        dp[i][j] = 0;
                    }
                }
                else if (j == i + 2)
                {
                    if (s[i] == s[j])
                    {
                        dp[i][j] = 3;
                    }
                    else
                    {
                        dp[i][j] = 0;
                    }
                }
                else
                {
                    if (s[i] != s[j])
                    {
                        dp[i][j] = 0;
                    }
                    else if (dp[i + 1][j - 1] != 0)
                    {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                }

                updateResultIfBetter(globalMax, left, right, dp[i][j], i, j);
            }
        }

        std::cout << "left=" << left << ", right=" << right << std::endl;
        std::cout << right - left << std::endl;
        std::cout << "globalMax = " << globalMax << std::endl;
        for (int i = 0; i < dp.size(); ++i) {
            for (int j = 0; j < dp[i].size(); ++j) {
                std::cout << dp[i][j] << "  ";
            }
            std::cout << std::endl;
        }

        return(s.substr(left, globalMax));
    }
};


int main(void) {
    Solution sol;

    // std::string input("babad");
    // std::string input("a");
    std::string input("aacabdkacaa");
    

    std::string result = sol.longestPalindrome(input);
    std::cout << result << std::endl;

    return(0);
}