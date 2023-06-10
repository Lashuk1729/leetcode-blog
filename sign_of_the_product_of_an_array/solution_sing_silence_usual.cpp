class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign = 1, size = nums.size();
        for(int i = 0; i < size; i++) {
            if(nums[i] > 0) {
                sign *= 1;
            }

            else if(nums[i] < 0) {
                sign *= -1;
            }

            else{
                sign *= 0;
                break;
            }
        }
        return sign;
    }
};