/**
 * Nombre: Dijkstra
 * Descripcion: Camino minimo de una fuente con pesos no negativos usando cola de
 *   prioridad. g[u] = {(x,w)}. ans[i] guarda distancia (d) y predecesor (a) para
 *   reconstruir el camino.
 * Tiempo: O(E log V)
 * Uso: auto ans = Dijkstra(start, n, g); // ans[i].d, ans[i].a
 */
typedef ll tipo;
const int MAXN = 200005;

struct arista {
    int x; tipo w; // x -> next node, w = weight
};

struct nodo {
    tipo d, v, a; // d -> distance, v -> actual node, a = previous node
    bool operator<(const nodo& x) const {return d > x.d;}
};

vector<nodo> Dijkstra(int start, int n, vector<vector<arista>> &g) {
    vector<nodo> ans(n);
    vector<bool> visto(n, false);
    priority_queue<nodo> p; p.push({0,start,-1});
    while(!p.empty()) {
        nodo it=p.top(); p.pop();
        if(visto[it.v]) continue;
        else {
            ans[it.v] = it; visto[it.v] = true;
            for(arista u : g[it.v]) {
                if(!visto[u.x]) p.push({it.d + u.w, u.x, it.v});
            }
        }
    }
    return ans;
}

