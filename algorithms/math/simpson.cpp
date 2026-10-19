/**
 * Nombre: Integracion numerica (regla de Simpson)
 * Descripcion: Aproxima la integral definida de f en [a,b] partiendo el
 *   intervalo en n subintervalos y aproximando f por parabolas. El error es
 *   O((b-a) h^4), asi que con n grande alcanza para la precision tipica.
 * Tiempo: O(n) evaluaciones de f
 * Uso: double r = integrate(f, a, b); // o integrate(f, a, b, n)
 */
double integrate(double f(double), double a, double b, int n=10000){
    double r=0,h=(b-a)/n,fa=f(a),fb;
    forr(i,0,n) {fb=f(a+h*(i+1));r+=fa+4*f(a+h*(i+0.5))+fb;fa=fb;}
    return r*h/6.;
}
