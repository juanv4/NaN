/**
 * Nombre: Eulerian Path / Cycle
 * Descripcion: Halla un camino/ciclo que recorre cada arista exactamente una vez
 *   (Hierholzer). Version dirigida por defecto (descomentar para no dirigida). Verificar
 *   las condiciones de existencia (abajo) antes de llamar.
 * Tiempo: O(V + E)
 * Uso: add_edge(a,b); vector<int> path = get_path(start); // valido si SZ(path)==tot_edges+1
 */
// Todos tienen que cumplir: SZ(path) == tot_edges+1
//
// Existencia directed:
// Path: Que el start tenga out_deg=in_deg+1
//       Que el final tenga in_deg=out_deg+1
//       Que el resto tenga in_deg=out_deg
// 
// Cycle: Todos los nodos in_deg=out_deg
//
// Existencia undirected:
// Path: Que el start y final tengan deg impar, el resto todo par
// Cycle: Todos los nodos tienen grado par

// Directed version (uncomment commented code for undirected)
struct edge {
	int y;
//	list<edge>::iterator rev;
	edge(int _y):y(_y){}
};
list<edge> g[MAXN];
void add_edge(int a, int b){
	g[a].push_front(edge(b));//auto ia=g[a].begin();
//	g[b].push_front(edge(a));auto ib=g[b].begin();
//	ia->rev=ib;ib->rev=ia;
}
vector<int> p;
void go(int x){
	while(SZ(g[x])){
		int y=g[x].front().y;
		//g[y].erase(g[x].front().rev);
		g[x].pop_front();
		go(y);
	}
	p.pb(x);
}
vector<int> get_path(int x){ // get a path that begins in x
// check that a path exists from x before calling to get_path!
	p.clear();go(x);reverse(all(p));
	return p;
}
