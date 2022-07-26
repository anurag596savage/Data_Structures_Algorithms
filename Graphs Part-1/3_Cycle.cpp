#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

void Count_Distinct_3_Cycles(int** edges,int n,int& count)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(edges[i][j]==1)
			{
				for(int k=0;k<n;k++)
				{
					if(edges[j][k]==1 && edges[k][i]==1)
					{
						count++;
					}
				}
			}
		}
	}
	
	count = count/6;
}

int main()
{
	int n,e;
	cin>>n>>e;
	
	int** edges = new int*[n];
	for(int i=0;i<n;i++)
	{
		edges[i] = new int[n];
		for(int j=0;j<n;j++)
		{
			edges[i][j] = 0;
		}
	}
	
	for(int i=0;i<e;i++)
	{
		int f,s;
		cin>>f>>s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}
	
	int count = 0;
	Count_Distinct_3_Cycles(edges,n,count);
	
	cout<<count<<endl;
	
	return 0;
}

