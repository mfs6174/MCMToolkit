/*
ID: mfs6174
email: mfs6174@gmail.com
PROG: FCFS
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
#include<ctime>
#define sf scanf
#define pf printf
#define llg long long 

using namespace std;
ifstream inf("data1.in");
ofstream ouf("ren1.out");
ofstream ouf1("tian1.out");
//freopen("ti.in","r",stdin);
const int maxlongint=2147483647;

struct BR
{
  int mz,ry,sh,shh,cy;
  int ty,tm;
  bool ff;
  bool operator <(const BR &b)
  {
    return tm<b.ym;
  }
};

int i,j,k,y,n,m;
int time,zhou;
int wsh[10]={0,1,1,2,2,1};
int stp;

BR mz[500],zhan[500];
priority_queue<BR> ry,sh,cy;

int main()
{
  srand(time(NULL));
  

