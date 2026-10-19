/**
 * Nombre: Dinic (Max Flow)
 * Descripcion: Flujo maximo. Con source/sink dummy sobre grafo bipartito corre en
 *   O(sqrt(V) E) (equivalente a Hopcroft-Karp). Tras correr max_flow:
 *   Matching: aristas saturadas (sin source/sink). Min cut: nodos con dist>=0 vs dist<0.
 *   MVC: izquierda con dist<0 + derecha con dist>0. Max Independent Set: complemento (N-MVC).
 * Tiempo: O(V^2 E) general, O(sqrt(V) E) en bipartito
 * Uso: Dinic d(n); d.add_edge(s,t,cap); ll f = d.max_flow(src,dst);
 */
struct Dinic{
    int nodes,src,dst;
    vector<int> dist,q,work;
    struct edge { int to,rev; ll f,cap; };
    vector<vector<edge>> g;
    Dinic(int x):nodes(x),dist(x),q(x),work(x),g(x){}
    void add_edge(int s, int t, ll cap){
        g[s].pb({t,SZ(g[t]),0,cap});
        g[t].pb({s,SZ(g[s])-1,0,0});
    }
    bool dinic_bfs(){
        fill(all(dist),-1);dist[src]=0;
        int qt=0;q[qt++]=src;
        forn(qh, qt){
            int u=q[qh];
            forn(i,SZ(g[u])){
                edge &e=g[u][i];int v=g[u][i].to;
                if(dist[v]<0&&e.f<e.cap)dist[v]=dist[u]+1,q[qt++]=v;
            }
        }
        return dist[dst]>=0;
    }
    ll dinic_dfs(int u, ll f){
        if(u==dst)return f;
        for(int &i=work[u];i<SZ(g[u]);i++){
            edge &e=g[u][i];
            if(e.cap<=e.f)continue;
            int v=e.to;
            if(dist[v]==dist[u]+1){
                ll df=dinic_dfs(v,min(f,e.cap-e.f));
                if(df>0){e.f+=df;g[v][e.rev].f-=df;return df;}
            }
        }
        return 0;
    }
    ll max_flow(int _src, int _dst){
        src=_src;dst=_dst;
        ll result=0;
        while(dinic_bfs()){
            fill(all(work),0);
            while(ll delta=dinic_dfs(src,INF))result+=delta;
        }
        return result;
    }
};
