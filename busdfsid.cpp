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

void dayin()
{
  int i;
  for (i=1;i<=lc;i++)
    ouf<<xian[i]<<' ';
  ouf<<endl;
  for (i=1;i<=zc;i++)
    ouf<<zhan[i]<<' ';
  ouf<<endl;
}

void dfs(int x,int p,int ti,int z,D l)
{
  if (x>=dp)
    return;
  if (ff[z])
    return;
  int i,j,pp=0,tt=5,n;
  zc++;
  zhan[zc]=z;
  lc++;
  xian[lc]=l.z;
  ff[z]=true;
  if (l.w==0)
  {
    n=ch[l.z].n;
    for (i=l.m+1;i<=n;i++)
    {
      tt+=3;
      pp++;
      if (ch[l.z].l[i]==zhong)
      {
        //dayin();
        ouf<<x<<' '<<p+suan(l.z,pp)<<' '<<ti+tt-5<<' '<<endl<<endl;
        zc--;lc--;ff[z]=false;
        return;
      }
      for (j=0;j<hash[ch[l.z].l[i]].size();j++)
        if (hash[ch[l.z].l[i]][j].z!=l.z)
          dfs(x+1,p+suan(l.z,pp),ti+tt,ch[l.z].l[i],hash[ch[l.z].l[i]][j]);
    }
  }
  else
  {
    n=ch[l.z].nn;
    for (i=l.m+1;i<=n;i++)
    {
      tt+=3;
      pp++;
      if (ch[l.z].ll[i]==zhong)
      {
        //dayin();
        ouf<<x<<' '<<p+suan(l.z,pp)<<' '<<ti+tt-5<<' '<<endl<<endl;
        zc--;lc--;ff[z]=false;
        return;
      }
      for (j=0;j<hash[ch[l.z].ll[i]].size();j++)
        if (hash[ch[l.z].ll[i]][j].z!=l.z)
          dfs(x+1,p+suan(l.z,pp),ti+tt,ch[l.z].ll[i],hash[ch[l.z].ll[i]][j]);
    }
  }
  zc--;lc--;
  ff[z]=false;
}

int main()
{
  freopen("data2.txt","r",stdin);
  rm();
  sf("%d%d",&shi,&zhong);
  dp=3;
  for (i=0;i<hash[shi].size();i++)
  {
  dfs(0,0,0,shi,hash[shi][0]);
  }
  return 0;
}

