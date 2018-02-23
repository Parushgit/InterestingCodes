#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<unordered_set>

using namespace std;

int getLengthOfTheShortestVacation(int A[], int actualUnique, int start, int computedUnique, int len)
{
    map<int,bool>m;
    map<int,bool>::iterator it; 

    //Maximum size of the window
    int sizeOfWindow=100000;
    int end = 0;

    for(int i = start; i < len; i++)
    {
        it = m.find(A[i]);
        if(it != m.end())
        {
            if(A[start] == A[i])
                start = start + 1;
            end = i;
        }
        else
        {
            m[A[i]]= true;
            end=i;
            computedUnique++;
        }

        //When all the cities have been visited, compute the vacation time
        if(computedUnique == actualUnique)
        {
            if(end - start < sizeOfWindow)
                sizeOfWindow = end - start + 1;  
            end++;
            return sizeOfWindow;
        }  
    }
    return 100000;
}
int main()
{

    int A[] = {10,1,1,2,2,1,3}; 

    const size_t len = sizeof(A) / sizeof(A[0]);
    unordered_set<int> s(A, A + len);
    int actualUnique = s.size(); // Number of unique elements

    int sizeOfWindow = 100000;
    int output_sizeOfWindow;
    int start=0, end=0;

    for(int i=0;i < len; i++) // Looping through the array
    {
        output_sizeOfWindow = getLengthOfTheShortestVacation(A, actualUnique, i, 0, len);

        if(output_sizeOfWindow < sizeOfWindow)  //If the number of days are shorter than the previously calculated value of the number of days
            sizeOfWindow = output_sizeOfWindow;
    }
	printf("window size is %d\n", sizeOfWindow);
    return 0;
}