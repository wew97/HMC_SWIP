#include <stdio.h>
#define k (21 - i - m - b - a - c)

int computeGCD(int x, int y)
{
    int temp;

    while(y) {
        temp = x % y;
        x = y;
        y = temp;
    }
    return x;
}

long computeLCM(int x, int y)
{
    long temp = x*y;
    
    temp = temp/computeGCD(x, y);
    return temp;
}

int main()
{
    int i, m, b, a, c;
    long lcmMax = 0, lcmThis;
    int firstValue, secondValue;

    for(i = 1; i < 7; i++) {
        for(m = 1; m < 7; m++) {
            if(i == m) continue;
            for(b = 1; b < 7; b++) {
                if(b == i || b == m) continue;
                for(a = 1; a < 7; a++) {
                    if(a == i || a == m || a == b) continue;
                    for(c = 1; c < 7; c++) {
                        if(c == i || c == m || c == b || c == a) continue;
                        if(0 < k && k < 7 && i*a*k == b*m*k + m*a*c) { 
                            printf("%d%d.%d%d%d%d\n", i, m, b, a, c, k);
                            lcmThis = computeLCM(i*10 + m, b*1000 + a*100 + c*10 +k);
                            if (lcmThis > lcmMax) {
                                lcmMax = lcmThis;
                                firstValue = i*10 + m;
                                secondValue = b*1000 + a*100 + c*10 +k;                                
                            }
                        }
                    }
                }
            }
        }
    }
    
    printf("LCM(%d, %d) = %ld\n", firstValue, secondValue, lcmMax);
}