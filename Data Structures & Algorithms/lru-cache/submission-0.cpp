class LRUCache {
    unordered_map<int, pair<int, int>> data;
    map<int, int> record;
    unsigned long long time;
    int capacity;
    int size;
public:
    LRUCache(int capacity) {
        time = 0;
        this->capacity = capacity;
        size = 0;
    }
    
    int get(int key) {
        if (!data.contains(key)) {
            return -1;
        }
        int lVal = data[key].first;
        int lOldTime = data[key].second;
        record.erase(lOldTime);
        time++;
        data[key].second = time;
        record[time] = key;
        return lVal;
    }
    
    void put(int key, int value) {
        if (data.contains(key)) {
            int lVal = data[key].first;
            int lOldTime = data[key].second;
            if (lOldTime != 0) {
                record.erase(lOldTime);
            }
        }
        else {
            if (size < capacity) {
                size++;
            }
            else {
                auto lIt = record.begin();
                int lLRUKey = lIt->second;
                data.erase(lLRUKey);
                record.erase(lIt);
            }
        }
        time++;
        data[key].first = value;
        data[key].second = time;
        record[time] = key;
    }
};
