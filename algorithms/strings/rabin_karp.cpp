/**
 * Nombre: Rabin-Karp
 * Descripcion: Busca todas las ocurrencias del patron s dentro de t usando
 *   hashing polinomial (p=31, mod 1e9+7). Compara el hash de cada ventana de
 *   |s| con el hash del patron y devuelve las posiciones (0-indexed) donde
 *   arranca cada ocurrencia. Asume alfabeto 'a'-'z'.
 * Tiempo: O(|s| + |t|)
 * Uso: vector<ll> pos = rabin_karp(s, t);
 */

vector <ll> rabin_karp(string s, string t) {
    ll p=31, m=1e9+7, n=2147483647;
    ll S=s.size(), T=t.size();
    vector <ll> p_pow;
    p_pow.pb(1);
    forn(i,max(S,T)) p_pow.pb((p_pow.back()*p)%m);
    vector <ll> h; h.pb(0);
    forn(i,T) h.pb((h.back()+(t[i]-'a'+1)*p_pow[i])%m);
    ll h_s=0;
    forn(i,S) h_s=(h_s+(s[i]-'a'+1)*p_pow[i])%m;
    vector <ll> o;
    forn(i,T-S+1) {
        ll cur_h=(h[i+S]+m-h[i])%m;
        if(cur_h==(h_s*p_pow[i])%m) o.pb(i);
    }
    return 0;
}
