class SeatManager {
public:
    int count = 1;
    priority_queue<int, vector<int>, greater<int>> un_res;
    SeatManager(int n) {
        
    }
    
    int reserve() {
        if(!un_res.empty()) {
            int temp = un_res.top();
            un_res.pop();
            return temp;
        }
        else{
            count += 1;
            return count - 1;
        }
    }
    
    void unreserve(int seatNumber) {
        if(seatNumber == count)
            count -= 1;
        else
            un_res.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */