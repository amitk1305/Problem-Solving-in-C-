class Solution {
public:
    long long flowerGame(int n, int m) {
          int cnt=0;
          long long oddx=0;
          long long oddy=0;
          long long evenx=0;
          long long eveny=0;
          if(n%2==0)
          {
            oddx=n/2;
            evenx=n/2;
          }
          else
          {
            oddx=n/2+1;
            evenx=n/2;
          }

          if(m%2==0)
          {
            oddy=m/2;
            eveny=m/2;
          }
          else
          {
            oddy=m/2+1;
            eveny=m/2;
          }
          return oddx*eveny+oddy*evenx;
    }
};
