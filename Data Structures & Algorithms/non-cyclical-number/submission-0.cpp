class Solution {
    int digit_sum(int n){
        int sum=0;
        while(n>0){
            int rem=n%10;
            sum+=(rem*rem);
            n/=10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        n=digit_sum(n);
        while(n/10!=0){
            n=digit_sum(n);
        }
        return n==1;
    }
};
