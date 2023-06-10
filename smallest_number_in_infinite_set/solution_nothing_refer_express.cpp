class SmallestInfiniteSet {
public:
    int counter;
    priority_queue<int, vector<int>, greater<int>> add_ele_pq;
    set<int> add_ele_set;
    SmallestInfiniteSet() {
        counter = 1;
    }
    
    int popSmallest() {
        if(add_ele_pq.empty() != true) {
            int top = add_ele_pq.top();
            add_ele_pq.pop();
            add_ele_set.erase(top);
            return top;
        }

        else {
            counter += 1;
            return counter - 1;
        }
    }
    
    void addBack(int num) {
        if(num >= counter){
            return;
        }
        
        if(add_ele_set.find(num) != add_ele_set.end()) {
            return;
        }

        add_ele_pq.push(num);
        add_ele_set.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */