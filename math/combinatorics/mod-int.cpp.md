---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-range-affine-range-sum-2.test.cpp
    title: test/verify/yosupo-range-affine-range-sum-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-dpl-5-i.test.cpp
    title: test/verify/aoj-dpl-5-i.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-multipoint-evaluation.test.cpp
    title: test/verify/yosupo-multipoint-evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-polynomial-interpolation.test.cpp
    title: test/verify/yosupo-polynomial-interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-sparse-matrix-det.test.cpp
    title: test/verify/yosupo-sparse-matrix-det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-sqrt-of-formal-power-series.test.cpp
    title: test/verify/yosupo-sqrt-of-formal-power-series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-queue-operate-all-composite.test.cpp
    title: test/verify/yosupo-queue-operate-all-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-exp-of-formal-power-series.test.cpp
    title: test/verify/yosupo-exp-of-formal-power-series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-dynamic-tree-vertex-set-path-composite-2.test.cpp
    title: test/verify/yosupo-dynamic-tree-vertex-set-path-composite-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-point-set-range-composite.test.cpp
    title: test/verify/yosupo-point-set-range-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-inv-of-formal-power-series.test.cpp
    title: test/verify/yosupo-inv-of-formal-power-series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yukicoder-650.test.cpp
    title: test/verify/yukicoder-650.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-bellnoulli-number.test.cpp
    title: test/verify/yosupo-bellnoulli-number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-dpl-5-j.test.cpp
    title: test/verify/aoj-dpl-5-j.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-2405.test.cpp
    title: test/verify/aoj-2405.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-matrix-det.test.cpp
    title: test/verify/yosupo-matrix-det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-range-affine-range-sum.test.cpp
    title: test/verify/yosupo-range-affine-range-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-find-linear-recurrence.test.cpp
    title: test/verify/yosupo-find-linear-recurrence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-point-set-range-composite-2.test.cpp
    title: test/verify/yosupo-point-set-range-composite-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-dpl-5-g.test.cpp
    title: test/verify/aoj-dpl-5-g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-partition-function.test.cpp
    title: test/verify/yosupo-partition-function.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-point-set-range-composite-3.test.cpp
    title: test/verify/yosupo-point-set-range-composite-3.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-range-affine-range-sum-3.test.cpp
    title: test/verify/yosupo-range-affine-range-sum-3.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-dynamic-tree-vertex-set-path-composite.test.cpp
    title: test/verify/yosupo-dynamic-tree-vertex-set-path-composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/verify/yosupo-log-of-formal-power-series.test.cpp
    title: test/verify/yosupo-log-of-formal-power-series.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"math/combinatorics/mod-int.cpp\"\ntemplate< int mod >\n\
    struct ModInt {\n  int x;\n\n  ModInt() : x(0) {}\n\n  ModInt(int64_t y) : x(y\
    \ >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n\n  ModInt &operator+=(const\
    \ ModInt &p) {\n    if((x += p.x) >= mod) x -= mod;\n    return *this;\n  }\n\n\
    \  ModInt &operator-=(const ModInt &p) {\n    if((x += mod - p.x) >= mod) x -=\
    \ mod;\n    return *this;\n  }\n\n  ModInt &operator*=(const ModInt &p) {\n  \
    \  x = (int) (1LL * x * p.x % mod);\n    return *this;\n  }\n\n  ModInt &operator/=(const\
    \ ModInt &p) {\n    *this *= p.inverse();\n    return *this;\n  }\n\n  ModInt\
    \ operator-() const { return ModInt(-x); }\n\n  ModInt operator+(const ModInt\
    \ &p) const { return ModInt(*this) += p; }\n\n  ModInt operator-(const ModInt\
    \ &p) const { return ModInt(*this) -= p; }\n\n  ModInt operator*(const ModInt\
    \ &p) const { return ModInt(*this) *= p; }\n\n  ModInt operator/(const ModInt\
    \ &p) const { return ModInt(*this) /= p; }\n\n  bool operator==(const ModInt &p)\
    \ const { return x == p.x; }\n\n  bool operator!=(const ModInt &p) const { return\
    \ x != p.x; }\n\n  ModInt inverse() const {\n    int a = x, b = mod, u = 1, v\
    \ = 0, t;\n    while(b > 0) {\n      t = a / b;\n      swap(a -= t * b, b);\n\
    \      swap(u -= t * v, v);\n    }\n    return ModInt(u);\n  }\n\n  ModInt pow(int64_t\
    \ n) const {\n    ModInt ret(1), mul(x);\n    while(n > 0) {\n      if(n & 1)\
    \ ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n\
    \n  friend ostream &operator<<(ostream &os, const ModInt &p) {\n    return os\
    \ << p.x;\n  }\n\n  friend istream &operator>>(istream &is, ModInt &a) {\n   \
    \ int64_t t;\n    is >> t;\n    a = ModInt< mod >(t);\n    return (is);\n  }\n\
    \n  static int get_mod() { return mod; }\n};\n\nusing modint = ModInt< mod >;\n"
  code: "template< int mod >\nstruct ModInt {\n  int x;\n\n  ModInt() : x(0) {}\n\n\
    \  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}\n\n \
    \ ModInt &operator+=(const ModInt &p) {\n    if((x += p.x) >= mod) x -= mod;\n\
    \    return *this;\n  }\n\n  ModInt &operator-=(const ModInt &p) {\n    if((x\
    \ += mod - p.x) >= mod) x -= mod;\n    return *this;\n  }\n\n  ModInt &operator*=(const\
    \ ModInt &p) {\n    x = (int) (1LL * x * p.x % mod);\n    return *this;\n  }\n\
    \n  ModInt &operator/=(const ModInt &p) {\n    *this *= p.inverse();\n    return\
    \ *this;\n  }\n\n  ModInt operator-() const { return ModInt(-x); }\n\n  ModInt\
    \ operator+(const ModInt &p) const { return ModInt(*this) += p; }\n\n  ModInt\
    \ operator-(const ModInt &p) const { return ModInt(*this) -= p; }\n\n  ModInt\
    \ operator*(const ModInt &p) const { return ModInt(*this) *= p; }\n\n  ModInt\
    \ operator/(const ModInt &p) const { return ModInt(*this) /= p; }\n\n  bool operator==(const\
    \ ModInt &p) const { return x == p.x; }\n\n  bool operator!=(const ModInt &p)\
    \ const { return x != p.x; }\n\n  ModInt inverse() const {\n    int a = x, b =\
    \ mod, u = 1, v = 0, t;\n    while(b > 0) {\n      t = a / b;\n      swap(a -=\
    \ t * b, b);\n      swap(u -= t * v, v);\n    }\n    return ModInt(u);\n  }\n\n\
    \  ModInt pow(int64_t n) const {\n    ModInt ret(1), mul(x);\n    while(n > 0)\
    \ {\n      if(n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n \
    \   return ret;\n  }\n\n  friend ostream &operator<<(ostream &os, const ModInt\
    \ &p) {\n    return os << p.x;\n  }\n\n  friend istream &operator>>(istream &is,\
    \ ModInt &a) {\n    int64_t t;\n    is >> t;\n    a = ModInt< mod >(t);\n    return\
    \ (is);\n  }\n\n  static int get_mod() { return mod; }\n};\n\nusing modint = ModInt<\
    \ mod >;\n"
  dependsOn: []
  isVerificationFile: false
  path: math/combinatorics/mod-int.cpp
  requiredBy: []
  timestamp: '2019-11-30 23:36:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/yosupo-range-affine-range-sum-2.test.cpp
  - test/verify/aoj-dpl-5-i.test.cpp
  - test/verify/yosupo-multipoint-evaluation.test.cpp
  - test/verify/yosupo-polynomial-interpolation.test.cpp
  - test/verify/yosupo-sparse-matrix-det.test.cpp
  - test/verify/yosupo-sqrt-of-formal-power-series.test.cpp
  - test/verify/yosupo-queue-operate-all-composite.test.cpp
  - test/verify/yosupo-exp-of-formal-power-series.test.cpp
  - test/verify/yosupo-dynamic-tree-vertex-set-path-composite-2.test.cpp
  - test/verify/yosupo-point-set-range-composite.test.cpp
  - test/verify/yosupo-inv-of-formal-power-series.test.cpp
  - test/verify/yukicoder-650.test.cpp
  - test/verify/yosupo-bellnoulli-number.test.cpp
  - test/verify/aoj-dpl-5-j.test.cpp
  - test/verify/aoj-2405.test.cpp
  - test/verify/yosupo-matrix-det.test.cpp
  - test/verify/yosupo-range-affine-range-sum.test.cpp
  - test/verify/yosupo-find-linear-recurrence.test.cpp
  - test/verify/yosupo-point-set-range-composite-2.test.cpp
  - test/verify/aoj-dpl-5-g.test.cpp
  - test/verify/yosupo-partition-function.test.cpp
  - test/verify/yosupo-point-set-range-composite-3.test.cpp
  - test/verify/yosupo-range-affine-range-sum-3.test.cpp
  - test/verify/yosupo-dynamic-tree-vertex-set-path-composite.test.cpp
  - test/verify/yosupo-log-of-formal-power-series.test.cpp
documentation_of: math/combinatorics/mod-int.cpp
layout: document
redirect_from:
- /library/math/combinatorics/mod-int.cpp
- /library/math/combinatorics/mod-int.cpp.html
title: math/combinatorics/mod-int.cpp
---