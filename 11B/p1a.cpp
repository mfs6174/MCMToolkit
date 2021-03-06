/*
ID: mfs6174
email: mfs6174@gmail.com
PROG: P1A
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
ofstream ouf("rs1.csv");
//freopen("ti.in","r",stdin);
const int maxlongint=2147483647;

struct D
{
  int h,q;
  double x,y,r;
  bool f;
};

int i,j,k,t,n,m,mz,tt;
double tu[1000][1000],d[1000][1000];
D dian[1000];
double mint[1000],rt[1000];
int tong[1000],shu[1000];
vector<int> guan[1000];

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

void getmin(int a,int b,int x)
{
  int i,t;
  double mm=maxlongint;
  for (i=a;i<=b;i++)
    if (d[i][x]<mm)
    {
      mm=d[i][x];
      t=i;
    }
  tong[t]++;
  rt[t]+=dian[x].r;
  guan[t].push_back(x);
  mint[x]=gettime(mm);
  shu[x]=t;
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
  }
  infb>>m;
  for (i=1;i<=m;i++)
  {
    infb>>t>>tt;
    tu[t][tt]=tu[tt][t]=dst(dian[t],dian[tt]);
  }
  floyd(1,n);
  for (i=21;i<=92;i++)
    getmin(1,20,i);
  for (i=1;i<=20;i++)
  {
    tong[i]++;
    rt[i]+=dian[i].r;
    guan[i].push_back(i);
  }
  for (i=21;i<=92;i++)
    ouf<<i<<';'<<fixed<<setprecision(2)<<mint[i]<<';'<<shu[i]<<endl;
  for (i=1;i<=20;i++)
  {
    ouf<<i<<';'<<tong[i]<<';'<<rt[i]<<" ;";
    for (j=0;j<guan[i].size();j++)
      ouf<<guan[i][j]<<';';
    ouf<<endl;
  }
  return 0;
}

