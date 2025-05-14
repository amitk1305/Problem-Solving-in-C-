const int nChar = 26, mod=1000000007;
long long logCheck[32][nChar][nChar]; 
auto init = [](vector<int>& nums, int t){
    //look up nums
    memset(logCheck,0,sizeof(logCheck));
    for(char c=0;c<nChar;c++) for(char next=1; next<=nums[c];next++)
        logCheck[0][c][(c+next)%nChar]=1;

    int index=1; int curr=1; 
    //each log; [index][nChar][nChar]; O(log(t))
    //            ^
    for(;curr<t;curr*=2){

        //each character array ; [index][m][nChar]; 26
        //                               ^
        for(char m=0;m<nChar;m++){

            //freq of characters of prev array; [index-1][m][n]; 26
            //                                               ^
            for(char n=0;n<nChar;n++){

                //look up others prev character arrays; [index-1][n][o]; 26
                //                                                   ^  
                for(char o = 0;o<nChar;o++){
                    logCheck[index][m][o]+=logCheck[index-1][m][n]*logCheck[index-1][n][o];

                    if(logCheck[index][m][o]>mod) logCheck[index][m][o]%=mod;
                }
            } 
        }
        index++;
    }
    for(int i=0;i<index;i++){
        cout<<"2^"<<i<<" :\n";
        for(char m=0;m<nChar;m++){
            cout<<char('a'+m)<<" : ";                                     
            for(char n=0;n<nChar;n++){
                cout<<logCheck[i][m][n]<<" ";
            } 
            cout<<endl;
        }
    }
};
class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        
        //init(nums,t);
        //init is for testing, I prefer my code short
        memset(logCheck,0,sizeof(logCheck));
        for(char c=0;c<nChar;c++) for(char next=1; next<=nums[c];next++)
            logCheck[0][c][(c+next)%nChar]=1;

        int index=0; int curr=1; 
        for(;curr*2<=t;curr*=2) {
            index++;
            for(char m=0;m<nChar;m++) for(char n=0;n<nChar;n++) for(char o = 0;o<nChar;o++){
                logCheck[index][m][o]+=logCheck[index-1][m][n]*logCheck[index-1][n][o];
                if(logCheck[index][m][o]>mod) logCheck[index][m][o]%=mod;
            }
        }
        
        vector<long> currCount(nChar,0), nextCount(nChar,0); long long res=0;
        for(int i=0;i<s.size();i++) currCount[s[i]-'a']++;
        
        while(t){
            //cout<<t<<" "<<index<<" "<<curr<<endl;;
            if(t>=curr) {
                for(char n=0;n<nChar;n++) for(char o = 0;o<nChar;o++){
                    nextCount[o]+=currCount[n]*logCheck[index][n][o];
                    if(nextCount[o]>mod) nextCount[o]%=mod;
                }
                t-=curr; 
                swap(currCount,nextCount);
                nextCount=vector<long>(nChar,0);
            }
            index--; curr/=2;
        }

        for(char c=0;c<nChar;c++) res+=currCount[c];

        return res%mod;

    }
};