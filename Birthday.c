#include <stdio.h>

long long allDiff(int n){
    long long tmp = 1;
    for (int i=0;i<n;i++){
        tmp *= (365-i);
    }
    return tmp;
}

long long allSitu(int n){
    long long tmp = 1;
    for (int i=0;i<n;i++){
        tmp *= 365;
    }
    return tmp;
}

long double test(int n){
    long double tmp = 1;
    for (int i=0;i<n;i++){
        tmp *= (365-i);
        tmp /= 365;
    }
    return tmp;
}
int main(){
    for (int i=2;i<=365;i++){
        double a = 1 - test(i);
        printf("%3d人的几率为%.19f%\n", i, a*100);
    }
    return 0;
}