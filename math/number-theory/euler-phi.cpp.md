---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/aoj-ntl-1-d.test.cpp
    title: test/verify/aoj-ntl-1-d.test.cpp
  - icon: ':x:'
    path: test/verify/yosupo-tetration-mod.test.cpp
    title: test/verify/yosupo-tetration-mod.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/euler-phi.md
    document_title: "Euler's-Phi-Function(\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\
      \u6570)"
    links: []
  bundledCode: "#line 1 \"math/number-theory/euler-phi.cpp\"\n/**\n * @brief Euler's-Phi-Function(\u30AA\
    \u30A4\u30E9\u30FC\u306E\u03C6\u95A2\u6570)\n * @docs docs/euler-phi.md\n */\n\
    template< typename T >\nT euler_phi(T n) {\n  T ret = n;\n  for(T i = 2; i * i\
    \ <= n; i++) {\n    if(n % i == 0) {\n      ret -= ret / i;\n      while(n % i\
    \ == 0) n /= i;\n    }\n  }\n  if(n > 1) ret -= ret / n;\n  return ret;\n}\n"
  code: "/**\n * @brief Euler's-Phi-Function(\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\
    \u6570)\n * @docs docs/euler-phi.md\n */\ntemplate< typename T >\nT euler_phi(T\
    \ n) {\n  T ret = n;\n  for(T i = 2; i * i <= n; i++) {\n    if(n % i == 0) {\n\
    \      ret -= ret / i;\n      while(n % i == 0) n /= i;\n    }\n  }\n  if(n >\
    \ 1) ret -= ret / n;\n  return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/number-theory/euler-phi.cpp
  requiredBy: []
  timestamp: '2020-03-03 18:28:13+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/verify/yosupo-tetration-mod.test.cpp
  - test/verify/aoj-ntl-1-d.test.cpp
documentation_of: math/number-theory/euler-phi.cpp
layout: document
redirect_from:
- /library/math/number-theory/euler-phi.cpp
- /library/math/number-theory/euler-phi.cpp.html
title: "Euler's-Phi-Function(\u30AA\u30A4\u30E9\u30FC\u306E\u03C6\u95A2\u6570)"
---
## 概要

正の整数 $n$ が与えられたとき, $1$ から $n$ までの自然数のうち $n$ と互いに素なものの個数 $\phi(n)$ を求める.

以下の式で効率的に求めることができる.

$\phi(n)=n\displaystyle\prod_{i=1}^k(1-\dfrac{1}{p_i})$ (ただし $p_i$ は $n$ の素因数)

* `euler_phi(n)`: $\phi(n)$ を返す.

## 計算量

* $O(\sqrt N)$