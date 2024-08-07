class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c==1)
            return true;
      long long  int left=0, right = sqrt(c);
        while(left<=right){
           long long int sum = (left*left) + (right*right);
            if(sum==c)
                return true;
            else if(sum<c)
                left++;
            else
                right--;
        }
        return false;
    }
};