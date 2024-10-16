#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> timeTaken(vector<int>& arrival, vector<int>& state) {
    int num_transits = state.size();
    vector<int> transit_times (num_transits);
    vector<int> priority (num_transits);
    vector<bool> transited (num_transits);

    int time = 0;
    int num_transited = 0;
    int previous_action = 2;
    while (num_transited < num_transits) {
        for (int i=0; i<priority.size(); i++) {
            if (time >= arrival[i] && transited[i] == 0) {
                priority[i] = 1;
                if (previous_action == 2 && state[i] == 1) {
                    priority[i] += 1; // Higher priority to exits if no previous action
                }
                else if (previous_action == 0 && state[i] == 0) {
                    priority[i] += 1; // Higher priority to entrances if entrance was previous action
                }
                else if (previous_action == 1 && state[i] ==1) {
                    priority[i] += 1; // Higher priority to exits if exit was previous action
                }
            }
        }

        vector<int>::iterator highest_priority = max_element(priority.begin(), priority.end()); // Iterator to highest priority element
        int winner_index = distance(priority.begin(), highest_priority); // Find index of highest priority element
        
        // Only allow transit if person has arrived
        if (arrival[winner_index] <= time) {
            transited[winner_index] = 1; // Indicate person has transited
            transit_times[winner_index] = time; // Set time of person's transit
            num_transited++; // Increment number of transits
            priority[winner_index] = -1; // Drop priority out of range
            previous_action = state[winner_index]; // Set previous action for next time
        }
        time++; // Increment time
    }
    return transit_times;
}

        // for (int i=0; i<arrival.size(); i++) {
        //     int num_desired_transits = count(arrival.begin(), arrival.end(), i);
        //     if (num_desired_transits == 1) {
        //         timeTaken[i] = arrival[i];
        //     }
        //     else {
        //         if arrival[i] 
        //     }
        // }
    