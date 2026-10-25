class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> speed_pos;
        for (int i = 0; i < position.size(); i++) {
            speed_pos.push_back({position[i], speed[i]});
        }
        sort(speed_pos.begin(), speed_pos.end(), greater<>());
        double time = (double)(target - speed_pos[0].first)/speed_pos[0].second;
        int car_fleet = 1;

        for (int i = 1; i < position.size(); i++) {
            double time_curr = (double)(target - speed_pos[i].first) / speed_pos[i].second;
            if (time_curr > time) {
                time = time_curr;
                car_fleet++;
            }
        }
        return car_fleet;
    }
};
