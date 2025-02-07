#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector <pair<int, int>> time(n);
	
	for(int i =0; i<n; i++)
	{
		cin>>time[i].second>>time[i].first;
	}
	
	sort(time.begin(), time.end());
	
	vector <int> ans = {0};
	int i =0;
	for(int j= 1; j< n; j++)
	{
		if(time[j].second >= time[i].first)
		{
			ans.push_back(j);
			i = j;
		}
	} 
	
	for(int i =0; i<(int)ans.size(); i++)
	{
		cout<<ans[i]<<" ";
	}
}
