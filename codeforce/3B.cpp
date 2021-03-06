/**
 *0-1 knapsack problem,but can't solve with dp. The key things here is that the capacities of items is small
 *(usually 2),so sight in another way.
 *
 */

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool myfunc(pair<int,int> a, pair<int,int> b){
	return a.first > b.first;
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	vector<pair<int,int> > v[3];
	for(int i = 0;i < n;i++){
		int t,p;
		scanf("%d%d",&t,&p);
		v[t].push_back(make_pair(p,i + 1));
	}
	sort(v[1].begin(),v[1].end(),myfunc);
	sort(v[2].begin(),v[2].end(),myfunc);
	int s2 = min(int(v[2].size()), m / 2);
	int s1 = min(int(v[1].size()),m - s2 * 2);
	v[2].resize(s2);
	int i = s1,j = s2;
	while(j > 0 && i < v[1].size() - 1 && v[1][i].first + v[1][i + 1].first > v[2][j - 1].first){
		j--;
		i += 2;
	}
	v[1].resize(i);
	v[2].resize(j);
	int c = 0;
	for(int k = 0;k < i;k++)
		c += v[1][k].first;
	for(int k = 0;k < j;k++)
		c += v[2][k].first;
	printf("%d\n",c);
	for(int k = 0;k < i;k++)
		printf("%d\n",v[1][k].second);
	for(int k = 0;k < j;k++)
		printf("%d\n",v[2][k].second);
	return 0;
}
