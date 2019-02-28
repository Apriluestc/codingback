#pragma once

class 435
{
public:
    static bool cmp(const Interval& a, const Interval& b)
    {
        return a.end < b.end;
    }

    int eraseOrderlapIntervals(vector<Interval>& intervals)
    {
        int size = intervals.size();
        if(intervals.empty())
            return 0;
        int ans = 1;    //非重叠区间
        sort(intervals.begin(), intervals.end());
        int _end = intervals[0].end;
        for(int i = 0;i < size;++i)
        {
            if(intervals[i].start < _end)
                continue;
            ans++;
            _end = intervals[i].end;
        }
        return size - ans;
    }
private:

};

