/**
 * Nombre: Topological Sort
 * Descripcion: Orden topologico de un DAG. Usa priority_queue para devolver el orden
 *   lexicograficamente menor. Si el grafo no es DAG, el resultado tiene menos de n nodos.
 * Tiempo: O(n + m)
 * Uso: vi orden = tsort(g, n);
 */
vi tsort(vector<vi> &g, int n){  // lexicographically smallest topological sort
    vi r; priority_queue<ll> q;
    vi d(2*n);
    forn(i, n) for(ll j: g[i]) d[j]++;
    forn(i, n) if(!d[i]) q.push(-i);
    while(!q.empty()){
        ll x=-q.top(); q.pop(); r.pb(x);
        for(ll j: g[x]){
            d[j]--;
            if(!d[j]) q.push(-j);
        }
    }
    return r;  // if not DAG it will have less than n elements
}
