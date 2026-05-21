class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0, j = heights.size() -1, i =0;
        while (i < j)
        {         
            int area = (j - i)* min(heights[i], heights[j]);
            if(area > maxArea) maxArea = area;
            if(heights[i] < heights[j])
                i++;
            else 
                j--;
        }

        return maxArea;
    }
};
