#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;
int main()
{
    long long prev3, prev2, prev1; 
    long long output;

    prev3 = 1;
    prev2 = 1;
    prev1 = 2;

    long long n = pow(10,9);

    for(int i = 4; i <=n; i++) {
        output = (prev1 + prev3) % 1000000007;
        prev3 = prev2;
        prev2 = prev1;
        prev1 = output;
    }

    cout<<output<<endl;
}