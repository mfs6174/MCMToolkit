/*
ID: mfs6174
email: mfs6174@gmail.com
PROG: ti
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
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.in","r",stdin);
const int maxlongint=2147483647;

struct D
{
  double l;
  int a,b;
  bool operator<(const D &x) const
  {
    return l<x.l;
  }
};

void init(int n)
{
  int i;
  for (i=1;i<=n;i++)
    ff[i]=i;
}

int cha(int x)
{
	if (ff[x]==x)
		return x;
	ff[x]=cha(ff[x]);
	return ff[x];
}

void bing(int x,int y)
{
	int i,j;
	i=cha(x);j=cha(y);
	if (i!=j)
	ff[i]=j;//总根为标志，把总根挂到另一个的总根下
}

int main()
{
  freopen("park.in","r",stdin);
  for (i=1;i<=8;i++)
    dian[i].input();
  for (i=1;i<=4;i++)
    dian[8+i].input();
  n=12;m=0;
  //连边方式1
  for (i=1;i<=8;i++)
    for (j=i+1;j<=8;j++)
      if (dian[i].x!=dian[j].x&&dian[i].y!=dian[j].y)
      {
        m++;
        bian[m].a=i;bian[m].b=j;
        bian[m].l=dst(dian[i],dian[j]);
      }
  for (i=9;i<=n;i++)
    for (j=i+1;j<=n;j++)
    {
      m++;
      bian[m].a=i;bian[m].b=j;
      bian[m].l=dst(dian[i],dian[j]);
    }
  for (i=1;i<=8;i++)
    for (j=9;j<=n;j++)
    {
      m++;
      bian[m].a=i;bian[m].b=j;
      bian[m].l=dst(dian[i],dian[j]);
    }
  //最小生成树
  sort(&bian[1],&bian[m+1]);
  init(n);
  s=0;
  for (i=1;i<=m;i++)
    if (cha(bian[i].a)!=cha(bian[i].b))
    {
      bing(bian[i].a,bian[i].b);
      s+=bian[i].l;
      yong[i]=true;
      printf("%d  %d\n",bian[i].a,bian[i].b);
    }
  printf("\n%.4lf\n",s);
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
      dd[i][j]=md[i][j]=INF;
  for (i=1;i<=m;i++)
  {
    if (yong[i])
    {
      dd[bian[i].a][bian[i].b]=dd[bian[i].b][bian[i].a]=bian[i].l;
      md[bian[i].a][bian[i].b]=md[bian[i].b][bian[i].a]=bian[i].l;
    }
  }
  for (k=1;k<=n;k++)
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        if (md[i][k]<INF&&md[k][j]<INF)
          if (md[i][k]+md[k][j]<md[i][j])
            md[i][j]=md[i][k]+md[k][j];
  printf("\n");
  for (i=1;i<=8;i++)
    for (j=i+1;j<=8;j++)
      if (md[i][j]>dst(dian[i],dian[j])*1.4)
        printf("%d  %d  %.3lf  %.3lf\n",i,j,md[i][j],dst(dian[i],dian[j]));
  printf("\n");
  for (i=1;i<=8;i++)
    for (j=i+1;j<=8;j++)
      if (dian[i].x!=dian[j].x&&dian[i].y!=dian[j].y)
        printf("%d  %d  %.3lf\n",i,j,dst(dian[i],dian[j]));
  return 0;
}

  
