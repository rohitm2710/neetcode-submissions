class Solution {
public:
    bool isPalindrome(string s) {
        int left=0;
        int right=s.size()-1;
        while(left<=right){
            while((left<right) &&(s[left]<'A' || s[left]>'Z')&&(s[left]<'a' || s[left]>'z')&&(s[left]<'0' || s[left]>'9')){
                left++;
            }
            while((right>left) &&(s[right]<'A' || s[right]>'Z')&&(s[right]<'a' || s[right]>'z')&&(s[right]<'0' || s[right]>'9')){
                right--;
            }
            if(tolower(s[left])==tolower(s[right])){
                left++;
                right--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
