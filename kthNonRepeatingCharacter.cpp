#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<unordered_set>

using namespace std;

int kthNonRepeatingCharacter(string str, int k)
{
    int count = 0;
    for(int i = 0; i < str.length(); i++)
    {
        int j = 0, flag = 1;
        while(str[j] != '\0')
        {
            if(i != j && str[i] == str[j])
            {
                flag = 0;
                break;
            }
            j++;
        }
        if(flag == 1)
        {
            count ++;
            if(count == k)
                return i;
        }
    }
    return -1;
}

int main()
{
    string str = "hellohowareyou";
    int k = 3;
    int output = kthNonRepeatingCharacter(str, k);
    if(output == -1)
        cout<<"No character"<<endl;
    else   
        cout<<"The kth one is: "<< str[output]<<endl;
    return 0;
}