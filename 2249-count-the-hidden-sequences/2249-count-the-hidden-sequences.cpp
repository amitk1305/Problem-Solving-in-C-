class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int mn=0,mx=0,sum=0;
        for(int x=0;x<differences.size();x++)
        {
            sum+=differences[x];
            mn=min(mn,sum);
            mx=max(mx,sum);
            if(mx-mn>upper-lower)
                return 0;
        }
        return (upper-lower)-(mx-mn)+1;
    }
};