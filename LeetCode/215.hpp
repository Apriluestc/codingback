#pragma once

struct cmp
{
    bool operator()(int x, int y)
    {
        return x > y;
    }
};
class 215
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int, vector<int>, cmp> q;
        for(auto val : nums)
        {
            q.push(val);
            if(q.size() > k)
                q.pop();
        }
        return q.top();
    }
private:

};

//快速排序


