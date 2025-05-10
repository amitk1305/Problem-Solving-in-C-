class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long czero1 = 0, czero2 = 0, sum1 = 0, sum2 = 0;
        long long n = nums1.size()>nums2.size()? nums1.size() : nums2.size();
        // (1) First let's compute all the sizes and no of zeros 
        for(int i=0;i<n;i++){
            if(nums1.size() > i){
                if(nums1[i] != 0) sum1 = sum1 + nums1[i];
                else czero1++;
            }
            if(nums2.size()>i){
                if(nums2[i] != 0) sum2 = sum2 + nums2[i];
                else czero2++;
            }
        }

        cout << "sum1 - "<<sum1<<" - sum2 -> "<<sum2<<endl;
        // (2) If No Zeros in both then you know it's easy
        if(czero1==0 && czero2 == 0){
            if(sum1 == sum2) return sum1;
            else return -1;
        }

        // (3) If one of them have zero condition

        if(czero1==0 || czero2==0){
            // vector<int> nums3;
            if(czero1 ==0){
                if(sum2>sum1) return -1;
            }else{
                if(sum1>sum2)return -1;
            }
            int czero = czero1 == 0 ? czero = czero2 : czero = czero1;
            int sum = abs(sum1- sum2);
            cout << "sum - "<<sum << " czero - "<<czero<<endl;
            if(sum < czero) return -1;
            else return sum1>sum2?sum1:sum2;
        }

        // (4) If both have zero logic too lazy to make sum global variable as 2nd day after break let's go 

        if(czero1!= 0 && czero2 !=0){
            if(sum1 == sum2){
                if(czero1>czero2){
                    return sum1+czero1;
                }else return sum1+czero2;
            }
            else if(sum1>sum2){
                long long sum = abs(sum1- sum2);
                if(sum+czero1 <czero2)return sum2+czero2;
                return sum1+czero1;
            }else{
                long long sum = abs(sum1- sum2);
                if(sum+ czero2 < czero1) return sum1+czero1;
                return sum2+czero2;
            }
        }

        return -1;
    }
};