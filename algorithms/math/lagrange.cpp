/**
 * Nombre: Interpolacion de Lagrange
 * Descripcion: Dados n puntos (xi,yi) de un polinomio de grado < n, evalua
 *   ese polinomio en un x cualquiera sin calcular sus coeficientes. Util para
 *   sumas de potencias y recurrencias polinomiales (con n = grado+1 puntos).
 *   Ojo con la division entera / el overflow: si se trabaja modulo p usar
 *   inverso modular.
 * Tiempo: O(n^2)
 * Uso: ll y = lagrange(a, x); // a = {(x0,y0), ..., (xn-1,yn-1)}
 */
ll lagrange(vii a, ll x){

	ll ans = 0;
	int n = SZ(a);
	forn(i, n){
		ll term = a[i].second;
		forn(j, n){
			if(j != i)
				term = term*(x-a[j].first)/(a[i].first-a[j].first);
		}
		ans += term;
	}
	return ans;
}

