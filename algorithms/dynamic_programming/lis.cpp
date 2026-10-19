/**
 * Nombre: Longest Increasing Subsequence (LIS)
 * Descripcion: Longitud de la subsecuencia creciente mas larga. strict=1 exige estrictamente
 *   creciente, strict=0 permite iguales (no decreciente).
 * Tiempo: O(n log n), memoria O(n)
 * Uso: ll len = lis(a, strict);
 */

// strict = 1: estrictamente creciente
ll lis(vi &a, int strict = 0){
	vi temp; temp.pb(a[0]);
	forr(i, 1, SZ(a)){
		ll x = a[i];
		if(x >= temp.back()+strict) temp.pb(x);
		else {
			auto it = upper_bound(all(temp), x-strict);
			*it = x;
		}
	}
	return SZ(temp);
}
