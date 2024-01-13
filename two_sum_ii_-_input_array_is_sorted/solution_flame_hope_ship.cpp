class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        bool flag = 0;
        int left = 0, right = numbers.size() - 1;
        while(left < right) {
            if(numbers[left] + numbers[right] == target)
            {
                flag = 1;
                break;
            }
            else if(numbers[left] + numbers[right] > target)
                right -= 1;
            else
                left += 1;
        }
        if(flag)
            return {left+1, right+1};
        else
            return {};
    }
};