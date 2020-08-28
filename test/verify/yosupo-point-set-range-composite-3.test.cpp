#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "../../template/template.cpp"

#include "../../structure/develop/splay-tree-base.cpp"
#include "../../structure/develop/reversible-splay-tree.cpp"

#include "../../math/combinatorics/mod-int.cpp"

using mint = ModInt< 998244353 >;

int main() {
  int N, Q;
  cin >> N >> Q;
  using pi = pair< mint, mint >;
  auto f = [](const pi &a, const pi &b) -> pi {
    return {a.first * b.first, a.second * b.first + b.second};
  };
  auto s = [](const pi &a) { return a; };
  RST< pi > seg(f, s, pi(1, 0));
  vector< pi > V(N);
  for(int i = 0; i < N; i++) {
    cin >> V[i].first >> V[i].second;
  }
  auto root = seg.build(V);
  for(int i = 0; i < Q; i++) {
    int t;
    cin >> t;
    if(t == 0) {
      int p;
      mint a, b;
      cin >> p >> a >> b;
      seg.set_element(root, p, pi(a, b));
    } else {
      int l, r;
      mint x;
      cin >> l >> r >> x;
      auto ret = seg.query(root, l, r);
      cout << ret.first * x + ret.second << "\n";
    }
  }
}

