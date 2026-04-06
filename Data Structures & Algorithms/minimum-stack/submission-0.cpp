class MinStack {
    vector<int> minData;
    vector<int> data;
    int pos;
    int minPos;
public:
    MinStack() {
        pos = -1;
        minPos = -1;
    }
    
    void push(int val) {
        pos++;
        data.push_back(val);
        if (minData.empty() || minData[minPos] >= val) {
            minPos++;
            minData.push_back(val);
        }
    }
    
    void pop() {
        if (!minData.empty() && minData[minPos] == data[pos]) {
            minPos--;
            minData.pop_back();
        }
        pos--;
        data.pop_back();
    }
    
    int top() {
        return data[pos];
    }
    
    int getMin() {
        return minData[minPos];
    }
};
