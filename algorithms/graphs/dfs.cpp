/**
 * Nombre: DFS
 * Descripcion: Recorrido en profundidad marcando visitados sobre el grafo global
 *   g (lista de adyacencia). Base para recorridos y armado de componentes.
 * Tiempo: O(V+E)
 * Uso: dfs(start); // usa g y visto globales
 */
const int MAXN = 200005;
vector< vector<int> > g(MAXN); // graph represented as an adjacency list
vector <bool> visto(MAXN,false);

void dfs(int v) {
    visto[v] = true;
    for (int u : g[v]) if (!visto[u]) dfs(u);
}

