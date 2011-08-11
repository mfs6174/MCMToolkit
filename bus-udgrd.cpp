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
//ifstream inf("data3.txt");
ofstream ouf("out-udgrd.txt");
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
int i,j,t,n,m,shi,zhong,dp,k,o,u,co;
B ch[1000];
char tc;
D td;
bool ff[10000];
double f[20][11000];
int ot[20][11000],zhan[20][11000],xian[20][11000];
int dtzhan[20][11000];

double dtm[50][50];
vector<int> dui[50];
int bus2dt[11000];

int  tepan;

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


void mfs(int x,int p,double ti,D &l,int z,int hs)
{
  int i,pp=0,tt=0,n;
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
        dtzhan[x+1][ch[l.z].l[i]]=hs;
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
            dtzhan[x+1][ch[l.z].l[i]]=hs;
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
        dtzhan[x+1][ch[l.z].ll[i]]=hs;
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
            dtzhan[x+1][ch[l.z].ll[i]]=hs;
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
  ouf<<zhan[x][y];
  if (dtzhan[x][y])
    ouf<<" B"<<dtzhan[x][y];
  ouf<<" L"<<xian[x][y]<<' ';
}

void rdt()
{
  int i,t;
  //sf("%d",&t);
  for (i=1;i<=39;i++)
  {
    sf("%d",&t);
    sf("%d",&t);
    while (t)
    {
      dui[i].push_back(t);
      bus2dt[t]=i;
      sf("%d",&t);
    }
  }
  for (i=0;i<dui[12].size();i++)
    dui[40].push_back(dui[12][i]);
  for (i=0;i<dui[18].size();i++)
    dui[41].push_back(dui[18][i]);
}

void dtinit()
{
  int i,j,k;
  for (i=1;i<=41;i++)
    for (j=1;j<=41;j++)
      dtm[i][j]=maxlongint;
  for (i=1;i<=22;i++)
    dtm[i][i+1]=dtm[i+1][i]=2.5;
  dtm[40][12]=dtm[12][40]=4;
  dtm[41][18]=dtm[18][41]=4;
  for (i=24;i<=25;i++)
    dtm[i][i+1]=dtm[i+1][i]=2.5;
  dtm[39][24]=dtm[24][39]=2.5;
  for (i=26;i<=27;i++)
    dtm[i][40]=dtm[40][i]=2.5;
  for (i=27;i<=31;i++)
    dtm[i][i+1]=dtm[i+1][i]=2.5;
  for (i=33;i<=38;i++)
    dtm[i][i+1]=dtm[i+1][i]=2.5;
  for (i=32;i<=33;i++)
    dtm[i][41]=dtm[41][i]=2.5;
  for (k=1;k<=41;k++)
    for (i=1;i<=41;i++)
      for (j=1;j<=41;j++)
        if (dtm[i][k]+dtm[k][j]<dtm[i][j])
          dtm[i][j]=dtm[i][k]+dtm[k][j];
}

int main()
{
  freopen("data2.txt","r",stdin);
  rm();
  //freopen("data3.txt","r",stdin);
  rdt();
  dtinit();
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
    // for (i=0;i<hash[shi].size();i++)
    // mfs(0,0,0,hash[shi][i],shi,0);
    for (i=0;i<=dp;i++)
    {
      if (i)
        co=5;
      else
        co=0;
      for (j=1;j<=9999;j++)
        if (f[i][j]!=maxlongint)
        {
          for (k=0;k<hash[j].size();k++)
            mfs(i,ot[i][j],f[i][j]+co,hash[j][k],j,0);
            int hh=bus2dt[j];
            if (!hh)
              continue;
            for (o=0;o<dui[hh].size();o++)
            {
              int ss=dui[hh][o];
              if (ss!=j)
                for (k=0;k<hash[ss].size();k++)
                  mfs(i,ot[i][j],f[i][j]+co,hash[ss][k],j,ss);
            }
            for (u=1;u<=41;u++)
            {
              if (u==hh)
                continue;
              for (o=0;o<dui[u].size();o++)
              {
                int ss=dui[u][o];
                int pp=ot[i][j]+3;
                double tt=f[i][j]+8+dtm[hh][u];
                if (tt<f[i+1][ss])
                {
                  f[i+1][ss]=tt;
                  xian[i+1][ss]=1000;
                  zhan[i+1][ss]=j;
                  ot[i+1][ss]=pp;
                  dtzhan[i+1][ss]=0;
                }
                else
                  if (f[i+1][ss]==tt)
                  {
                    if (pp<ot[i+1][ss])
                    {
                      ot[i+1][ss]=pp;
                      xian[i+1][ss]=1000;
                      zhan[i+1][ss]=j;
                      dtzhan[i+1][ss]=0;
                    }
                  } 
              }
            }
        }
    }
    for (i=1;i<=dp+1;i++)
    {
      if (f[i][zhong]<10000)
      {
        ouf<<i-1<<endl;
        if (xian[i][zhong]==1000)
          tepan=2;
        else
          tepan=0;
        ouf<<f[i][zhong]+tepan<<' '<<ot[i][zhong]<<endl;
        dayin(i,zhong);
        ouf<<zhong<<endl<<endl;
      }
    }
    ouf<<endl;
  }
  return 0;
}

