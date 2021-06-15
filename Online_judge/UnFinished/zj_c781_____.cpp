/*
***Bipartite Matching***
    Solution:
        Even numbers and odd numbers can be seen as bipartite parts,
        for 4N - (i+j) can never be a prime when (i+j) is even.
    Problem:
        Memory is limited to 64MB, currently no method to cut down
        the usage of memory 
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2345678;

typedef vector<int> vec;
struct Matched {
    int u, v;
};

int t;

bool is_prime[4 * MAX_N + 1];
vector<vec> G;
bool used[2 * MAX_N];
int match[2 * MAX_N];

vector<Matched> res;

void sieve_prime() {
    int S = 4 * MAX_N;
    for(int i=2; i<=S; i++) {
        is_prime[i] = true;
    }

    for(int i=2; i<=S; i++) {
        if(is_prime[i]) {
            for(int j=2*i; j<=S; j+=i)
                is_prime[j] = false;
        }
    }
}

void add_edge(int u, int v) {
    G[v].push_back(u);
    G[u].push_back(v);
}

bool dfs(int v) {
    used[v] = true;

    for(int i=0; i<G[v].size(); i++) {
        int u = G[v][i], w = match[u];

        if(w >= 0 && G[v].size()-i > 1)
            continue;
        else if(w < 0 || (!used[i] && dfs(w))) {
            match[v] = u;
            match[u] = v;

            if(u > v)
                swap(u, v);
            res.push_back((Matched){u, v});
            
            return true;
        }
    }
    return false;
}

void bipartite_matching(int N) {
    memset(match, -1, sizeof(match));
    res.clear();

    for(int v=0; v<2*N; v++) {
        if(match[v] < 0) {
            memset(used, 0, sizeof(used));
            dfs(v);
        }
    }

    for(int i=0; i<res.size(); i++) {
        cout << res[i].u << ' ' << res[i].v << '\n';
    }
    return;
}

void solve(int N) {
    for(int i=0; i<2*N; i++) {
        for(int j=i+1; j<2*N; j++) {
            if(is_prime[4*N - i - j])
                add_edge(i, j);
        }
    }

    bipartite_matching(N);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve_prime();

    int t;
    cin >> t;
    while(t--) {
        int N;
        cin >> N;
        G.resize(2 * MAX_N);

        solve(N);
        for(int i=0; i<2*N; i++)
            G[i].clear();
    }
    
    
    return 0;
}