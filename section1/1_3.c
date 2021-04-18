// A program to calculate the sum of integers from 1 to n (the positive number)
// 1 から n までの正整数の和を計算するプログラム
// Written by N.Aoki, HCU
// 2021/03/11 ver1.0

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int main (void){

    /* Explanation of each variable : 各変数の説明 */
    // Store calculation results in sigma, Store control variable in for statement.
    // sigma に計算結果を格納, i はfor文の制御用変数
    int sigma = 0, i;
    // Store the input string in a buffer, Manipulate the string itself with endptr.
    // 入力文字列を buffer に格納, 文字列自体を endptr で操作
    char buffer[32], *endptr;
    // Store input positive integer in n.
    // 入力正整数を n に格納
    long n;

    /* Input the number of n : n を入力 */
    printf("Input Number ?:");

    /* Processing of input n : 入力 n の処理 */
    // Escape EOF
    // 改行のみの場合はエラー終了
    if (scanf("%31[^\n]%*[^\n]", buffer) != 1) {
        fprintf(stderr, "Error: No input specified\n");
        return 1;
    }
    // Processing to skip the trailing newline
    // 末尾の改行を読み飛ばす処理
    scanf("%*c");
    // Escape not number
    // 数字以外が混入した場合はエラー終了
    n = strtol(buffer, &endptr, 10);
    if (*endptr != '\0') {
        fprintf(stderr, "Error: Invalid charcter found: %c\n", *endptr);
        return 1;
    }
    // Escape the case of overflow and underflow
    // あまりにも大きい場合や小さい場合は予めエラー終了
    if (errno == ERANGE) {
        fprintf(stderr, "Error: Out of range (%s)\n", n == LONG_MAX ? "Overflow" : "Underflow");
        return 1;
    }
    // Escape the negative number
    // 負整数の場合はエラー終了
    if (n <= 0){
        fprintf(stderr, "Error: Out if range %ld\n", n);
        return 1;
    }

    /* calculation sigma from 1 to 100 : 1 から n までの値を総和計算 */
    for(i = 1; i <= n; i++) sigma+=i;

    /* Show summation results : 総和の結果を表示 */
    printf("SIGMA(1:%ld)=%d\n", n, sigma);

    return 0;
}