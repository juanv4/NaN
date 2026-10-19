/**
 * Nombre: Random (mt19937)
 * Descripcion: Generador Mersenne Twister con seed por reloj (no predecible,
 *   a diferencia de rand()). Para valores de 64 bits usar mt19937_64.
 *   Tambien sirve para shuffle: shuffle(all(v), rng).
 * Tiempo: O(1) por numero
 * Uso: int x = my_random(l, r); // uniforme en [l,r]
 */
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_random(int l, int r){ // Random number in [l, r]
    return uniform_int_distribution<int>(l, r)(rng);
}
