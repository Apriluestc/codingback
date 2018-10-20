#pragma once
#include<iostream>

using namespace std;
#include<assert.h>
#include<stack>
#include<stdio.h>
template<size_t M, size_t N>
class Maze
{
public:
    Maze(int maze[M][N])
    {
        for(size_t i = 0; i < M; ++i)
        {
            for(size_t j = 0; j < N; ++j)
            {
                _maze[i][j] = maze[i][j];
            }
        }
    }
    struct Pos
    {
        int _row;
        int _col;   //列
    };
    bool CheckAccess(Pos next)
    {
        if((next._row >= 0 && next._row < M)
            && (next._col >= 0 && next._col < N)
            &&_maze[next._row][next._col] == 0)
        {
            return true;
        }
        return false;
    }
    bool CheckAccessShort(Pos next, Pos cur)//函数重载
    {
        if((next._row >= 0 && next._row < M) 
           && (next._col >= 0 && next._col < N)) 
        {
            if(_maze[next._row][next._col] == 0)
            {
                return true;
            }
            else if(_maze[next._row][next._col] == 1)
            {
                return false;
            }
            else
            {
                return _maze[next._row][next._col] > _maze[cur._row][cur._col] + 1;
            }
        }
        else
        {
            return false;
        }
    }
    bool GetMazePath(Pos entry)
    {
        stack<Pos> paths;
        paths.push(entry);
        while(!paths.empty())
        {
            //栈顶的坐标就是当前的位置
            Pos cur = paths.top();
            _maze[cur._row][cur._col] = 2;
            if(cur._row == M-1)
            {   
                return true;
            }
            
            Pos next = cur;
            next._row -= 1;
            if(CheckAccess(next))
            {
                paths.push(next);
                continue;
            }
            //下
            next = cur;
            next._row += 1;
            if(CheckAccess(next))
            {
                paths.push(next);
                continue;
            }
            
            //左
            next = cur;
            next._col -= 1;
            if(CheckAccess(next))
            {
                paths.push(next);
                continue;
            }
            //右
            next = cur;
            next._col += 1;
            if(CheckAccess(next))
            {
                paths.push(next);
                continue;
            }
            paths.pop();
        }
        return false;
    }
    //最短路径
    void GetShortPath(Pos entry, stack<Pos>& path, stack<Pos>& shortPath)
    {
        Pos cur = entry;
        path.push(cur);
        //_maze[cur._row][cur._col] = 2;
        if(entry._row == N-1)
        {
            if(shortPath.empty() || path.size() < shortPath.size())
            {
                shortPath = path;
            }
            //return true;
        }
        Pos next = cur;
        next._row -= 1;
        if(CheckAccessShort(next, cur))
        {   
            _maze[next._row][next._col] = _maze[cur._row][cur._col] + 1;
            GetShortPath(next, path, shortPath);
        }
        //GetshortPath(next);


        next = cur;
        next._row += 1;
        if(CheckAccessShort(next, cur))
        {
            _maze[next._row][next._col] = _maze[cur._row][cur._col] + 1;
            GetShortPath(next, path, shortPath);
        }
        next = cur;
        next._col -= 1;
        if(CheckAccessShort(next, cur))
        {
            _maze[next._row][next._col] = _maze[cur._row][cur._col] + 1;
            GetShortPath(next, path, shortPath);
        }
        next = cur;
        next._col += 1;
        if(CheckAccessShort(next, cur))
        {
            _maze[next._row][next._col] = _maze[cur._row][cur._col] + 1;
            GetShortPath(next, path, shortPath);
        }
        //_maze[cur._row][cur._col] = 3;
        path.pop();
        //return false;
        Print();
    }



    bool GetMazePathR(Pos entry)
    {
        Pos cur = entry;
        _maze[cur._row][cur._col] = 2;
        if(entry._row == N-1)
        {
            return true;
        }
        Pos next = cur;

        next._row -= 1;

        //上
        if(CheckAccess(next))
        {
            if(GetMazePathR(next))
            {
                return true;
            }
        }
        //右
        next = cur;
        next._col += 1;
        if(CheckAccess(next))
        {
            if(GetMazePathR(next))
            {
                return true;
            }
        }

        //下
        next = cur;
        next._row += 1;
        if(CheckAccess(next))
        {
            if(GetMazePathR(next))
            {
                return true;
            }
        }
        //左
        next = cur;
        next._col -= 1;
        if(CheckAccess(next))
        {
            if(GetMazePathR(next))
            {
                return true;
            }
        }
        _maze[cur._row][cur._col] = 3;
        return false;


    }
    void Print()
    {
        for(size_t i = 0; i < M; ++i)
        {
            for(size_t j = 0; j < N; ++j)
            {
                cout<<_maze[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    //~Maze() {}

protected:
    int _maze[M][N];

};


void ReadMaze(int maze[10][10])
{
    FILE* fout = fopen("MazeMap.txt", "r");
    assert(fout);

    for(size_t i = 0; i < 10; ++i)
    {
        for(size_t j = 0; j < 10; )
        {
            char ch = fgetc(fout);
            if(ch == '0' || ch == '1' || ch == '2')
            {
                maze[i][j] = ch - '0';
                ++j;
            }
        }
        
    }
}
void TestMaze()
{
    int maze[10][10];
    ReadMaze(maze);
    Maze<10, 10> m(maze);
    //Pos entry;
    //entry._row = 2;
    //entr._col = 0;
    Maze<10, 10>::Pos entry;
    entry._row = 2;
    entry._col = 0;
    //m.GetMazePath(entry);
    //m.GetMazePathR(entry);
    stack<Maze<10, 10>::Pos> path, shortPath;
    m.GetShortPath(entry, path, shortPath);
    //m.Print();


}
