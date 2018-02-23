// you can use includes, for example:
// #include <algorithm>
#include<algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

char ranks[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};

int getTheIndex(char element)
{
    for(int i = 0; i < 13; i++)
        if(element == ranks[i])
            return i;
    return -1;
}
int solution(string &A, string &B) {
    
    // write your code in C++14 (g++ 6.2.0)
    
    int num = 0, AIndex, BIndex;
    int len = A.length();
    
    for(int i = 0; i < len; i++)
    {
        AIndex = getTheIndex(A[i]);
        BIndex = getTheIndex(B[i]);
        //cout<<A[i]<<endl;
        
        if(AIndex > BIndex)
            num++;
    }
    return num;
}