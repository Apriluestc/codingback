#pragma once

class 680
{
public:
    bool isPalindrome(string s, int left, int right)
    {
        if(s.empty())
            return true;
        while(left < right)
        {
            if(s[left] != s[right])
                return false;
        }
        return true;
    }
    bool validPalindrome(string s)
    {
        int left = 0, right = s.size() - 1;
        while(left < right)
        {
            if(s[left] != s[right])
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right--);
            left++;
            right--;
        }
        return true;
    }
private:

};

