---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dp/cumulative-sum.cpp
    title: "Cumulative-Sum(\u4E00\u6B21\u5143\u7D2F\u7A4D\u548C)"
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"test/verify/yosupo-static-range-sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#line 1 \"template/template.cpp\"\
    \n#include<bits/stdc++.h>\n\nusing namespace std;\n\nusing int64 = long long;\n\
    const int mod = 1e9 + 7;\n\nconst int64 infll = (1LL << 62) - 1;\nconst int inf\
    \ = (1 << 30) - 1;\n\nstruct IoSetup {\n  IoSetup() {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n    cout << fixed << setprecision(10);\n  \
    \  cerr << fixed << setprecision(10);\n  }\n} iosetup;\n\n\ntemplate< typename\
    \ T1, typename T2 >\nostream &operator<<(ostream &os, const pair< T1, T2 >& p)\
    \ {\n  os << p.first << \" \" << p.second;\n  return os;\n}\n\ntemplate< typename\
    \ T1, typename T2 >\nistream &operator>>(istream &is, pair< T1, T2 > &p) {\n \
    \ is >> p.first >> p.second;\n  return is;\n}\n\ntemplate< typename T >\nostream\
    \ &operator<<(ostream &os, const vector< T > &v) {\n  for(int i = 0; i < (int)\
    \ v.size(); i++) {\n    os << v[i] << (i + 1 != v.size() ? \" \" : \"\");\n  }\n\
    \  return os;\n}\n\ntemplate< typename T >\nistream &operator>>(istream &is, vector<\
    \ T > &v) {\n  for(T &in : v) is >> in;\n  return is;\n}\n\ntemplate< typename\
    \ T1, typename T2 >\ninline bool chmax(T1 &a, T2 b) { return a < b && (a = b,\
    \ true); }\n\ntemplate< typename T1, typename T2 >\ninline bool chmin(T1 &a, T2\
    \ b) { return a > b && (a = b, true); }\n\ntemplate< typename T = int64 >\nvector<\
    \ T > make_v(size_t a) {\n  return vector< T >(a);\n}\n\ntemplate< typename T,\
    \ typename... Ts >\nauto make_v(size_t a, Ts... ts) {\n  return vector< decltype(make_v<\
    \ T >(ts...)) >(a, make_v< T >(ts...));\n}\n\ntemplate< typename T, typename V\
    \ >\ntypename enable_if< is_class< T >::value == 0 >::type fill_v(T &t, const\
    \ V &v) {\n  t = v;\n}\n\ntemplate< typename T, typename V >\ntypename enable_if<\
    \ is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {\n  for(auto &e\
    \ : t) fill_v(e, v);\n}\n\ntemplate< typename F >\nstruct FixPoint : F {\n  FixPoint(F\
    \ &&f) : F(forward< F >(f)) {}\n \n  template< typename... Args >\n  decltype(auto)\
    \ operator()(Args &&... args) const {\n    return F::operator()(*this, forward<\
    \ Args >(args)...);\n  }\n};\n \ntemplate< typename F >\ninline decltype(auto)\
    \ MFP(F &&f) {\n  return FixPoint< F >{forward< F >(f)};\n}\n#line 4 \"test/verify/yosupo-static-range-sum.test.cpp\"\
    \n\n#line 1 \"dp/cumulative-sum.cpp\"\n/**\n * @brief Cumulative-Sum(\u4E00\u6B21\
    \u5143\u7D2F\u7A4D\u548C)\n * @docs docs/cumulative-sum.md\n */\ntemplate< class\
    \ T >\nstruct CumulativeSum {\n  vector< T > data;\n\n  CumulativeSum() = default;\n\
    \n  explicit CumulativeSum(size_t sz) : data(sz, 0) {}\n\n  void add(int k, const\
    \ T &x) {\n    data[k] += x;\n  }\n\n  void build() {\n    for(int i = 1; i <\
    \ data.size(); i++) {\n      data[i] += data[i - 1];\n    }\n  }\n\n  T query(int\
    \ k) const {\n    if(k < 0) return 0;\n    return data[min(k, (int) data.size()\
    \ - 1)];\n  }\n};\n#line 6 \"test/verify/yosupo-static-range-sum.test.cpp\"\n\n\
    int main() {\n  int n, q;\n  cin >> n >> q;\n  CumulativeSum< int64 > cs(n);\n\
    \  for(int i = 0; i < n; i++) {\n    int x;\n    cin >> x;\n    cs.add(i, x);\n\
    \  }\n  cs.build();\n  for(int i = 0; i < q; i++) {\n    int l, r;\n    cin >>\
    \ l >> r;\n    cout << cs.query(r - 1) - cs.query(l - 1) << \"\\n\";\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include \"../../template/template.cpp\"\n\n#include \"../../dp/cumulative-sum.cpp\"\
    \n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  CumulativeSum< int64 > cs(n);\n\
    \  for(int i = 0; i < n; i++) {\n    int x;\n    cin >> x;\n    cs.add(i, x);\n\
    \  }\n  cs.build();\n  for(int i = 0; i < q; i++) {\n    int l, r;\n    cin >>\
    \ l >> r;\n    cout << cs.query(r - 1) - cs.query(l - 1) << \"\\n\";\n  }\n}\n"
  dependsOn:
  - template/template.cpp
  - dp/cumulative-sum.cpp
  isVerificationFile: true
  path: test/verify/yosupo-static-range-sum.test.cpp
  requiredBy: []
  timestamp: '2020-05-15 00:40:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/yosupo-static-range-sum.test.cpp
layout: document
redirect_from:
- /verify/test/verify/yosupo-static-range-sum.test.cpp
- /verify/test/verify/yosupo-static-range-sum.test.cpp.html
title: test/verify/yosupo-static-range-sum.test.cpp
---