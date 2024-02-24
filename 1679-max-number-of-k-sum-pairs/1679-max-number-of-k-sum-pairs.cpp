class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        // using two poiners approach;
        int i=0;
        int j=nums.size()-1;
        int count=0;
        while(j>i)
        {
            if(nums[i]+nums[j]==k)
            {
                i++;
                j--;
                count++;
            }
            else if(nums[i]+nums[j]<k)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return count;

    }
};