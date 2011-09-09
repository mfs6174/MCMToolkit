/*
ID: mfs6174
email: mfs6174@gmail.com
PROG: P1A1
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<deque>
#include<iomanip>
#include<cmath>
#include<set>
#define sf scanf
#define pf printf
#define llg long long 

using namespace std;
ifstream inf("data1.txt");
ifstream infb("data3.txt");
ofstream ouf("rs1.csv");
//freopen("ti.in","r",stdin);
const int maxlongint=2147483647;

struct D
{
  int h,q;
  double x,y;
  bool f;
};

int i,j,k,t,n,m,mm,tt;
double tu[1000][1000],d[1000][1000];
D dian[1000];
double mint[1000];
int tong[1000],shu[1000];
vector<int> guan[1000];
int ff[100],ji[1000],rr[100];
bool cnot[1000];

inline double dst(D &a,D &b)
{
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

inline double gettime(double d)
{
  return d/10.0;
}

void floyd(int a,int n)
{
  int i,j,k,t;
  for (i=a;i<=n;i++)
    for (j=a;j<=n;j++)
      d[i][j]=tu[i][j];
  for (k=a;k<=n;k++)
    for (i=a;i<=n;i++)
      for (j=a;j<=n;j++)
        if (d[i][k]!=maxlongint&&d[k][j]!=maxlongint)
        {
          t=d[i][k]+d[k][j];
          if (t<d[i][j])
            d[i][j]=t;
        }
}

void getmin(int a,int b,int x)
{
  int i,t;
  double mm=maxlongint;
  for (i=a;i<=b;i++)
  {
    if (d[i][x]<mm)
    {
      mm=d[i][x];
      t=i;
    }
    if (gettime(d[i][x])<=3.0)
    {
      guan[x].push_back(i);
      tong[x]++;
    }
  }
  if (gettime(mm)>3.0)
  {
    ji[t]++;
    ff[x]=t;
    cnot[x]=true;
  }
}

void dfs(int x)
{
  int i;
  if (x>92)
  {
    int md=-1,mx=maxlongint;
    for (i=1;i<=20;i++)
    {
      md=max(md,ji[i]);
      mx=min(mx,ji[i]);
      if (md-mx<mm)
      {
        mm=md-mx;
        memcpy(rr,ff,sizeof(ff));
      }
    }
    return;
  }
  if (cnot[x])
    dfs(x+1);
  else
  {
    int  mmm=maxlongint,t;
    for (i=0;i<tong[x];i++)
    {
      if (ji[guan[x][i]]<mmm)
      {
        mmm=ji[guan[x][i]];
        t=guan[x][i];
      }
    }
    ff[x]=t;
    ji[t]++;
    dfs(x+1);
    ji[t]--;
  }
}

int main()
{
  inf>>n;
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
      tu[i][j]=maxlongint;
  for (i=1;i<=n;i++)
    inf>>dian[i].x>>dian[i].y;
  infb>>m;
  for (i=1;i<=m;i++)
  {
    infb>>t>>tt;
    tu[t][tt]=tu[tt][t]=dst(dian[t],dian[tt]);
  }
  floyd(1,n);
  for (i=21;i<=92;i++)
    getmin(1,20,i);
  mm=maxlongint;
  dfs(21);
  cout<<mm<<endl;
  for (i=21;i<=92;i++)
    ouf<<i<<';'<<fixed<<setprecision(2)<<gettime(d[rr[i]][i])<<';'<<rr[i]<<endl;
  for (i=1;i<=20;i++)
    ouf<<i<<';'<<ji[i]<<endl;
  return 0;
}

