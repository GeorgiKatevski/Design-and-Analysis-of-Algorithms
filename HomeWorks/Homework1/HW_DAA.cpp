#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;




int next(vector<int>& arr, int target, int end)
{
	int start = 0;

	int ans = -1;
	while (start <= end)
	{
		int mid = (start + end) / 2;

		// Move to right side if target is 
		// greater. 
		if (arr[mid] <= target)
			start = mid + 1;

		// Move left side. 
		else
		{
			ans = mid;
			end = mid - 1;
		}
	}

	return ans;
}



// Driver code 
int main()
{
	int n;
	scanf("%d", &n);
	vector<int> vec(n);
	for (int m = 0; m < n; m++)
	{
		int k;
		scanf("%d", &k);
		vec[m] = k;
	}
	int M;
	scanf("%d", &M);
	
	vector<pair<int,int>> vec2(M);
	for (int i = 0; i < M; i++)
	{
		pair<int, int> p;
		int k1;
		scanf("%d", &k1);
		int k2;
		scanf("%d", &k2);
		p.first = k1;
		p.second = k2;
		vec2[i] = p;
	}

	for (int i = 0; i < M; i++)
	{
		int g1 = next(vec,vec2[i].first,vec.size());
		int g2 = next(vec, vec2[i].second, vec.size());

		printf("%d\n", g2 - g1);

	}


	return 0;
}
