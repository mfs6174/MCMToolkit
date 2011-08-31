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
#include<ctime>
#define sf scanf
#define pf printf
#define llg long long 

using namespace std;
//ifstream inf("ti.in");
ofstream ouf("chuyuan.txt");
//freopen("ti.in","r",stdin);
const int maxlongint=2147483647;
double gai[10][30]={{0},{0,0,0.29,0.51,0.20},{0,0,0.20,0.65,0.15},{0,0,0.00,0.00,0.02,0.05,0.07,0.24,0.29,0.20,0.05,0.05,0.02},{0,0,0.00,0.00,0.00,0.02,0.03,0.07,0.15,0.16,0.17,0.14,0.10,0.08,0.05,0.03},{0,0,0.00,0.04,0.18,0.22,0.20,0.16,0.09,0.05,0.05}};

int getcy(int tp)
{
  int i;
  double s=0,tt=rand()%1000/1000.0;
  for (i=2;i<=20;i++)
  {
    s+=gai[tp][i];
    if (s>=tt)
      return i;
  }
  //return gc[tp];
}

int i,j;
int main()
{
  srand(time(NULL));
  for (i=1;i<=5;i++)
  {
    for (j=1;j<=1500;j++)
      ouf<<getcy(i)<<' ';
    ouf<<endl;
  }
  return 0;
}
