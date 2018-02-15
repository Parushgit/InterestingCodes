#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

//BELOW APPROACH IS TAKEN IN ORDER TO REDUCE THE COMPLEXITY AND MAKE IT O(ROOT(N)). WE DON'T NEED TO COMPARE WITH ALL N VALUES SINCE PRIME NUMBER IS G
//GENERALLY IN MULTIPLES OF 6J+I
bool isPrimeNumber(int n)
{
    if(n <= 1) 
        return false;
    if(n <= 3)  
        return true;
 
    if(n%2 == 0 || n%3 == 0) 
        return false;
 
    for (int i=5; i*i <= n; i = i+6)
        if (n % i == 0 || n % (i+2) == 0)
           return false;
    return true;
}

void calculateSumOfDigits(int input)
{
    int in = input;
    int sum = 0;
    while(input >= 1)
    {
        sum = sum + input % 10; // TO GET THE DIGIT
        input = input / 10; // TO REDUCE THE NUMBER FOR NEXT COMPUTATION
    }

    if(isPrimeNumber(sum))
        cout << sum << endl;
    else
    {
        //DO NOTHING
    }
}
int main()
{
    for(int i = 1; i <= 100000; i++)
    {
        calculateSumOfDigits(i);
    }
}