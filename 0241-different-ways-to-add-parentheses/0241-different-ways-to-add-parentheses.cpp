class Solution {
public:
    map<pair<int,int>,vector<int>>dp;
    vector<int> solve(int i, int j, string &s){
        if(j-i+1 <= 2) return {stoi(s.substr(i,j-i+1))};

        if(dp.find({i,j}) != dp.end()) return dp[{i,j}];
        vector<int> v;
        for(int k=i; k<=j; k++){
            if(!(s[k] >= '0' && s[k] <= '9')){
                vector<int> temp1 = solve(i,k-1,s);
                vector<int> temp2 = solve(k+1,j,s);
                if(s[k] == '+'){
                    for(int x = 0; x<temp1.size(); x++){
                        for(int y=0; y<temp2.size(); y++){
                            v.push_back(temp1[x] + temp2[y]);
                        }
                    }
                }
                else if(s[k] == '-'){
                    for(int x = 0; x<temp1.size(); x++){
                        for(int y=0; y<temp2.size(); y++){
                            v.push_back(temp1[x] - temp2[y]);
                        }
                    }
                }
                else if(s[k] == '*'){
                    for(int x = 0; x<temp1.size(); x++){
                        for(int y=0; y<temp2.size(); y++){
                            v.push_back(temp1[x] * temp2[y]);
                        }
                    }
                }
            }

        } 
        return dp[{i,j}] = v;
    }
    vector<int> diffWaysToCompute(string s) {
        return solve(0,s.length()-1,s);
    }
};