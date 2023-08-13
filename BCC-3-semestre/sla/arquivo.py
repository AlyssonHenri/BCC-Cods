from queue import Queue

MAX = 150
MAXV = 21000
INF = 1000000000000000

class Aresta:
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c

class Edge:
    def __init__(self, u=0, v=0, nxt=0, cost=0, flow=0):
        self.u = u
        self.v = v
        self.nxt = nxt
        self.cost = cost
        self.flow = flow

V = 0
E = 0
A = 0
f = 0
sp = 0
dist = [0] * MAX
p = [0] * MAX
visited = [False] * MAX
graph = [Edge() for _ in range(MAXV)]
edges = [Aresta(0, 0, 0) for _ in range(MAXV)]

def addEdge(u, v, c, f):
    global A
    graph[A] = Edge(u, v, previous[u], c, f)
    previous[u] = A
    A += 1
    graph[A] = Edge(v, u, previous[v], -c, 0)
    previous[v] = A
    A += 1

def augment(v, minEdge):
    global f
    i = p[v]
    while i != -1:
        minEdge = min(minEdge, graph[i].flow)
        i = p[graph[i].u]
    
    i = p[v]
    while i != -1:
        graph[i].flow -= minEdge
        graph[i ^ 1].flow += minEdge
        i = p[graph[i].u]
    
    f = minEdge

def dijkstra(s, t):
    global sp
    for i in range(V + 1):
        dist[i] = INF
        p[i] = -1
        visited[i] = False
    
    q = Queue()
    dist[s] = 0
    visited[s] = True
    q.put(s)

    while not q.empty():
        u = q.get()
        i = previous[u]
        while i != -1:
            v = graph[i].v
            if graph[i].flow and dist[u] + graph[i].cost < dist[v]:
                dist[v] = dist[u] + graph[i].cost
                p[v] = i
                if not visited[v]:
                    visited[v] = True
                    q.put(v)
            i = graph[i].nxt
        
        visited[u] = False
    
    sp = dist[t]
    return sp != INF

t = 1
d = 0
k = 0

while True:
    try:
        V, E = map(int, input().split())
        print("Instancia", t)
        t += 1
        A = 0
        previous = [-1] * (V + 2)

        for i in range(E):
            a, b, c = map(int, input().split())
            edges[i].a = a
            edges[i].b = b
            edges[i].c = c
        
        d, k = map(int, input().split())
        
        addEdge(0, 1, 0, d)
        addEdge(V, V + 1, 0, d)
        
        for i in range(E):
            addEdge(edges[i].a, edges[i].b, edges[i].c, k)
            addEdge(edges[i].b, edges[i].a, edges[i].c, k)
        
        maxFlow = 0
        resp = 0
        
        while dijkstra(0, V + 1):
            f = 0
            augment(V + 1, INF)
            maxFlow += f
            resp += sp * f
            if maxFlow == d:
                break
        
        if maxFlow != d:
            print("impossivel")
        else:
            print(resp)
        
        print()
    except EOFError:
        break
