/**
 * Nombre: Angular Sort
 * Descripcion: Comparador para ordenar puntos por angulo respecto al origen. Primero separa
 *   por semiplano (izquierdo/derecho) y desempata por producto vectorial.
 * Tiempo: O(N log N) al usarlo con sort
 * Uso: sort(all(pts), AngularSort);
 */
// Angular sort
punto origin = {0LL,0LL};
 
bool AngularSort(const punto &A, const punto &B) {
	bool aorig = (A < origin); // semiplano izquierdo o derecho
	bool borig = (B < origin); // semiplano izquierdo o derecho
	if (aorig != borig) { return aorig > borig; } // primero sem izq
 
	return (A^B) > 0; // desempate por producto vectorial si mismo sem
}
