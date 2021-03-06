#define MAX_N 1000
int par[MAX_N];
int rank[MAX_N];

int init(){
	for(int i = 0;i < MAX_N;i++){
		par[i] = i;
		rank[i] = 0;
	}
}

int find(int x){
	if(par[x] == x)
		return x;
	return par[x] = find(par[x]);
}

void unite(int x, int y){
	x = find(x);
	y = find(y);
	if(x == y)
		return;
	if(rank[x] < rank[y])
		par[x] = y;
	else{
		par[y] = x;
		if(rank[x] == rank[y])
			rank[x]++;
	}
}
