#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

bool visited[1001][1001];

bool hasCycle(vector<vector<char>> &board, int n, int m,int i,int j,char color,int count,int x,int y)
{
	if(j+1<m)
	{
        if(x==i && y==j+1)
        {
            
        }
		else if(board[i][j+1]==color)
		{
			if(visited[i][j+1] && count>=4)
			{
				return true;
			}
			else
			{
				visited[i][j+1] = true;
				if(hasCycle(board,n,m,i,j+1,color,count+1,i,j))
				{
					return true;
				}
				visited[i][j+1] = false;
			}
		}
	}
	
	if(i+1<n)
	{
        if(x==i+1 && y==j)
        {
            
        }
		else if(board[i+1][j]==color)
		{
			if(visited[i+1][j] && count>=4)
			{
				return true;
			}
			else
			{
				visited[i+1][j] = true;
				if(hasCycle(board,n,m,i+1,j,color,count+1,i,j))
				{
					return true;
				}
				visited[i+1][j] = false;
			}
		}
	}
	
	if(j-1>=0)
	{
        if(x==i && y==j-1)
        {
            
        }
		else if(board[i][j-1]==color && count>=4)
		{
			if(visited[i][j-1])
			{
				return true;
			}
			else
			{
				visited[i][j-1] = true;
				if(hasCycle(board,n,m,i,j-1,color,count+1,i,j))
				{
					return true;
				}
				visited[i][j-1] = false;
			}
		}
	}
	
	if(i-1>=0)
	{
        if(x==i-1 && y==j)
        {
            
        }
		else if(board[i-1][j]==color && count>=4)
		{
			if(visited[i-1][j])
			{
				return true;
			}
			else
			{
				visited[i-1][j] = true;
				if(hasCycle(board,n,m,i-1,j,color,count+1,i,j))
				{
					return true;
				}
				visited[i-1][j] = false;
			}
		}
	}
	
	return false;
}

bool hasCycle(vector<vector<char>> &board, int n, int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			visited[i][j] = false;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			visited[i][j] = true;
			char color = board[i][j];
			if(hasCycle(board,n,m,i,j,color,1,-1,-1))
			{
				return true;
			}
			visited[i][j] = false;
		}
	}
	
	return false;
}

int main()
{
	int n,m;
	cin>>n>>m;
	
	vector<vector<char>> board(n,vector<char>(m));
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>board[i][j];
		}
	}
	
	cout<<endl;
	
	cout<<(hasCycle(board,n,m)?"true":"false")<<endl;
	
	
	return 0;
}

