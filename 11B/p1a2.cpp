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
ifstream inf4("data4.txt");
ofstream ouf("rs11.csv");
//freopen("ti.in","r",stdin);
const int maxlongint=2147483647;

struct D
{
  int h,q;
  double x,y,r;
  bool f;
};

int i,j,k,t,n,m,mm,tt;
double tu[1000][1000],d[1000][1000];
D dian[1000];
double mint[1000],rt[1000],rrt[1000],zongr[1000],mmd;
int tong[1000],shu[1000];
vector<int> guan[1000];
int ff[100],ji[1000],rr[100],rrj[100],zong[1000];
bool cnot[1000];
int qu[10][3]={{0},{1,20},{93,100},{166,182},{320,328},{372,386},{475,485}};
int jie[10]={0,92,73,154,52,103,108};

inline double dst(D &a,D &b)
{
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

inline double gettime(double d)
{
  return d/10.0;
}

inline int getnum(int x)
{
  int i,m=0;
  for (i=1;i<=5;i++)
  {
    if (x>m&&x<=m+jie[i])
      return i;
    m+=jie[i];
  }
  return i;
}

void floyd(int a,int n)
{
  int i,j,k;
  double t;
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

void getmin(int x)
{
  int i,t,h=getnum(x);
  double mm=maxlongint;
  for (i=qu[h][0];i<=qu[h][1];i++)
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
      zong[i]++;
      zongr[i]+=dian[x].r;
    }
  }
  if (gettime(mm)>3.0)
  {
    ji[t]++;
    rt[t]+=dian[x].r;
    ff[x]=t;
    cnot[x]=true;
  }
}

void dfs(int x)
{
  int i,j;
  if (x>n)
  {
    int md=-1,mx=maxlongint;
    double mdd=-1,mdx=maxlongint;
    for (j=1;j<=6;j++)
      for (i=qu[j][0];i<=qu[j][1];i++)
      {
        md=max(md,ji[i]);
        mx=min(mx,ji[i]);
        mdd=max(mdd,rt[i]);
        mdx=min(mdx,rt[i]);
      }
    mmd=mdd-mdx;
    mm=md-mx;
    memcpy(rr,ff,sizeof(rr));
    memcpy(rrj,ji,sizeof(rrj));
    memcpy(rrt,rt,sizeof(rrt));
    return;
  }
  if (cnot[x]||dian[x].f)
    dfs(x+1);
  else
  {
    double  mmm=maxlongint,mm2=0;
    int t;
    for (i=0;i<tong[x];i++)
    {
      if (rt[guan[x][i]]<mmm)
      {
        mmm=rt[guan[x][i]];
        mm2=zongr[guan[x][i]];
        t=guan[x][i];
      }
      else
        if (rt[guan[x][i]]==mmm)
          if (zongr[guan[x][i]]<mm2)
          {
            mm2=zong[guan[x][i]];
            t=guan[x][i];
          }
    }
    ff[x]=t;
    ji[t]++;
    rt[t]+=dian[x].r;
    dfs(x+1);
  }
}

int main()
{
  inf>>n;
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
      tu[i][j]=maxlongint;
  for (i=1;i<=n;i++)
  {
    inf>>dian[i].x>>dian[i].y;
    inf4>>dian[i].r;
    tu[i][i]=0;
  }
  infb>>m;
  for (i=1;i<=m;i++)
  {
    infb>>t>>tt;
    tu[t][tt]=tu[tt][t]=dst(dian[t],dian[tt]);
  }
  floyd(1,n);
  for (j=1;j<=6;j++)
    for (i=qu[j][0];i<=qu[j][1];i++)
    {
      dian[i].f=true;
      ji[i]++;zong[i]++;
      rt[i]+=dian[i].r;zongr[i]+=dian[i].r;
    }
  for (i=1;i<=n;i++)
    if (!dian[i].f)
      getmin(i);
  mm=maxlongint;
  dfs(21);
  cout<<mm<<' '<<mmd<<endl;
  for (i=1;i<=n;i++)
    if (!dian[i].f)
      ouf<<i<<';'<<fixed<<setprecision(3)<<gettime(d[rr[i]][i])<<';'<<rr[i]<<endl;
  for (i=1;i<=n;i++)
    if (dian[i].f)
      ouf<<i<<';'<<zong[i]<<';'<<rrj[i]<<';'<<zongr[i]<<';'<<rrt[i]<<endl;
  return 0;
}

