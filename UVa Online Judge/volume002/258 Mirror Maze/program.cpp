// Mirror Maze
// UVa IDs: 258
// Verdict: Time Limit Excess
// Submission Date: 2016-05-25
// UVa Run Time: s
//
// 版权所有（C）2016，邱秋。metaphysis # yeah dot net

#include <iostream>
#include <cstring>

using namespace std;

char grid[60][60];
int flapped[60][60], column, row, startx, starty, endx, endy;
int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int mirror[4][2][3] = {{{0, 1, 1}, {0, -1, 3}}, {{-1, 0, 0}, {1, 0, 2}}, {{0, -1, 3}, {0, 1, 1}}, {{1, 0, 2}, {-1, 0, 0}}};
bool found = false;

void dfs(int x, int y, int heading)
{
    if (found)
        return;
        
    int lastx = x, lasty = y, xx = x, yy = y;
    while (xx >= 0 && xx < row && yy >= 0 && yy < column)
    {
        if (grid[xx][yy] == '.')
        {
            lastx = xx;
            lasty = yy;
            
            xx += direction[heading][0];
            yy += direction[heading][1];
        }
    }
    
    if (grid[xx][yy] == '/' || grid[xx][yy] == '\\')
    {
        int reflect = 0;
        if (grid[xx][yy] == '\\')
            reflect = 1;
            
        int xxx = xx + mirror[heading][reflect][0];
        int yyy = yy + mirror[heading][reflect][1];

        if (grid[xxx][yyy] != '*')
        {
            flapped[xx][yy] = 1;
            dfs(xxx, yyy, mirror[heading][reflect][2]);
            flapped[xx][yy] = 0;
        }
        
        if (flapped[xx][yy] == 0)
        {
            flapped[xx][yy] = 1;
            if (grid[xx][yy] == '/')
                grid[xx][yy] = '\\';
            else
                grid[xx][yy] = '/';
            
            reflect = (reflect == 0 ? 1 : 0);
            
            xxx = xx + mirror[heading][reflect][0];
            yyy = yy + mirror[heading][reflect][1];
            
            if (grid[xxx][yyy] != '*')
                dfs(xxx, yyy, mirror[heading][reflect][2]);
            
            if (grid[xx][yy] == '/')
                grid[xx][yy] = '\\';
            else
                grid[xx][yy] = '/';
            flapped[xx][yy] = 0;
        }
    }
    
    if (lastx == endx && lasty == endy)
    {
        found = true;
        
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
                cout << grid[i][j];
            cout << endl;
        }
    }
}

int main(int argc, char *argv[])
{
    bool first = true;
    while (cin >> column >> row, column > 0 && row > 0)
    {
        bool startSetted = false;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < column; j++)
            {
                cin >> grid[i][j];
                if (grid[i][j] == '.')
                {
                    if (i == 0 || i == (row - 1) || j == 0 || j == (column - 1))
                    {
                        if (startSetted == false)
                        {
                            startx = i;
                            starty = j;
                            startSetted = true;
                        }
                        else
                        {
                            endx = i;
                            endy = j;
                        }
                    }
                }
            }

        memset(flapped, 0, sizeof(flapped));
        
        if (first)
            first = false;
        else
            cout << endl;
        
        int heading;
        if (startx == 0 && starty != 0 && starty != (column - 1))
            heading = 2;
        else if (startx == (row - 1) && starty != 0 && starty != (column - 1))
            heading = 0;
        else if (starty == 0 && startx != 0 && startx != (row - 1))
            heading = 1;
        else if (starty == (column - 1) && startx != 0 && startx != (row - 1))
            heading = 3;
        
        found = false;    
        dfs(startx, starty, heading);
    }
    
	return 0;
}