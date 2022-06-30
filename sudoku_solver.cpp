#include<bits/stdc++.h>

using namespace std;


int n = 9;

bool check(vector<vector<int>> board,int i,int j,int c)
{
    for(int k=0;k<9;k++)
    {
        if(board[i][k]==c || board[k][j]==c)
            return false;
    }
        
    int startr = 3*(i/3);
    int startc = 3*(j/3);
    
    for(int x=startr;x<startr+3;x++)
    {
        for(int y=startc;y<startc+3;y++)
        {
            if(board[x][y]==c)
                return false;
        }
    }
        
    return true;
}


bool solve(vector<vector<int>>& board,int i,int j)
{
    if(i==9) return true;
    if(j==9) return solve(board,i+1,0);
        
    if(board[i][j]!=0) return solve(board,i,j+1);
       
    for(int c=1;c<=9;c++)
    {
        if(check(board,i,j,c))
        {
            board[i][j] = c;
            if(solve(board,i,j+1)) return true;
            board[i][j] = 0;
        }
    }
        
    return false;
}


bool solveSudoku(vector<vector<int>>& a)
{
    n = 9;
    if(solve(a,0,0))
    {
        return true;
    }
    else
    {
        cout << "No Solution" << endl;
        return false;
    }
}



int main()
{
    vector<vector<int>> board;

    for(int i=0;i<9;i++)
    {
        board.push_back({});
        for(int j=0;j<9;j++)
        {
            int t;
            cin >> t;
            board[i].push_back(t);
        }
    }

    if(!solveSudoku(board))
        return 0;

    cout << "\nThe solution is:" << endl;

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}