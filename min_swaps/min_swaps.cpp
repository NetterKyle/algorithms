#include <iostream>
#include <vector>
#include <numeric>

int minSwaps(std::vector<int> data) {
    std::vector<int> partial_sums(data.size()); // Intialize vector for storing partial sums
    int max_total_ones = partial_sums.back(); // Find total number of ones
    int window_size = max_total_ones; // Assign window size to total number of ones

    // Return 0 if there are no zeros
    if(window_size == 0)
        return 0;
    
    // Find number of ones in first window
    int max_ones_first_window = data[window_size-1];

    // Initialize maximum one window to first window
    int max_ones_in_any_window = max_ones_first_window;

    // Find window with maximum number of ones
    for(int i = window_size; i < data.size(); ++i) {
        int max_ones_previous_window = partial_sums[i-window_size]; // Find total ones in previous window
        int max_ones_current_window = partial_sums[i]; // Find total ones in current window
        max_ones_in_any_window = std::max(max_ones_in_any_window,  max_ones_current_window - max_ones_previous_window); // Take the max of the current and previous window maxes
    }
    return max_total_ones - max_ones_in_any_window; // Find how many ones the window with the maximum number of ones would need to swap in order to collect all ones
}