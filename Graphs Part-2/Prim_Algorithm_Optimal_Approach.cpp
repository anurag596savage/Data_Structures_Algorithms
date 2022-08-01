#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

bool visited[100001];
int parent[100001];
int weight[100001];

int main()
{
	int n,e;
	cin>>n>>e;
	
	vector<pair<int,int>>v[n];
	
	for(int i=0;i<e;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		
		v[x].push_back(make_pair(y,z));
		v[y].push_back(make_pair(x,z));
	}
	
	for(int i=0;i<n;i++)
	{
		parent[i] = -1;
		weight[i] = INT_MAX;
		visited[i] = false;
	}
	
	weight[0] = 0;
	
	priority_queue< pair<int,int>,vector< pair<int,int> >,greater< pair<int,int> > >pq;
	
	pq.push(make_pair(0,0));
	
	for(int i=0;i<n-1;i++)
	{
		int minVertex = pq.top().second;
		visited[minVertex] = true;
		pq.pop();
		for(int j=0;j<v[minVertex].size();j++)
		{
			int vertex = v[minVertex][j].first;
			int value = v[minVertex][j].second;
			if(!visited[vertex] && value<weight[vertex])
			{
				weight[vertex] = value;
				parent[vertex] = minVertex;
				pq.push(make_pair(value,vertex));
			}
		}
	}
	
	for(int i=1;i<n;i++)
	{
		cout<<min(i,parent[i])<<" "<<max(i,parent[i])<<" "<<weight[i]<<endl;
	}
	
	
	return 0;
}

