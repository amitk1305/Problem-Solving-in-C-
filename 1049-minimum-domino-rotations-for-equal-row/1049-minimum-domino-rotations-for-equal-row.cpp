class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
       int element1 = tops[0];
       int cnt1=1;
       for(int i=1;i<n;i++){
          if(tops[i]==element1) cnt1++;
          if(tops[i]!=element1) cnt1--;
          if(cnt1==0) {
            cnt1 = 1;
            element1 = tops[i];
          }
       }
       for(int i=0;i<n;i++){
          if(bottoms[i]==element1) cnt1++;
          if(bottoms[i]!=element1) cnt1--;
          if(cnt1==0) {
            cnt1 = 1;
            element1 = bottoms[i];
          }}
          int cnt2 = 0;
          int cnt3 = 0;
      for(int i=0;i<n;i++){
         if(tops[i]!=element1 && bottoms[i]!=element1) return -1;
         if(tops[i]!=element1 && bottoms[i]==element1) cnt2++;
         if(bottoms[i]!=element1 && tops[i]==element1 ) cnt3++;
      }
      
        return min(cnt2,cnt3);
    }
};