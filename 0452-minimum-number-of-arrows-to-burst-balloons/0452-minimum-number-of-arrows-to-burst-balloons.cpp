class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        multimap<int,int>mp;
        for(auto it:points){
            mp.insert({it[0],it[1]});
        }
        auto a=mp.begin();a++;
        int xmin=(mp.begin())->first,xmax=(mp.begin())->second,c=1;
        for(a;a!=mp.end();a++){
            if(a->first<=xmax){
                xmax=min(a->second,xmax);
                xmin=max(a->first,xmin);
            }
            else{
                c++;
                xmax=a->second;
                xmin=a->first;
            }
        }
        return c;

    }
};