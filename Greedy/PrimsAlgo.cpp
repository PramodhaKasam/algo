#include <bits/stdc++.h>
using namespace std;

void prims(vector <vector<int>> graph, int n)
{
	vector <int> parent(n, -1);
	vector <int> key(n, INT_MAX);
	
	key[0] = 0;
	vector <int> visited(n, false);
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, 0});
	
	while(!pq.empty())
	{
		int u = pq.top().second;
		
		pq.pop();
		
		if(visited[u]) continue;
		
		visited[u] = true;
		
		for(int v =0; v<n; v++)
		{
			if(graph[u][v] && !visited[v] && key[v] > graph[u][v] )
			{
				key[v] = graph[u][v];
				parent[v] = u;
				pq.push({graph[u][v], v});
			}
		}
	}
	
	for(int i =1; i<n; i++)
	{
		cout<<parent[i]<<" -> "<< key[i]<<endl;
	}
	
}

int main()
{
	int n = 5;
	vector <vector<int>> graph = 
	{
		{0, 2, 0, 5, 2},
		{2, 0, 3, 0, 4}, 
		{0, 3, 0, 5, 0},
		{5, 0, 5, 0, 2},
		{2, 4, 0, 2, 0}
	};
	
	prims(graph, n);
		
		
}
