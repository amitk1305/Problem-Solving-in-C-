class Solution {
int dp[301][11];// cache
public:
    int Helper(vector<int> &jobDifficulty, int index , int d, int n){
        /*BASE CASE
          If day is equal to 1 then we simply find the maximum difficulty and
          return it
          */
       if(d == 1){
          int maxDifficulty =jobDifficulty[index];
          for(int i=index ;i<n ;i++){
              maxDifficulty =max(maxDifficulty, jobDifficulty[i]);
          }
          return maxDifficulty;
       }


      //Memoization
       if(dp[index][d] != -1){
           return dp[index][d];
       }

       int maxD= jobDifficulty[index];
       int finalResult = INT_MAX;
      /*
      RECURSIVE CALL
       Try one by one with all possibility

       take {index} job's first day
       then take {index,index+1} job's second day
       then take {index,index+1,index+2}
       ...so on....
       */

       for(int i=index; i<= n-d ;i++){
           maxD =max(maxD,jobDifficulty[i]);
           int result = maxD+ Helper(jobDifficulty, i+1, d-1,n);
           finalResult = min(finalResult, result);
       }

       dp[index][d] =finalResult;
       return finalResult;

    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n= jobDifficulty.size();
        if(n< d){
            return -1;
        }
        memset(dp ,-1, sizeof(dp));
        return Helper(jobDifficulty, 0, d, n);
    }
};