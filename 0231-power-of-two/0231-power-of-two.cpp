class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        for(int i=0;i<=30;i++){
            int m = pow(2,i);
            if(n==m){
             return true;
            }
        }

        
        return false;
    }
};