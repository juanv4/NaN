/**
 * Nombre: Ecuacion Diofantica (Euclides extendido)
 * Descripcion: Euclides extendido: calcula gcd(a,b) y una solucion particular (x,y) de
 *   a*x + b*y = gcd(a,b). find_any_solution resuelve a*x + b*y = c (tiene solucion sii
 *   gcd(a,b) | c). El resto de soluciones se obtiene desplazando por b/g y a/g.
 * Tiempo: O(log min(a,b))
 * Uso: ll g = gcd(a,b,x,y);  o  find_any_solution(a,b,c,x0,y0,g);
 */
ll gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

// Soluciones a la ecuacion ax+by=c, retorna true si hay solucion
// x0 e y0 son soluciones particulares de la ecuacion.
// g es el gcd(a,b), hay solucion si y solo si divide a c.
bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) return false;

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}
// Todas las soluciones de ax+by=c son de la forma: (x, y) = (x0+k*b/g, y0-k*a/g), para todo k


