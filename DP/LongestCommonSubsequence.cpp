#include <bits/stdc++.h>
using namespace std;

void prints(vector<vector<int>> pos, int n, int m, string str)
{
	if(n == 0 || m== 0) return;
	
	if(pos[n][m] == 2)
	{
		prints(pos, n-1, m-1, str);
		cout<<str[n-1];
	}
	else if(pos[n][m] == 1)
	{
		prints(pos, n, m-1, str);
	}
	else{
		prints(pos, n-1, m, str);
	}
}

int main()
{
	string str1, str2;
	cin>>str1>>str2;
	
	int n = str1.size();
	int m = str2.size();
	
	vector <vector<int>> arr(n+1, vector<int>(m+1, 0));
	vector <vector<int>> pos(n+1, vector<int>(m+1, 0));
	
	for(int i =1; i < n+1; i++)
	{
		for(int j =1; j < m+1; j++)
		{
			if(str1[i] == str2[j])
			{
				arr[i][j] = arr[i-1][j-1]+1;
				pos[i][j] = 2;
			}
			else{
				if(arr[i-1][j] >= arr[i][j-1])
				{
					arr[i][j] = arr[i-1][j];
					pos[i][j] = 3;
				}
				else{
					arr[i][j] = arr[i][j-1];
					pos[i][j] = 1;
				}
			}
		}
	}
	
	cout<<arr[n][m]<<endl;
	
	prints(pos, n, m, str1);
	
}
