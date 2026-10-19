/**
 * Nombre: Eliminacion Gaussiana (reduce)
 * Descripcion: Lleva la matriz a su forma escalonada reducida (in-place) con
 *   pivoteo parcial y devuelve el determinante (0 si es singular). Para
 *   resolver un sistema pasar la matriz aumentada [A|b]: la solucion queda en
 *   la ultima columna. Requiere EPS definido.
 * Tiempo: O(n^2 m)
 * Uso: double det = reduce(x); // x queda reducida
 */
double reduce(vector<vector<double> > &x) { // returns determinant
    int n=x.size(),m=x[0].size();
    int i=0,j=0;double r=1.;
    while(i<n&&j<m){
        int l=i;
        forr(k,i+1,n)if(abs(x[k][j])>abs(x[l][j]))l=k;
        if(abs(x[l][j])<EPS){j++;r=0.;continue;}
        if(l!=i){r=-r;swap(x[i],x[l]);}
        r*=x[i][j];
        for(int k=m-1;k>=j;k--)x[i][k]/=x[i][j];
        forr(k,0,n){
            if(k==i)continue;
            for(int l=m-1;l>=j;l--)x[k][l]-=x[k][j]*x[i][l];
        }
        i++;j++;
    }
    return r;
}
