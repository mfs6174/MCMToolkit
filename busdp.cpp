/*
ID: mfs6174
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
#define sf scanf
using namespace std;
//ifstream inf("data1.txt");
ofstream ouf("out.txt");
const int maxlongint=2147483647;

struct D
{
  int z,w,m;
};
struct B
{
  int t,n,nn,m;
  int l[100],ll[100];
};

vector<D> hash[10000];
int zhan[10000],xian[10000];
int i,j,t,n,m,shi,zhong,zc,lc,dp;
B ch[1000];
char tc;
D td;
bool ff[10000];
int f[5][11000],ot[5][11000];

int val(const string &x)
{
    istringstream t(x);
    int r;
    t>>r;
    return r;
}

void rm()
{
  int i,j,h,t,tt;
  while (sf("%d",&h)!=EOF&&h)
  {
    sf("%d%d",&ch[h].t,&tt);
    if (tt==1)
    {
      sf("%d%c",&t,&tc);
      ch[h].m=2;
      while (tc!='\n')
      {
        ch[h].n++;
        ch[h].l[ch[h].n]=t;
        td.z=h;td.w=0;td.m=ch[h].n;
        hash[t].push_back(td);
        sf("%d%c",&t,&tc);
      }
      ch[h].n++;
      ch[h].l[ch[h].n]=t;
      td.z=h;td.w=0;td.m=ch[h].n;
      hash[t].push_back(td);
      sf("%d",&j);
      sf("%d%c",&t,&tc);
      while (tc!='\n')
      {
        ch[h].nn++;
        ch[h].ll[ch[h].nn]=t;
        td.z=h;td.w=1;td.m=ch[h].nn;
        hash[t].push_back(td);
        sf("%d%c",&t,&tc);
      }
      ch[h].nn++;
      ch[h].ll[ch[h].nn]=t;
      td.z=h;td.w=1;td.m=ch[h].nn;
      hash[t].push_back(td);
      continue;
    }
    if (tt==0)
    {
      sf("%d%c",&t,&tc);
      ch[h].m=1;
      while (tc!='\n')
      {
        ch[h].n++;
        ch[h].l[ch[h].n]=t;
        td.z=h;td.w=0;td.m=ch[h].n;
        hash[t].push_back(td);
        sf("%d%c",&t,&tc);
      }
      ch[h].n++;
      ch[h].l[ch[h].n]=t;
      td.z=h;td.w=0;td.m=ch[h].n;
      hash[t].push_back(td); 
      for (i=1;i<=ch[h].n;i++)
      {
        ch[h].l[ch[h].n+i]=ch[h].l[i];
        td.z=h;td.w=0;td.m=ch[h].n+i;
        hash[ch[h].l[i]].push_back(td);
      }
      ch[h].n*=2;
      continue;
    }
    ch[h].m=2;
    ch[h].n=1;
    ch[h].l[1]=tt;
    td.z=h;td.w=0;td.m=1;
    hash[tt].push_back(td);   
    sf("%d%c",&t,&tc);
    while (tc!='\n')
    {
      ch[h].n++;
      ch[h].l[ch[h].n]=t;
      td.z=h;td.w=0;td.m=ch[h].n;
      hash[t].push_back(td); 
      sf("%d%c",&t,&tc);
    }
    ch[h].n++;
    ch[h].l[ch[h].n]=t;
    td.z=h;td.w=0;td.m=ch[h].n;
    hash[t].push_back(td);   
    for (i=ch[h].n;i>=1;i--)
    {
      ch[h].nn++;
      ch[h].ll[ch[h].nn]=ch[h].l[i];
      td.z=h;td.w=1;td.m=ch[h].nn;
      hash[ch[h].l[i]].push_back(td); 
    }
  }
}

int suan(int x,int s)
{
  if (ch[x].t==1)
    return 1;
  if (s<=20)
    return 1;
  if (s<=40)
    return 2;
  return 3;
}


void dfs(int x,int p,int ti,D l)
{
  int i,j,pp=0,tt=5,n;
  if (l.w==0)
  {
    n=ch[l.z].n;
    for (i=l.m+1;i<=n;i++)
    {
      tt+=3;
      pp++;
      f[x+1][ch[l.z].l[i]]=min(f[x+1][ch[l.z].l[i]],ti+tt);
      if (f[x+1][ch[l.z].l[i]]==ti+tt)
        ot[x+1][ch[l.z].l[i]]=min(p+suan(l.z,pp),ot[x+1][ch[l.z].l[i]]);
    } 
  }
  else
  {
    n=ch[l.z].nn;
    for (i=l.m+1;i<=n;i++)
    {
      tt+=3;
      pp++;
      f[x+1][ch[l.z].ll[i]]=min(f[x+1][ch[l.z].ll[i]],ti+tt);
      if (f[x+1][ch[l.z].ll[i]]==ti+tt)
        ot[x+1][ch[l.z].ll[i]]=min(p+suan(l.z,pp),ot[x+1][ch[l.z].ll[i]]);
    }
  }
}

int main()
{
  freopen("data2.txt","r",stdin);
  rm();
  sf("%d%d",&shi,&zhong);
  dp=3;
  for (i=0;i<=3;i++)
    for (j=1;j<=9999;j++)
      f[i][j]=maxlongint;
  f[0][shi]=0;
  for (i=0;i<hash[shi].size();i++)
    dfs(0,0,0,hash[shi][i]);
  
  
  return 0;
}

