class Solution {
    using pii = pair<int, int>;
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        map<char, vector<int>> matches;
        for(int i = 0; i < n; i++){
            matches[ring[i]].push_back(i);
        }
        vector<pii> pos_cost;
        pos_cost.push_back({0, 0});
        for(auto ch : key){
            vector<pii> pos_cost_curr;
            for(auto curr_pos : matches[ch]){
                int curr_cost = INT_MAX;
                for(auto [pos, cost] : pos_cost){
                    int clkwise_trans_cost = abs(pos - curr_pos);
                    int temp_cost = cost + min(clkwise_trans_cost, n - clkwise_trans_cost);
                    curr_cost = min(curr_cost, temp_cost);
                }
                pos_cost_curr.push_back({curr_pos, curr_cost});
            }
            pos_cost = pos_cost_curr;
        }
        int min_cost = INT_MAX;
        for(auto [pos, cost] : pos_cost){
            min_cost = min(min_cost, cost);
        }
        return min_cost + key.size();
    }
};