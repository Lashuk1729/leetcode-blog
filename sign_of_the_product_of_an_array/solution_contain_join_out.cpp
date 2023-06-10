class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign = 1;
        for(int i = 0; i < nums.size(); i++) {
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