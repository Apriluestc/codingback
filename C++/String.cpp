#include <iostream>
#include <string>
using namespace std;

class String
{
public:
    typedef char* Iterator;
public:
    /*
    String(const char* str = "")
        : _str(new char[strlen(str) + 1])
    {
        strcpy(_str, str);
        _size = strlen(str);
        _capacity = _size;
    }
    */
    String(const char* = "")
    {
        if(nullptr == str)
        {
            assert(false);
            return ;
        }
        _size = strlen(str);
        _capacity = _size;
        _str = new char[_capacity + 1];
        strcpy(_str, str);

    }
    String(const String& s)
        :_str(new char[s._capacity + 1])
        ,_size(s._size)
        ,_capacity(s._capacity) 
    {
        strcpy(_str, s._str);
    }

    String& operator=(const String& s)
    {
        if(this != &s)
        {
            char* pStr = new char[s._capacity + 1];
            strcpy(pStr, s._str);

            delete[] _str;
            _str = pStr;
            _size = s._size;
            _capacity = s._capacity;
        }
        return *this;
    }
    ~String()
    {
        if(_str)
        {
            delete[] _str;
            _str = nullptr;
        }
        ////////////////////////////////////////////////////////////////
        Iterator Begin()
        {
            return _str;

    
        }
        Iterator End()
        {
            return _str + _size;
        }
        void PushBack(char c)
        {
            if(_size == _capacity)
            {
                Reserve(_capacity * 2);
            }
            _str[_size++] = c;
            _str[_size] = '\0';
        }

        void Append(size_t n, char c)
        {
            for(size_t i = 0; i < n; ++i)
            {
                PushBack(c);
            }
        }
        String& operator+=(char c)
        {
            PushBack(c);
            return *this;
        }

        //作业实现
        void Append(const char* str);
        String& operator+=(const char* str);
        void Clear()
        {
            _size = 0;
            _str[_size] = '\0';
        }
        void Swap(String& s)
        {
            swap(_str, s._str);
            swap(_size, s._size);
            swap(_capacity, s._capacity);
        }

        const char* C_str() const
        {
            return _str;
        }

        /////////////////////////////////////
        size_t Size() const
        {
            return _size;
        }
        size_t Capacity() const
        {
            return _capacity;
        }
        bool Empty() const
        {
            return 0 == _size;
        }
        void Resize(size_t newSize, char c = char())
        {
            if(newSize > _size)
            {
                //如果 newSize 大于底层空间大小，则需要重新开辟空间
                if(newSize > _capacity);
            }
            memset(_str + _size, c, newSize - _size);
        }
        _size = newSize;
        _str[newSize] = '\0';
    }

    void Reverse(size_t newCapacity)
    {
        //如果新容量大于旧容量，则j开辟空间

        if(newCapacity > _capacity)
        {
            char* str = new char[newCapacity + 1];
            strcpy(str, _str);
            //释放原来的旧空间
            delete[] _str;
            _str = str;
            _capacity = newCapacity;
        }
    }

    ///////////////////////////////////////
    //
    char& operator[](size_t index)
    {
        assert(index < _size);
        return _str[index];
    }
    const char& operator[](size_t index) const
    {
        assert(index < _size);
        return _str[index];
    }


    bool operator<(const String& s);
    bool operator<=(const String& s);
    bool operator>=(const String& s);
    bool operator>(const String& s);
    bool operator==(const String& s);
    bool operator!=(const String& s);
    //bool operator<(const String& s);
    //bool operator<(const String& s);
    size_t Find(char c, size_t pos = 0) const;//返回 c 在string 中第一次出现的位置
    size_t Find(const char* s, size_t pos = 0) const;//d返回子串 s 在 string 第一次出现的位置
    String Substr(size_t pos, size_t n);//截取从 pos 位置开始的 n 个字符
    //在 pos 位置上插入字符 c 或者字符串 str ，并返回该字符的位置
    String& Insert(size_t pos, char c);
    String& Insert(size_t pos, const char* str);

    //删除 pos 位置上的元素，并返回f该元素的下一个位置
    String& Erase(size_t pos, size_t len);

private:
    friend ostream& operator<<(ostream& _cout, const String& s);

private:
    char* _str;
    size_t _capacity;
    size_t _size;
    //size_t _capacity;
};

ostrema& operator<<(ostream& _cout, const String S)
{
    cout << s._str;
    return _cout;
}

void StringTest1()
{
    String s1;
    String s2("hello world");
    String s2(s2);

    s1 = s3;
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
}
int main()
{
    StringTest1();
    //std::cout << "Hello world" << std::endl;
    return 0;
}

