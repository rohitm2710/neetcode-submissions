class Solution {
    public int maxArea(int[] heights) {
        int st=0;
        int end=heights.length-1;
        int maxArea=0;
        while(st<end){
            int area=Math.min(heights[st],heights[end])*(end-st);
            maxArea=Math.max(maxArea,area);
            if(heights[st]>=heights[end]){
                end--;
            }
            else st++;
        }
        return maxArea;
    }
}
