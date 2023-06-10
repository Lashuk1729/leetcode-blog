class MyHashSet {
public:
    set<int> hashset;
    MyHashSet() {}
    
    void add(int key) {
        hashset.insert(key);
    }
    
    void remove(int key) {
        hashset.erase(key);
    }
    
    bool contains(int key) {
        auto pos = hashset.find(key);
        if (pos != hashset.end())
            return true;
        else
            return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */