#include <iostream>
#include <vector>
#include <unordered_map>

/*
nums     = [23,  2,  6,  4,  7]
prefixes = [23, 25, 31, 35, 42]

nums      = [2,  4,  3]
prefixes  = [2,  6,  9]
remainder = [2,  0,  3]

*/

class Solution {
public:
    bool checkSubarraySum(std::vector<int>& nums, int k) {
        int size = nums.size();
        std::unordered_map<int, int> prefixes = {{0, -1}};
        int cumSum = 0;

        for (int i = 0; i < size; ++i)
        {
            cumSum += nums[i];
            int remainder = cumSum % k;
            if (auto it = prefixes.find(remainder); it == prefixes.end())
            {
                prefixes[remainder] = i;
            }
            else
            {
                if ((i - it->second >= 2))
                {
                    return(true);
                }
            }
        }

        return(false);
    }
};

int main(void) {
    Solution sol;

    std::vector<int> input = {2,4,3};
    int k = 6;

    int result = sol.checkSubarraySum(input, k);
    std::cout << result << std::endl;

    return(0);
}