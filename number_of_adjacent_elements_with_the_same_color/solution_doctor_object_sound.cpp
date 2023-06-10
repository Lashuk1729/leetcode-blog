class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> nums(n, 0);
        vector<int> answer;
        int count = 0;

        for (int i = 0; i < queries.size(); i++) {
            int index = queries[i][0];
            int color = queries[i][1];

            int prevColor = nums[index];
            nums[index] = color;

            if (index > 0 && nums[index-1] != 0 && nums[index-1] == color) {
                count++;
            }

            if (index < n-1 && nums[index+1] != 0 && nums[index+1] == color) {
                count++;
            }

            if (prevColor != 0) {
                if (index > 0 && nums[index-1] != 0 && nums[index-1] == prevColor) {
                    count--;
                }

                if (index < n-1 && nums[index+1] != 0 && nums[index+1] == prevColor) {
                    count--;
                }
            }

            answer.push_back(count);
        }

        return answer;
    }
};