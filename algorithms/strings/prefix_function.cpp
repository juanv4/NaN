/**
 * Nombre: Prefix Function (KMP)
 * Descripcion: Funcion prefijo de KMP: pi[i] = longitud del mayor borde propio
 *   (prefijo que ademas es sufijo) de s[0..i]. Base para busqueda de patrones.
 * Tiempo: O(n)
 * Uso: vector<int> pi = prefix_function(s);
 */
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    forr(i,1,n) {
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}
