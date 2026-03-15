from itertools import product
import subprocess


def prufer_trees(n):
    if n == 2:
        return [[(1,2)]]
    trees = []
    for seq in product(range(1,n+1), repeat=n-2):
        deg = [0]+[1]*n
        for x in seq:
            deg[x]+=1
        seq=list(seq)
        edges=[]
        import heapq
        pq=[i for i in range(1,n+1) if deg[i]==1]
        heapq.heapify(pq)
        for x in seq:
            leaf=heapq.heappop(pq)
            edges.append((leaf,x))
            deg[leaf]-=1
            deg[x]-=1
            if deg[x]==1:
                heapq.heappush(pq,x)
        a=heapq.heappop(pq); b=heapq.heappop(pq)
        edges.append((a,b))
        trees.append(edges)
    uniq=[]
    seen=set()
    for edges in trees:
        s=tuple(sorted(tuple(sorted(e)) for e in edges))
        if s not in seen:
            seen.add(s)
            uniq.append(list(s))
    return uniq


def reachability(n, directed_edges):
    g=[[0]*n for _ in range(n)]
    for i in range(n):
        g[i][i]=1
    for u,v in directed_edges:
        g[u-1][v-1]=1
    for k in range(n):
        for i in range(n):
            if g[i][k]:
                rowk=g[k]
                rowi=g[i]
                for j in range(n):
                    if rowk[j]: rowi[j]=1
    return [''.join('1' if g[i][j] else '0' for j in range(n)) for i in range(n)]

for n in range(2,8):
    trees=prufer_trees(n)
    for edges in trees:
        m=len(edges)
        for mask in range(1<<m):
            directed=[]
            for i,(u,v) in enumerate(edges):
                if (mask>>i)&1:
                    directed.append((u,v))
                else:
                    directed.append((v,u))
            mat=reachability(n,directed)
            inp='1\n'+str(n)+'\n'+'\n'.join(mat)+'\n'
            res=subprocess.run(['cf\\competition\\cf1086\\d_test.exe'],input=inp.encode(),stdout=subprocess.PIPE).stdout.decode().strip().splitlines()
            if not res or res[0].strip().upper()!='YES':
                print('counterexample n',n)
                print('edges',directed)
                print('\n'.join(mat))
                print('output:\n', '\n'.join(res))
                raise SystemExit
print('no false negatives up to n=7')
