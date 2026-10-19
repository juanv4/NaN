/**
 * Nombre: Elevator Problem (DP sobre subconjuntos)
 * Descripcion: Dado el peso de cada persona y la capacidad x del ascensor, calcula el minimo
 *   numero de viajes para subir a todos. DP sobre mascaras guardando (viajes, peso del ultimo viaje).
 * Tiempo: O(N * 2^N)
 * Uso: ll v = elevator_problem(n, x, peso);
 */

ll elevator_problem(int n, ll x, vector <ll> &peso) {
    vector <pair<ll,ll>> best(1<<n); best[0] = {1,0};
    forr(s,1,(1<<n)) {
        best[s] = {n+1,0};
        forn(p,n) {
            if(s&(1<<p)) {
                pair<ll,ll> option = best[s^(1<<p)];
                if(option.second + peso[p] <= x) {
                    option.second += peso[p];
                }
                else{
                    option.first++; option.second = peso[p];
                }
                best[s] = min(best[s],option);
            }
        }
    }
    return best[(1<<n)-1].first;
}

