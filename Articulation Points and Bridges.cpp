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

#define pii pair<int, int>
vector<int> adj[mx];
int low[mx];
int disc[mx];
bool visited[mx];
int ti  = 0;
int parent[mx];
vector<pii> B;
vector<int> P;
pii b;

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

            if( parent[s]==-1 && child >1 ){P.push_back(s);}
            if( parent[s]!=-1 && low[v] >= disc[s] ){P.push_back(s);}
            if(low[v] > disc[s]){b.first = s; b.second = v; B.push_back(b);}
        }
        else if(parent[s]!=v){
            low[s] = min(low[s], disc[v]);
        }
    }
}

bool comp(pii a, pii b)
{
    if(a.first==b.first){
        return a.second < b.second;
    }
    else{ return a.first < b.first; }
}



int main()
{
    #ifdef dipu
    //freopen("inp.txt","r",stdin);
    #endif

    int e,v;
    memset(visited, false, sizeof visited);
    memset(parent, -1, sizeof parent);
    memset(disc, 0, sizeof disc);
    for(int i=0; i<mx; i++){
        low[i] = INT_MAX;
    }
    cin >> v >> e;
    int x, y;
    for(int i=0; i<e; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=0; i<v; i++){
        if(!visited[i]){
            articulation(i);
        }
    }


    //sort(P.begin(), P.end());
    cout << "Articulation Points : " << P.size() << endl;
    if(P.size()>0){
        for(int i=0; i<P.size(); i++){
            cout << P[i] << " ";
        }
        cout << endl;
    }



    //sort(B.begin(),B.end(),comp);
    cout << "Articulation Bridges : " << B.size() << endl;
    if(B.size()>0){
        for(int i=0; i<B.size(); i++){
            cout << B[i].first << " " << B[i].second << endl;
        }
    }
}
