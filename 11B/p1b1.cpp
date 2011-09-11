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
ifstream inf5("data5.txt");
ofstream ouf("rs13.csv");
//freopen("ti.in","r",stdin);
const int maxlongint=2147483647;

struct D
{
  int h,q,c;
  double x,y,r;
  bool f;
  int dao[1000];
};

int i,j,k,t,n,m,q,tt;
double tu[1000][1000],d[1000][1000];
D dian[1000];
double mint[1000],rt[1000];
int tong[1000],shu[1000];
vector<int> guan[1000];
int you[1000];
int zhen[100][20];

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
int main()
{
  inf>>n;
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
      tu[i][j]=maxlongint;
  for (i=1;i<=n;i++)
  {
    inf>>dian[i].x>>dian[i].y;
    tu[i][i]=0;
  }
  infb>>m;
  for (i=1;i<=m;i++)
  {
    infb>>t>>tt;
    tu[t][tt]=tu[tt][t]=dst(dian[t],dian[tt]);
  }
  inf5>>q;
  for (i=1;i<=q;i++)
    inf5>>you[i];
  floyd(1,n);
  for (i=1;i<=92;i++)
    for (j=1;j<=q;j++)
    {
      double mm=maxlongint;
      int t;
      for (k=1;k<=20;k++)
        if (d[k][you[j]]<mm)
        {
          mm=d[k][you[j]];
          t=k;
        }
      if (mm<=d[i][you[j]])
        zhen[i][j]=t;
      else
        zhen[i][j]=0;
    }
  ouf<<"0;";
  for (i=1;i<=q;i++)
    ouf<<you[i]<<';';
  ouf<<endl;
  for (i=1;i<=92;i++)
  {
    ouf<<i<<';';
    int cc=0;
    for (j=1;j<=q;j++)
    {
      ouf<<zhen[i][j]<<';';
      if (zhen[i][j])
        cc++;
    }
    ouf<<(double)cc/q<<endl;
  }
  return 0;
}

