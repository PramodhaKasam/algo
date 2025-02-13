#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int n, e;
public:
	Graph(int i, int j)
	{
		n= i;
		e= j;
	}
	vector <vector<pair<int, int>>> adj;
	void addEdge(int a, int b, int wt)
	{
		adj[a-1].push_back({b-1, wt});
	}
};

int Bellman(vector<int>& dist, int n, int e, Graph& g1)
{
	for(int j =0; j<n-1; j++)
	{
		for(int i =0; i<n; i++)
		{
			for(auto it: g1.adj[i])
			{
				int y = it.first;
				int z = it.second;
				
				if(dist[y] > dist[i] + z)
				{
					dist[y] = dist[i] + z;
				}
			}
		}
	}
	
	for(int i =0; i<n; i++)
	{
		for(auto it: g1.adj[i])
		{
			int y = it.first;
			int z = it.second;
			
			if(dist[y] > dist[i] + z)
			{
				return -1;
			}
		}
	}
	
	return 0;
}


int main()
{
	int n, e;
	cin>>n>>e;
	Graph g1(n, e);
	g1.adj.resize(n);
	for(int i =0; i<e; i++)
	{
		int x, y, z;
		cin>>x>>y>>z;
		
		g1.addEdge(x, y, z);
	}
	
	vector <int> dist(n);
	dist[0] =0;
	
	int z= Bellman(dist, n, e, g1);
	
	if(z == -1) cout<<"Negative cycle detected";
	else
	{
		for(int i =0; i<n;i++)
		{
			cout<<dist[i]<<" ";
		}
	}
}
