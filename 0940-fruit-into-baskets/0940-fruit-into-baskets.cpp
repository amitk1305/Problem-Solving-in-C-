class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans=0, n=fruits.size(),left=0;
        vector<int>mp(n+2,0), curElements;
        for(int right=0;right<n;right++){
           mp[fruits[right]]++;
           if(mp[fruits[right]]==1)curElements.push_back(fruits[right]);
           while(curElements.size()>2){
             mp[fruits[left]]--;
             if(mp[fruits[left]]==0) curElements.erase(find(curElements.begin(), curElements.end(), fruits[left]));
             left++;
           }
           int curAns=0;
           for(auto x:curElements) curAns+=mp[x];
           ans=max(ans, curAns);
        }
        return ans;
    }
};