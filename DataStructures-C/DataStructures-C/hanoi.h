//
//  hanoi.h
//  DataStructures-C
//
//  Created by dev on 15/12/17.
//  Copyright © 2015年 azurestudio. All rights reserved.
//

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
