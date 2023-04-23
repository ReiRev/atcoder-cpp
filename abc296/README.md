# Atcoder Beginner Contest 296

- <https://atcoder.jp/contests/abc296>

## D - M<=ab

### a, bの扱いについて

a, bはここでは対称な値となっているが、そのままでは解きにくいので、a<=bという制約をつけてあげると考えやすい。

### loopの処理について

ループの条件内で、`for(int i=a;a*a<=M;a++)`みたいにしていると、a*aでオーバーフローするのでやってはいけない。

### Floor関数について

M/aのフロア関数は、`(M+a-1)/a`で簡潔に書くことができる。

## E - Transition Game

まず、遷移が存在するので、グラフ問題に帰着できるのではないかと考える。すると、サイクル数を数えれば良いことに気づくので、強連結成分分解をすれば良いのだということに気づくのが鍵。

## History

- A
  - AC: 2023/4/9
- B
  - AC: 2023/4/9
- C
  - AC: 2023/4/9
- D
  - AC(with editorial): 2023/4/9
- E
  - AC(with editorial): 2023/4/24
