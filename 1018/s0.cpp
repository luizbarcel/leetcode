#include <iostream>
#include <vector>

/*
- Example 1:

Input: nums = [0,1,1]
Output: [true,false,false]
Explanation: The input numbers in binary are 0, 01, 011; which are 0, 1, and 3 in base-10.
Only the first number is divisible by 5, so answer[0] is true.

- Example 2:

Input: nums = [1,1,1]
Output: [false,false,false]

*/


class Solution {
public:
    std::vector<bool> prefixesDivBy5(std::vector<int>& nums) {
        int size = nums.size();
        std::vector<bool> result;
        int currentRemainder = 0;

        for (int i = 0; i < size; ++i)
        {
            if (i == 0)
            {
                currentRemainder = nums[i] % 5;
            }
            else
            {
                currentRemainder = ((currentRemainder << 1) + nums[i]) % 5;
            }

            result.push_back(currentRemainder == 0);
        }

        return (result);
    }
};

int main(void) {
    Solution sol;

    // std::vector<int> input = {0, 1, 1};
    // std::vector<int> input = {1, 1, 1};

    std::vector<int> input = {1,0,1,1,1,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,1,0,0,1,1,1,1,1,1,0,1,1,0,1,0,0,0,0,0,0,1,0,1,1,1,0,0,1,0};

    std::vector<bool> result = sol.prefixesDivBy5(input);
    
    for (auto elem : result)
    {
        std::cout << elem << std::endl;
    }

    return(0);
}
