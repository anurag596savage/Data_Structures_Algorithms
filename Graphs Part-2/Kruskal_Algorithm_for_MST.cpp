#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

class edge
{
	public : 
	
	int v1;
	int v2;
	int weight;	
};

bool compare(edge a,edge b)
{
	return a.weight<b.weight;
}

int main()
{
	int n,e;
	cin>>n>>e;
	edge* arr = new edge[e];
	for(int i=0;i<e;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		arr[i].v1 = x;
		arr[i].v2 = y;
		arr[i].weight = z;
	}
	
	int* parent = new int[n];
	for(int i=0;i<n;i++)
	{
		parent[i] = i;
	}
	
	edge* ans = new edge[n-1];
	
	sort(arr,arr+e,compare);
	
	int i=0,count=0;
	
	while(count!=n-1)
	{
		int current_v1 = arr[i].v1;
		int current_v2 = arr[i].v2;
		int p1,p2;
		while(parent[current_v1]!=current_v1)
		{
			current_v1 = parent[current_v1];
		}
		p1 = current_v1;
		while(parent[current_v2]!=current_v2)
		{
			current_v2 = parent[current_v2];
		}
		p2 = current_v2;
		if(p1!=p2)
		{
			ans[count].v1 = arr[i].v1;
			ans[count].v2 = arr[i].v2;
			ans[count].weight = arr[i].weight;
			
			// Connecting the parent nodes
			parent[p1] = p2;
			
			count++;
		}
		
		i++;
	}
	
	for(int i=0;i<n-1;i++)
	{
		cout<<min(ans[i].v1,ans[i].v2)<<" "<<max(ans[i].v1,ans[i].v2)<<" "<<ans[i].weight<<endl;
	}
	
	return 0;
}

