// A program to calculate the factorial of an arbitrary integer
// 任意の整数の階乗を計算するプログラム
// Note: Use functions with recursive calls for factorial calculations
// 注意：階乗計算には再帰呼び出しによる関数を使用
// Written by N.Aoki, HCU
// 2021/03/11 ver1.0

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int input_check(); // In Check input : 入力監視用
int calculation_factorial(int n); // Calculate the factorial : 階乗を計算

int main (void){

    /* Explanation of each variable : 各変数の説明 */
    // Store the input integer in n, use i as a control variable for the for statement
    // 入力整数を n に格納,  i はfor文の制御用変数,
    int n, i;

    /* Monitor input of any integer : 任意の整数の入力を監視 */
    if ((n = input_check()) == -1) return 1;

    /* Display of the derivation process equation : 導出過程式の表示 */
    if (n >= 0){
        for(i = 0; i < n; i++){
            if (i == (n - 1)) printf("%d", (n - i));
            else printf("%d×", (n - i));
        }
    }else if(n < 0){
        for(i = 0; i > n; i--){
             if (i == (n + 1)) printf("%d", (n - i));
             else printf("%d×", (n - i));
        }
    }

    /* Displays the factorial of any integer : 任意の整数の階乗を表示 */
    printf(" = %d\n", calculation_factorial(n));

    return 0;
}

/* In Check input, returns the input value when normal, -1 when abnormal. : 入力監視用, 正常時は入力数値を, 異常時は-1を返す */
int input_check (void){

    /* Explanation of each variable : 各変数の説明 */
    // Store the input string in a buffer, Manipulate the string itself with endptr.
    // 入力文字列を buffer に格納, 文字列自体を endptr で操作
    char buffer[32], *endptr;
    // Variables for storing the officially adopted n
    // 正式採用の n を格納用の変数
    long n;

    /* Input the number of n : n を入力 */
    printf("Input Number ?:");

    /* Processing of input n : 入力nの処理 */
    // Escape EOF
    // 改行のみの場合はエラー終了
    if (scanf("%31[^\n]%*[^\n]", buffer) != 1) {
        fprintf(stderr, "Error: No input specified\n");
        return -1;
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
        return -1;
    }
    // Escape the case of overflow and underflow
    // あまりにも大きい場合や小さい場合は予めエラー終了
    if (errno == ERANGE) {
        fprintf(stderr, "Error: Out of range (%s)\n", n == LONG_MAX ? "Overflow" : "Underflow");
        return -1;
    }

    /* Returns the input integer : 入力された整数を返す */
    return (int)n;

}

/* A function that recursively calculates the factorial of
   an argument and returns the result of the final operation.
   : 引数の階乗を再起的に計算し最終演算結果を返す関数 */
int calculation_factorial(int n){

    /* Explanation of each variable : 各変数の説明 */
    // The variable tmp to be used in the derivation process
    // 導出過程で使用する変数 tmp
    int tmp;

    if (n == 0) return 0; // The factorial of 0 is 0 : 0 の階乗は 0
    else if (n > 0){

        // Recursive call : 再帰呼び出し
        tmp = calculation_factorial(n - 1);

        /* Return the result of factorial : 階乗の結果を返す */
        return n * tmp;

    }else if (n < 0){

        // Recursive call : 再帰呼び出し
        tmp = calculation_factorial(n + 1);

        /* Return the result of factorial : 階乗の結果を返す */
        return n * tmp;

    }

    return 0;

}
