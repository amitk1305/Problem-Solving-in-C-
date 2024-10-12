#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int, int> events;
        
        // Mark the start and end events
        for (auto& interval : intervals) {
            events[interval[0]]++; // Start of an interval
            events[interval[1] + 1]--; // End of an interval
        }
        
        int currentGroups = 0;
        int maxGroups = 0;
        
        // Sweep line to calculate the maximum number of overlapping intervals
        for (auto& event : events) {
            currentGroups += event.second;
            maxGroups = max(maxGroups, currentGroups);
        }
        
        return maxGroups;
    }
};
