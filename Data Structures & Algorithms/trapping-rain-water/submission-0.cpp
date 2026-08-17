class Solution {
public:
    int trap(vector<int>& heights) {
        int n=heights.size();
        vector<vector<int>> data(3,vector<int>(n));
        int maxLeft=heights[0];
        for(int i=0;i<n;i++){
            data[0][i]=maxLeft;
            if(heights[i]>maxLeft) maxLeft=heights[i];
        }
        int maxRight=heights[n-1];
        for(int i=n-1;i>=0;i--){
            data[1][i]=maxRight;
            if(heights[i]>maxRight) maxRight=heights[i];
        }
        for(int i=0;i<n;i++){
            data[2][i]=min(data[0][i],data[1][i]);
        }
        int sum=0;
        for(int i=0;i<n;i++){
            if(data[2][i]-heights[i]>0){
                sum+=data[2][i]-heights[i];
            }
        }
        return sum;
    }
};
