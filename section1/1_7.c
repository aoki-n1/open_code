// A program to display any input integer (0-255) in hexadecimal and binary
// 入力された任意の整数(0～255)を16進数と2進数で表示するプログラム
//ritten by N.Aoki, HCU
// 2021/03/11 ver1.0

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int calculation_bin(int n);

int main (void){

    /* Explanation of each variable : 各変数の説明 */
    // Store the input string in a buffer, Manipulate the string itself with endptr.
    // 入力文字列を buffer に格納, 文字列自体を endptr で操作
    char buffer[32], *endptr;
    // Store input positive integer in n.
    // 入力正整数を n に格納
    long n;

    /* Input the number of n : n を入力 */
    // Input the number of n.
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
    // If out-of-range integer ( n < 0 or n > 255 ), exit normally
    // 範囲外整数の場合は正常終了
    if ((n < 0) || (n > 255)){
        fprintf(stderr, "Error: Out of range (%ld)\n", n);
        return 1;
    }

    /* Displays any input integer ( 0 - 255 ) in hexadecimal and binary : 入力された任意の整数(0～255)を16進数と2進数で表示 */
    printf("%ld = %lX(HEX) = %08d(BIN)\n", n, n, calculation_bin(n));

    return 0;
}

/* Argument Positive-integer-value n(10) : 引数　正の整数値 n(10) */
/* Return Value n(2) : 戻り値 n(2) */
int calculation_bin(int n){

    /* Explanation of each variable : 各変数の説明 */
    // Store binary representation in bin, use digit to advance the number of digits
    // 2進数表現を bin に格納, 桁数を繰り上げるために digit を使用
    int result_bin = 0, digit = 1;

    /* Convert to binary representation : 2進数表現に変換 */
    while(n > 0){
        // Calculate in order from the last digit
        // 下位桁から順に計算
        result_bin += (n % 2)*digit;
        n = n/2;
        digit = digit * 10;
    }

    /* Binary representation of n : n の2進数表現 */
    return result_bin;
}