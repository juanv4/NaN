/**
 * Nombre: Exponenciacion de matrices
 * Descripcion: Producto de matrices modulo MOD y potencia por binary
 *   exponentiation. Sirve para resolver recurrencias lineales (Fibonacci,
 *   contar caminos de largo k en un grafo, etc.). Requiere MOD definido.
 * Tiempo: O(n^3 log e)
 * Uso: Matrix r = be(m, e); // m^e ; ones(n) = identidad n x n
 */
typedef vector<vector<ll>> Matrix;

Matrix ones(int n) {
    Matrix r(n,vector<ll>(n));
    forn(i,n)r[i][i]=1;
    return r;
}
Matrix operator*(Matrix &a, Matrix &b) {
    int n=a.size(),m=b[0].size(),z=a[0].size();
    Matrix r(n,vector<ll>(m));
    forn(i,n)forn(j,m)forn(k,z)
        r[i][j]+=a[i][k]*b[k][j],r[i][j]%=MOD;
    return r;
}
Matrix be(Matrix b, ll e) {
    Matrix r=ones(b.size());
    while(e){if(e&1LL)r=r*b;b=b*b;e/=2;}
    return r;
}
