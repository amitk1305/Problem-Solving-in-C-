class Solution {
private:
    long long int convert(string s){
        long long int num=0;
        for (int i=0; i<s.size(); i++){
            if (i==0 && s[i]=='-'){continue;}
            num*= 10;
            num+= (s[i]-'0');
        }
        if (s[0]=='-')num*=-1;
        return num;
}
string convertback(long long int num){
    string ans;
    bool neg=0;
    if (num<0){num*= -1; neg=1;}
    while (num>0){
        ans+= ((num%10)+'0');
        num/=10;
    } 
    if (neg)ans.push_back('-');
    reverse(ans.begin(),ans.end());
    return ans;
}
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> stk;
        for (auto val: tokens){
            if (val=="+"|| val=="-"|| val=="*"|| val=="/"){
                long long int b= convert(stk.top());
                stk.pop();
                long long int a= convert(stk.top());
                stk.pop();
                if (val == "+"){
                    string c= convertback(a+b);
                    stk.push(c);
                }
                else if (val=="*"){
                    string c= convertback(a*b);
                    stk.push(c);
                }
                else if (val== "-"){
                    string c= convertback(a-b);
                    stk.push(c);    
                }
                else if (val=="/"){
                    string c= convertback(a/b);
                    stk.push(c);
                }
            }
            else stk.push(val);
        }
        return convert(stk.top());
    }
};