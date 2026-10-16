class Solution {
public:
    int maxArea(vector<int>& heights) {
// Optimized Approach, TWO POINTER, TC=O(N), SC=O(1)

        int st=0, end=heights.size()-1, maxWater=0, width, height, area;
        
        while(st<end) {
            height=min(heights[st], heights[end]);
            width=end-st;

            area=height*width;
            maxWater=max(area, maxWater);

            if(heights[st]<=heights[end])
            st++;

            else
            end--;
        }

        return maxWater;

/*
Brute Force Approach, TC=O(N^2), SC=O(1)

        int maxArea=0, area, height, width;
        for(int left=0;left<heights.size()-1;left++) {
            for(int right=left+1;right<heights.size();right++) {
                height=min(heights[left], heights[right]);

                width=right-left;

                area=width*height;
                maxArea=max(area, maxArea);
            }
        }

        return maxArea;
*/
    }
};
