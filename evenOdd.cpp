#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>

using namespace std;

int sumOfVectors(vector<int> vec, string flag) {
    int sum = 0;
    if(flag == "even") {
        for(int i = 0; i < vec.size(); i += 2) {
            sum += vec[i];
        } 
    }
    else {
        for(int i = 1; i < vec.size(); i += 2) {
            sum += vec[i];
        } 
    }
    return sum;   
}
bool oddEven(string a, vector<int> a1, vector<int> a2) {
    int arr1Sum = sumOfVectors(a1, a);
    int arr2Sum = sumOfVectors(a2, a);
    return arr1Sum < arr2Sum;
}
int main()
{
    vector<int> a1;
    a1.push_back(10);
    a1.push_back(20);
    a1.push_back(30);
    a1.push_back(40);
    a1.push_back(50);
    a1.push_back(60);

    vector<int> a2;
    a2.push_back(11);
    a2.push_back(12);
    a2.push_back(13);
    a2.push_back(14);
    a2.push_back(15);
    a2.push_back(16);

    cout<<oddEven("even", a1, a2)<<endl;
    return 0;
}