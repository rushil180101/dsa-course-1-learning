#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    unordered_map<int, int> dsrank;
    unordered_map<int, int> dssize;
    unordered_map<int, int> parent;

    DisjointSet() {}

    int get_parent(int x) {
        if (parent.find(x)==parent.end()) {
            // as the node is not found, set default values
            parent[x] = x;
            dsrank[x] = 0;
            dssize[x] = 1;
            return parent[x];
        }
        // path compression
        if (parent[x]==x) {
            return parent[x];
        }
        parent[x] = get_parent(parent[x]);
        return parent[x];
    }

    void union_by_dsrank(int u, int v) {
        // find ultimate parent of u and v
        int pu = get_parent(u);
        int pv = get_parent(v);
        if (pu==pv) { // already belong to the same component
            return;
        }

        // find rank of pu and pv
        int rpu = dsrank[pu];
        int rpv = dsrank[pv];

        // connect smaller to larger rank value
        if (rpu>=rpv) {
            parent[pv] = pu;
            if (rpu==rpv) {
                dsrank[pu]++;
            }
        }
        else {
            parent[pu] = pv;
        }
    }

    void union_by_dssize(int u, int v) {
        // find ultimate parent of u and v
        int pu = get_parent(u);
        int pv = get_parent(v);
        if (pu==pv) { // already belong to the same component
            return;
        }

        // find size of pu and pv
        int spu = dssize[pu];
        int spv = dssize[pv];
        if (spu>=spv) {
            parent[pv] = pu;
            dssize[pu] += spv;
        }
        else {
            parent[pu] = pv;
            dssize[pv] += spu;
        }
    }

    void check_same_component_existence(int u, int v) {
        int pu = get_parent(u);
        int pv = get_parent(v);

        cout << "Ultimate parent of " << u << " = " << pu << "\n";
        cout << "Ultimate parent of " << v << " = " << pv << "\n";
        if (pu==pv) {
            cout << u << " and " << v << " belong to the same component\n";
        }
        else {
            cout << u << " and " << v << " DO NOT belong to the same component\n";
        }
        cout << "\n";
    }
};

int main() {
    DisjointSet ds1;
    ds1.union_by_dsrank(1, 2);
    ds1.union_by_dsrank(2, 3);
    ds1.union_by_dsrank(4, 5);
    ds1.union_by_dsrank(6, 7);
    ds1.union_by_dsrank(5, 6);

    ds1.check_same_component_existence(1, 2);
    ds1.check_same_component_existence(4, 7);
    ds1.check_same_component_existence(3, 7);
    ds1.check_same_component_existence(2, 6);
    ds1.check_same_component_existence(3, 4);
    ds1.check_same_component_existence(3, 5);

    ds1.union_by_dsrank(3, 7);
    cout << "\n\n----- Added 3---7 edge -----\n\n";
    ds1.check_same_component_existence(1, 2);
    ds1.check_same_component_existence(4, 7);
    ds1.check_same_component_existence(3, 7);
    ds1.check_same_component_existence(2, 6);
    ds1.check_same_component_existence(3, 4);
    ds1.check_same_component_existence(3, 5);

    cout << "\n\n----------------------- Union by size ----------------------------\n\n";

    DisjointSet ds2;
    ds2.union_by_dssize(1, 2);
    ds2.union_by_dssize(2, 3);
    ds2.union_by_dssize(4, 5);
    ds2.union_by_dssize(6, 7);
    ds2.union_by_dssize(5, 6);

    ds2.check_same_component_existence(1, 2);
    ds2.check_same_component_existence(4, 7);
    ds2.check_same_component_existence(3, 7);
    ds2.check_same_component_existence(2, 6);
    ds2.check_same_component_existence(3, 4);
    ds2.check_same_component_existence(3, 5);

    ds2.union_by_dssize(3, 7);
    cout << "\n\n----- Added 3---7 edge -----\n\n";
    ds2.check_same_component_existence(1, 2);
    ds2.check_same_component_existence(4, 7);
    ds2.check_same_component_existence(3, 7);
    ds2.check_same_component_existence(2, 6);
    ds2.check_same_component_existence(3, 4);
    ds2.check_same_component_existence(3, 5);

    return 0;
}