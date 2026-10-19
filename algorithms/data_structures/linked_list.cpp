/**
 * Nombre: Linked List circular sobre arrays
 * Descripcion: Lista doblemente enlazada circular de n posiciones fijas
 *   representada con dos arrays (l[i] anterior, r[i] siguiente). Permite
 *   borrar elementos en O(1) manteniendo el orden original de los vecinos.
 * Tiempo: build O(n), erase O(1)
 * Uso: linked_list L(n); L.erase(pos); // vecinos: L.l[pos], L.r[pos]
 */
struct linked_list {
    ll n;
    vi l, r;
    linked_list(int n): n(_n) {
        l.resize(n); r.resize(n);
        forn(i, n){
            l[i] = (i-1+n)%n;
            r[i] = (i+1)%n;
        }
    }
    void erase(int pos){
        r[l[pos]] = r[pos];
        l[r[pos]] = l[pos];
    }
};
