/**
 * Nombre: Numeros de Catalan
 * Descripcion: Calcula los numeros de Catalan. Version DP con la recurrencia
 *   C[i]=sum C[j]*C[i-j-1], y version por formula binom(2n,n)/(n+1) con factoriales
 *   e inversos precomputados (fact, ifact).
 * Tiempo: DP O(n^2); formula O(1) tras precomputar factoriales
 * Uso: auto c = catalan(n); // vector DP  |  ll x = catalan(n); // formula mod
 */

vector<ll> catalan(int n) { //O(N^2)
    vector<ll> c(n+1,0); c[0] = c[1] = 1;
    forr(i,2,n+1) forn(j,i) c[i] += c[j] * c[i-j-1];
    return c;
}

// Catalan formula
// binom(2n,n) / (n+1) --- (2n!) / [(n+1)! * n!]

ll catalan(ll n) {
	return (((fact[2*n] * ifact[n+1])%MOD)*ifact[n])%MOD;
}




