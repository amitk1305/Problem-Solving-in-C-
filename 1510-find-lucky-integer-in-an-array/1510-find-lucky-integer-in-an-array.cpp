class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        
        // Count frequency of each element
        for(int num : arr) {
            freq[num]++;
        }
        
        int maxLucky = -1;
        
        // Find lucky numbers and track maximum
        for(auto& pair : freq) {
            if(pair.first == pair.second) {
                maxLucky = max(maxLucky, pair.first);
            }
        }
        
        return maxLucky;
    }
};