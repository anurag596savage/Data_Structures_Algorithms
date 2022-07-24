#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

vector<int> Get_Connnected_Components(int** edges,int n,int current,bool* visited,vector<int>& v)
{
	v.push_back(current);
	visited[current] = true;
	for(int i=0;i<n;i++)
	{
		if(!visited[i] && edges[i][current])
		{
			Get_Connnected_Components(edges,n,i,visited,v);
		}
	}
	
	return v;
}

vector<vector<int>> Get_Connnected_Components(int** edges,int n)
{
	vector<vector<int>>ans;
	bool* visited = new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i] = false;
	}
	
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			vector<int>v;
			Get_Connnected_Components(edges,n,i,visited,v);
			ans.push_back(v);
		}
	}
	
	return ans;
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
		
		edges[s][f] = 1;
		edges[f][s] = 1;
	}
	
	vector<vector<int>>ans = Get_Connnected_Components(edges,n);
	
	for(int i=0;i<ans.size();i++)
	{
        sort(ans[i].begin(),ans[i].end());
		for(int j=0;j<ans[i].size();j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}

