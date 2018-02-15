#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
bool pangram(string input)
{
    vector<bool> hash(26, false);
    int position;
    for(int i = 0; i<input.length(); i++)
    {
        if(input[i] >= 'A' && input[i] <= 'Z')  //FOR UPPER CASE
            position = input[i] - 'A';          //TO GET THE INDEX OF CHARACTER IN HASH VECTOR
        if(input[i] >= 'a' && input[i] <= 'z')  //FOR LOWER CASE
            position = input[i] - 'a';          //TO GET THE INDEX OF CHARACTER IN HASH VECTOR
        hash[position] = true;
    }

    for(int i = 0; i <hash.size(); i++)         //IF ANY HASH VALUE IS FALSE THAT MEANS THAT CHARACTER IS NOT AVAILABLE IN THE INPUT
        if(hash[i] == false)
            return false;
    return true;
}
int main()
{
    string input;
    cout<<"Enter the input string"<<endl;
    cin >> input;
    if(pangram(input) == true)
        cout<<"Wuhu!"<<endl;
    else 
        cout<<"Sorry!"<<endl;
}