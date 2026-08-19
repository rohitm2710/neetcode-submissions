class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0;
        int n=digits.size();
        digits[n-1]+=1;
        if(digits[n-1]>9){
            carry=1;
            digits[n-1]%=10;
        }
        if(carry==1){
            if(n==1){
                digits.insert(digits.begin(),1);
            }
            else{
                int i=n-2;
                while(carry!=0&&i>=0){
                    digits[i]++;
                    carry=0;
                    if(digits[i]>9){
                        carry=1;
                        digits[i]%=10;
                    }
                    i--;
                }
                if(carry==1){
                    digits.insert(digits.begin(),1);
                }
            }
        }
        return digits;
    }
};
