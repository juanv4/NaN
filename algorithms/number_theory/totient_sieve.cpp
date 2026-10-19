/**
 * Nombre: Criba lineal de phi de Euler
 * Descripcion: Criba lineal que calcula la funcion totient de Euler phi[i] para
 *   todo i < n, ademas de la lista de primos. phi[i] = cantidad de enteros en
 *   [1,i] coprimos con i.
 * Tiempo: O(n)
 * Uso: sieve(n); // llena phi[] y prime
 */
bool is_composite[1000];
int phi[1000];
vector<long long> prime;

void sieve (int n) {
    fill(is_composite, is_composite + n, false);
    phi[1] = 1;
    for (int i = 2; i < n; ++i) {
        if (!is_composite[i]) {
            prime.push_back (i);
            phi[i] = i - 1; //i is prime
        }
        for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
            is_composite[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];	//prime[j] divides i
                break;
            } else {
                phi[i * prime[j]] = phi[i] * phi[prime[j]];	//prime[j] does not divide i
            }
        }
    }
}
