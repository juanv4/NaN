/**
 * Nombre: Criba de primos
 * Descripcion: Obtiene todos los primos <= n y llena min_prime[i] con el menor primo que
 *   divide a i, lo que permite factorizar cualquier i <= n en O(log i).
 * Tiempo: O(n log log n)
 * Uso: vi primos = criba(n); // luego min_prime[i] para factorizar
 */
// Criba lineal, obtiene los primos menores al parametro
vi min_prime; // min_prime[i] contiene el menor primo que divide a i, util para factorizar en log(i)

vi criba(ll n) {
    vb prime(n+1,true);
    min_prime.resize(n+1,INF);
    vi primos;
    for(ll p=2; p*p<=n; p++){
        if(!prime[p]) continue;
        for(ll i=p*p; i<=n; i += p) {
            prime[i] = false;
            min_prime[i] = min(min_prime[i],p);
        }
    }
    forr(i, 2, n+1){
        if(prime[i]) primos.pb(i), min_prime[i] = i;
    }
    return primos; // lista de primos hasta n
}