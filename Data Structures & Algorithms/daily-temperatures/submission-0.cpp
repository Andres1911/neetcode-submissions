class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        deque<int> indices;
        vector<int> result(temperatures.size());

        for (int i = 0; i < temperatures.size(); i++) {
            while (!indices.empty() && temperatures[i] > temperatures[indices.back()]) {
                int prev_index = indices.back();
                indices.pop_back();
                result[prev_index] = i - prev_index;
            }
            indices.push_back(i);
        }

        return result;
    }
};
