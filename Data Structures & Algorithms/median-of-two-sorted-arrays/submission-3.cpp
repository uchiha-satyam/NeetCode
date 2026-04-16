class Solution {
    bool isValid (int p1, int p2, vector<int>& vec1, vector<int>& vec2) {
        cout << "isValid\n";
        if (p1 + 1 < vec1.size() && p2 >= 0 && vec1[p1 + 1] < vec2[p2]) {
            return false;
        }
        if (p2 + 1 < vec2.size() && p1 >= 0 && vec2[p2 + 1] < vec1[p1]) {
            return false;
        }
        return true;
    }
    double getMedian (int p1, int p2, vector<int>& vec1, vector<int>& vec2, bool isOdd) {
        priority_queue<int> lPq;
        if (p1 >= 0) {
            lPq.push(vec1[p1]);
        }
        if (p2 >= 0) {
            lPq.push(vec2[p2]);
        }
        if (p1 - 1 >= 0) {
            lPq.push(vec1[p1 - 1]);
        }
        if (p2 - 1 >= 0) {
            lPq.push(vec2[p2 - 1]);
        }
        double lResult = 0.0;
        lResult += lPq.top();
        if (!isOdd) {
            lPq.pop();
            lResult += lPq.top();
            lResult /= 2.0;
        }
        return lResult;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size() > nums1.size()) {
            swap(nums1, nums2);
        }
        int lLeft = 0, lRight = nums1.size() - 1;
        int lSize = nums1.size() + nums2.size();
        int lMidSize = lSize/2 + 1;
        while (lLeft <= lRight) {
            int lMid = lLeft + (lRight - lLeft)/2;
            int lOtherMid = lMidSize - 2 - lMid;
            cout << lLeft << ", " << lRight << ", " << lMid << " -> " << lOtherMid << "(" << nums1.size() << ", " << nums2.size() << ")\n";
            if (lOtherMid >= (int)nums2.size()) {
                cout << "1st\n";
                lLeft = lMid + 1;
            }
            else if (lOtherMid < -1) {
                cout << "2nd\n";
                lRight = lMid - 1;
            }
            else if (isValid(lMid, lOtherMid, nums1, nums2)) {
                cout << "3rd\n";
                return getMedian(lMid, lOtherMid, nums1, nums2, lSize%2);
            }
            else if (lMid + 1 < nums1.size() && lOtherMid >= 0 && nums1[lMid + 1] < nums2[lOtherMid]) {
                cout << "4th\n";
                lLeft = lMid + 1;
            }
            else {
                cout << "5th\n";
                lRight = lMid - 1;
            }
        }
        return 0;
    }
};
