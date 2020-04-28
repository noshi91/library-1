---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/verify/aoj-dpl-1-i.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#5a4423c79a88aeb6104a40a645f9430c">test/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/verify/aoj-dpl-1-i.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-26 02:30:05+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_I">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_I</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/dp/knapsack-limitations-2.cpp.html">Knapsack-Limitations(個数制限つきナップサック問題) $O(N^2 \max(v_i)^2)$ <small>(dp/knapsack-limitations-2.cpp)</small></a>
* :heavy_check_mark: <a href="../../../library/dp/knapsack-limitations.cpp.html">Knapsack-Limitations(個数制限つきナップサック問題) $O(NW)$ <small>(dp/knapsack-limitations.cpp)</small></a>
* :heavy_check_mark: <a href="../../../library/template/template.cpp.html">template/template.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_I"

#include "../../template/template.cpp"

#include "../../dp/knapsack-limitations.cpp"

#include "../../dp/knapsack-limitations-2.cpp"

int main() {
  int N;
  int64 W;
  cin >> N >> W;
  vector< int > v(N);
  vector< int64 > w(N), m(N);
  for(int i = 0; i < N; i++) {
    cin >> v[i] >> w[i] >> m[i];
  }
  cout << knapsack_limitations(w, m, v, W) << endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/verify/aoj-dpl-1-i.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_I"

#line 1 "template/template.cpp"
#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

const int64 infll = (1LL << 62) - 1;
const int inf = (1 << 30) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;


template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
  os << p.first << " " << p.second;
  return os;
}

template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
  is >> p.first >> p.second;
  return is;
}

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
  for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for(T &in : v) is >> in;
  return is;
}

template< typename T1, typename T2 >
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

template< typename T = int64 >
vector< T > make_v(size_t a) {
  return vector< T >(a);
}

template< typename T, typename... Ts >
auto make_v(size_t a, Ts... ts) {
  return vector< decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));
}

template< typename T, typename V >
typename enable_if< is_class< T >::value == 0 >::type fill_v(T &t, const V &v) {
  t = v;
}

template< typename T, typename V >
typename enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {
  for(auto &e : t) fill_v(e, v);
}

template< typename F >
struct FixPoint : F {
  FixPoint(F &&f) : F(forward< F >(f)) {}
 
  template< typename... Args >
  decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, forward< Args >(args)...);
  }
};
 
template< typename F >
inline decltype(auto) MFP(F &&f) {
  return FixPoint< F >{forward< F >(f)};
}
#line 4 "test/verify/aoj-dpl-1-i.test.cpp"

#line 1 "dp/knapsack-limitations.cpp"
/**
 * @brief Knapsack-Limitations(個数制限つきナップサック問題) $O(NW)$
 * @docs docs/knapsack-limitations.md
 */
template< typename T, typename Compare = greater< T > >
vector< T > knapsack_limitations(const vector< int > &w, const vector< int > &m, const vector< T > &v,
                                 const int &W, const T &NG, const Compare &comp = Compare()) {
  const int N = (int) w.size();
  vector< T > dp(W + 1, NG), deqv(W + 1);
  dp[0] = T();
  vector< int > deq(W + 1);
  for(int i = 0; i < N; i++) {
    for(int a = 0; a < w[i]; a++) {
      int s = 0, t = 0;
      for(int j = 0; w[i] * j + a <= W; j++) {
        if(dp[w[i] * j + a] != NG) {
          auto val = dp[w[i] * j + a] - j * v[i];
          while(s < t && comp(val, deqv[t - 1])) --t;
          deq[t] = j;
          deqv[t++] = val;
        }
        if(s < t) {
          dp[j * w[i] + a] = deqv[s] + j * v[i];
          if(deq[s] == j - m[i]) ++s;
        }
      }
    }
  }
  return dp;
}
#line 6 "test/verify/aoj-dpl-1-i.test.cpp"

#line 1 "dp/knapsack-limitations-2.cpp"
/**
 * @brief Knapsack-Limitations(個数制限つきナップサック問題) $O(N^2 \max(v_i)^2)$
 * @docs docs/knapsack-limitations-2.md
 */
template< typename T >
T knapsack_limitations(const vector< T > &w, const vector< T > &m, const vector< int > &v,
                       const T &W) {
  const int N = (int) w.size();
  auto v_max = *max_element(begin(v), end(v));
  if(v_max == 0) return 0;
  vector< int > ma(N);
  vector< T > mb(N);
  for(int i = 0; i < N; i++) {
    ma[i] = min< T >(m[i], v_max - 1);
    mb[i] = m[i] - ma[i];
  }
  T sum = 0;
  for(int i = 0; i < N; i++) sum += ma[i] * v[i];
  auto dp = knapsack_limitations(v, ma, w, sum, T(-1), less<>());
  vector< int > ord(N);
  iota(begin(ord), end(ord), 0);
  sort(begin(ord), end(ord), [&](int a, int b) {
    return v[a] * w[b] > v[b] * w[a];
  });
  T ret = T();
  for(int i = 0; i < dp.size(); i++) {
    if(dp[i] > W || dp[i] == -1) continue;
    T rest = W - dp[i], cost = i;
    for(auto &p : ord) {
      auto get = min(mb[p], rest / w[p]);
      if(get == 0) break;
      cost += get * v[p];
      rest -= get * w[p];
    }
    ret = max(ret, cost);
  }
  return ret;
}
#line 8 "test/verify/aoj-dpl-1-i.test.cpp"

int main() {
  int N;
  int64 W;
  cin >> N >> W;
  vector< int > v(N);
  vector< int64 > w(N), m(N);
  for(int i = 0; i < N; i++) {
    cin >> v[i] >> w[i] >> m[i];
  }
  cout << knapsack_limitations(w, m, v, W) << endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
