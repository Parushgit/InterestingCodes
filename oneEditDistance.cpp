/*LeetCode unlocked question:
Q - 161
Given two strings S and T, determine if they are both one edit distance apart.
*/

#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

bool isOneEditDistancePossible(string a, string b) {
    int diff, m, n, i, j;
    m = a.length();
    n = b.length();
    int count = 0;

    diff = abs(m-n);
    if(diff > 1)
        return false;
    
    while(i < m && j < n) {
        if(a[i] != b[j]) {
            if(count > 1)
                return true;
            else if(m > n)
                i++;
            else if(n < m)
                j++;
            else {
                i++;
                j++;
            }
            count++; 
        }
        i++;
        j++;
    }

    if(i < m || j < n)
        count++;
    
    return count == 1;
}
int main()
{
    string a = "geekss";
    string b = "geaks";
    cout<<isOneEditDistancePossible(a, b)<<endl;
    return 0;
}