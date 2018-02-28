
// Print all permutations with repetition of characters
// Given a string of length n, print all permutation of the given string. Repetition of characters is allowed. Print these permutations in lexicographically sorted order 
// Examples:

// Input: AB
// Ouput: All permutations of AB with repetition are:
//       AA
//       AB
//       BA
//       BB

// Input: ABC
// Output: All permutations of ABC with repetition are:
//        AAA
//        AAB
//        AAC
//        ABA
//        ...
//        ...
//        CCB
//        CCC

#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>

using namespace std;

void permutation(string str, char *data, int last, int index, int len)
{
    for(int i = 0; i < len; i++)
    {
        data[index] = str[i];
        if(index == last)
            cout << data << endl;
        else 
            permutation(str, data, last, index + 1, len);
    }
}
int main()
{
    string str = "AB";
    int len = str.length();
    char *data = (char *)malloc (sizeof(char) * (len + 1));
    data[len] = '\0';

    sort(str.begin(), str.end());
    
    permutation(str, data, len - 1, 0, len);

}