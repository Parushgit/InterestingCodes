#include<iostream>
#include<stdio.h>
#include<unordered_map>

using namespace std;

bool ifPalindrome(string s) {
    int i = 0, j = s.length() - 1;
    while(i < j) {
        if(s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

bool shouldSwap(string input, int i, int j) {
    for(int a = i; a < j; a++) {
        if(input[a] == input[j])
            return false;
    }
    return true;
}

void getAllPermutations(string &input, int begin, int end) {
    if(begin == end) {
        //cout<<input<<endl;
        if(ifPalindrome(input))
            cout<<input<<endl;
    }

    for(int i = begin; i <= end; i++) {
        bool check = shouldSwap(input, begin, i);
        if(check) {
            swap(input[begin], input[i]);
            getAllPermutations(input, begin+1, end);
            swap(input[begin], input[i]);
        }
    }
}
void palindromicPermutations(string input) {
    int len = input.length();
    unordered_map<char, int> umap;

    for(int i = 0; i < input.length(); i++) {
        umap[input[i] - 'a']++;
    }

    int odd = 0;

    for (int i = 0; i < input.length(); i++) 
        if (umap[i] % 2 == 1) 
            odd++;

    /* Palindrome condition : 
    if length is odd then only one letter's frequency must be odd 
    if length is even no letter should have odd frequency */
    if ((len % 2 == 1 && odd == 1 ) || (len %2 == 0 && odd == 0)) {
        cout<<"Possible permutations are:"<<endl;
    }
    else {
        cout<<"No permutations are possible"<<endl;
        return;
    } 

    getAllPermutations(input, 0, input.length() - 1);

}
int main() {
    string input = "aabcb";
    palindromicPermutations(input);
    return 0;
}