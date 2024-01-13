class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int curr, max_area = INT_MIN;
        while(left < right) {
            curr = min(height[right],height[left]) * (right - left);
            if(max_area < curr)
                max_area = curr;
                
            if(height[left] < height[right])
                left += 1;
            else
                right -= 1;
        }
        return max_area;
    }
};