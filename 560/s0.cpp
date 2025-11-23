#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraySum(std::vector<int>& nums, int k) {

        std::unordered_map<int, int> prefixes = {{0, 1}};
        int cumSum = 0;
        int subArrayCount = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            cumSum += nums[i];

            if (auto it = prefixes.find(cumSum - k); it != prefixes.end())
            {
                subArrayCount += it->second;
            }

            if (prefixes.find(cumSum) == prefixes.end())
            {
                prefixes[cumSum] = 1;
            }
            else
            {
                prefixes[cumSum] += 1;
            }
        }

        return(subArrayCount);
    }
};

int main(void) {
    Solution sol;

    std::vector<int> input = {1};
    int k = 0;

    int result = sol.subarraySum(input, k);
    std::cout << result << std::endl;

    return(0);
}