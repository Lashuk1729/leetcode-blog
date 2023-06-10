class FrequencyTracker {
private:
    std::unordered_map<int, int> freq;
    std::unordered_map<int, std::unordered_set<int>> freqIndex;
public:
    FrequencyTracker() {}
    void add(int number) {
        freqIndex[freq[number]].erase(number);
        freq[number]++;
        freqIndex[freq[number]].insert(number);
    }
    void deleteOne(int number) {
        if (freq.count(number) > 0) {
            freqIndex[freq[number]].erase(number); 
            freq[number]--;
            if (freq[number] > 0) {
                freqIndex[freq[number]].insert(number);
            } else { 
                freq.erase(number);
            }
        }
    }
    bool hasFrequency(int frequency) {
        return freqIndex.count(frequency) > 0 && !freqIndex[frequency].empty();
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */