#pragma GCC optimize("O3", "unroll-loops")

class FoodRatings {
public:
    unordered_map<string, int> foodRating;
    unordered_map<string, string> foodCuisine;

    struct Compare {
        bool operator()(pair<int, string> left, pair<int, string> right) {
            if(left.first != right.first)
                return left.first < right.first; // decreasing
            return left.second > right.second;   // increasing            
        }
    };

    unordered_map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, Compare >> cuisineRating;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i < n; i++) {
            foodRating[foods[i]] = ratings[i];
            foodCuisine[foods[i]] = cuisines[i];
            cuisineRating[cuisines[i]].push({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        foodRating[food] = newRating;
        string cuisine = foodCuisine[food];
        cuisineRating[cuisine].push({newRating, food});
    }
    
    string highestRated(string cuisine) {
        auto highestRated = cuisineRating[cuisine].top();
        while(foodRating[highestRated.second] != highestRated.first) {
            cuisineRating[cuisine].pop();
            highestRated = cuisineRating[cuisine].top();
        }
        return highestRated.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();