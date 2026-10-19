/**
 * Nombre: Knapsack 0/1
 * Descripcion: Problema de la mochila 0/1: maximiza el valor total sin superar la capacidad w,
 *   usando cada item a lo sumo una vez. DP clasico sobre la capacidad.
 * Tiempo: O(n * w)
 * Uso: ll best = knapsack(v, n, w); // v = vector<item>{w, v}
 */
//~ Problema de la mochila - O(n*w)

struct item { int w, v; };

ll knapsack(vector <item> &v, int n, int w) {
    vector <ll> dp(w+1,0), aux(w+1,0);
    forn(i,n) {
        forn(j,w+1) {
            aux[j]=dp[j];
            if(j-v[i].w < 0) continue;
            aux[j]=max(aux[j],dp[j-v[i].w]+v[i].v);
        }
        forn(j,w+1) dp[j]=aux[j];
    }
    ll ans = 0;
    forn(i,w+1) ans=max(ans,dp[i]);
    return ans;
}
