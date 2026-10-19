/**
 * Nombre: DSU (Union-Find)
 * Descripcion: Conjuntos disjuntos con path compression y union por size.
 *   Permite unir componentes y preguntar si dos elementos estan en la misma.
 *   sz[find(x)] es el tamano de la componente de x.
 * Tiempo: O(alpha(n)) amortizado por operacion (inversa de Ackermann, ~O(1))
 * Uso: DSU d(n); d.join(a,b); d.same(a,b); d.find(a);
 */
struct DSU {
    vi link, sz;

    DSU(int tam) {
        link.resize(tam+5), sz.resize(tam+5);
        forn(i, tam+5) link[i] = i, sz[i] = 1;
    }

    ll find(ll x){ return link[x] = (link[x] == x ? x : find(link[x])); }
    bool same(ll a, ll b) { return find(a) == find(b); }

    void join(ll a, ll b) {
        a = find(a), b = find(b);
        if(a == b) return;
        if(sz[a] < sz[b]) swap(a,b);
        sz[a] += sz[b];
        link[b] = a;
    }
};
