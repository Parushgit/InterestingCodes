/*
LeetCode locked question: (Uber)
Q - 266
Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.
Hint:

Consider the palindromes of odd vs even length. What difference do you notice? Count the frequency of each character. If each character occurs even number of times, then it must be a palindrome. How about character which occurs odd number of times?
*/

/*
Solutuion : Given string will be palindrome if all the characters count are even in number and if all are even then there can be one more character count
which is odd. Hence check both the conditions.
*/
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
bool palindromePermutation(string input) {
    if(input.length() == 0) {
        return true;
    }

    unordered_map<int, int> umap;
    int count_odd = 0;
    for(int i = 0; i < input.length(); i++) {
        umap[input[i]]++;
    }

    for(unordered_map<int, int>::iterator it = umap.begin(); it != umap.end(); it++) {
        if(it->second % 2 != 0)
            count_odd++;
    }
    return count_odd <= 1;
}

int main() {
    cout<<palindromePermutation("carerac")<<endl;
    return 0;
}