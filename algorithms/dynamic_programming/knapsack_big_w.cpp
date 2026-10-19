/**
 * Nombre: Knapsack con peso grande (DP por valor)
 * Descripcion: Mochila 0/1 cuando la capacidad w es enorme pero los valores son chicos. En
 *   vez de indexar por peso, la DP indexa por valor total (dp[v] = minimo peso para lograr valor v)
 *   y devuelve el mayor valor con peso <= w.
 * Tiempo: O(n * MAXV), con MAXV = suma maxima de valores
 * Uso: ll best = knapsack(v, n, w); // v = vector<item>{w, v}
 */

struct item { int w, v; };

ll knapsack(vector <item> &v, int n, int w) {
    int MAXV = 100005;
    vector <ll> dp(MAXV+1,INF), aux(MAXV+1,INF);
    vector <bool> visto(MAXV,false);
    visto[0]=true; dp[0]=0;
    forn(i,n) {
        forn(j,MAXV) {
            aux[j]=dp[j];
            if(j-v[i].v < 0) continue;
            if(visto[j-v[i].v] == true) {
                aux[j]=min(aux[j],dp[j-v[i].v]+v[i].w);
                visto[j]=true;
            }
        }
        forn(j,MAXV) dp[j]=aux[j];
    }
    ll ans = 0;
    forn(i,MAXV+1) if(dp[i] <= w && visto[i]==true) ans=i;
    return ans;
}
