---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/verify/yosupo-general-matching.test.cpp
    title: test/verify/yosupo-general-matching.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://qiita.com/Kutimoti_T/items/5b579773e0a24d650bdf
  bundledCode: "#line 1 \"graph/flow/gabow-edmonds.cpp\"\n// https://qiita.com/Kutimoti_T/items/5b579773e0a24d650bdf\n\
    struct GabowEdmonds {\n\n  struct edge {\n    int to, idx;\n  };\n\n  vector<\
    \ vector< edge > > g;\n  vector< pair< int, int > > edges;\n  vector< int > mate,\
    \ label, first;\n  queue< int > que;\n\n  GabowEdmonds(int n) : g(n + 1), mate(n\
    \ + 1), label(n + 1, -1), first(n + 1) {}\n\n  void add_edge(int u, int v) {\n\
    \    ++u, ++v;\n    g[u].push_back((edge) {v, (int) (edges.size() + g.size())});\n\
    \    g[v].push_back((edge) {u, (int) (edges.size() + g.size())});\n    edges.emplace_back(u,\
    \ v);\n  }\n\n  int find(int x) {\n    if(label[first[x]] < 0) return first[x];\n\
    \    first[x] = find(first[x]);\n    return first[x];\n  }\n\n  void rematch(int\
    \ v, int w) {\n    int t = mate[v];\n    mate[v] = w;\n    if(mate[t] != v) return;\n\
    \    if(label[v] < g.size()) {\n      mate[t] = label[v];\n      rematch(label[v],\
    \ t);\n    } else {\n      int x = edges[label[v] - g.size()].first;\n      int\
    \ y = edges[label[v] - g.size()].second;\n      rematch(x, y);\n      rematch(y,\
    \ x);\n    }\n  }\n\n  void assign_label(int x, int y, int num) {\n    int r =\
    \ find(x);\n    int s = find(y);\n    int join = 0;\n    if(r == s) return;\n\
    \    label[r] = -num;\n    label[s] = -num;\n    while(true) {\n      if(s !=\
    \ 0) swap(r, s);\n      r = find(label[mate[r]]);\n      if(label[r] == -num)\
    \ {\n        join = r;\n        break;\n      }\n      label[r] = -num;\n    }\n\
    \    int v = first[x];\n    while(v != join) {\n      que.push(v);\n      label[v]\
    \ = num;\n      first[v] = join;\n      v = first[label[mate[v]]];\n    }\n  \
    \  v = first[y];\n    while(v != join) {\n      que.push(v);\n      label[v] =\
    \ num;\n      first[v] = join;\n      v = first[label[mate[v]]];\n    }\n  }\n\
    \n  bool augment_check(int u) {\n    que = queue< int >();\n    first[u] = 0;\n\
    \    label[u] = 0;\n    que.push(u);\n    while(!que.empty()) {\n      int x =\
    \ que.front();\n      que.pop();\n      for(auto e : g[x]) {\n        int y =\
    \ e.to;\n        if(mate[y] == 0 && y != u) {\n          mate[y] = x;\n      \
    \    rematch(x, y);\n          return true;\n        } else if(label[y] >= 0)\
    \ {\n          assign_label(x, y, e.idx);\n        } else if(label[mate[y]] <\
    \ 0) {\n          label[mate[y]] = x;\n          first[mate[y]] = y;\n       \
    \   que.push(mate[y]);\n        }\n      }\n    }\n    return false;\n  }\n\n\
    \  vector< pair< int, int > > max_matching() {\n    for(int i = 1; i < g.size();\
    \ i++) {\n      if(mate[i] != 0) continue;\n      if(augment_check(i)) label.assign(g.size(),\
    \ -1);\n    }\n    vector< pair< int, int > > ret;\n    for(int i = 1; i < g.size();\
    \ i++) {\n      if(i < mate[i]) ret.emplace_back(i - 1, mate[i] - 1);\n    }\n\
    \    return ret;\n  }\n};\n"
  code: "// https://qiita.com/Kutimoti_T/items/5b579773e0a24d650bdf\nstruct GabowEdmonds\
    \ {\n\n  struct edge {\n    int to, idx;\n  };\n\n  vector< vector< edge > > g;\n\
    \  vector< pair< int, int > > edges;\n  vector< int > mate, label, first;\n  queue<\
    \ int > que;\n\n  GabowEdmonds(int n) : g(n + 1), mate(n + 1), label(n + 1, -1),\
    \ first(n + 1) {}\n\n  void add_edge(int u, int v) {\n    ++u, ++v;\n    g[u].push_back((edge)\
    \ {v, (int) (edges.size() + g.size())});\n    g[v].push_back((edge) {u, (int)\
    \ (edges.size() + g.size())});\n    edges.emplace_back(u, v);\n  }\n\n  int find(int\
    \ x) {\n    if(label[first[x]] < 0) return first[x];\n    first[x] = find(first[x]);\n\
    \    return first[x];\n  }\n\n  void rematch(int v, int w) {\n    int t = mate[v];\n\
    \    mate[v] = w;\n    if(mate[t] != v) return;\n    if(label[v] < g.size()) {\n\
    \      mate[t] = label[v];\n      rematch(label[v], t);\n    } else {\n      int\
    \ x = edges[label[v] - g.size()].first;\n      int y = edges[label[v] - g.size()].second;\n\
    \      rematch(x, y);\n      rematch(y, x);\n    }\n  }\n\n  void assign_label(int\
    \ x, int y, int num) {\n    int r = find(x);\n    int s = find(y);\n    int join\
    \ = 0;\n    if(r == s) return;\n    label[r] = -num;\n    label[s] = -num;\n \
    \   while(true) {\n      if(s != 0) swap(r, s);\n      r = find(label[mate[r]]);\n\
    \      if(label[r] == -num) {\n        join = r;\n        break;\n      }\n  \
    \    label[r] = -num;\n    }\n    int v = first[x];\n    while(v != join) {\n\
    \      que.push(v);\n      label[v] = num;\n      first[v] = join;\n      v =\
    \ first[label[mate[v]]];\n    }\n    v = first[y];\n    while(v != join) {\n \
    \     que.push(v);\n      label[v] = num;\n      first[v] = join;\n      v = first[label[mate[v]]];\n\
    \    }\n  }\n\n  bool augment_check(int u) {\n    que = queue< int >();\n    first[u]\
    \ = 0;\n    label[u] = 0;\n    que.push(u);\n    while(!que.empty()) {\n     \
    \ int x = que.front();\n      que.pop();\n      for(auto e : g[x]) {\n       \
    \ int y = e.to;\n        if(mate[y] == 0 && y != u) {\n          mate[y] = x;\n\
    \          rematch(x, y);\n          return true;\n        } else if(label[y]\
    \ >= 0) {\n          assign_label(x, y, e.idx);\n        } else if(label[mate[y]]\
    \ < 0) {\n          label[mate[y]] = x;\n          first[mate[y]] = y;\n     \
    \     que.push(mate[y]);\n        }\n      }\n    }\n    return false;\n  }\n\n\
    \  vector< pair< int, int > > max_matching() {\n    for(int i = 1; i < g.size();\
    \ i++) {\n      if(mate[i] != 0) continue;\n      if(augment_check(i)) label.assign(g.size(),\
    \ -1);\n    }\n    vector< pair< int, int > > ret;\n    for(int i = 1; i < g.size();\
    \ i++) {\n      if(i < mate[i]) ret.emplace_back(i - 1, mate[i] - 1);\n    }\n\
    \    return ret;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/flow/gabow-edmonds.cpp
  requiredBy: []
  timestamp: '2019-11-30 23:02:43+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/verify/yosupo-general-matching.test.cpp
documentation_of: graph/flow/gabow-edmonds.cpp
layout: document
redirect_from:
- /library/graph/flow/gabow-edmonds.cpp
- /library/graph/flow/gabow-edmonds.cpp.html
title: graph/flow/gabow-edmonds.cpp
---