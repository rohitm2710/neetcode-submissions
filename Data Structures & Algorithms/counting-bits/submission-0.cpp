class Solution {
private:
    int set_bit(int n){
        int count=0;
        while(n>0){
            if((n&1)==1){
                count++;
            }
            n>>=1;
        }
        return count;
    }
public:
    vector<int> countBits(int n) {
        vector<int> counts;
        for(int i=0;i<=n;i++){
            counts.push_back(set_bit(i));
        }
        return counts;
    }
};
