/*
Complement of DNA String
*/

#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

string complementString(string s) {
    reverse(s.begin(), s.end());
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'T')
            s[i] = 'A';
        else if(s[i] == 'A')
            s[i] = 'T';
        else if(s[i] == 'C')
            s[i] = 'G';
        else if(s[i] == 'G')
            s[i] = 'C';
    }
    return s;
}

int main()
{
    cout<<complementString("ACCGGGTTTT")<<endl;
    return 0;
}