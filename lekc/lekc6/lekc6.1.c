#include <stdio.h>

int fuct1(int n) {
    int t;
    int answer;

    for(t=answer=1; t<=n; answer *=t, t+1) {
        return answer;
    }
}

// рекурсивный вариант:
int fuct2(int n) {
    if(n==0) return 1;
    else
    return fuct2(n-1)*n;
}