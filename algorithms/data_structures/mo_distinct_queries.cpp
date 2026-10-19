/**
 * Nombre: Mo's Algorithm (D-Query: distintos en rango)
 * Descripcion: Responde queries de rango offline ordenandolas por bloque de l
 *   y por r, moviendo los punteros de a uno. Aca resuelve la cantidad de
 *   valores distintos en [l,r]; cambiar add()/erase() para otra query.
 *   Requiere MAXN definido y valores de v acotados por MAXN.
 * Tiempo: O((n + q) sqrt(n))
 * Uso: mo M; M.read_queries(m); M.get_mo(v); // respuestas en M.ans
 */

struct query{
    int l, r, ind;
    bool operator <(query q) const {
        return r < q.r;
    }
};

struct mo {
    const int block = 448; // sqrt(MAXN)
    vector<vector<query>> q;
    vector<ll> ans, cont;

    mo(){
        ans.resize(MAXN), cont.resize(MAXN);
        q.resize(MAXN/block+5);
    }

    void read_queries(int m) { // m --> number of queries
        ans.resize(m,0);
        forn(i, m) {
            int l, r; cin >> l >> r;
            l--; r--; // For 0-indexed 
            q[l / block].pb({l,r,(int)i});
        } 
    }

    void add(ll &sum, ll val) {
        if(cont[val] == 0) sum++;
        cont[val]++;
    }

    void erase(ll &sum, ll val) {
        if(cont[val] == 1) sum--;
        cont[val]--;
    }

    void get_mo(vector<ll> &v) { 
        ll sum = 0;
        forn(i,q.size()) {
            sort(all(q[i])); 
            int l, r; l = r = block * i; 
            for(query u : q[i]) { // Solve for [l,r]
                while(r <= u.r) add(sum,v[r]), r++;
                while(l <= u.l) erase(sum,v[l]), l++;
                while(l > u.l) l--, add(sum,v[l]);
                ans[u.ind] = sum;     
            }
            while(l < r) erase(sum,v[l]), l++;
        }
    }
};
