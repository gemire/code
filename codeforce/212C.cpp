#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
long long gao(int n,int tag,int a[]){//dp[i][j]��ǰi���ַ������������������j��β���������ַ� Ϊ��A�� ʱj==1
	long long dp[110][2]={};
	dp[0][tag]=1;
	for(int i=0;i<n;i++){
		if(!a[i+1]){//���ʱ����Ҫ���1״̬����Ϊ�����ɣ���B����ֻ��AB->BA
			dp[i+1][0]=dp[i][0];
		} else {
			if(a[i]){ 
			     dp[i+1][1]=dp[i][0]+dp[i][1];
			}else {
				 dp[i+1][0]=dp[i-1][0]+dp[i-1][1];// AB->BA
				 dp[i+1][1]=dp[i][0]+dp[i][1];
			}
		}
	}
	return dp[n][tag];
}
int main()
{
	char s[110];
	int n=strlen(gets(s)),a[110];
	int pos=strcspn(s,"B");
	if(pos>=n-1) 
	{
		puts("1");
		return 0;
	}
	for(int i=0;i<n;i++) a[i+1]= (s[(i+pos)%n]=='A');
	printf("%I64d\n",gao(n,0,a)+gao(n,1,a));
	return 0;
}

