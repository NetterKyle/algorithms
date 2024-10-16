#include <iostream>
#include <vector>
#include "priority_queue.cpp"

using namespace std;
int main() {
    vector<int> arrival = {0,1,1,2,4};
    vector<int> state = {0,1,0,0,1};

    vector<int> transitTimes = timeTaken(arrival, state);

    for (int i=0; i < transitTimes.size(); i++) {
        cout << transitTimes[i] << " ";
    }
}