/**
 * Nombre: Numeros de Bell
 * Descripcion: bell[i] = cantidad de particiones de un conjunto de i elementos. Se calculan
 *   con el triangulo de Bell: bell[i][0]=bell[i-1][i-1], bell[i][j]=bell[i-1][j-1]+bell[i][j-1].
 *   Devuelve los numeros de Bell de 0 a n. Serie: 1,1,2,5,15,52,203,...
 * Tiempo: O(n^2)
 * Uso: vector<int> b = bellNumber(n); // b[i] = i-esimo numero de Bell
 */
// Los numeros de Bell son utiles para calcular de cuantas maneras
// podemos subdivir el conjunto utilizando todos los elementos

// O(n^2)
// Numeros de Bell
// Bell numbers = {1, 1, 2, 5, 15, 52, 203, 877, 4140, 21147, ...}
// bell[i][j] = bell[i-1][j-1] + bell[i][j-1]
// bell[i][0] = bell[i-1][i-1]

vector<int> bellNumber(int n) {
    vector<vector<int>> bell(n+1,vector<int>(n+1));
    vector<int> ans(n+1,0); // Numeros de bell desde 0 hasta n
    bell[0][0] = 1;
    forr(i, 1, n+1){
        bell[i][0] = bell[i-1][i-1];
        forr(j, 1, i+1) bell[i][j] = bell[i-1][j-1] + bell[i][j-1];
    }
    forn(i, n+1) ans[i] = bell[i][0];
    return ans;
}
