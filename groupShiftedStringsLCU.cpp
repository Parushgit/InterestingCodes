/*
LeetCode locked question: (Uber)
Q - 249
Given a string, we can “shift” each of its letter to its successive letter, for example: “abc” -> “bcd”. We can keep “shifting” which forms the sequence:

“abc” -> “bcd” -> … -> “xyz” Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

For example,
Given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
Return:
[
	["abc","bcd","xyz"],
	["az","ba"],  
	["acef"],  
	["a","z"]
] Note: For the return value, each inner list's elements must follow the lexicographic order.
*/

#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>

using namespace std;

string getDiffInString(string word) {
    if(word.length() == 1) {
        return "-1";
    }
    string res = "" ;
    int count = 0;
    for(int i = 1; i < word.length(); i++) {
        res += to_string(word[i] - word[i-1]);
    }
    return res;
}
void printGroupOfStrings(vector<string> input) {
    map<string, vector<string> > umap;
    string getDiff;
    for(auto word: input) {
        getDiff = getDiffInString(word);
        umap[getDiff].push_back(word);
    }

    for(map<string, vector<string> >::iterator it = umap.begin(); it != umap.end(); it++) {
        vector<string> temp = it->second;
        for(int i = 0; i < temp.size(); i++) {
            cout<<temp[i]<<"\t";
        }
        cout<<endl;
    }
}
int main() {
    vector<string> input;
    input.push_back("abc");
    input.push_back("bcd");
    input.push_back("xyz");
    input.push_back("a");
    input.push_back("z");
    input.push_back("ab");
    input.push_back("de");
    input.push_back("acde");
    printGroupOfStrings(input);
    return 0;
}