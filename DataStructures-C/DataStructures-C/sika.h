//
//  sika.h
//  DataStructures-C
//
//  Created by dev on 15/12/17.
//  Copyright © 2015年 azurestudio. All rights reserved.
//

#ifndef sika_h
#define sika_h

#include <stdio.h>

#define N 20
long combi(int n,int r)
{
    int i ;
    long p = 1;
    for (i=1; i<=r; i++) {
        p=p*(n-i+1)/i;
    }
    return p;
}
void paint() {
    int n, r;
    int temp[N+1]={0};
    temp[1]=1;
    int t;
    int t2=-1;
    int mid;
    for(n = 1; n <= N; n++){
        mid = n/2+n%2;
        for(r = 1; r <= n; r++){
            int i;
            if(r == 1){
                for(i = 0; i <= (N-n); i++)
                    printf("   ");
            }else{
                printf("   ");
            }
            if(n==1){
                printf("%3d",1);
            }
            else{
                t= temp[r-1]+temp[r];
                printf("%3d",t);
                if(t2!=-1)
                {
                    temp[r-1]=t2;
                }
                t2=t;
                if(r==n)
                {
                    temp[r]=t;
                    t2=-1;
                }
            }
        }
        printf("\n");
    }
}
void paint2() {
    int n, r, t;
    for(n = 0; n <= N; n++) {
        for(r = 0; r <= n; r++) {
            int i;/* 排版设定开始 */
            if(r == 0) {
                for(i = 0; i <= (N-n); i++)
                    printf("   ");
            }else {
                printf("   ");
            } /* 排版设定结束 */
            printf("%3d", combi(n, r));
        }
        printf("\n");
    }
}
#endif /* sika_h */
