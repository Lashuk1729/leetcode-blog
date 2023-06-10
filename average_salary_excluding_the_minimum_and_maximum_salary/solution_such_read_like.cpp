class Solution {
public:
    double average(vector<int>& salary) {
        double sum = salary[0];
        int size = salary.size(), min_sal = salary[0], max_sal = salary[0];
        for(int i = 1; i < size; i++) {
            if(min_sal > salary[i]) {
                min_sal = salary[i];
            }
            if(max_sal < salary[i]) {
                max_sal = salary[i];
            }
            sum += salary[i];
        }
        sum -= (min_sal + max_sal);
        return sum / (size - 2);
    }
};