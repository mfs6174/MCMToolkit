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
  int l[150],ll[150];
};

vector<D> hash[10000];
int i,j,t,n,m,shi,zhong,dp,k;
B ch[1000];
char tc;
D td;
bool ff[10000];
int f[20][11000],ot[20][11000],zhan[20][11000],xian[20][11000];

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
      for (i=2;i<=ch[h].n;i++)
      {
        ch[h].l[ch[h].n+i-1]=ch[h].l[i];
        td.z=h;td.w=0;td.m=ch[h].n+i-1;
        hash[ch[h].l[i]].push_back(td);
      }
      ch[h].n=ch[h].n*2-1;
      for (i=ch[h].n;i>=1;i--)
      {
        ch[h].nn++;
        ch[h].ll[ch[h].nn]=ch[h].l[i];
        td.z=h;td.w=1;td.m=ch[h].nn;
        hash[ch[h].l[i]].push_back(td);
      }
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


void mfs(int x,int p,int ti,D &l,int z)
{
  int i,pp=0,tt=5,n;
  if (l.w==0)
  {
    n=ch[l.z].n;
    for (i=l.m+1;i<=n;i++)
    {
      tt+=3;
      pp++;
      if (ti+tt<f[x+1][ch[l.z].l[i]])
      {
        f[x+1][ch[l.z].l[i]]=ti+tt;
        xian[x+1][ch[l.z].l[i]]=l.z;
        zhan[x+1][ch[l.z].l[i]]=z;
        ot[x+1][ch[l.z].l[i]]=p+suan(l.z,pp);
      }
      else
        if (f[x+1][ch[l.z].l[i]]==ti+tt)
        {
          if (p+suan(l.z,pp)<ot[x+1][ch[l.z].l[i]])
          {
            ot[x+1][ch[l.z].l[i]]=p+suan(l.z,pp);
            xian[x+1][ch[l.z].l[i]]=l.z;
            zhan[x+1][ch[l.z].l[i]]=z;
          }
        }
    }
  }
  else
  {
    n=ch[l.z].nn;
    for (i=l.m+1;i<=n;i++)
    {
      tt+=3;
      pp++;
      if (ti+tt<f[x+1][ch[l.z].ll[i]])
      {
        f[x+1][ch[l.z].ll[i]]=ti+tt;
        xian[x+1][ch[l.z].ll[i]]=-l.z;
        zhan[x+1][ch[l.z].ll[i]]=z;
        ot[x+1][ch[l.z].ll[i]]=p+suan(l.z,pp);
      }
      else
        if (f[x+1][ch[l.z].ll[i]]==ti+tt)
        {
          if (p+suan(l.z,pp)<ot[x+1][ch[l.z].ll[i]])
          {
            ot[x+1][ch[l.z].ll[i]]=p+suan(l.z,pp);
            xian[x+1][ch[l.z].ll[i]]=-l.z;
            zhan[x+1][ch[l.z].ll[i]]=z;
          }
        }
    }
  }
}

void dayin(int x,int y)
{
  if (y==shi)
    return;
  dayin(x-1,zhan[x][y]);
  ouf<<zhan[x][y]<<" L"<<xian[x][y]<<' ';
}

int main()
{
  freopen("data3.txt","r",stdin);
  rm();
  dp=5;
  while (sf("%d%d",&shi,&zhong)!=EOF)
  {
    ouf<<shi<<' '<<zhong<<endl;
    for (i=0;i<=dp+1;i++)
      for (j=1;j<=9999;j++)
      {
        f[i][j]=maxlongint;
        ot[i][j]=maxlongint;
      }
    f[0][shi]=0;
    ot[0][shi]=0;
    for (i=0;i<hash[shi].size();i++)
      mfs(0,0,0,hash[shi][i],shi);
    for (i=1;i<=dp;i++)
      for (j=1;j<=9999;j++)
        if (f[i][j]!=maxlongint)
          for (k=0;k<hash[j].size();k++)
            mfs(i,ot[i][j],f[i][j],hash[j][k],j);
    for (i=2;i<=dp+1;i++)
    {
      if (f[i][zhong]<10000)
      {
        ouf<<i-1<<endl;
        ouf<<f[i][zhong]-5<<' '<<ot[i][zhong]<<endl;
        dayin(i,zhong);
        ouf<<zhong<<endl<<endl;
      }
    }
    ouf<<endl;
  }
  return 0;
}

