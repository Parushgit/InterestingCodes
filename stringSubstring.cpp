
/* 
Given two strings, find if first string is a subsequence of second
Given two strings str1 and str2, find if str1 is a subsequence of str2. A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements (source: wiki). Expected time complexity is linear.
*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<string.h>
using namespace std;

bool isSubString(string s1, string s2, int m, int n)
{
    if(m == 0)
        return true;
    if(n == 0)
        return false;
    if(s2[n-1] == s1[m-1])
        return isSubString(s1, s2, m-1, n-1);
    return isSubString(s1, s2, m, n-1);
}

int main()
{
    string s1, s2;
    cout<<"Enter string 1"<<endl;
    cin>>s1;
    cout<<"Enter string 2"<<endl;
    cin>>s2;
        isSubString(s1, s2, s1.length(), s2.length()) ? cout<<"Is a substring\n" : cout<<"Is not a substring\n";
    return 0;
}