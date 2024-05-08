class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& arr) {

        vector<int>score = arr;

        sort(score.begin(), score.end(), greater<int>());
        unordered_map<int, string>mpp;

        for(int i = 0; i<score.size(); i++){
            if(i == 0){
                mpp[score[i]] = "Gold Medal";
            }else if(i == 1){
                mpp[score[i]] = "Silver Medal";
            }else if(i == 2){
                mpp[score[i]] = "Bronze Medal";
            }else{
                mpp[score[i]] = to_string(i+1);
            }
        }

        vector<string>ans;
        for(int i = 0; i<arr.size(); i++){
            if(mpp.find(arr[i]) != mpp.end()){
                ans.push_back(mpp[arr[i]]);
            }
        }


        return ans;
    }
};