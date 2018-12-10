#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int i = 0, j = -1, maxLen = 0;
        for (int k = 1; k < s.length(); k++) {
            if (s[k] == s[k - 1]) continue;
            if (j >= 0 && s[j] != s[k]) {
                maxLen = max(k - i, maxLen);
                i = j + 1;
            }
            j = k - 1;
        }
        return max((int)(s.length() - i), maxLen);
    }
};


int main() {
    Solution sol;
    string s("eceba");
    cout << sol.lengthOfLongestSubstringTwoDistinct(s) << endl;
    return 0;
}