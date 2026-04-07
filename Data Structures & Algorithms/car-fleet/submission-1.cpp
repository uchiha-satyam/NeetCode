class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        set<pair<int, int>, greater<pair<int, int>>> lData;
        int lFleet = 0;
        float lTime = 0, lSpeed = 0, lPosition = target;
        for (int i=0; i<position.size(); i++) {
            lData.insert(make_pair(position[i], speed[i]));
        }
        for (auto& lPair : lData) {
            float lCurrPos = lPair.first;
            float lCurrSpeed = lPair.second;
            float lRelSpeed = lCurrSpeed - lSpeed;
            float lCurrTime = (lPosition - lCurrPos) / lRelSpeed;
            if (lRelSpeed < 0 || lCurrTime > lTime) {
                lFleet++;
                lTime = (target - lCurrPos) / lCurrSpeed;
                lPosition = lCurrPos;
                lSpeed = lCurrSpeed;
            }
        }
        return move(lFleet);
    }
};
