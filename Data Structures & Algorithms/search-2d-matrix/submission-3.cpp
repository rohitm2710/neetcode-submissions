class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int st=0;
        int end=matrix.size()-1;
        if(target>matrix[end][matrix[0].size()-1]||target<matrix[0][0]) return false;
        int mid;
        while(st<=end){
            mid=st+(end-st)/2;
            if(matrix[mid][0]==target) return true;
            else if(matrix[mid][0]<target) st=mid+1;
            else end=mid-1;
        }
        int row=end;
        st=0;
        end=matrix[0].size()-1;
        while(st<=end){
            mid=st+(end-st)/2;
            if(matrix[row][mid]==target) return true;
            else if(matrix[row][mid]<target) st=mid+1;
            else end=mid-1;
        }
        return false;
    }
};
