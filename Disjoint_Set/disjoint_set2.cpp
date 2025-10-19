#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> rank, size, parent;

    DisjointSet(int n) {
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);
        for (int i=0; i<=n; i++) {
            parent[i] = i;
        }
    }

    int get_ultimate_parent(int node) {
        if (parent[node]==node) {
            return node;
        }
        // path compression
        parent[node] = get_ultimate_parent(parent[node]);
        return parent[node];
    }

    void union_by_rank(int u, int v) {
        // get ultimate parent of u and v
        int pu = get_ultimate_parent(u);
        int pv = get_ultimate_parent(v);
        if (pu==pv) { // already belong to the same component
            return;
        }

        // get rank of pu and pv
        int rpu = rank[pu];
        int rpv = rank[pv];

        // connect smaller rank to larger rank
        if (rpu>=rpv) {
            parent[pv] = pu;
            if (rpu==rpv) {
                rank[pu]++;
            }
        }
        else {
            parent[pu] = pv;
        }
    }

    void union_by_size(int u, int v) {
        // find ultimate parent of u and v
        int pu = get_ultimate_parent(u);
        int pv = get_ultimate_parent(v);
        if (pu==pv) { // already belong to the same component
            return;
        }

        // find size of pu and pv
        int spu = size[pu];
        int spv = size[pv];

        // connnect smaller to larger
        if (spu>=spv) {
            parent[pv] = pu;
            size[pu] += spv;
        }
        else {
            parent[pu] = pv;
            size[pv] += spu;
        }
    }

    void check_same_component_existence(int u, int v) {
        int pu = get_ultimate_parent(u);
        int pv = get_ultimate_parent(v);

        cout << "Ultimate parent of " << u << " = " << pu << "\n";
        cout << "Ultimate parent of " << v << " = " << pv << "\n";
        if (pu==pv) {
            cout << "Y --> " << u << " and " << v << " belong to the same component\n";
        }
        else {
            cout << "N --> " << u << " and " << v << " DO NOT belong to the same component\n";
        }
        cout << "\n";
    }
};

int main() {
    int n = 7;
    DisjointSet ds1(n);
    ds1.union_by_rank(1, 2);
    ds1.union_by_rank(2, 3);
    ds1.union_by_rank(4, 5);
    ds1.union_by_rank(6, 7);
    ds1.union_by_rank(5, 6);

    ds1.check_same_component_existence(1, 2);
    ds1.check_same_component_existence(4, 7);
    ds1.check_same_component_existence(3, 7);
    ds1.check_same_component_existence(2, 6);
    ds1.check_same_component_existence(3, 4);
    ds1.check_same_component_existence(3, 5);

    ds1.union_by_rank(3, 7);
    cout << "\n\n----- Added 3---7 edge -----\n\n";
    ds1.check_same_component_existence(1, 2);
    ds1.check_same_component_existence(4, 7);
    ds1.check_same_component_existence(3, 7);
    ds1.check_same_component_existence(2, 6);
    ds1.check_same_component_existence(3, 4);
    ds1.check_same_component_existence(3, 5);


    cout << "\n\n----------------------------- Union by size ---------------------------\n\n";
    DisjointSet ds2(n);
    ds2.union_by_size(1, 2);
    ds2.union_by_size(2, 3);
    ds2.union_by_size(4, 5);
    ds2.union_by_size(6, 7);
    ds2.union_by_size(5, 6);

    ds2.check_same_component_existence(1, 2);
    ds2.check_same_component_existence(4, 7);
    ds2.check_same_component_existence(3, 7);
    ds2.check_same_component_existence(2, 6);
    ds2.check_same_component_existence(3, 4);
    ds2.check_same_component_existence(3, 5);

    ds2.union_by_size(3, 7);
    cout << "\n\n----- Added 3---7 edge -----\n\n";
    ds2.check_same_component_existence(1, 2);
    ds2.check_same_component_existence(4, 7);
    ds2.check_same_component_existence(3, 7);
    ds2.check_same_component_existence(2, 6);
    ds2.check_same_component_existence(3, 4);
    ds2.check_same_component_existence(3, 5);

    return 0;
}