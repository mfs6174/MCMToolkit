/*
ID: mfs6174
email: mfs6174@gmail.com
PROG: floodfill
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
#define MAXN 1000
using namespace std;
ifstream inf("data1.txt");
ofstream ouf("data3.out");
//freopen("ti.in","r",stdin);
const int maxlongint=2147483647;

struct P
{
  int x,y;
  P(int _x=0,int _y=0){x=_x;y=_y;}
};

int i,j,t,n,m,cc=0;
int ff[MAXN][MAXN];
int tu[MAXN][MAXN];
vector<P> rr[10];
bool fl;

void floodfill(int x,int y)
{
  if (tu[x][y]==0)
    return;
  if (ff[x][y]!=0)
    return;
  if (fl)
  {
    cc++;
    fl=false;
  }
  ff[x][y]=cc;
  rr[cc].push_back(P(x,y));
  int i,j;
  for (i=-1;i<=1;i++)
    for (j=-1;j<=1;j++)
      floodfill(x+i,y+j);
}

  
int main()
{
  inf>>n>>m;
  for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
      inf>>tu[i][j];
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    {
      fl=true;
      floodfill(i,j);
    }
  ouf<<cc;
  for (i=1;i<=cc;i++)
  {
    for (j=0;j<rr[i].size();j++)
      ouf<<rr[i][j].x<<' ';
    ouf<<endl;
    for (j=0;j<rr[i].size();j++)
      ouf<<rr[i][j].y<<' ';
    ouf<<endl;
    ouf<<endl;
  }
  return 0;
}
