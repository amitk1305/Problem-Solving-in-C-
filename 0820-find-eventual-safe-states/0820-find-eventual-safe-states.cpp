class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        int n = graph.size();
        unordered_map<int,bool> safe;
        for(int i = 0; i < n; i++){
            if (dfs(graph, i, safe)) res.push_back(i);
        }
        return res;
    }
    bool dfs(vector<vector<int>>& graph,int i,unordered_map<int,bool>& safe){
        if(safe.find(i) != safe.end()) return safe[i];
        safe[i] = false;
        for(int nbr : graph[i]){
            if (!dfs(graph, nbr, safe))
            return false;
        }
        safe[i] = true;
        return true;
    }
};