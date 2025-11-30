#include <iostream>
#include <vector>
#include <unordered_map>

/*
input      = [3,  1,  4,  2]
prefixes   = [3,  4,  8, 10]
remainders = [3,  4,  2,  4]


input      = [6,  3,  5,  2]
prefixes   = [6,  9, 14, 16]
remainders = [6,  0,  5,  7]

*/


class Solution {
public:
    int minSubarray(std::vector<int>& nums, int p) {
        int size = nums.size();
        long long prefixSum = 0;
        long long numsSum = 0;
        for (int i = 0; i < size; ++i)
        {
            numsSum += nums[i];
        }

        int remainder = numsSum % p;

        if (remainder == 0)
        {
            return (0);
        }

        std::unordered_map<int, int> prefixes = { {0, - 1} };
        int result = size;

        for (int i = 0; i < size; ++i)
        {
            prefixSum += nums[i];
            int currentRemainder = prefixSum % p ;
            int needed = (currentRemainder - remainder + p) % p;

            if (prefixes.count(needed)) {
                result = std::min(result, i - prefixes[needed]);
            }

            prefixes[currentRemainder] = i;
        }


        return (result == size ? -1 : result);
    }
};

int main(void) {
    Solution sol;

    // Test case 1
    // std::vector<int> nums = {3,1,4,2};
    // int result = sol.minSubarray(nums, 6);

    // Test case 2
    // std::vector<int> nums = {6,3,5,2};
    // int result = sol.minSubarray(nums, 9);
    
    // Test case 3
    std::vector<int> nums = {1,2,3};
    int result = sol.minSubarray(nums, 3);

    // Test case 4
    // std::vector<int> nums = {1000000000,1000000000,1000000000};
    // int result = sol.minSubarray(nums, 3);

    // Test case 5
    // std::vector<int> nums = {26,19,11,14,18,4,7,1,30,23,19,8,10,6,26,3};
    // int result = sol.minSubarray(nums, 26);

    // Test case 6
    // std::vector<int> nums = {8,32,31,18,34,20,21,13,1,27,23,22,11,15,30,4,2};
    // int result = sol.minSubarray(nums, 148);
    

    std::cout << result << std::endl;

    return(0);
}
