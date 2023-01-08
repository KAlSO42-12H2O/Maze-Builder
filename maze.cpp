#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int dx[8]={-1,-1,-1,0,0,1,1,1},dy[8]={-1,0,1,-1,1,-1,0,1};
int hsh(int x,int y)
{
	return x*1000+y;
}
pair<int,int> unhsh(int x)
{
	return make_pair(x/1000,x%1000);
}
char s[505][505];
int f[250005];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
struct edge{
	int u,v;
}G[500005];
void add(int x,int y)
{
	int x1=unhsh(x).first,x2=unhsh(y).first;
	int y1=unhsh(x).second,y2=unhsh(y).second;
	for(int i=2*x1;i<=2*x2;i++)
		for(int j=2*y1;j<=2*y2;j++)
			s[i][j]='A';
}
int m,n;
int main()
{
	printf("The size of your maze:\n");
	scanf("%d",&n);
	srand(time(0));
	int S=rand()%n+1,T=rand()%n+1;
	S=2*S,T=2*T;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n-1;j++)
		{
			G[++m]=edge{hsh(i,j),hsh(i,j+1)};
			G[++m]=edge{hsh(j,i),hsh(j+1,i)};
		}
	random_shuffle(G+1,G+m+1);
	random_shuffle(G+1,G+m+1);
	random_shuffle(G+1,G+m+1);
	for(int i=1;i<=1000*n+n;i++) f[i]=i;
	for(int i=1;i<=m;i++)	
	{
		int u=G[i].u,v=G[i].v;
		if(find(u)==find(v)) continue;
		f[find(u)]=find(v);
		add(u,v);
	}
	n=2*n+1;
	for(int i=1;i<=n;i++) s[i][1]=s[i][n]=s[1][i]=s[n][i]='#';
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s[i][j]=='A') continue;
			bool ok=0;
			for(int k=0;k<8;k++)
			{
				if(s[i+dx[k]][j+dy[k]]=='A')
				{
					ok=1;
					break;
				}
			}
			if(ok) s[i][j]='#';
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(j==1&&i==S) putchar('S');
			else if(j==n&&i==T) putchar('T');
			else
			if(s[i][j]=='#') putchar('#');
			else
			{
				putchar('.');
			}
		}
		puts("");
	}
	return 0;
}
