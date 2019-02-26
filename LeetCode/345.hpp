#pragma once

class 345
{
public:
    string reverseVowels(string s)
    {
        int left = 0, right = s.size() - 1;
        while(left < right)
        {
            if(!isAeiou(s[left]))
                left++;
            else if(!isAeiou(s[right]))
                right--;
            else if(isAeiou(s[left]) && isAeiou(s[right]))
            {
                swap(s[left], s[right]);
                left++;
                right--;
            }
    
        }
        return s;
    }
private:
    bool isAeiou(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' \
                  || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

};

