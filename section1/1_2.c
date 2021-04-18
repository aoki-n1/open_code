// A program to calculate the sum of integers from 1 to 100
// 1 から 100 までの整数の和を計算するプログラム
// Written by N.Aoki, HCU
// 2021/03/11 ver1.0

#include <stdio.h>

int main (void){

    /* Explanation of each variable : 各変数の説明 */
    // Store calculation results in sigma, use i as a control variable for the for statement
    // sigma に計算結果を格納, i はfor文の制御用変数
    int sigma = 0, i;

    /* calculation sigma from 1 to 100 : 1 から 100 までの値を総和計算 */
    for(i = 1; i <= 100; i++) sigma += i;

    /* Show summation results : 総和の結果を表示 */
    printf("SIGMA(1:100) = %d\n", sigma);

    return 0;
}
