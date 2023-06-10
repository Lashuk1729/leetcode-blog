class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int sum = 0, res = 0;
        int low = 0, high = people.size()-1;
        while(low <= high)
        {
            sum = people[low] + people[high];
            if(sum <= limit)
            {
                res += 1;
                low += 1;
                high -= 1;
            }
            else
            {
                res += 1;
                high -= 1;
            }
        }
        return res;
    }
};