#include<bits/stdc++.h>
using namespace std;

class Timer {

    private:
    // create a minHeap
    priority_queue<int, vector<int>, greater<int>> timerQueue;
    mutex mtx;
    int currentHardwareTarget = -1; // shows the next timer end time.
    bool isHardwareActive = false; // any upcoming timer??

    void setTimer(int timeStamp) {
        // Update our state tracking
        currentHardwareTarget = timeStamp;
        isHardwareActive = true;
    }

    int getCurrentTime() {
        // simulates chrono::system_clock::now();
        return 1; 
    }

    void handleTimer() {
        lock_guard<mutex> lock(mtx); // ensures one thread of execution

        if(timerQueue.empty()) return;

        timerQueue.pop(); // pop out expired timer

        if(!timerQueue.empty()) {
            setTimer(timerQueue.top());
        }
    }

    public: 
    void setNewTimer(int timeStamp) {
        lock_guard<mutex> lock(mtx);

        timerQueue.push(timeStamp);

        if(timerQueue.top() == timeStamp) {
            setTimer(timeStamp);
        }
    }



}