// A program to calculate the sum of integers from 1 to n (the positive number), exit by entering a negative integer
// 1 から n までの正整数の和を計算するプログラム, 負整数の入力で終了
// Written by N.Aoki, HCU
// 2021/03/11 ver1.0

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

long calculation_sigma(); // Calculate the sum of positive integers : 正整数の総和を計算

int main (void){

    /* Watch for negative integer input, terminate successfully as soon as input is received //
       負整数の入力の監視, 入力され次第正常終了 */
    while(1) if(calculation_sigma() == 1) return 0;

    // Essential for processing system definition
    // 処理系定義のために必要不可欠
    return 0;
}

/* Function to calculate and display the sum of any positive integer : 任意の正整数の総和を計算し表示する関数 */
/* Argument none : 引数 なし */
/* Return At the end of normal operation (0), at the end of abnormal operation (1) : 戻り値 正常終了時（0）, 異常入力時（1） */
long calculation_sigma (void){

    /* Explanation of each variable : 各変数の説明 */
    // Store the input string in a buffer, Manipulate the string itself with endptr
    // 入力文字列を buffer に格納, 文字列自体を endptr で操作
    char buffer[32], *endptr;
    // Use i as a control variable for the for statement
    // Store input positive integer in n, Store calculation results in sigma
    // 入力正整数を n に格納, sigma に計算結果を格納, i はfor文の制御用変数
    long i, n, sigma = 0;

    /* Input the number of n : n を入力 */
    printf("Input Number ?:");

    /* Processing of input n : 入力nの処理 */
    // Escape EOF
    // 改行のみの場合はエラー終了
    if (scanf("%31[^\n]%*[^\n]", buffer) != 1) {
        fprintf(stderr, "Error: No input specified\n");
        return 1;
    }
    // Processing to skip the trailing newline
    // 末尾の改行を読み飛ばす処理
    scanf("%*c");
    // Process to read strings corresponding to n
    // n に相当する文字列を読み込む処理
    n = strtol(buffer, &endptr, 10);
    // Escape not number
    // 数字以外が混入した場合はエラー終了
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
    // If negative integer, exit normally,
    // Even if the input value is too large to overflow the result of the factorial calculation, it will terminate normally.
    // 負整数の場合は正常終了, 階乗計算結果が溢れるような大き過ぎる入力値の場合も正常終了
    if (n <= 0 || n > 4294967295){
        printf("finish\n");
        return 1;
    }

    /* calculation sigma from 1 to 100 : 1 から n までの値を総和計算 */
    for(i = 1; i <= n; i++) sigma+=i;

    /* Show summation results : 総和の結果を表示 */
    printf("SIGMA(1:%ld)=%ld\n", n, sigma);

    return 0;
}