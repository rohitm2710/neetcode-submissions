class Solution {
private:
    void swap(int& a,int& b){
        int c=a;
        a=b;
        b=c;
    }
    int k_val;
    int needed;
    int pivot(vector<int>& nums,int l,int u){
        if(l>=u) return l;
        int p=l;
        while(l<u){
            while(u>p&&nums[u]>=nums[p]){
                u--;
            }
            if(u!=p){
                swap(nums[u],nums[p]);
                p=u;
            }
            while(l<p&&nums[l]<=nums[p]){
                l++;
            }
            if(l!=p){
                swap(nums[l],nums[p]);
                p=l;
            }
        }
        return p;
    }
    bool found=false;
    void q_sort(vector<int>& nums,int l,int u){
        if(found) return;
        if(l>=u){
            if(l==nums.size()-k_val){
                needed=nums[l];
                found=true;
            }
            return;
        }
        int p=pivot(nums,l,u);
        if(p==nums.size()-k_val){
            needed=nums[p];
            found=true;
            return;
        }
        q_sort(nums,l,p);
        q_sort(nums,p+1,u);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        k_val=k;
        q_sort(nums,0,nums.size()-1);
        return needed;
    }
};
