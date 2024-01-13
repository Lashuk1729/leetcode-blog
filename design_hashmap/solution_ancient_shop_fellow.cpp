class MyHashMap {
private:
    vector<pair<int,int>> key_val;
public:
    MyHashMap() {}

    void put(int key, int value) {
        for(auto& pair : key_val) {
            if(pair.first == key) {
                pair.second = value;
                return;
            }
        }
        key_val.push_back(make_pair(key, value));
    }
    
    int get(int key) {
        for(auto& pair : key_val)
            if(pair.first == key)
                return pair.second;
        return -1;
    }
    
    void remove(int key) {
        for(auto it = key_val.begin(); it != key_val.end(); it++) {
            if(it->first == key) {
                key_val.erase(it);
                return;
            }
        }
    }
};