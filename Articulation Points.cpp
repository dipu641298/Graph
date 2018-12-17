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
#define mx 10007

#define rep(a,b) for(int i=a; i<b; i++)

void print2(vi v){for(int i=0; i<v.size(); i++){cout<<v[i]<<" ";}cout<<endl;}
void print1(int ar[],int n){for(int i=0; i<n; i++){cout<<ar[i]<<" ";}cout<<endl;}

vector<int> adj[mx];
int low[mx];
int disc[mx];
bool visited[mx];
int ti  = 0;
bool art_point[mx];
int parent[mx];

void articulation(int s)
{
    visited[s] = true;
    low[s] = disc[s] = ++ti;
    int child = 0;
    for(int i=0; i<adj[s].size(); i++){
        int v = adj[s][i];
        if(!visited[v]){
            child++;
            parent[v] = s;
            articulation(v);
            low[s] = min(low[s], low[v]);

            if( parent[s]==-1 && child >1 ){art_point[s]=true;}
            if( parent[s]!=-1 && low[v] >= disc[s] ){art_point[s] = true;}
        }
        else if(parent[s]!=v){
            low[s] = min(low[s], disc[v]);
        }
    }
}


int main()
{
    #ifdef dipu
    //freopen("inp.txt","r",stdin);
    #endif

    int e,v;
    memset(art_point, false, sizeof art_point);
    memset(visited, false, sizeof visited);
    memset(parent, -1, sizeof parent);
    memset(disc, 0, sizeof disc);
    for(int i=0; i<mx; i++){
        low[i] = INT_MAX;
    }
    cin >> e >> v;
    int x, y;
    for(int i=0; i<e; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=1; i<=v; i++){
        if(!visited[i]){
            articulation(i);
        }
    }

    int cnt = 0;
    for(int i=0; i<=v; i++){
        if(art_point[i]){
            cout << i << " ";
            cnt++;
        }
    }
    cout << cnt << endl;

}
