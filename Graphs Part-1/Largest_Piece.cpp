#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

bool visited[1001][1001];

int x_direction[] = {0,1,0,-1};
int y_direction[] = {1,0,-1,0};

bool isValid(int n,int x,int y)
{
	return (x>=0 && x<n && y>=0 && y<n);
}

void getBiggestPieceSize(vector<vector<int>> &cake, int n,int i,int j,int& count)
{
	
	int ans = count;
	for(int k=0;k<4;k++)
	{
		int new_x = i+x_direction[k];
		int new_y = j+y_direction[k];
		if(!isValid(n,new_x,new_y))
		{
			continue;
		}
		if(!visited[new_x][new_y] && cake[new_x][new_y]==1)
		{
			visited[new_x][new_y] = true;
			count = count+1;
			getBiggestPieceSize(cake,n,new_x,new_y,count);
			ans = max(ans,count);
		}
	}
	
	count = ans;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			visited[i][j] = false;
		}
	}
	
	int ans = 0;
	int count = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(!visited[i][j] && cake[i][j]==1)
			{
				visited[i][j] = true;
				count=1;
				getBiggestPieceSize(cake,n,i,j,count);
				if(count>ans)
				{
					ans = count;
				}
			}
		}
	}
	
	return ans;
}

int main()
{
	int n;
	cin>>n;
	
	vector<vector<int>>cake(n,vector<int>(n));
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>cake[i][j];
		}
	}
	
	cout<<getBiggestPieceSize(cake,n)<<endl;
	
	return 0;
}

