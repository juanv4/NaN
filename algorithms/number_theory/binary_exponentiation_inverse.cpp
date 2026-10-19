/**
 * Nombre: Exponenciacion binaria + inverso modular
 * Descripcion: be/be_it calculan x^y mod m (version recursiva e iterativa).
 *   inv_mod devuelve el inverso multiplicativo modular via pequeno teorema de
 *   Fermat (requiere m primo).
 * Tiempo: O(log y)
 * Uso: be(x,y,m); inv_mod(x,m); // m primo para inv_mod
 */
ll be(ll x, ll y, ll m) {
    if (y == 0) return 1;
    ll p = be(x, y/2, m) % m;
    p = (p * p) % m;
    return (y%2 == 0)? p : (x * p) % m;
}

ll be_it(ll b, ll e, ll m) {
    ll r=1; b%=m;
    while(e){if(e&1LL)r=r*b%m;b=b*b%m;e/=2;}
    return r;
}

ll inv_mod(ll x, ll m) {return be(x,m-2,m);}

