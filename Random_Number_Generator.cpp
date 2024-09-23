#include <bits/stdc++.h>
using namespace std;
int main() {
    // Get the current time since epoch as seed
    // Initialize Mersenne Twister random number generator with the seed
    mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());

    // Define the range for random numbers
    uniform_int_distribution<int> dist(1, 100);  // Range: 1 to 100
    // Generate random numbers
    for (int i = 0; i < 5; ++i) {
        cout << "Random Number " << i + 1 << ": " << dist(rng) << endl;
    }
    return 0;
}
