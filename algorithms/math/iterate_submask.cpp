/**
 * Nombre: Iterar submascaras
 * Descripcion: Recorre, para cada mascara, todas sus submascaras. En total sobre todas las
 *   mascaras el costo es 3^n (cada bit puede estar en mask y no, en submask, o en ninguna).
 * Tiempo: O(3^n) para recorrer todas las mascaras y sus submascaras
 * Uso: patron (sm recorre las submascaras de mask); adaptar el cuerpo del do-while.
 */
// 3 ^ n iteration
forn(mask, (1<<n)){
    int sm = 0;
    do {
        // do something with submask
    } while (sm=(sm-mask)&mask);
}
