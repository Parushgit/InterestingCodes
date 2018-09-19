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
    cout<<palindromePermutation("aabc")<<endl;
    return 0;
}