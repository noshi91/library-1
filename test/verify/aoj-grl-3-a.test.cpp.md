---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph-template.cpp
    title: graph/graph-template.cpp
  - icon: ':heavy_check_mark:'
    path: graph/others/low-link.cpp
    title: "Low-Link(\u6A4B/\u95A2\u7BC0\u70B9)"
  - icon: ':question:'
    path: template/template.cpp
    title: template/template.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
  bundledCode: "#line 1 \"test/verify/aoj-grl-3-a.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\
    \n\n#line 1 \"template/template.cpp\"\n#include<bits/stdc++.h>\n\nusing namespace\
    \ std;\n\nusing int64 = long long;\nconst int mod = 1e9 + 7;\n\nconst int64 infll\
    \ = (1LL << 62) - 1;\nconst int inf = (1 << 30) - 1;\n\nstruct IoSetup {\n  IoSetup()\
    \ {\n    cin.tie(nullptr);\n    ios::sync_with_stdio(false);\n    cout << fixed\
    \ << setprecision(10);\n    cerr << fixed << setprecision(10);\n  }\n} iosetup;\n\
    \n\ntemplate< typename T1, typename T2 >\nostream &operator<<(ostream &os, const\
    \ pair< T1, T2 >& p) {\n  os << p.first << \" \" << p.second;\n  return os;\n\
    }\n\ntemplate< typename T1, typename T2 >\nistream &operator>>(istream &is, pair<\
    \ T1, T2 > &p) {\n  is >> p.first >> p.second;\n  return is;\n}\n\ntemplate< typename\
    \ T >\nostream &operator<<(ostream &os, const vector< T > &v) {\n  for(int i =\
    \ 0; i < (int) v.size(); i++) {\n    os << v[i] << (i + 1 != v.size() ? \" \"\
    \ : \"\");\n  }\n  return os;\n}\n\ntemplate< typename T >\nistream &operator>>(istream\
    \ &is, vector< T > &v) {\n  for(T &in : v) is >> in;\n  return is;\n}\n\ntemplate<\
    \ typename T1, typename T2 >\ninline bool chmax(T1 &a, T2 b) { return a < b &&\
    \ (a = b, true); }\n\ntemplate< typename T1, typename T2 >\ninline bool chmin(T1\
    \ &a, T2 b) { return a > b && (a = b, true); }\n\ntemplate< typename T = int64\
    \ >\nvector< T > make_v(size_t a) {\n  return vector< T >(a);\n}\n\ntemplate<\
    \ typename T, typename... Ts >\nauto make_v(size_t a, Ts... ts) {\n  return vector<\
    \ decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));\n}\n\ntemplate< typename\
    \ T, typename V >\ntypename enable_if< is_class< T >::value == 0 >::type fill_v(T\
    \ &t, const V &v) {\n  t = v;\n}\n\ntemplate< typename T, typename V >\ntypename\
    \ enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {\n  for(auto\
    \ &e : t) fill_v(e, v);\n}\n\ntemplate< typename F >\nstruct FixPoint : F {\n\
    \  FixPoint(F &&f) : F(forward< F >(f)) {}\n \n  template< typename... Args >\n\
    \  decltype(auto) operator()(Args &&... args) const {\n    return F::operator()(*this,\
    \ forward< Args >(args)...);\n  }\n};\n \ntemplate< typename F >\ninline decltype(auto)\
    \ MFP(F &&f) {\n  return FixPoint< F >{forward< F >(f)};\n}\n#line 4 \"test/verify/aoj-grl-3-a.test.cpp\"\
    \n\n#line 2 \"graph/graph-template.cpp\"\n\ntemplate< typename T = int >\nstruct\
    \ Edge {\n  int from, to;\n  T cost;\n  int idx;\n\n  Edge() = default;\n\n  Edge(int\
    \ from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx)\
    \ {}\n\n  operator int() const { return to; }\n};\n\ntemplate< typename T = int\
    \ >\nstruct Graph {\n  vector< vector< Edge< T > > > g;\n  int es;\n\n  Graph()\
    \ = default;\n\n  explicit Graph(int n) : g(n), es(0) {}\n\n  size_t size() const\
    \ {\n    return g.size();\n  }\n\n  void add_directed_edge(int from, int to, T\
    \ cost = 1) {\n    g[from].emplace_back(from, to, cost, es++);\n  }\n\n  void\
    \ add_edge(int from, int to, T cost = 1) {\n    g[from].emplace_back(from, to,\
    \ cost, es);\n    g[to].emplace_back(to, from, cost, es++);\n  }\n\n  void read(int\
    \ M, int padding = -1, bool weighted = false, bool directed = false) {\n    for(int\
    \ i = 0; i < M; i++) {\n      int a, b;\n      cin >> a >> b;\n      a += padding;\n\
    \      b += padding;\n      T c = T(1);\n      if(weighted) cin >> c;\n      if(directed)\
    \ add_directed_edge(a, b, c);\n      else add_edge(a, b, c);\n    }\n  }\n};\n\
    \ntemplate< typename T = int >\nusing Edges = vector< Edge< T > >;\n#line 2 \"\
    graph/others/low-link.cpp\"\n\n/**\n * @brief Low-Link(\u6A4B/\u95A2\u7BC0\u70B9\
    )\n * @see http://kagamiz.hatenablog.com/entry/2013/10/05/005213\n * @docs docs/low-link.md\n\
    \ */\ntemplate< typename T = int >\nstruct LowLink : Graph< T > {\npublic:\n \
    \ using Graph< T >::Graph;\n  vector< int > ord, low, articulation;\n  vector<\
    \ Edge< T > > bridge;\n  using Graph< T >::g;\n\n  virtual void build() {\n  \
    \  used.assign(g.size(), 0);\n    ord.assign(g.size(), 0);\n    low.assign(g.size(),\
    \ 0);\n    int k = 0;\n    for(int i = 0; i < (int) g.size(); i++) {\n      if(!used[i])\
    \ k = dfs(i, k, -1);\n    }\n  }\n\n  explicit LowLink(const Graph< T > &g) :\
    \ Graph< T >(g) {}\n\nprivate:\n  vector< int > used;\n\n  int dfs(int idx, int\
    \ k, int par) {\n    used[idx] = true;\n    ord[idx] = k++;\n    low[idx] = ord[idx];\n\
    \    bool is_articulation = false, beet = false;\n    int cnt = 0;\n    for(auto\
    \ &to : g[idx]) {\n      if(to == par && !exchange(beet, true)) {\n        continue;\n\
    \      }\n      if(!used[to]) {\n        ++cnt;\n        k = dfs(to, k, idx);\n\
    \        low[idx] = min(low[idx], low[to]);\n        is_articulation |= par >=\
    \ 0 && low[to] >= ord[idx];\n        if(ord[idx] < low[to]) bridge.emplace_back(to);\n\
    \      } else {\n        low[idx] = min(low[idx], ord[to]);\n      }\n    }\n\
    \    is_articulation |= par == -1 && cnt > 1;\n    if(is_articulation) articulation.push_back(idx);\n\
    \    return k;\n  }\n};\n#line 6 \"test/verify/aoj-grl-3-a.test.cpp\"\n\nint main()\
    \ {\n  int V, E;\n  cin >> V >> E;\n  LowLink<> g(V);\n  g.read(E, 0);\n  g.build();\n\
    \  auto &art = g.articulation;\n  sort(art.begin(), art.end());\n  for(auto &v\
    \ : art) cout << v << \"\\n\";\n}\n\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\
    \n\n#include \"../../template/template.cpp\"\n\n#include \"../../graph/others/low-link.cpp\"\
    \n\nint main() {\n  int V, E;\n  cin >> V >> E;\n  LowLink<> g(V);\n  g.read(E,\
    \ 0);\n  g.build();\n  auto &art = g.articulation;\n  sort(art.begin(), art.end());\n\
    \  for(auto &v : art) cout << v << \"\\n\";\n}\n\n"
  dependsOn:
  - template/template.cpp
  - graph/others/low-link.cpp
  - graph/graph-template.cpp
  isVerificationFile: true
  path: test/verify/aoj-grl-3-a.test.cpp
  requiredBy: []
  timestamp: '2020-09-15 01:04:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/aoj-grl-3-a.test.cpp
layout: document
redirect_from:
- /verify/test/verify/aoj-grl-3-a.test.cpp
- /verify/test/verify/aoj-grl-3-a.test.cpp.html
title: test/verify/aoj-grl-3-a.test.cpp
---