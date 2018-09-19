#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
int CWheel(vector<int> queue, double AdmissionCost, double costToRunTheWheel) {

    if(queue.size() == 0)
        return 0;
    
    double totalRunningCost = 0.0;
    double totalAdmissionCost = 0.0;
    double profit;
    int enteringPersons, remainingPersons;
    double maximumProfit = -__DBL_MAX__;
    int maximumProfitIndex = 0;

    //Modify the queue
    for(int i = 0; i < queue.size(); i++) {
        if(queue.at(i) > 4) {
            int temp = queue.at(i);
            queue.at(i) = 4;
            remainingPersons = temp - 4;
            if(i+1 < queue.size())
                queue.at(i+1) += remainingPersons;
            else
                queue.push_back(remainingPersons);
        }
    }

    for(int i = 0; i < queue.size(); i++) {
        cout<<queue.at(i)<<"\t";
    }
    cout<<endl;

    profit = queue[0] * AdmissionCost;
    cout<<"Initial Profit:"<<profit<<endl;
    maximumProfit = profit;

    for(int i = 1; i < queue.size(); i++) {
        // totalRunningCost = costToRunTheWheel;
        // cout<<"Total Running Cost:"<<totalRunningCost<<endl;
        // totalAdmissionCost = queue.at(i) * AdmissionCost;
        // cout<<"Total Admission Cost:"<<totalAdmissionCost<<endl;
        profit += queue.at(i) * AdmissionCost - costToRunTheWheel;
        cout<<"Cumulative Profit:"<<profit<<endl;

        if (profit >= maximumProfit) {
            maximumProfit = profit;
            maximumProfitIndex = i;
        }
    }
    if(maximumProfit <= 0)
        return -1;
    return maximumProfitIndex;
}

int main() {
    vector<int> queue;
    queue.push_back(0);
    queue.push_back(1);
    queue.push_back(0);
    queue.push_back(0);
    queue.push_back(4);
    queue.push_back(4); 
    queue.push_back(5); 
    queue.push_back(4);
    cout<<CWheel(queue, 5, 10)<<endl;
}