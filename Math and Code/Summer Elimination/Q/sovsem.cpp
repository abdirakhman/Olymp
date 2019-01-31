  int X = 0, M = 0;
  forn(i, h)
    forn(j, w)
      if (s[i][j] == '*') {
        X++;
        if ((i + j) % 2 == 1)
          forn(k, 4) {
            int j1 = j + dx[k], i1 = i + dy[k];
            if (0 <= j1 && j1 < w && 0 <= i1 && i1 < h && s[i1][j1] == '*')
              add(F(i, j), F(i1, j1));
          }
      }

  
