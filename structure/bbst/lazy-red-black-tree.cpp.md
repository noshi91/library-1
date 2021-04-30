---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/yosupo-range-affine-range-sum-2.test.cpp
    title: test/verify/yosupo-range-affine-range-sum-2.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/lazy-red-black-tree.md
    document_title: "Lazy-Red-Black-Tree(\u9045\u5EF6\u4F1D\u642C\u8D64\u9ED2\u6728\
      )"
    links: []
  bundledCode: "#line 1 \"structure/bbst/lazy-red-black-tree.cpp\"\n/**\n * @brief\
    \ Lazy-Red-Black-Tree(\u9045\u5EF6\u4F1D\u642C\u8D64\u9ED2\u6728)\n * @docs docs/lazy-red-black-tree.md\n\
    \ */\ntemplate< typename Monoid, typename OperatorMonoid, typename F, typename\
    \ G, typename H >\nstruct LazyRedBlackTree {\npublic:\n  enum COLOR {\n    BLACK,\
    \ RED\n  };\n\n  struct Node {\n    Node *l, *r;\n    COLOR color;\n    int level,\
    \ cnt;\n    Monoid key, sum;\n    OperatorMonoid lazy;\n\n    Node() {}\n\n  \
    \  Node(const Monoid &k, const OperatorMonoid &laz) :\n        key(k), sum(k),\
    \ l(nullptr), r(nullptr), color(BLACK), level(0), cnt(1), lazy(laz) {}\n\n   \
    \ Node(Node *l, Node *r, const Monoid &k, const OperatorMonoid &laz) :\n     \
    \   key(k), color(RED), l(l), r(r), lazy(laz) {}\n\n    bool is_leaf() const {\n\
    \      return l == nullptr;\n    }\n  };\n\nprivate:\n  Node *propagate(Node *t)\
    \ {\n    t = clone(t);\n    if(t->lazy != OM0) {\n      if(t->is_leaf()) {\n \
    \       t->key = g(t->key, t->lazy);\n      } else {\n        if(t->l) {\n   \
    \       t->l = clone(t->l);\n          t->l->lazy = h(t->l->lazy, t->lazy);\n\
    \          t->l->sum = g(t->l->sum, t->lazy);\n        }\n        if(t->r) {\n\
    \          t->r = clone(t->r);\n          t->r->lazy = h(t->r->lazy, t->lazy);\n\
    \          t->r->sum = g(t->r->sum, t->lazy);\n        }\n      }\n      t->lazy\
    \ = OM0;\n    }\n    return update(t);\n  }\n\n  inline Node *alloc(Node *l, Node\
    \ *r) {\n    auto t = &(*pool.alloc() = Node(l, r, M1, OM0));\n    return update(t);\n\
    \  }\n\n  virtual Node *clone(Node *t) {\n    return t;\n  }\n\n  Node *rotate(Node\
    \ *t, bool b) {\n    t = propagate(t);\n    Node *s;\n    if(b) {\n      s = propagate(t->l);\n\
    \      t->l = s->r;\n      s->r = t;\n    } else {\n      s = propagate(t->r);\n\
    \      t->r = s->l;\n      s->l = t;\n    }\n    update(t);\n    return update(s);\n\
    \  }\n\n  Node *submerge(Node *l, Node *r) {\n    if(l->level < r->level) {\n\
    \      r = propagate(r);\n      Node *c = (r->l = submerge(l, r->l));\n      if(r->color\
    \ == BLACK && c->color == RED && c->l && c->l->color == RED) {\n        r->color\
    \ = RED;\n        c->color = BLACK;\n        if(r->r->color == BLACK) return rotate(r,\
    \ true);\n        r->r->color = BLACK;\n      }\n      return update(r);\n   \
    \ }\n    if(l->level > r->level) {\n      l = propagate(l);\n      Node *c = (l->r\
    \ = submerge(l->r, r));\n      if(l->color == BLACK && c->color == RED && c->r\
    \ && c->r->color == RED) {\n        l->color = RED;\n        c->color = BLACK;\n\
    \        if(l->l->color == BLACK) return rotate(l, false);\n        l->l->color\
    \ = BLACK;\n      }\n      return update(l);\n    }\n    return alloc(l, r);\n\
    \  }\n\n  Node *build(int l, int r, const vector< Monoid > &v) {\n    if(l + 1\
    \ >= r) return alloc(v[l]);\n    return merge(build(l, (l + r) >> 1, v), build((l\
    \ + r) >> 1, r, v));\n  }\n\n  Node *update(Node *t) {\n    t->cnt = count(t->l)\
    \ + count(t->r) + t->is_leaf();\n    t->level = t->is_leaf() ? 0 : t->l->level\
    \ + (t->l->color == BLACK);\n    t->sum = f(f(sum(t->l), t->key), sum(t->r));\n\
    \    return t;\n  }\n\n  void dump(Node *r, typename vector< Monoid >::iterator\
    \ &it, OperatorMonoid lazy) {\n    if(r->lazy != OM0) lazy = h(lazy, r->lazy);\n\
    \    if(r->is_leaf()) {\n      *it++ = g(r->key, lazy);\n      return;\n    }\n\
    \    dump(r->l, it, lazy);\n    dump(r->r, it, lazy);\n  }\n\n  Node *merge(Node\
    \ *l) {\n    return l;\n  }\n\npublic:\n\n  VectorPool< Node > pool;\n  const\
    \ F f;\n  const G g;\n  const H h;\n  const OperatorMonoid OM0;\n  const Monoid\
    \ M1;\n\n  LazyRedBlackTree(int sz, const F &f, const G &g, const H &h, const\
    \ Monoid &M1, const OperatorMonoid &OM0) :\n      pool(sz), M1(M1), OM0(OM0),\
    \ f(f), g(g), h(h) { pool.clear(); }\n\n\n  inline Node *alloc(const Monoid &key)\
    \ {\n    return &(*pool.alloc() = Node(key, OM0));\n  }\n\n  inline int count(const\
    \ Node *t) { return t ? t->cnt : 0; }\n\n  inline const Monoid &sum(const Node\
    \ *t) { return t ? t->sum : M1; }\n\n  pair< Node *, Node * > split(Node *t, int\
    \ k) {\n    if(!t) return {nullptr, nullptr};\n    t = propagate(t);\n    if(k\
    \ == 0) return {nullptr, t};\n    if(k >= count(t)) return {t, nullptr};\n   \
    \ Node *l = t->l, *r = t->r;\n    pool.free(t);\n    if(k < count(l)) {\n    \
    \  auto pp = split(l, k);\n      return {pp.first, merge(pp.second, r)};\n   \
    \ }\n    if(k > count(l)) {\n      auto pp = split(r, k - count(l));\n      return\
    \ {merge(l, pp.first), pp.second};\n    }\n    return {l, r};\n  }\n\n  tuple<\
    \ Node *, Node *, Node * > split3(Node *t, int a, int b) {\n    auto x = split(t,\
    \ a);\n    auto y = split(x.second, b - a);\n    return make_tuple(x.first, y.first,\
    \ y.second);\n  }\n\n  template< typename ... Args >\n  Node *merge(Node *l, Args\
    \ ...rest) {\n    Node *r = merge(rest...);\n    if(!l || !r) return l ? l : r;\n\
    \    Node *c = submerge(l, r);\n    c->color = BLACK;\n    return c;\n  }\n\n\
    \  Node *build(const vector< Monoid > &v) {\n    return build(0, (int) v.size(),\
    \ v);\n  }\n\n  vector< Monoid > dump(Node *r) {\n    vector< Monoid > v((size_t)\
    \ count(r));\n    auto it = begin(v);\n    dump(r, it, OM0);\n    return v;\n\
    \  }\n\n  string to_string(Node *r) {\n    auto s = dump(r);\n    string ret;\n\
    \    for(int i = 0; i < s.size(); i++) {\n      ret += std::to_string(s[i]);\n\
    \      ret += \", \";\n    }\n    return ret;\n  }\n\n  void insert(Node *&t,\
    \ int k, const Monoid &v) {\n    auto x = split(t, k);\n    t = merge(merge(x.first,\
    \ alloc(v)), x.second);\n  }\n\n  Monoid erase(Node *&t, int k) {\n    auto x\
    \ = split(t, k);\n    auto y = split(x.second, 1);\n    auto v = y.first->key;\n\
    \    pool.free(y.first);\n    t = merge(x.first, y.second);\n    return v;\n \
    \ }\n\n  Monoid query(Node *&t, int a, int b) {\n    auto x = split(t, a);\n \
    \   auto y = split(x.second, b - a);\n    Monoid ret = sum(y.first);\n    t =\
    \ merge(x.first, y.first, y.second);\n    return ret;\n  }\n\n  void set_propagate(Node\
    \ *&t, int a, int b, const OperatorMonoid &pp) {\n    auto x = split(t, a);\n\
    \    auto y = split(x.second, b - a);\n    y.first->lazy = h(y.first->lazy, pp);\n\
    \    t = merge(x.first, propagate(y.first), y.second);\n  }\n\n  void set_element(Node\
    \ *&t, int k, const Monoid &x) {\n    t = propagate(t);\n    if(t->is_leaf())\
    \ {\n      t->key = t->sum = x;\n      return;\n    }\n    if(k < count(t->l))\
    \ set_element(t->l, k, x);\n    else set_element(t->r, k - count(t->l), x);\n\
    \    t = update(t);\n  }\n\n  void push_front(Node *&t, const Monoid &v) {\n \
    \   t = merge(alloc(v), t);\n  }\n\n  void push_back(Node *&t, const Monoid &v)\
    \ {\n    t = merge(t, alloc(v));\n  }\n\n  Monoid pop_front(Node *&t) {\n    auto\
    \ ret = split(t, 1);\n    t = ret.second;\n    return ret.first->key;\n  }\n\n\
    \  Monoid pop_back(Node *&t) {\n    auto ret = split(t, count(t) - 1);\n    t\
    \ = ret.first;\n    return ret.second->key;\n  }\n};\n"
  code: "/**\n * @brief Lazy-Red-Black-Tree(\u9045\u5EF6\u4F1D\u642C\u8D64\u9ED2\u6728\
    )\n * @docs docs/lazy-red-black-tree.md\n */\ntemplate< typename Monoid, typename\
    \ OperatorMonoid, typename F, typename G, typename H >\nstruct LazyRedBlackTree\
    \ {\npublic:\n  enum COLOR {\n    BLACK, RED\n  };\n\n  struct Node {\n    Node\
    \ *l, *r;\n    COLOR color;\n    int level, cnt;\n    Monoid key, sum;\n    OperatorMonoid\
    \ lazy;\n\n    Node() {}\n\n    Node(const Monoid &k, const OperatorMonoid &laz)\
    \ :\n        key(k), sum(k), l(nullptr), r(nullptr), color(BLACK), level(0), cnt(1),\
    \ lazy(laz) {}\n\n    Node(Node *l, Node *r, const Monoid &k, const OperatorMonoid\
    \ &laz) :\n        key(k), color(RED), l(l), r(r), lazy(laz) {}\n\n    bool is_leaf()\
    \ const {\n      return l == nullptr;\n    }\n  };\n\nprivate:\n  Node *propagate(Node\
    \ *t) {\n    t = clone(t);\n    if(t->lazy != OM0) {\n      if(t->is_leaf()) {\n\
    \        t->key = g(t->key, t->lazy);\n      } else {\n        if(t->l) {\n  \
    \        t->l = clone(t->l);\n          t->l->lazy = h(t->l->lazy, t->lazy);\n\
    \          t->l->sum = g(t->l->sum, t->lazy);\n        }\n        if(t->r) {\n\
    \          t->r = clone(t->r);\n          t->r->lazy = h(t->r->lazy, t->lazy);\n\
    \          t->r->sum = g(t->r->sum, t->lazy);\n        }\n      }\n      t->lazy\
    \ = OM0;\n    }\n    return update(t);\n  }\n\n  inline Node *alloc(Node *l, Node\
    \ *r) {\n    auto t = &(*pool.alloc() = Node(l, r, M1, OM0));\n    return update(t);\n\
    \  }\n\n  virtual Node *clone(Node *t) {\n    return t;\n  }\n\n  Node *rotate(Node\
    \ *t, bool b) {\n    t = propagate(t);\n    Node *s;\n    if(b) {\n      s = propagate(t->l);\n\
    \      t->l = s->r;\n      s->r = t;\n    } else {\n      s = propagate(t->r);\n\
    \      t->r = s->l;\n      s->l = t;\n    }\n    update(t);\n    return update(s);\n\
    \  }\n\n  Node *submerge(Node *l, Node *r) {\n    if(l->level < r->level) {\n\
    \      r = propagate(r);\n      Node *c = (r->l = submerge(l, r->l));\n      if(r->color\
    \ == BLACK && c->color == RED && c->l && c->l->color == RED) {\n        r->color\
    \ = RED;\n        c->color = BLACK;\n        if(r->r->color == BLACK) return rotate(r,\
    \ true);\n        r->r->color = BLACK;\n      }\n      return update(r);\n   \
    \ }\n    if(l->level > r->level) {\n      l = propagate(l);\n      Node *c = (l->r\
    \ = submerge(l->r, r));\n      if(l->color == BLACK && c->color == RED && c->r\
    \ && c->r->color == RED) {\n        l->color = RED;\n        c->color = BLACK;\n\
    \        if(l->l->color == BLACK) return rotate(l, false);\n        l->l->color\
    \ = BLACK;\n      }\n      return update(l);\n    }\n    return alloc(l, r);\n\
    \  }\n\n  Node *build(int l, int r, const vector< Monoid > &v) {\n    if(l + 1\
    \ >= r) return alloc(v[l]);\n    return merge(build(l, (l + r) >> 1, v), build((l\
    \ + r) >> 1, r, v));\n  }\n\n  Node *update(Node *t) {\n    t->cnt = count(t->l)\
    \ + count(t->r) + t->is_leaf();\n    t->level = t->is_leaf() ? 0 : t->l->level\
    \ + (t->l->color == BLACK);\n    t->sum = f(f(sum(t->l), t->key), sum(t->r));\n\
    \    return t;\n  }\n\n  void dump(Node *r, typename vector< Monoid >::iterator\
    \ &it, OperatorMonoid lazy) {\n    if(r->lazy != OM0) lazy = h(lazy, r->lazy);\n\
    \    if(r->is_leaf()) {\n      *it++ = g(r->key, lazy);\n      return;\n    }\n\
    \    dump(r->l, it, lazy);\n    dump(r->r, it, lazy);\n  }\n\n  Node *merge(Node\
    \ *l) {\n    return l;\n  }\n\npublic:\n\n  VectorPool< Node > pool;\n  const\
    \ F f;\n  const G g;\n  const H h;\n  const OperatorMonoid OM0;\n  const Monoid\
    \ M1;\n\n  LazyRedBlackTree(int sz, const F &f, const G &g, const H &h, const\
    \ Monoid &M1, const OperatorMonoid &OM0) :\n      pool(sz), M1(M1), OM0(OM0),\
    \ f(f), g(g), h(h) { pool.clear(); }\n\n\n  inline Node *alloc(const Monoid &key)\
    \ {\n    return &(*pool.alloc() = Node(key, OM0));\n  }\n\n  inline int count(const\
    \ Node *t) { return t ? t->cnt : 0; }\n\n  inline const Monoid &sum(const Node\
    \ *t) { return t ? t->sum : M1; }\n\n  pair< Node *, Node * > split(Node *t, int\
    \ k) {\n    if(!t) return {nullptr, nullptr};\n    t = propagate(t);\n    if(k\
    \ == 0) return {nullptr, t};\n    if(k >= count(t)) return {t, nullptr};\n   \
    \ Node *l = t->l, *r = t->r;\n    pool.free(t);\n    if(k < count(l)) {\n    \
    \  auto pp = split(l, k);\n      return {pp.first, merge(pp.second, r)};\n   \
    \ }\n    if(k > count(l)) {\n      auto pp = split(r, k - count(l));\n      return\
    \ {merge(l, pp.first), pp.second};\n    }\n    return {l, r};\n  }\n\n  tuple<\
    \ Node *, Node *, Node * > split3(Node *t, int a, int b) {\n    auto x = split(t,\
    \ a);\n    auto y = split(x.second, b - a);\n    return make_tuple(x.first, y.first,\
    \ y.second);\n  }\n\n  template< typename ... Args >\n  Node *merge(Node *l, Args\
    \ ...rest) {\n    Node *r = merge(rest...);\n    if(!l || !r) return l ? l : r;\n\
    \    Node *c = submerge(l, r);\n    c->color = BLACK;\n    return c;\n  }\n\n\
    \  Node *build(const vector< Monoid > &v) {\n    return build(0, (int) v.size(),\
    \ v);\n  }\n\n  vector< Monoid > dump(Node *r) {\n    vector< Monoid > v((size_t)\
    \ count(r));\n    auto it = begin(v);\n    dump(r, it, OM0);\n    return v;\n\
    \  }\n\n  string to_string(Node *r) {\n    auto s = dump(r);\n    string ret;\n\
    \    for(int i = 0; i < s.size(); i++) {\n      ret += std::to_string(s[i]);\n\
    \      ret += \", \";\n    }\n    return ret;\n  }\n\n  void insert(Node *&t,\
    \ int k, const Monoid &v) {\n    auto x = split(t, k);\n    t = merge(merge(x.first,\
    \ alloc(v)), x.second);\n  }\n\n  Monoid erase(Node *&t, int k) {\n    auto x\
    \ = split(t, k);\n    auto y = split(x.second, 1);\n    auto v = y.first->key;\n\
    \    pool.free(y.first);\n    t = merge(x.first, y.second);\n    return v;\n \
    \ }\n\n  Monoid query(Node *&t, int a, int b) {\n    auto x = split(t, a);\n \
    \   auto y = split(x.second, b - a);\n    Monoid ret = sum(y.first);\n    t =\
    \ merge(x.first, y.first, y.second);\n    return ret;\n  }\n\n  void set_propagate(Node\
    \ *&t, int a, int b, const OperatorMonoid &pp) {\n    auto x = split(t, a);\n\
    \    auto y = split(x.second, b - a);\n    y.first->lazy = h(y.first->lazy, pp);\n\
    \    t = merge(x.first, propagate(y.first), y.second);\n  }\n\n  void set_element(Node\
    \ *&t, int k, const Monoid &x) {\n    t = propagate(t);\n    if(t->is_leaf())\
    \ {\n      t->key = t->sum = x;\n      return;\n    }\n    if(k < count(t->l))\
    \ set_element(t->l, k, x);\n    else set_element(t->r, k - count(t->l), x);\n\
    \    t = update(t);\n  }\n\n  void push_front(Node *&t, const Monoid &v) {\n \
    \   t = merge(alloc(v), t);\n  }\n\n  void push_back(Node *&t, const Monoid &v)\
    \ {\n    t = merge(t, alloc(v));\n  }\n\n  Monoid pop_front(Node *&t) {\n    auto\
    \ ret = split(t, 1);\n    t = ret.second;\n    return ret.first->key;\n  }\n\n\
    \  Monoid pop_back(Node *&t) {\n    auto ret = split(t, count(t) - 1);\n    t\
    \ = ret.first;\n    return ret.second->key;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/bbst/lazy-red-black-tree.cpp
  requiredBy: []
  timestamp: '2020-05-14 23:23:31+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/yosupo-range-affine-range-sum-2.test.cpp
documentation_of: structure/bbst/lazy-red-black-tree.cpp
layout: document
redirect_from:
- /library/structure/bbst/lazy-red-black-tree.cpp
- /library/structure/bbst/lazy-red-black-tree.cpp.html
title: "Lazy-Red-Black-Tree(\u9045\u5EF6\u4F1D\u642C\u8D64\u9ED2\u6728)"
---
## 概要

Lazy-Red-Black-Tree は Red-Black-Tree に遅延伝搬を実装したものである.

* `LazyRedBlackTree(n, f, g, h, M1, OM0)`: サイズ `n` で初期化する. ここで `f` は2つの区間の要素をマージする二項演算, `g` は要素と作用素をマージする二項演算, `h` は作用素同士をマージする二項演算, `M1` はモノイドの単位元, `OM0` は作用素の単位元である.
* `split(t, k)`: 木 `t` を $[0, k)[k, n)$ で分割する.
* `split3(t, a, b)`: 木 `t` を $[0, a)[a, b)[b, n)$ で分割する.
* `merge(l, r)`: 木 `l` と木 `r` を併合する.
* `build(v)`: 配列 `v` をもとに木を構築する.
* `dump(r)`: 木 `r` の葉を通りがけ順に格納したものを返す.
* `to_string(r)`: `dump(r)` をスペース区切りで文字列として連結したものを返す.
* `insert(t, k, v)`: 木 `t` の位置 `k` (0-indexed) にノード `v` を挿入する.
* `erase(t, k)`: 木 `t` の位置 `k` (0-indexed) のノードを削除する.
* `query(t, l, r)`: 区間 $[l, r)$ の要素を二項演算した結果を返す.
* `set_element(t, k, x)`: 木 `t` の位置 `k` (0-indexed) のノードを `x` に変更する.
* `set_propagate(t, a, b, pp)`: 木 `t` の区間 $[a, b)$ の要素に作用素 `pp` を適用する.
* `push_front(t, v)`: 木 `t` の先頭にノード `v` を挿入する.
* `push_back(t, v)`: 木 `t` の末尾にノード `v` を挿入する.
* `pop_front(t)`: 木 `t` の先頭要素を削除する.
* `pop_back(t)`: 木 `t` の末尾要素を削除する.

## 計算量

* $O(\log n)$ 但し `build` と `dump` は $O(n)$