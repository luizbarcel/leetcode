#include <iostream>
#include <vector>
#include <unordered_map>

/*
Remainder by 5
nums      = [4,  5,  0, -2, -3,  1]
prefixes  = [4,  9,  0,  7,  4,  5]
remainder = [4,  4,  0,  2,  4,  0]

Remainder by 2
nums      = [-1,  2,  9]
prefixes  = [-1,  1, 10]
remainder = []

*/


class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) {
        std::unordered_map<int,int> prefixes = {{0, 1}};
        int size = nums.size();
        int cumSum = 0;
        int countSubArrays = 0;

        for (int i = 0; i < size; ++i)
        {
            cumSum += nums[i];
            int remainder = (cumSum % k) < 0 ? (cumSum % k) + k : cumSum % k; // Tricky part
            if (auto it = prefixes.find(remainder); it == prefixes.end())
            {
                prefixes[remainder] = 1;
            }
            else
            {
                countSubArrays += prefixes[remainder];
                prefixes[remainder] += 1;
            }
        }

        return(countSubArrays);
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