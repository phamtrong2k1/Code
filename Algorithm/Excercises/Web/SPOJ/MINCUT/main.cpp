#include <bits/stdc++.h>
#define MIN(x, y) if (x > y) x = y;
#define MAX(x, y) if (x < y) x = y;
#define PB push_back
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define maxc 1000000007
#define maxn 1007

using namespace std;

int n, m, k, a[maxn][maxn];
long long s[maxn][maxn];

long long get(int u, int v, int p, int q)
{
  return s[p][q] - s[u-1][q] - s[p][v-1] + s[u-1][v-1];
}
void trau()
{
  for (int i = 1; i <= k; i++)
  {
    int x, y, u, v; cin >> x >> y >> u >> v;
    long long res = maxc*maxc;
    for (int j = y; j < v; j++)
    {
      long long cur1 = get(x, y, u, j);
      long long cur2 = get(x, j+1, u, v);
      if (abs(cur1-cur2) < res) res = abs(cur1-cur2);
    }
    for (int j = x; j < u; j++)
    {
      long long cur1 = get(x, y, j, v);
      long long cur2 = get(j+1, y, u, v);
      if (abs(cur1-cur2) < res) res = abs(cur1-cur2);
    }
    cout <<res<<endl;
  }
}

void full()
{
  for (int i = 1; i <= k; i++)
  {
    int x, y, u, v; scanf("%d %d %d %d", &x, &y, &u, &v);
    long long res = 1ll*maxc*maxc;
    int l = x, r = u;
    if (r - l == 1) res = min(res, abs(get(x, y, l, v) - get(r, y, u, v)));
    while (r - l > 1)
    {
      int mid = (r + l)/2;
      long long cur1 = get(x, y, mid, v);
      long long cur2 = get(mid+1, y, u, v);
      res = min(res, abs(cur1 - cur2));
      if (cur1 > cur2) r = mid; else l = mid;
      if (r - l == 1) res = min(res, abs(get(x, y, l, v) - get(r, y, u, v)));
    }
    l = y, r = v;
    if (r - l == 1) res = min(res, abs(get(x, y, u, l) - get(x, r, u, v)));
    while (r - l > 1)
    {
      int mid = (r + l)/2;
      long long cur1 = get(x, y, u, mid);
      long long cur2 = get(x, mid+1, u, v);
      res = min(res, abs(cur1 - cur2));
      if (cur1 > cur2) r = mid; else l = mid;
      if (r - l == 1) res = min(res, abs(get(x, y, u, l) - get(x, r, u, v)));
    }
    printf("%lld\n", res);
  }

}
int main()
{
  freopen("INP.TXT", "r", stdin);
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    {
      scanf("%d", &a[i][j]);
      s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
    }
  //if (k*n < 10000000) trau();
   full();
}
