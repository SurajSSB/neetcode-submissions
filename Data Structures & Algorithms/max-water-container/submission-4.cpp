class Solution {
public:
    int maxArea(vector<int>& heights) {
        int result = 0, j = heights.size() -1, i = 0;
        while (i < j)
        {         
            int area = (j - i)* min(heights[i], heights[j]);
            result = max(area, result);
            if(heights[i] < heights[j])
                i++;
            else 
                j--;
        }

        return result;
    }
};
