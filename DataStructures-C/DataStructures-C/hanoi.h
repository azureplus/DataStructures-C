//
//  hanoi.h
//  DataStructures-C
//
//  Created by dev on 15/12/17.
//  Copyright © 2015年 azurestudio. All rights reserved.
/*1.河内之塔
说明河内之塔(Towers of Hanoi)是法国人M.Claus(Lucas)于1883年从泰国带至法国的，河内为越战时北越的首都，即现在的胡志明市；1883年法国数学家 Edouard Lucas曾提及这个故事，据说创世纪时Benares有一座波罗教塔，是由三支钻石棒（Pag）所支撑，开始时神在第一根棒上放置64个由上至下依由小至大排列的金盘（Disc），并命令僧侣将所有的金盘从第一根石棒移至第三根石棒，且搬运过程中遵守大盘子在小盘子之下的原则，若每日仅搬一个盘子，则当盘子全数搬运完毕之时，此塔将毁损，而也就是世界末日来临之时。
解法如果柱子标为ABC，要由A搬至C，在只有一个盘子时，就将它直接搬至C，当有两个盘子，就将B当作辅助柱。如果盘数超过2个，将第三个以下的盘子遮起来，就很简单了，每次处理两个盘子，也就是：A->B、A ->C、B->C这三个步骤，而被遮住的部份，其实就是进入程式的递回处理。事实上，若有n个盘子，则移动完毕所需之次数为2^n - 1，所以当盘数为64时，则所需次数为：264- 1 = 18446744073709551615为5.05390248594782e+16年，也就是约5000世纪，如果对这数字没什幺概念，就假设每秒钟搬一个盘子好了，也要约5850亿年左右
*/

#ifndef hanoi_h
#define hanoi_h

#include <stdio.h>
static int count = 0;
void hanoi(int n, char A, char B, char C) {
    if(n == 1) {
        printf("Move sheet %d from %c to %c\n", n, A, C);
    }
    else {
        hanoi(n-1, A, C, B);
        printf("Move sheet %d from %c to %c\n", n, A, C);
        hanoi(n-1, B, A, C);
    }
    count++;
}

int hanoi_main(int argc, const char *argv[]) {
    // insert code here...
    int n;
    printf("请输入盘数：");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    printf("count:%d\n",count);
    return 0;
}

#endif /* hanoi_h */
