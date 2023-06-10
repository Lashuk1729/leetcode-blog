class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> num_sort;
    int K;
    
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int i = 0; i < nums.size(); i++){
            num_sort.push(nums[i]);
            
            // this changed made the code accepted!!!
            if(num_sort.size() > K)
                num_sort.pop();
        }
            
    }
    
    int add(int val) {
        num_sort.push(val);
        if(num_sort.size() > K)
            num_sort.pop();
        
        return num_sort.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */