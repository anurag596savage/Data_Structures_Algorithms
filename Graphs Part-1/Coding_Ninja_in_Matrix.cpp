#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

bool visited[1001][1001];

bool hasPath(vector<vector<char>> &board, int n, int m,int i,int j,string s,int index)
{
	if(index==s.length())
	{
		return true;
	}
	if(j+1<m) // Towards right
	{
		if(!visited[i][j+1] && board[i][j+1]==s[index])
		{
			visited[i][j+1] = true;
			if(hasPath(board,n,m,i,j+1,s,index+1))
			{
				return true;
			}
			visited[i][j+1] = false;
		}
	}
	if(i+1<n) // Towards down
	{
		if(!visited[i+1][j] && board[i+1][j]==s[index])
		{
			visited[i+1][j] = true;
			if(hasPath(board,n,m,i+1,j,s,index+1))
			{
				return true;
			}
			visited[i+1][j] = false;
		}
	}
	if(j-1>=0) // Towards left
	{
		if(!visited[i][j-1] && board[i][j-1]==s[index])
		{
			visited[i][j-1] = true;
			if(hasPath(board,n,m,i,j-1,s,index+1))
			{
				return true;
			}
			visited[i][j-1] = false;
		}
	}
	
	if(i-1>=0) // Towards up
	{
		if(!visited[i-1][j] && board[i-1][j]==s[index])
		{
			visited[i-1][j] = true;
			if(hasPath(board,n,m,i-1,j,s,index+1))
			{
				return true;
			}
			visited[i-1][j] = false;
		}
	}
	
	if(i-1>=0 && j-1>=0) // Towards upward left
	{
		if(!visited[i-1][j-1] && board[i-1][j-1]==s[index])
		{
			visited[i-1][j-1] = true;
			if(hasPath(board,n,m,i-1,j-1,s,index+1))
			{
				return true;
			}
			visited[i-1][j-1] = false;
		}
	}
	
	if(i+1<n && j+1<m) // Towards downward right
	{
		if(!visited[i+1][j+1] && board[i+1][j+1]==s[index])
		{
			visited[i+1][j+1] = true;
			if(hasPath(board,n,m,i+1,j+1,s,index+1))
			{
				return true;
			}
			visited[i+1][j+1] = false;
		}
	}
	
	if(i+1<n && j-1>=0) // Towards downward left
	{
		if(!visited[i+1][j-1] && board[i+1][j-1]==s[index])
		{
			visited[i+1][j-1] = true;
			if(hasPath(board,n,m,i+1,j-1,s,index+1))
			{
				return true;
			}
			visited[i+1][j-1] = false;
		}
	}
	
	if(i-1>=0 && j+1<m) // Towards upward right
	{
		if(!visited[i-1][j+1] && board[i-1][j+1]==s[index])
		{
			visited[i-1][j+1] = true;
			if(hasPath(board,n,m,i-1,j+1,s,index+1))
			{
				return true;
			}
			visited[i-1][j+1] = false;
		}
	}
	
	return false;
	
}

bool hasPath(vector<vector<char>> &board, int n, int m)
{
	string s = "CODINGNINJA";
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
            visited[i][j] = false;
        }
    }
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(board[i][j]==s[0])
			{
				visited[i][j] = true;
				if(hasPath(board,n,m,i,j,s,1))
				{
					return true;
				}
				visited[i][j] = false;
			}
		}
	}
	
	return false;
}

int main()
{
	int n,m;
	cin>>n>>m;
	
	vector<vector<char>> board(n, vector<char>(m));
	for (int i=0; i<n;i++) 
	{
		string s;
		cin>>s;
        for(int j=0;j<s.length();j++)
        {
        	board[i][j] = s[j];
        }
    }
	
	bool ans = hasPath(board,n,m);
	cout<<ans<<endl;
	
	return 0;
}

