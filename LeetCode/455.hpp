#pragma once

class 455
{
public:
    int findContentChildren(vector<int>& g, vector<int> s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gi = 0, si = 0;
        //gi    学生胃口大小
        //si    饼干大小
        while(gi < s.size() && si < s.size())
        {
            if(si >= gi)
                gi++;
            si++;
        }
        return gi;
    }
private:

};

