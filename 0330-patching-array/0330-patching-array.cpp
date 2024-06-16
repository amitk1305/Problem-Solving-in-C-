class Solution {
public:
    //find sum till ith index for sum < n if sum for k (k E [1,n]) not found k <= n than add k in our array and increment no of elemrnt in our addition array by 1.
int minPatches(vector<int>& nums, int n) {
        long long int sum = 0, cnt = 0, i = 0;
        while(sum < n){
            // cout<<sum<<" ";
            if(i<nums.size() && nums[i]<=sum+1){
                sum += nums[i++];
            }else{
                cnt++;
                sum += sum+1;
            }
        }
        return cnt;
    }
};