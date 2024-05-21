class Solution {
public:

    void subsetsUntil(vector<int>& v, vector<vector<int>>& ans, vector<int> &subset, int index){
        ans.push_back(subset);
        for(int i=index; i<v.size(); i++){
            subset.push_back(v[i]);
            subsetsUntil(v,ans,subset,i+1);
            subset.pop_back();
        }
    }

    vector<vector<int>> Subset(vector<int> &v){
        vector<int> subset;
        vector<vector<int> >ans;
        int index =0;
        subsetsUntil(v,ans,subset,index);

        return ans;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans = Subset(nums);
        return ans;
    }
};