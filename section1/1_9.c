// A program to find the L.C.M. and G.C.M. of any two positive integers n and m
// L.C.M. (Least Common Multiple), G.C.M. (Greatest Common Measure)
// 任意の2正整数 n, m の最小公倍数と最大公約数を求めるプログラム
// Note : Use the function int GCM(int n, int m) and the function int LCM(int n, int m)
// 注意 : 関数 int GCM(int n, int m) と関数 int LCM(int n, int m) を利用する
// Written by N.Aoki, HCU
// 2021/03/11 ver1.0

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <string.h>

int GCM(int n, int m); // For G.C.M. : 最大公倍数用
int LCM(int n, int m); // For L.C.M. : 最小公約数用

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
    // Primary variable tmp to be used for preprocessing (replacement)
    // 前処理(置換)に使用する一次変数tmp
    int tmp;
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
    while(buffer_n != NULL) {
        buffer_m = strtok(NULL, ",");
        // Countermeasures against incorrect input
        // 誤入力対策
        if (buffer_m == NULL) roop_breaker--;
        if ((buffer_m != NULL) || (roop_breaker == 0)) break;
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
        fprintf(stderr, "Error: Invalid charcter found: %ld\n", n);
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
    // Escape the case of the negative number
    // 負整数の場合はエラー終了
    if (m <= 0){
        fprintf(stderr, "Error: Invalid charcter found: %ld\n", m);
        return 1;
    }

    // As a preprocessing step (n > m), temporarily save to tmp and replace 2 numbers
    // 前処理として (n > m) にtmpに一時待避させて2数を置換
    if (n < m){
        tmp = (int)n;
        n = m;
        m = tmp;
    }

    /* Show L.C.M. and G.C.M between n and m : 2正整数 n, m の最小公倍数と最大公約数を表示 */
    printf("GCM(%ld,%ld) = %d, LCM(%ld,%ld) = %d\n", n, m, GCM((int)n, (int)m), n, m, LCM((int)n, (int)m));

    return 0;
}

/* A function that returns the G.C.M. of two arguments as a return value : 2つの引数の最大公倍数を戻り値で返す関数 */
/* Argument Positive-integer-value n, m : 引数　正の整数値 n, m */
/* Return Value G.C.M : 戻り値 最大公約数 */
int GCM(int n, int m){

    /* Explanation of each variable : 各変数の説明 */
    // The variable tmp to be used in the derivation process
    // The variable tmp_pre for the product of n and m
    // 導出過程で使用する変数 tmp, n と m の積をとる変数 tmp_pre
    int tmp_pre, tmp;

    /* Calculate the product of n and m as preprocessing : 前処理としてnとmの積を計算 */
    tmp_pre = n * m;

    /* Euclid's reciprocal division method : ユークリッドのの互除法 */
    tmp = n % m;
    while(tmp != 0){
        n = m;
        m = tmp;
        tmp = n % m;
    }

    /* Return the G.C.M. : 最大公約数を返す */
    return tmp_pre/m;

}

/* A function that returns the L.C.M. of two arguments as a return value : 2つの引数の最小公倍数を戻り値で返す関数 */
/* Argument Positive-integer-value n, m : 引数　正の整数値 n, m */
/* Return Value L.C.M : 戻り値 最小公倍数 */
int LCM(int n, int m){

    /* Explanation of each variable : 各変数の説明 */
    // The variable tmp to be used in the derivation process
    // 導出過程で使用する変数 tmp
    int tmp;

    /* Euclid's reciprocal division method : ユークリッドのの互除法 */
    tmp = n % m;
    while(tmp != 0){
        n = m;
        m = tmp;
        tmp = n % m;
    }

    /* Return the L.C.M. : 最小公倍数を返す */
    return m;

}