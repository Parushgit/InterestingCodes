/*
 * Suppose you are building a module for measuring the health of physical appliances. You may want to measure network bandwidth, CPU usage and memory. Assume there is a system monitoring daemon that calls the update() method periodically in the following class.
 * We are interested in the maximum and average statistics within a window of time. Remember that update/maximum/average may be called at arbitrary times. You may assume that timestamps are monotonically non-decreasing.
 * size(3.0) -- time window
 * update({1.0, 10.0})
 * update({2.0, 10.0})
 * update({3.0, 10.0})
 * update({4.0, 10.0})
 * 
 * maximum(4.1) - maximum b/w 1.1 and 4.1 = 10.0
 * average(4.1) - average b/w 1.1 and 4.1 = 10.0
 */

#include <iostream>
#include <climits>
#include <deque>
#include <cfloat>
#include <math.h>

using namespace std;

class Ambient {
    float _timeWindow;
    float maxi = FLT_MIN;
    float low;
    float high;
    deque<pair<float, float> > dq;

public:
    Ambient(float timeWindow) {
        _timeWindow = timeWindow;
        low = 0.0;
        high = 0.0;
    }

    void update(float timeStamp, float metric) {

        // Push it from back
        dq.push_back(make_pair(timeStamp, metric));
        low = dq.front().first;
        high = dq.back().first;
        
        // Check if it is in range
        if (high - low >= _timeWindow) {
            // Pop it from front
            dq.pop_front();
            // Update the low
            low = dq.front().first;
        }
        return;
    }

    float average(float time) {
        int count = 0;
        float sum = 0.0;

        // Base case
        if (dq.size() == 0)
            return 0.0;
        if (dq.size() == 1)
            return dq.back().second;

        float newHigh = time;
        float newLow = time - _timeWindow;
        
        for (int i = 0; i < dq.size(); i++) {
            if (dq[i].first >= newLow && dq[i].first <= newHigh) {
                sum += dq[i].second;
                count++;
            }
        }
        return sum == 0.0 ? 0.0 : (float) sum / count;
    }

    float maximum(float time) {
        maxi = 0.0;
        // Base case
        if (dq.size() == 0)
            return maxi;

        float newHigh = time;
        float newLow = time - _timeWindow;
        
        for (int i = 0; i < dq.size(); i++) {
            if (dq[i].first >= newLow && dq[i].first <= newHigh) {
                if (dq[i].second > maxi) {
                    maxi = dq[i].second;
                }
            }
        }
        return maxi;
    }
};

int main() {
    Ambient *obj = new Ambient(3.0);
    // Basic test cases;
    cout<<"Basic test cases:"<<endl;
    cout<<"The maximum: "<<obj->maximum(1.0)<<endl;
    cout<<"The average: "<<obj->average(1.0)<<endl;
    cout<<endl;

    // Test case 1:
    obj->update(1.0, 50.0);
    cout<<"Test case 1:"<<endl;
    cout<<"The maximum: "<<obj->maximum(1.0)<<endl;
    cout<<"The average: "<<obj->average(1.0)<<endl;
    cout<<"The maximum: "<<obj->maximum(2.0)<<endl;
    cout<<"The maximum: "<<obj->maximum(3.0)<<endl;
    cout<<"The maximum: "<<obj->maximum(4.1)<<endl;
    cout<<endl;

    // Test case 2:
    obj->update(1.0, 50.0);
    obj->update(2.0, 100.0);
    obj->update(3.0, 150.0);
    cout<<"Test case 2:"<<endl;
    cout<<"The maximum: "<<obj->maximum(3.1)<<endl;
    cout<<"The average: "<<obj->average(3.1)<<endl;
    cout<<endl;

    // Test case 3:
    obj->update(4.0, 200.0);
    cout<<"Test case 3:"<<endl;
    cout<<"The maximum: "<<obj->maximum(4.1)<<endl;
    cout<<"The average: "<<obj->average(4.1)<<endl;
    cout<<endl;

    // Test case 4:
    cout<<"Test case 4:"<<endl;
    cout<<"The maximum: "<<obj->maximum(7.1)<<endl;
    cout<<"The average: "<<obj->average(7.1)<<endl;
    cout<<endl;

    // Test case 5:
    obj->update(7.0, 300.0);
    cout<<"Test case 5:"<<endl;
    cout<<"The maximum: "<<obj->maximum(7.0)<<endl;
    cout<<"The average: "<<obj->average(7.0)<<endl;
    cout<<endl;

    // Test case 6:
    cout<<"Test case 6:"<<endl;
    cout<<"The maximum: "<<obj->maximum(8.1)<<endl;
    cout<<"The average: "<<obj->average(8.1)<<endl;
    cout<<endl;

    // Test case 7:
    cout<<"Test case 7:"<<endl;
    cout<<"The maximum: "<<obj->maximum(11.1)<<endl;
    cout<<"The average: "<<obj->average(11.1)<<endl;
    cout<<endl;

    return 0;
}