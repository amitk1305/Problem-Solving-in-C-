class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int>cnt(101,0);
        int res=0;
        for(int i:nums)
            cnt[i]+=1;
        int maxi=*max_element(cnt.begin(),cnt.end());
        for(int i:cnt){
            if(i==maxi)
                res+=maxi;
        }
        return res;
    }
};