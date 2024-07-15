lca



void dfs(int u){
    for (int v : a[u])
    if (v==up[u][0]) continue;
    up[v][0] = u;
    h[v] = h[u]+1;
    for (int j = 0; j <= lg; j++){
        up[v][j] = up[up[v][j-1]][j-1];
    }
    dfs(v);
}
int lca(int u, int v){
    if (h[u]!=h[v]){
        if (h[u]<h[v]) swap(u,v);
        for (int j = 0; (1<<j) <= (h[u]-h[v]); j++){
            if ((h[u]-h[v])>>j & 1) u = up[u][j];
        }
    }
    if (u==v) return u;
    for (int j = __lg(h[u]); j >= 0; j--)
    {
        if (up[u][j]!=up[v][j])
        {
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0];
}




rmq
for (int j = 1; j <= lg; j++){
    for (int i = 1; i + (1<<j) - 1; i++){
        t[i][j] = min(t[i][j-1],t[i+(1<<(j-1))][j-1]);
    }
}
get()
int k = __lg(r-l+1);
return t[l][k] r-(1<<k)+1 k
