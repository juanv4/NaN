/**
 * Nombre: Floyd-Warshall
 * Descripcion: Camino minimo entre todos los pares de nodos sobre una matriz de adyacencia.
 *   Admite pesos negativos; un valor negativo en la diagonal indica un ciclo negativo.
 * Tiempo: O(n^3)
 * Uso: floyd(matriz, n); // matriz[i][j] queda con la distancia minima i->j
 */

void floyd(vector<vector<int>>&matriz, ll n) {
    forn(k,n) forn(i,n) forn(j,n) {
        matriz[i][j]=min(matriz[i][j],matriz[i][k]+matriz[k][j]);
    }
}
