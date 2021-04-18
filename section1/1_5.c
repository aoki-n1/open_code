// A program that calculates the value of n ÷ m by rounding to the second decimal place
// n ÷ m の値を四捨五入して少数第二位まで計算するプログラム
// ritten by N.Aoki, HCU
// 2021/03/11 ver1.0

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <string.h>

int main (void){

    /* Explanation of each variable : 各変数の説明 */
    // Store the input string in a buffer, Manipulate the string itself with endptr.
    // 入力文字列を buffer に格納, 文字列自体を endptr で操作
    char buffer[32], *endptr;
    // Buffer_n to manipulate input n, buffer_m to manipulate input m
    // 入力 n を操作する用 buffer_n, 入力 m を操作する用 buffer_m
    char *buffer_n, *buffer_m;
    // Variables for storing the officially adopted n and m
    // 正式採用の n と m を格納用の変数
    long n, m;
    // Used for error handling for input in formats other than n and m.
    // n, m の形式以外での入力に対するエラー処理に使用
    int roop_breaker = 1;

    /* Input the number of any characters include n and m : n と m を入力 */
    printf("Input Number ?,?:");

    /* Processing of input n : 入力 n と m の処理 */
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
    buffer_n = strtok(buffer, ", ");
    // Process to read strings corresponding to m
    // m に相当する文字列を読み込む処理
    while(buffer_n != NULL){
        buffer_m = strtok(NULL, ",");
        // Countermeasures against incorrect input
        // 誤入力対策
        if(buffer_m == NULL) roop_breaker--;
        if((buffer_m != NULL) || (roop_breaker == 0)) break;
        }
    // Reads a string equivalent to n as n
    // n に相当する文字列を n として読み込み
    n = strtol(buffer_n, &endptr, 10);
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
    // Reads a string equivalent to m as m
    // m に相当する文字列を m として読み込み
    m = strtol(buffer_m, &endptr, 10);
    if (*endptr != '\0') {
        fprintf(stderr, "Error: Invalid charcter found: %c\n", *endptr);
        return 1;
    }
    // Escape the case of overflow and underflow
    // あまりにも大きい場合や小さい場合は予めエラー終了
    if (errno == ERANGE) {
        fprintf(stderr, "Error: Out of range (%s)\n", m == LONG_MAX ? "Overflow" : "Underflow");
        return 1;
    }

    /* Calculation n ÷ m, rounding half up (i.e. fractions) : n ÷ m の値を四捨五入して少数第二位まで計算 */
    printf("%ld/%ld = %.2f\n", n, m, (float)n/(float)m);

    return 0;
}