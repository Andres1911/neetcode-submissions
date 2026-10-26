class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        deque<int> dq;
        int max_area = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (!dq.empty() && heights[i] < heights[dq.back()]) {
                int curr_pop = dq.back();
                dq.pop_back();
                int left = (dq.empty()) ? 0 : dq.back() + 1;
                int right = i - 1;
                int area = (right - left + 1) * heights[curr_pop];
                max_area = max(max_area, area);
                // cout<<"Popping element: "<<curr_pop<<" Reached area: "<<left<<" "<<right<<" Area: "<<area<<"\n";
            }
            dq.push_back(i);
        }
        return max_area;
    }
};
