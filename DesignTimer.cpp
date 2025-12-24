#include<bits/stdc++.h>
using namespace std;

/**
* Design a Timer class with the following methods:
* private void setTimer(int timestamp): Sets a timer, which calls handleTimer when it expires. If called again, 
*   it overrides the previous timers, meaning only one timer is kept at any time.
* private void handleTimer(): Handles the timer expiration event.
* private getCurrentTime(): Returns the current time.
* public void setNewTimer(int timestamp): Allows the user to set multiple timers.
*Only setNewTimer can be called by the user.
* Implement these four methods in the Timer class, and provide sample code for setNewTimer.
*/
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
