/**
 * Nombre: Compresion de coordenadas
 * Descripcion: Mapea los valores de un vector al rango [0,k) manteniendo el
 *   orden relativo y eliminando duplicados. Sirve para indexar estructuras
 *   por valores muy grandes o dispersos.
 * Tiempo: build O(n log n), obtener O(log n)
 * Uso: compresion c(v); int id = c.obtener(x); // c.todos[id] == x
 */
struct compresion {
    vector<int> todos;
    compresion(vector<int> v) {
        todos = v; sort(all(todos));
        todos.erase(unique(all(todos)),todos.end());
    }
    int obtener(int x) { // Esto se podria hacer tambien con un unordered_map en O(1)
        return (int)(lower_bound(all(todos),x)-todos.begin());
    }
};
