#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<pair<int, int>> events;
    for (auto& t : trips) {
        int num = t[0], from = t[1], to = t[2];
        events.push_back({from, num});   // pickup
        events.push_back({to, -num});    // dropoff
    }
    sort(events.begin(), events.end());
    int current = 0;
    for (auto& e : events) {
        current += e.second;
        if (current > capacity) return false;
    }
    return true;
}
int main() {
    vector<vector<int>> trips = {
        {2, 1, 5},
        {3, 3, 7}
    };
    int capacity = 4;
    if (carPooling(trips, capacity))
        cout << "Car pooling possible within capacity.\n";
    else
        cout << "Car pooling NOT possible (capacity exceeded).\n";
    return 0;
}
