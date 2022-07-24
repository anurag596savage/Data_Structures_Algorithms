#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

vector<int> Get_Path_BFS(int** edges,int n,int start,int end,bool* visited)
{
	if(start==end)
	{
		vector<int>v;
		v.push_back(start);
		return v;
	}
	
	queue<int>q;
	q.push(start);
	unordered_map<int,int>ParentMap;
	ParentMap[start] = -1;
	visited[start] = true;
	vector<int>v;
	while(!q.empty())
	{
		int element = q.front();
		q.pop();
		for(int i=0;i<n;i++)
		{
			if(!visited[i] && edges[i][element]==1)
			{
				q.push(i);
				ParentMap[i] = element;
				visited[i] = true;
				if(i==end)
				{
					v.push_back(i);
					int child = i;
					while(ParentMap[child]!=-1)
					{
						v.push_back(ParentMap[child]);
						child = ParentMap[child];
					}
					break;
				}
			}
		}
	}
	
	return v;
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
	
	int start,end;
	cin>>start>>end;
	
	bool* visited = new bool[n];
	for(int i=0;i<n;i++)
	{
		visited[i] = false;
	}
	
	vector<int>ans = Get_Path_BFS(edges,n,start,end,visited);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}





