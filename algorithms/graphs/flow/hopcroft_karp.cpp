/**
 * Nombre: Hopcroft-Karp (matching bipartito)
 * Descripcion: Matching maximo bipartito rapido. g es la lista de vecinos de la particion
 *   izquierda; btoa se pasa lleno de -1 con tamano de la particion derecha. Devuelve el
 *   tamano del matching y deja en btoa[i] la pareja del nodo i de la derecha (-1 si no).
 * Tiempo: O(sqrt(V) * E)
 * Uso: vi btoa(m, -1); int m = hopcroftKarp(g, btoa);
 */
bool dfs(int a, int L, vector<vi> &g, vi &btoa, vi &A, vi &B) {
    if(A[a] != L) return 0;
    A[a] = -1;
    for(auto b: g[a]) if(B[b] == L + 1) {
        B[b] = 0;
        if (btoa[b] == -1 || dfs(btoa[b], L+1, g, btoa, A, B))
            return btoa[b] = a, 1;
    }
    return 0;
}

int hopcroftKarp(vector<vi> &g, vi &btoa) { // bipartite matching rapido
    int res = 0;
    vi A(SZ(g)), B(SZ(btoa)), cur, next;
    for(;;) {
        fill(all(A), 0); fill(all(B), 0);
        /// Find the starting nodes for BFS (i.e. layer 0).
        cur.clear();
        for(auto a : btoa) if(a != -1) A[a] = -1;
        forn(a, SZ(g)) if(A[a] == 0) cur.pb(a);
        /// Find all layers using bfs.
        for(int lay = 1;; lay++) {
            bool islast = 0;
            next.clear();
            for(auto a: cur) for(auto b: g[a]) {
                if (btoa[b] == -1) {
                    B[b] = lay; islast = 1;
                } else if (btoa[b] != a && !B[b]) {
                    B[b] = lay; next.pb(btoa[b]);
                }
            }
            if(islast) break;
            if(next.empty()) return res;
            for(auto a : next) A[a] = lay;
            cur.swap(next);
        }
        /// Use DFS to scan for augmenting paths.
        forn(a, SZ(g)) res += dfs(a, 0, g, btoa, A, B);
    }
}