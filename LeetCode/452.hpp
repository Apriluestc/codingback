#pragma once

class 452
{
public:
    static bool cmp(const pair<int, int>& left, const pair<int, int>& right)
    {
        return left.second < right.second;
    }
    int findMinArrowShots(vector<pair<int, int>>& points)
    {
        if(points.empty())
            return 0;
        int ans = 1;
        sort(points.begin(), points.end(), cmp);
        int axis = points[0].second;
        for(int i = 0;i < points.size();++i)
        {
            if(axis < points[i].first)
            {
                ans++;
                axis = points[i].second;
            }
        }
        return ans;
    }
private:

};

