/*
ID: mfs6174
PROG: bus
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
#define MAXE 200002  
#define MAXV 100001  
using namespace std;
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.in","r",stdin);

const long long INF=(long long)1<<63-1;  
typedef pair<long long,long long> pii;  
long long t,m,n,V,E,pos=0,head[MAXV];  
long long ans,d[MAXV],pa[MAXV];  
bool cannot=0;  
struct Edge  
{  
  long long w,next,v;  
}node[MAXE*2];  
//无向图邻接表  
void add(long long u,long long v,long long w)  
{  
  if(u==v) return;                  //如果指向自己的边则舍去  
  node[pos].v=v;  
  node[pos].w=w;  
  node[pos].next=head[u];  
  head[u]=pos++;  
}  
//S为起点标号  
void dijkstra(long long s)  
{  
  for(long long i=0;i<=V;i++) d[i]=INF;d[s]=0;  
  priority_queue<pii,vector<pii>,greater<pii> > q;  
  bool done[MAXV];
  pa[s]=s;
  memset(done,0,sizeof(done));  
  q.push(make_pair(d[s],s));  
  while(!q.empty()){  
    pii u=q.top();q.pop();  
    long long x=u.second;  
    if(done[x]) continue;  
    done[x]=true;  
    for(long long i=head[x];i!=-1;i=node[i].next)       //松弛操作  
      if(d[node[i].v]>d[x]+node[i].w)
      {
        pa[node[i].v]=x;
        d[node[i].v]=d[x]+node[i].w;  
        q.push(make_pair(d[node[i].v],node[i].v));  
      }  
  }  
}

vector<int> hash[11000];
void rm()
{
}

int  main()  
{  
  long long u,v,w,s,t;  
  scanf("%lld%lld%lld%lld",&E,&V,&s,&t);  
  pos=1;  
  memset(head,-1,sizeof(head));  
  for(long long i=0;i<E;i++){  
    scanf("%lld%lld%lld",&u,&v,&w);  
    add(u,v,w);  
    add(v,u,w);  
  }  
  dijkstra(s);  
  printf("%lld\n",d[t]);  
  return 0;  
}  
