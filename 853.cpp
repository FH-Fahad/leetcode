// https://leetcode.com/problems/car-fleet/

class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        map<float, float> cars;
        int fleets = 0, n = speed.size();
        float lastTime = -1.0f;

        for (int i = 0; i < n; i++)
        {
            cars.insert({-position[i], speed[i]});
        }

        for (auto &car : cars)
        {
            auto time = (target + car.first) / car.second;
            if (lastTime < time)
            {
                fleets++;
                lastTime = time;
            }
        }
        return fleets;
    }
};