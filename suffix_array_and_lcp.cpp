// implentation of suffix array and lcp O(nlgn) & O(n)
// tested

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 1<<21;
char *S;
int N, gap;
int sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN];

//#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
// lcp[i] = longest common prefix of sorted suffix_array between index i, i+1
// if i==N lcp[i] = 0

bool sufCmp(int i, int j) {
  if (pos[i] != pos[j])
    return pos[i]<pos[j];
  i += gap;
  j += gap;
  return (i<N && j<N) ? pos[i]<pos[j] : i>j;
}

void buildSA() {
  N = strlen(S);
  for(int i=0; i<N; ++i) sa[i] = i, pos[i] = S[i];
  for (gap = 1;;gap *= 2) {
    sort(sa, sa + N, sufCmp);
    for(int i=0; i<(N-1); ++i) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
    for(int i=0; i<N; ++i) pos[sa[i]] = tmp[i];
    if (tmp[N - 1] == N - 1) break;
  }
}

void buildLCP() {
  for (int i = 0, k = 0; i < N; ++i) if (pos[i] != N - 1) {
    for (int j = sa[pos[i] + 1]; S[i + k] == S[j + k]; ++k);
    lcp[pos[i]] = k;
    if(k) --k;
  }
}

int main() {
  S = "vivek";
  buildSA();
  buildLCP();

   for(int i=0;i<=4;i++)
  {
  	printf("sa: %d pos: %d\n",sa[i],pos[i]);
  }

  return 0;
}
