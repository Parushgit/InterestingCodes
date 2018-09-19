class Solution {
public:
    string removeDupUtil(string str, int n)
    {
        int i, k = 0;
        for(i = 1; i < n; i++)
        {
            if(str[i-1] != str[i])
                str[k++] = str[i-1];
            else
            {
                while(str[i-1] == str[i])
                    i++;
            }
        }
        str[k++] = str[i-1];
        str[k] = '\0';
        if(k != n)
            return removeDupUtil(str, k);
        else
            return str;
    }
    string removeDuplicateLetters(string s) {
        int len = s.length();
        return removeDupUtil(s, len);
    }
};