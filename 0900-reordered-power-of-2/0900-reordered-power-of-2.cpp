class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int i = 0;
        string gn = to_string(n);
        sort(gn.begin(),gn.end());
        while(true){
            long long num = pow(2 , i);
            string s = to_string(num);
            sort(s.begin(),s.end());
            if(gn == s)return true;
            if(gn.size() < s.size())return false;
            i++;
        } 
        return false;
    }
};