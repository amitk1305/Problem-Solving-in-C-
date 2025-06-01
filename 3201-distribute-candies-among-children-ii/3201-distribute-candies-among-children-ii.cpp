class Solution {
public:
    long nC2(int n){ return (long)(n+2)*(n+1)/2; };
    long long distributeCandies(int n, int limit) {
        //x+y+z = n
        //x<=limit 
        //y<=limit
        //z<=limit
        //S=(1+x+x^2+x^3+...+x^limit)(1+x+x^2+x^3+...+x^limit)(1+x+x^2+x^3+...+x^limit) , x^n?
        //(1+x+x^2+x^3+...+x^limit) = (1+x+x^2+x^3+...) - (x^(limit+1)+x^(limit+2)+....)
        //= 1/(1-x) - x^(limit+1)*1/(1-x)
        //S = (1/(1-x) - x^(limit+1)*1/(1-x))^3 = (1-x^(limit+1))^3/(1-x)^3 
        //S = (1-3x^(limit+1)+3x^(2limit+2)-x^(3limit+3))(1+x+x^2+x^3+...)^3 , x^n?
        long long res = nC2(n); 
        if(limit+1<=n) res-=3*nC2(n-limit-1);
        if(2*limit+2<=n) res+=3*nC2(n-2*limit-2);
        if(3*limit+3<=n) res-=nC2(n-3*limit-3);
        return res;
    }
};