/*LeetCode locked question: (Bloomberg)
Q - 582
Given n processes, each process has a unique PID (process id) and its PPID (parent process id).

Each process only has one parent process, but may have one or more children processes. This is just like a tree structure. Only one process has PPID that is 0, which means this process has no parent process. All the PIDs will be distinct positive integers.

We use two list of integers to represent a list of processes, where the first list contains PID for each process and the second list contains the corresponding PPID.

Now given the two lists, and a PID representing a process you want to kill, return a list of PIDs of processes that will be killed in the end. You should assume that when a process is killed, all its children processes will be killed. No order is required for the final answer.

Example 1:
Input: 
pid =  [1, 3, 10, 5]
ppid = [3, 0, 5, 3]
kill = 5
Output: [5,10]
Explanation: 
           3
         /   \
        1     5
             /
            10
Kill 5 will also kill 10.
Note:
The given kill id is guaranteed to be one of the given PIDs.
n >= 1.
*/

#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

void killProcesses(vector<int>& ppid, vector<int>& pid, int kill, vector<int>& result) {
    result.push_back(kill);
    for(int i = 0; i < ppid.size(); i++) {
        if(kill == ppid[i]) {
            killProcesses(ppid, pid, pid[i], result);
        }
    }
}

void getAllChildren(unordered_map<int, vector<int> > umap, int kill, vector<int>& result) {
    if(umap.find(kill) != umap.end()) {
        vector<int> temp = umap[kill];
        for(int i = 0; i < temp.size(); i++) {
            result.push_back(temp[i]);
            getAllChildren(umap, temp[i], result);
        }
    }
}

void killProcessesUsingMap(vector<int>& ppid, vector<int>& pid, int kill, vector<int>& result) {
    unordered_map<int, vector<int> > umap;

    for(int i = 0; i < ppid.size(); i++) {
        if(umap.find(ppid[i]) == umap.end()) {
            vector<int> temp;
            temp.push_back(pid[i]);
            umap[ppid[i]] = temp;
        }
        else {
            vector<int> temp = umap[ppid[i]];
            temp.push_back(pid[i]);
            umap[ppid[i]] = temp;
        }
    }

    result.push_back(kill);
    getAllChildren(umap, kill, result);
}

void printVector(vector<int> vec) {
    for(int i = 0; i < vec.size(); i++) {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<int> ppid;
    vector<int> pid;
    ppid.push_back(0);
    ppid.push_back(2);
    ppid.push_back(2);
    ppid.push_back(5);
    ppid.push_back(5);
    ppid.push_back(3);
    ppid.push_back(9);
    ppid.push_back(9);

    pid.push_back(2);
    pid.push_back(1);
    pid.push_back(5);
    pid.push_back(3);
    pid.push_back(9);
    pid.push_back(7);
    pid.push_back(4);
    pid.push_back(8);

    int kill = 5;

    vector<int> result;

    //Naive way: Time complexity - O(pow(n,n))
    //killProcesses(ppid, pid, kill, result);

    //Efficient way: Time complexity - O(N), Space complexity - O(N)
    killProcessesUsingMap(ppid, pid, kill, result);

    printVector(result);
}