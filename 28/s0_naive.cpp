#include <unordered_map>
#include <string>
#include <iostream>

/*
       s  s  s  a  a  a  s  s  a  a  s  a  s  a  d
map
s      0  1  2 -1 -1 -1  6  7 -1 -1 10 -1 12 -1 -1
sa    -1 -1 -1  3 -1 -1 -1 -1  8 -1 -1 11 -1 13 -1  
sad   -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 14

       h  e  l  l  o

map
l     -1 -1  2 -1 -1
ll    -1 -1 -1  3 -1

*/

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        std::unordered_map<int, int> mp;
        for (int i = 0; i < needle.size(); ++i)
        {
            mp[i] = -1;
        }

        for (int i = 0; i < haystack.size(); i++)
        {
            for (int j = needle.size() - 1; j >= 0; j--)
            {
                if (mp[j - 1] != -1 && haystack[i] == needle[j]) {
                    mp[j] = i;
                }
                else
                {
                    mp[j] = -1;
                }
            }

            if (mp[needle.size() - 1] != - 1) {
                return(mp[needle.size() - 1] - needle.size() + 1);
            }
        }

        return(-1);
    }
};


int main(void) {
    Solution sol;
    int result = sol.strStr("sssaaassaasasad", "sad");
    std::cout << result << std::endl;

    return(0);
}