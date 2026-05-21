class Solution {
public:
    int maxArea(vector<int>& heights) {
        int result = 0, j = heights.size() -1, i = 0;
        while (i < j)
        {         
            int area = (j - i)* min(heights[i], heights[j]);
            result = max(area, result);

            // skip all bars shorter than current bottleneck
            int h = min(heights[i], heights[j]);
            while (i < j && heights[i]  <= h) i++;
            while (i < j && heights[j] <= h) j--;
        }

        return result;
    }
};
