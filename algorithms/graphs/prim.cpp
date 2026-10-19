/**
 * Nombre: Prim (MST)
 * Descripcion: Arbol de expansion minima en grafo no dirigido. Parte de un nodo y va
 *   agregando la arista de menor peso hacia un nodo nuevo (via set/priority queue)
 *   hasta tener n-1 aristas. Adyacencias en el global v[]. Devuelve las aristas del MST.
 * Tiempo: O(E log E)
 * Uso: Prim(start); // v[u] = {(vecino, peso)}; devuelve vector<pair> de aristas
 */

vector <pair<ll,ll>> v[500005];
vector <pair<ll,ll>> a;
vector <bool> visto(500005,false);
map <pair<ll,ll>,bool> mapa;

struct arista
{
    ll n, m; // n=nodo padre, m=nodo nuevo
    ll peso;
};

struct compare
{
    bool operator()(arista a, arista b)
    {
        if(a.peso!=b.peso) return a.peso<b.peso;
        else return true;
    }
};

vector <pair<ll,ll>> Prim(ll n)
{
    vector <pair<ll,ll>> lista;
    visto[n]=true;
    set <arista,compare> s;
    forn(i,v[n].size())
    {
        arista aux;
        aux.n=n; aux.m=v[n][i].F; aux.peso=v[n][i].S;
        s.insert(aux);
    }
    while(s.size()!=0)
    {
        auto it=s.begin();
        if(visto[it->m]==true) {s.erase(it); continue;}
        visto[it->m]=true;
        ll ini=it->n, fin=it->m, p=it->peso;
        lista.pb(mp(ini,fin));
        forn(i,v[fin].size())
        {
            arista aux;
            aux.n=fin; aux.m=v[fin][i].F; aux.peso=v[fin][i].S;
            if(visto[aux.m]==false) s.insert(aux);
        }
    }
    return lista;
}
