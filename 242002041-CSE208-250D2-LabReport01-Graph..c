
#include <stdio.h>

#define MAX 100
#define INF 999999

int n, m, g[MAX][MAX];

struct Edge {
    int u, v, w;
} e[10000];

int find(int p[], int x) {
    if (p[x] != x)
        p[x] = find(p, p[x]);
    return p[x];
}

// Print path
void print(int p[], int s, int d, int cost, char name[]) {
    if (cost == INF) {
        printf("%s: Not Possible\n", name);
        return;
    }

    int path[MAX], k = 0;
    int x = d;

    while (x != -1 && k < MAX) {
        path[k++] = x;
        if (x == s) break;
        x = p[x];
    }

    if (k == 0 || path[k - 1] != s) {
        printf("%s: Not Possible\n", name);
        return;
    }

    printf("%s: ", name);

    for (int i = k - 1; i >= 0; i--) {
        printf("%d", path[i]);
        if (i > 0) printf(" -> ");
    }

    printf(" (Cost: %d)\n", cost);
}

// BFS
int bfs(int a[MAX][MAX], int s, int d, int p[]) {
    int q[MAX], vis[MAX] = {0};
    int f = 0, r = 0, cost = 0;

    for (int i = 0; i < n; i++)
        p[i] = -1;

    q[r++] = s;
    vis[s] = 1;

    while (f < r) {
        int u = q[f++];

        for (int v = 0; v < n; v++) {
            if (a[u][v] != INF && !vis[v]) {
                vis[v] = 1;
                p[v] = u;
                q[r++] = v;
            }
        }
    }

    if (!vis[d]) return INF;

    while (d != s) {
        cost += a[d][p[d]];
        d = p[d];
    }

    return cost;
}

// Dijkstra
void dijkstra(int s, int d, char name[]) {
    int dis[MAX], p[MAX], vis[MAX] = {0};

    for (int i = 0; i < n; i++) {
        dis[i] = INF;
        p[i] = -1;
    }

    dis[s] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        for (int j = 0; j < n; j++) {
            if (!vis[j] && (u == -1 || dis[j] < dis[u]))
                u = j;
        }

        if (u == -1 || dis[u] == INF)
            break;

        vis[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!vis[v] && g[u][v] != INF &&
                dis[u] + g[u][v] < dis[v]) {

                dis[v] = dis[u] + g[u][v];
                p[v] = u;
            }
        }
    }

    print(p, s, d, dis[d], name);
}

// Kruskal
void kruskal(int s, int d, char name[]) {
    int a[MAX][MAX], p[MAX], path[MAX];

    for (int i = 0; i < n; i++) {
        p[i] = i;

        for (int j = 0; j < n; j++)
            a[i][j] = INF;
    }

    // Sort edges
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (e[i].w > e[j].w) {
                struct Edge t = e[i];
                e[i] = e[j];
                e[j] = t;
            }
        }
    }

    // Build MST
    for (int i = 0; i < m; i++) {
        int u = find(p, e[i].u);
        int v = find(p, e[i].v);

        if (u != v) {
            p[u] = v;

            a[e[i].u][e[i].v] = e[i].w;
            a[e[i].v][e[i].u] = e[i].w;
        }
    }

    int cost = bfs(a, s, d, path);

    print(path, s, d, cost, name);
}

// Prim
void prim(int s, int d, char name[]) {
    int key[MAX], p[MAX], vis[MAX] = {0};
    int a[MAX][MAX], path[MAX];

    for (int i = 0; i < n; i++) {
        key[i] = INF;
        p[i] = -1;

        for (int j = 0; j < n; j++)
            a[i][j] = INF;
    }

    key[s] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;

        for (int j = 0; j < n; j++) {
            if (!vis[j] && (u == -1 || key[j] < key[u]))
                u = j;
        }

        if (u == -1 || key[u] == INF)
            break;

        vis[u] = 1;

        for (int v = 0; v < n; v++) {
            if (g[u][v] != INF && !vis[v] &&
                g[u][v] < key[v]) {

                key[v] = g[u][v];
                p[v] = u;
            }
        }
    }

    // Build MST
    for (int i = 0; i < n; i++) {
        if (p[i] != -1) {
            a[i][p[i]] = g[i][p[i]];
            a[p[i]][i] = g[i][p[i]];
        }
    }

    int cost = bfs(a, s, d, path);

    print(path, s, d, cost, name);
}

// Check connectivity
int connected() {
    int vis[MAX] = {0}, q[MAX];
    int f = 0, r = 0;

    q[r++] = 0;
    vis[0] = 1;

    while (f < r) {
        int u = q[f++];

        for (int v = 0; v < n; v++) {
            if (g[u][v] != INF && !vis[v]) {
                vis[v] = 1;
                q[r++] = v;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!vis[i])
            return 0;
    }

    return 1;
}

// Remove edge
void removeEdge(int u, int v) {
    g[u][v] = INF;
    g[v][u] = INF;

    int k = 0;

    for (int i = 0; i < m; i++) {
        if (!((e[i].u == u && e[i].v == v) ||
              (e[i].u == v && e[i].v == u))) {

            e[k++] = e[i];
        }
    }

    m = k;
}

// Main function
int main() {
    int s, d, u, v;

    printf("Enter number of vertices and edges: ");

    if (scanf("%d%d", &n, &m) != 2 ||
        n < 1 || n > MAX || m < 0 || m > 10000) {
        printf("Invalid input!\n");
        return 1;
    }

    // Initialize graph
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = INF;
        }
    }

    // Input edges
    printf("Enter edges (u v weight):\n");

    for (int i = 0; i < m; i++) {
        if (scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w) != 3 ||
            e[i].u < 0 || e[i].u >= n ||
            e[i].v < 0 || e[i].v >= n ||
            e[i].w < 0 || e[i].w >= INF) {

            printf("Invalid edge input!\n");
            return 1;
        }

        int a = e[i].u;
        int b = e[i].v;

        g[a][b] = e[i].w;
        g[b][a] = e[i].w;
    }

    // Input source, destination and removed edge
    printf("Enter source, destination and edge to remove (s d u v): ");

    if (scanf("%d%d%d%d", &s, &d, &u, &v) != 4 ||
        s < 0 || s >= n || d < 0 || d >= n ||
        u < 0 || u >= n || v < 0 || v >= n) {

        printf("Invalid vertex input!\n");
        return 1;
    }

    // Original graph
    printf("\n--- Original Graph ---\n");

    dijkstra(s, d, "Shortest Path");
    kruskal(s, d, "Kruskal Path");
    prim(s, d, "Prim Path");

    // Remove edge
    printf("\nAfter Removing Edge (%d,%d):\n", u, v);

    removeEdge(u, v);

    // Updated graph
    if (connected()) {
        dijkstra(s, d, "Updated Shortest Path");
        kruskal(s, d, "Updated Kruskal Path");
        prim(s, d, "Updated Prim Path");
    } else {
        printf("Updated Shortest Path: Not Possible\n");
        printf("Updated Kruskal Path: Not Possible\n");
        printf("Updated Prim Path: Not Possible\n");
    }

    return 0;
}
