/*
LeetCode unlocked question:
Q - 161
Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters. The input string does not contain leading or trailing spaces and the words are always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".
Could you do it in-place without allocating extra space?
*/

#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

string revWords(string s) {
    int init = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ' ' || i == s.length() - 1) {
            if(i == s.length() - 1)
                i++;
            reverse(s.begin() + init, s.begin() + i);
            init = i + 1;
        }
    }
    reverse(s.begin(), s.end());
    return s;
}
int main() {
    string s = "Hey! You are awesome";
    cout<<revWords(s)<<endl;
    return 0;
}