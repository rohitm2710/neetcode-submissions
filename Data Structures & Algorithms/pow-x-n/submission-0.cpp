class Solution {
public:
    double myPow(double x, int n) {
        double mul=1;
        long long nn=n;
        if(nn<0){
            nn=-1*nn;
        }
        while(nn>0){
            if(nn&1){
                mul*=x;
            }
            x*=x;
            nn/=2;
        }
        if(n<0){
            return 1.0/mul;
        }
        return mul;
    }
};
