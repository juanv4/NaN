/**
 * Nombre: Z Function
 * Descripcion: z[i] = longitud del mayor prefijo comun entre s y el sufijo que
 *   empieza en i (z[0] queda 0). Base para busqueda de patrones y periodos.
 * Tiempo: O(n)
 * Uso: vector<int> z = z_function(s);
 */
vector<int> z_function(string s) {
    int n = (int) s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}
