/*Writer : Md. Shafiur Rahman Dipu  */

#include <bits/stdc++.h>
using namespace std;

#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define pi 2*acos(0.00)
#define INF 2e18

#define ull unsigned long long
#define ll long long
#define ld long double

#define vi vector<int>
#define qi queue<int>
#define si stack<int>
#define li list<int>
#define pb push_back
#define mx 100007

#define rep(a,b) for(int i=a; i<b; i++)

void print2(vi v){for(int i=0; i<v.size(); i++){cout<<v[i]<<" ";}cout<<endl;}
void print1(int ar[],int n){for(int i=0; i<n; i++){cout<<ar[i]<<" ";}cout<<endl;}

typedef pair<long, long> ii ;
vector<ii> g[mx] ;
priority_queue<ii, vector<ii>, greater<ii> > pq ;

ll dis[mx];

long dijkstra(int s, int d)
{
    for(int i=0; i<mx; i++){
        dis[i] = LONG_MAX;
    }
    pq = priority_queue<ii, vector<ii>, greater<ii> >() ;
    pq.push( make_pair(0, s)) ;
    bool found = false ;
    while( !pq.empty() ) {
        ii temp = pq.top(); pq.pop() ;
        long l = temp.first ;
        int u = temp.second ;
        if( u == d )  {
            found = true ;
            break ;
        }
        for( int j = 0; j < g[u].size(); ++j ) {
            ii temp = g[u][j] ;
            int v = temp.first ;
            long vl = temp.second;

            if( l + vl <= dis[v] ) {
                dis[v] = l+vl;
                pq.push( make_pair(l+vl, v)) ;
            }
        }
    }
    if(found){ return dis[d];}


}



int main()
{
    #ifdef dipu
    //freopen("inp.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    #endif

    int vertices, edge;
    cin >> vertices >> edge;
    long x,y;

    for(int j=0; j<edge; j++){
        cin >> x >> y;
        g[x].push_back(make_pair(j,y));
    }
    int source,destination;
    cin >> source >> destination;
    dijkstra(source, destination);


    return 0;
}
