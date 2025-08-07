// read the hints and try to solve yourself
// the only tough thing here is the base condition 
// which is used to ensure that the child stays within one
// particular half of the diagonal
// rest is simple basic dp on grids

class Solution {
public:
vector<vector<int>>dp;

int n ; 
    int f(int row , int col , vector<vector<int>>& fruits){
        if(row<= col || row>=n  || col >=n || row<0 ||col<0) return INT_MIN;
        // row<=col ensures ki upper triangle m na jaye
        if(row==n-1 && col==n-1)return 0;
        if(dp[row][col]!=-1)return dp[row][col];
        int op1 =  f(row-1,col+1,fruits);
        int op2 =  f(row,col+1,fruits);
        int op3 = f(row+1,col+1,fruits);
        return dp[row][col]=fruits[row][col]+max({op1,op2,op3});
    }

    int f1(int row , int col ,vector<vector<int>>& fruits){
        if(row>=col || row>=n || col >=n || row<0 ||col<0) return INT_MIN;
        // row>=col ensures ki lower triangle m na jaye
        if(row==n-1 && col==n-1)return 0;
        if(dp[row][col]!=-1)return dp[row][col];
        
        int op1 =  f1(row+1,col-1,fruits);
        int op2 =  f1(row+1,col,fruits);
        int op3 = f1(row+1,col+1,fruits);
        return dp[row][col]=fruits[row][col]+max({op1,op2,op3});
    }
    
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        n = fruits.size();
        long long cnt  = 0 ;
        for(int i = 0 ; i<n ; i++){
            cnt+=fruits[i][i];
        }
        dp.resize(n+1,vector<int>(n+1,-1));
        cnt+=f(n-1,0,fruits);
        dp.resize(n+1,vector<int>(n+1,-1));
        cnt+=f1(0,n-1,fruits);
        return cnt;
    }
};