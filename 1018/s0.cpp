#include <iostream>
#include <vector>

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        std::vector<bool> result;
        int currentNumber = nums[0];

        if (nums[0] == 0)
        {
            result.push_back(true);
        }
        else
        {
            result.push_back(false);
        }

        int currentPower = 2;

        for (int i = 1; i < nums.size(); ++i)
        {
            currentNumber += currentPower * nums[i];
            std::cout << currentNumber << std::endl;
            bool currentResult = currentNumber % 5 == 0 ? true : false;
            result.push_back(currentResult);
            currentPower *= 2;
        }

        return (result);
    }
};

int main(void) {
    Solution sol;

    std::vector<int> input = {-1,2,9};
    int k = 2;

    // std::vector<int> input = {4,  5,  0, -2, -3,  1};
    // int k = 5;

    int result = sol.subarraysDivByK(input, k);
    std::cout << result << std::endl;

    return(0);
}
