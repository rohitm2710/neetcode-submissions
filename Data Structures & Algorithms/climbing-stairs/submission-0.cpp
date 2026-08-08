class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        int s1=1;
        int s2=2;
        int res=s2;
        for(int i=3;i<=n;i++){
            res=s1+s2;
            s1=s2;
            s2=res;
        }
        return res;
    }
};
