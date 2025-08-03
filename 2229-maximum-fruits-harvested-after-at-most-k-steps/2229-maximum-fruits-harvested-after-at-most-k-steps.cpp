class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int left =0;
        int sum=0;
        int maxFruits=0;


        for(int right=0;right< fruits.size();right++){
            sum += fruits[right][1];

            //if window is too big (>K) shrink it form left
            while(left <= right && minsteps(fruits[left][0],fruits[right][0] , startPos) >k){
                sum -= fruits[left][1]; //Remove left fruit count
                left++;
            }
        //update max fruit collected
        maxFruits = max(maxFruits,sum);
        }

        return maxFruits;
    }

    private:
    int minsteps(int left ,int right, int start){
        return min(abs(start-left) + (right - left), abs(start -right )+ (right -left));
    }

};