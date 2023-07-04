#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string getModifiedString(string s) {
        // Base cases;
        if (s.length() == 0)
            return s;
        
        if (s.length() == 1)
            return s + "1";
        
        int count = 1;
        string result;
        for(int i = 0; i < s.length(); i++) {
            // Found the change
            if (i + 1 < s.length() && s[i] != s[i + 1]) {
                result += s[i] + to_string(count);
                count = 1;
            }
            // At the last character
            else if (i == s.length() - 1) {
                result += s[i] + to_string(count);
            }
            else {
                count++;
            }
        }
        return result;
    }
};

int main() {
    string result = "GeeeEEKKKss";
    Solution *obj = new Solution();
    cout<<"Output: "<<obj->getModifiedString(result)<<endl;

    string result2 = "eeeeeeeeeeeeee";
    cout<<"Output: "<<obj->getModifiedString(result2)<<endl;
    return 0;
}