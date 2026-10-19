/**
 * Nombre: Binary Lifting (k-esimo ancestro)
 * Descripcion: Precalcula jump[j][v] = 2^j-esimo ancestro de v a partir del
 *   arreglo de padres. lift(v,k) sube k niveles a v. Requiere LOG definido.
 * Tiempo: build O(n log n), lift O(log n)
 * Uso: binary_lifting bl(par); int a = bl.lift(v, k);
 */
struct binary_lifting {
    vector<vi> jump;
    binary_lifting(vi par){
        int n = SZ(par);
        jump.resize(LOG, vi(n));
        jump[0] = par;
 
        forr(j, 1, LOG){
            forn(i, n) jump[j][i] = jump[j-1][jump[j-1][i]];
        }
    }
 
    int lift(int v, int k){
        for(int i = LOG-1; i >= 0; i--) 
            if(k & (1<<i)) v = jump[i][v];
        return v;
    }
};
