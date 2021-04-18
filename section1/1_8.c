// A program to find the L.C.M. and G.C.M. of any two positive integers n and m
// L.C.M. (Least Common Multiple), G.C.M. (Greatest Common Measure)
// 任意の2正整数 n, m の最小公倍数と最大公約数を求めるプログラム
// Written by N.Aoki, HCU
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
    // The variable tmp to be used in the derivation process
    // The variable tmp_pre for the product of n and m
    // Variables n_n and n_m for n and m to be used in derivation
    // 導出過程で使用する変数 tmp, n と m の積をとる変数 tmp_pre, 導出に使用する n と m のための変数 n_n と n_m
    int tmp, tmp_pre, n_n, n_m;
    // Used for error handling for input in formats other than n and m
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
    // Escape the case of the negative number
    // 負整数の場合はエラー終了
    if (n <= 0){
        fprintf(stderr, "Error: Out if range %ld\n", n);
        return 1;
    }
    // Reads a string equivalent to m as m
    // m に相当する文字列を m として読み込み
    m = strtol(buffer_m, &endptr, 10);
    // Escape not number
    // 数字以外が混入した場合はエラー終了
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
    // Escape the case of the negative number
    // 負整数の場合はエラー終了
    if (m <= 0){
        fprintf(stderr, "Error: Invalid charcter found: %ld\n", m);
        return 1;
    }

    /* Calculate the product of n and m as preprocessing : 前処理としてnとmの積を計算 */
    tmp_pre = (int)n * (int)m;

    // As a preprocessing step (n > m), temporarily save to tmp and replace 2 numbers
    // 前処理として (n > m) にtmpに一時待避させて2数を置換
    if (n <= m){
        tmp = (int)n;
        n = m;
        m = tmp;
    }
    // Assign variables n_n and n_m for n and m to be used for derivation
    // 導出に使用する n と m のために変数 n_n と n_m に代入
    n_n = (int)n;
    n_m = (int)m;

    /* Euclid's reciprocal division method : ユークリッドのの互除法 */
    tmp = n_n % n_m;
    while(tmp != 0){
        n_n = n_m;
        n_m = tmp;
        tmp = n_n % n_m;
    }

    /* Show L.C.M. and G.C.M between n and m : 2正整数 n, m の最小公倍数と最大公約数を表示 */
    printf("GCM(%ld,%ld) = %d, LCM(%ld,%ld) = %d\n", n, m, tmp_pre/n_m, n, m, n_m);

    return 0;
}