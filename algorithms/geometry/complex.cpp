/**
 * Nombre: Puntos con std::complex
 * Descripcion: Usar std::complex como tipo punto (real=x, imag=y) para geometria. Notas:
 *   no se pueden leer con cin>> directamente; y una vez definidas las macros x/y no se
 *   pueden usar variables con esos nombres.
 * Tiempo: O(1) por operacion
 * Uso: typedef complex<double> complejo; complejo p(x,y); p.x, p.y;
 */

typedef complex<double> complejo;
#define x real()
#define y imag()

complejo a, b, c;
abs(a); // Devuelve sqrt(a.x^2 + a.y^2)
arg(a); // Devuelve el angulo entre ( -pi ; pi ]
conj(a); // Devuelve a.x - i*a.y
a*b; // Devuelve (a.x*b.x-a.y*b.y) + i*(a.x*b.y + a.y*b.x)
polar(1.0,pi); // Devuelve el complejo de modulo 1 y angulo pi
    (conj(a)*b).y // Producto cruz -> a.x*b.y - a.y*b.x
(conj(b-a)*(c-a)).y/abs(b-c) // Devuelve distancia punto a -> recta bc
