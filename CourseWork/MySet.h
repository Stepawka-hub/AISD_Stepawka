#pragma once
const int MAXN = 1000;
int p[MAXN], rank[MAXN];

void MakeSet(int x) {
    p[x] = x;
    rank[x] = 0;
}

int Find(int x) {
    if (x == p[x])
        return x;
    else
        return p[x] = Find(p[x]);
}

void Union(int x, int y) {
    if ((x = Find(x)) == (y = Find(y)))
        return;

    if (rank[x] < rank[y]) {
        p[x] = y;
    }

    else {
        p[y] = x;
        if (rank[x] == rank[y])
            ++rank[x];
    }
}