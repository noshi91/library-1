---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/segment-tree/lazy-segment-tree.cpp
    title: "Lazy-Segment-Tree(\u9045\u5EF6\u4F1D\u642C\u30BB\u30B0\u30E1\u30F3\u30C8\
      \u6728)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/yukicoder-1720.test.cpp
    title: test/verify/yukicoder-1720.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Permutation Tree(\u9806\u5217\u6728)"
    links:
    - https://codeforces.com/blog/entry/78898
  bundledCode: "#line 1 \"structure/segment-tree/lazy-segment-tree.cpp\"\n/**\n *\
    \ @brief Lazy-Segment-Tree(\u9045\u5EF6\u4F1D\u642C\u30BB\u30B0\u30E1\u30F3\u30C8\
    \u6728)\n * @docs docs/lazy-segment-tree.md\n */\ntemplate< typename Monoid, typename\
    \ OperatorMonoid, typename F, typename G, typename H >\nstruct LazySegmentTree\
    \ {\nprivate:\n  int n{}, sz{}, height{};\n  vector< Monoid > data;\n  vector<\
    \ OperatorMonoid > lazy;\n  const F f;\n  const G g;\n  const H h;\n  const Monoid\
    \ M1;\n  const OperatorMonoid OM0;\n\n  inline void update(int k) {\n    data[k]\
    \ = f(data[2 * k + 0], data[2 * k + 1]);\n  }\n\n  inline void all_apply(int k,\
    \ const OperatorMonoid &x) {\n    data[k] = g(data[k], x);\n    if(k < sz) lazy[k]\
    \ = h(lazy[k], x);\n  }\n\n  inline void propagate(int k) {\n    if(lazy[k] !=\
    \ OM0) {\n      all_apply(2 * k + 0, lazy[k]);\n      all_apply(2 * k + 1, lazy[k]);\n\
    \      lazy[k] = OM0;\n    }\n  }\n\npublic:\n  LazySegmentTree() = default;\n\
    \n  explicit LazySegmentTree(int n, const F f, const G g, const H h,\n       \
    \                    const Monoid &M1, const OperatorMonoid &OM0)\n      : n(n),\
    \ f(f), g(g), h(h), M1(M1), OM0(OM0) {\n    sz = 1;\n    height = 0;\n    while(sz\
    \ < n) sz <<= 1, height++;\n    data.assign(2 * sz, M1);\n    lazy.assign(2 *\
    \ sz, OM0);\n  }\n\n  explicit LazySegmentTree(const vector< Monoid > &v, const\
    \ F f, const G g, const H h,\n                           const Monoid &M1, const\
    \ OperatorMonoid &OM0)\n      : LazySegmentTree(v.size(), f, g, h, M1, OM0) {\n\
    \    build(v);\n  }\n\n  void build(const vector< Monoid > &v) {\n    assert(n\
    \ == (int) v.size());\n    for(int k = 0; k < n; k++) data[k + sz] = v[k];\n \
    \   for(int k = sz - 1; k > 0; k--) update(k);\n  }\n\n  void set(int k, const\
    \ Monoid &x) {\n    k += sz;\n    for(int i = height; i > 0; i--) propagate(k\
    \ >> i);\n    data[k] = x;\n    for(int i = 1; i <= height; i++) update(k >> i);\n\
    \  }\n\n  Monoid get(int k) {\n    k += sz;\n    for(int i = height; i > 0; i--)\
    \ propagate(k >> i);\n    return data[k];\n  }\n\n  Monoid operator[](int k) {\n\
    \    return get(k);\n  }\n\n  Monoid prod(int l, int r) {\n    if(l >= r) return\
    \ M1;\n    l += sz;\n    r += sz;\n    for(int i = height; i > 0; i--) {\n   \
    \   if(((l >> i) << i) != l) propagate(l >> i);\n      if(((r >> i) << i) != r)\
    \ propagate((r - 1) >> i);\n    }\n    Monoid L = M1, R = M1;\n    for(; l < r;\
    \ l >>= 1, r >>= 1) {\n      if(l & 1) L = f(L, data[l++]);\n      if(r & 1) R\
    \ = f(data[--r], R);\n    }\n    return f(L, R);\n  }\n\n  Monoid all_prod() const\
    \ {\n    return data[1];\n  }\n\n  void apply(int k, const OperatorMonoid &x)\
    \ {\n    k += sz;\n    for(int i = height; i > 0; i--) propagate(k >> i);\n  \
    \  data[k] = g(data[k], x);\n    for(int i = 1; i <= height; i++) update(k >>\
    \ i);\n  }\n\n  void apply(int l, int r, const OperatorMonoid &x) {\n    if(l\
    \ >= r) return;\n    l += sz;\n    r += sz;\n    for(int i = height; i > 0; i--)\
    \ {\n      if(((l >> i) << i) != l) propagate(l >> i);\n      if(((r >> i) <<\
    \ i) != r) propagate((r - 1) >> i);\n    }\n    {\n      int l2 = l, r2 = r;\n\
    \      for(; l < r; l >>= 1, r >>= 1) {\n        if(l & 1) all_apply(l++, x);\n\
    \        if(r & 1) all_apply(--r, x);\n      }\n      l = l2, r = r2;\n    }\n\
    \    for(int i = 1; i <= height; i++) {\n      if(((l >> i) << i) != l) update(l\
    \ >> i);\n      if(((r >> i) << i) != r) update((r - 1) >> i);\n    }\n  }\n\n\
    \  template< typename C >\n  int find_first(int l, const C &check) {\n    if(l\
    \ >= n) return n;\n    l += sz;\n    for(int i = height; i > 0; i--) propagate(l\
    \ >> i);\n    Monoid sum = M1;\n    do {\n      while((l & 1) == 0) l >>= 1;\n\
    \      if(check(f(sum, data[l]))) {\n        while(l < sz) {\n          propagate(l);\n\
    \          l <<= 1;\n          auto nxt = f(sum, data[l]);\n          if(not check(nxt))\
    \ {\n            sum = nxt;\n            l++;\n          }\n        }\n      \
    \  return l + 1 - sz;\n      }\n      sum = f(sum, data[l++]);\n    } while((l\
    \ & -l) != l);\n    return n;\n  }\n\n  template< typename C >\n  int find_last(int\
    \ r, const C &check) {\n    if(r <= 0) return -1;\n    r += sz;\n    for(int i\
    \ = height; i > 0; i--) propagate((r - 1) >> i);\n    Monoid sum = 0;\n    do\
    \ {\n      r--;\n      while(r > 1 and (r & 1)) r >>= 1;\n      if(check(f(data[r],\
    \ sum))) {\n        while(r < sz) {\n          propagate(r);\n          r = (r\
    \ << 1) + 1;\n          auto nxt = f(data[r], sum);\n          if(not check(nxt))\
    \ {\n            sum = nxt;\n            r--;\n          }\n        }\n      \
    \  return r - sz;\n      }\n      sum = f(data[r], sum);\n    } while((r & -r)\
    \ != r);\n    return -1;\n  }\n};\n\ntemplate< typename Monoid, typename OperatorMonoid,\
    \ typename F, typename G, typename H >\nLazySegmentTree< Monoid, OperatorMonoid,\
    \ F, G, H > get_lazy_segment_tree\n    (int N, const F &f, const G &g, const H\
    \ &h, const Monoid &M1, const OperatorMonoid &OM0) {\n  return LazySegmentTree{N,\
    \ f, g, h, M1, OM0};\n}\n\ntemplate< typename Monoid, typename OperatorMonoid,\
    \ typename F, typename G, typename H >\nLazySegmentTree< Monoid, OperatorMonoid,\
    \ F, G, H > get_lazy_segment_tree\n    (const vector< Monoid > &v, const F &f,\
    \ const G &g, const H &h, const Monoid &M1, const OperatorMonoid &OM0) {\n  return\
    \ LazySegmentTree{v, f, g, h, M1, OM0};\n}\n#line 2 \"structure/others/permutation-tree.cpp\"\
    \n\n/**\n * @brief Permutation Tree(\u9806\u5217\u6728)\n * @see https://codeforces.com/blog/entry/78898\n\
    \ */\nstruct PermutationTree {\npublic:\n  enum NodeType {\n    JOIN_ASC,\n  \
    \  JOIN_DESC,\n    LEAF,\n    CUT\n  };\n\n  struct Node {\n    NodeType type;\n\
    \    int l, r; // [l, r)\n    int min_v, max_v; // [min_v, max_v)\n    vector<\
    \ Node * > ch;\n\n    size_t size() const { return r - l; }\n\n    bool is_join()\
    \ const { return type == JOIN_ASC or type == JOIN_DESC; };\n\n    bool is_leaf()\
    \ const { return type == LEAF; }\n\n    bool is_cut() const { return type == CUT;\
    \ }\n  };\n\n  using NP = Node *;\n\n  PermutationTree() = default;\n\nprivate:\n\
    \  static void add_child(NP t, NP c) {\n    t->ch.emplace_back(c);\n    t->l =\
    \ min(t->l, c->l);\n    t->r = max(t->r, c->r);\n    t->min_v = min(t->min_v,\
    \ c->min_v);\n    t->max_v = max(t->max_v, c->max_v);\n  }\n\npublic:\n  static\
    \ NP build(vector< int > &A) {\n    int n = (int) A.size();\n\n    vector< int\
    \ > desc{-1};\n    vector< int > asc{-1};\n    vector< NP > st;\n\n    auto f\
    \ = [](int a, int b) { return min(a, b); };\n    auto g = [](int a, int b) { return\
    \ a + b; };\n    constexpr int lim = (1 << 30) - 1;\n    auto seg = get_lazy_segment_tree(vector<\
    \ int >(n), f, g, g, lim, 0);\n\n    for(int i = 0; i < n; i++) {\n      while(~desc.back()\
    \ and A[i] > A[desc.back()]) {\n        seg.apply(desc[desc.size() - 2] + 1, desc.back()\
    \ + 1, A[i] - A[desc.back()]);\n        desc.pop_back();\n      }\n      while(~asc.back()\
    \ and A[i] < A[asc.back()]) {\n        seg.apply(asc[asc.size() - 2] + 1, asc.back()\
    \ + 1, A[asc.back()] - A[i]);\n        asc.pop_back();\n      }\n      desc.emplace_back(i);\n\
    \      asc.emplace_back(i);\n\n      NP t = new Node{LEAF, i, i + 1, A[i], A[i]\
    \ + 1, {}};\n      for(;;) {\n        NodeType type = CUT;\n        if(not st.empty())\
    \ {\n          if(st.back()->max_v == t->min_v) {\n            type = JOIN_ASC;\n\
    \          } else if(t->max_v == st.back()->min_v) {\n            type = JOIN_DESC;\n\
    \          }\n        }\n        if(type != CUT) {\n          NP r = st.back();\n\
    \          if(type != r->type) {\n            r = new Node{type, r->l, r->r, r->min_v,\
    \ r->max_v, {r}};\n          }\n          add_child(r, t);\n          st.pop_back();\n\
    \          t = r;\n        } else if(seg.prod(0, i + 1 - (int) t->size()) == 0)\
    \ {\n          t = new Node{CUT, t->l, t->r, t->min_v, t->max_v, {t}};\n     \
    \     do {\n            add_child(t, st.back());\n            st.pop_back();\n\
    \          } while(t->max_v - t->min_v != t->size());\n          reverse(begin(t->ch),\
    \ end(t->ch));\n        } else {\n          break;\n        }\n      }\n     \
    \ st.emplace_back(t);\n      seg.apply(0, i + 1, -1);\n    }\n    return st[0];\n\
    \  }\n};\n"
  code: "#include \"../segment-tree/lazy-segment-tree.cpp\"\n\n/**\n * @brief Permutation\
    \ Tree(\u9806\u5217\u6728)\n * @see https://codeforces.com/blog/entry/78898\n\
    \ */\nstruct PermutationTree {\npublic:\n  enum NodeType {\n    JOIN_ASC,\n  \
    \  JOIN_DESC,\n    LEAF,\n    CUT\n  };\n\n  struct Node {\n    NodeType type;\n\
    \    int l, r; // [l, r)\n    int min_v, max_v; // [min_v, max_v)\n    vector<\
    \ Node * > ch;\n\n    size_t size() const { return r - l; }\n\n    bool is_join()\
    \ const { return type == JOIN_ASC or type == JOIN_DESC; };\n\n    bool is_leaf()\
    \ const { return type == LEAF; }\n\n    bool is_cut() const { return type == CUT;\
    \ }\n  };\n\n  using NP = Node *;\n\n  PermutationTree() = default;\n\nprivate:\n\
    \  static void add_child(NP t, NP c) {\n    t->ch.emplace_back(c);\n    t->l =\
    \ min(t->l, c->l);\n    t->r = max(t->r, c->r);\n    t->min_v = min(t->min_v,\
    \ c->min_v);\n    t->max_v = max(t->max_v, c->max_v);\n  }\n\npublic:\n  static\
    \ NP build(vector< int > &A) {\n    int n = (int) A.size();\n\n    vector< int\
    \ > desc{-1};\n    vector< int > asc{-1};\n    vector< NP > st;\n\n    auto f\
    \ = [](int a, int b) { return min(a, b); };\n    auto g = [](int a, int b) { return\
    \ a + b; };\n    constexpr int lim = (1 << 30) - 1;\n    auto seg = get_lazy_segment_tree(vector<\
    \ int >(n), f, g, g, lim, 0);\n\n    for(int i = 0; i < n; i++) {\n      while(~desc.back()\
    \ and A[i] > A[desc.back()]) {\n        seg.apply(desc[desc.size() - 2] + 1, desc.back()\
    \ + 1, A[i] - A[desc.back()]);\n        desc.pop_back();\n      }\n      while(~asc.back()\
    \ and A[i] < A[asc.back()]) {\n        seg.apply(asc[asc.size() - 2] + 1, asc.back()\
    \ + 1, A[asc.back()] - A[i]);\n        asc.pop_back();\n      }\n      desc.emplace_back(i);\n\
    \      asc.emplace_back(i);\n\n      NP t = new Node{LEAF, i, i + 1, A[i], A[i]\
    \ + 1, {}};\n      for(;;) {\n        NodeType type = CUT;\n        if(not st.empty())\
    \ {\n          if(st.back()->max_v == t->min_v) {\n            type = JOIN_ASC;\n\
    \          } else if(t->max_v == st.back()->min_v) {\n            type = JOIN_DESC;\n\
    \          }\n        }\n        if(type != CUT) {\n          NP r = st.back();\n\
    \          if(type != r->type) {\n            r = new Node{type, r->l, r->r, r->min_v,\
    \ r->max_v, {r}};\n          }\n          add_child(r, t);\n          st.pop_back();\n\
    \          t = r;\n        } else if(seg.prod(0, i + 1 - (int) t->size()) == 0)\
    \ {\n          t = new Node{CUT, t->l, t->r, t->min_v, t->max_v, {t}};\n     \
    \     do {\n            add_child(t, st.back());\n            st.pop_back();\n\
    \          } while(t->max_v - t->min_v != t->size());\n          reverse(begin(t->ch),\
    \ end(t->ch));\n        } else {\n          break;\n        }\n      }\n     \
    \ st.emplace_back(t);\n      seg.apply(0, i + 1, -1);\n    }\n    return st[0];\n\
    \  }\n};\n"
  dependsOn:
  - structure/segment-tree/lazy-segment-tree.cpp
  isVerificationFile: false
  path: structure/others/permutation-tree.cpp
  requiredBy: []
  timestamp: '2021-10-27 17:32:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/yukicoder-1720.test.cpp
documentation_of: structure/others/permutation-tree.cpp
layout: document
redirect_from:
- /library/structure/others/permutation-tree.cpp
- /library/structure/others/permutation-tree.cpp.html
title: "Permutation Tree(\u9806\u5217\u6728)"
---