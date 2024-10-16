#include <iostream>
#include "min_swaps.cpp"
#include <vector>
int main() {
    std::vector<int> data = {1, 0, 1, 0, 1};
    int answer = minSwaps(data);
    std::cout << answer;
}