#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;;
	cin>>n;
	
	vector <pair<int, int>> arr(n);
	
	for(int i =0; i<n; i++)
	{
		cin>>arr[i].first>>arr[i].second;
	}
	
	sort(arr.rbegin(), arr.rend());
	int k =0;
	for(int i =0; i<n; i++)
	{
		k = max(arr[i].second, k);
	}
	
	vector <int> day(k, 0);
	
	int ans =0;
	for(int i =0; i<n; i++)
	{
		bool poss = false;
		for(int j = arr[i].second; j >=0; j--)
		{
			if(day[j] == 0)
			{
				day[j] = -1;
				poss= true;
				break;
			}
		}
		
		if(poss) ans += arr[i].first;
	}
	
	cout<<ans;
}
