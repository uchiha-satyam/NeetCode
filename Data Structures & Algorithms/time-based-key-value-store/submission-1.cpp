class TimeMap {
    unordered_map<string, vector<pair<int, string>>> data;
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        data[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!data.contains(key)) {
            return "";
        }
        int lLeft = 0, lRight = data[key].size() - 1;
        int lPos = -1;
        while (lLeft <= lRight) {
            int lMid = lLeft + (lRight - lLeft)/2;
            if (data[key][lMid].first <= timestamp) {
                lPos = lMid;
                lLeft = lMid + 1;
            }
            else {
                lRight = lMid - 1;
            }
        }
        if (-1 == lPos) {
            return "";
        }
        return data[key][lPos].second;
    }
};
