//
//  sort_bubble.h
//  DataStructures-C
//
//  Created by dev on 15/12/17.
//  Copyright © 2015年 azurestudio. All rights reserved.
//

#ifndef sort_bubble_h
#define sort_bubble_h
#include <stdio.h>
#define MAX_SIZE 1000
void bubble_sort(int[],int);
void printArray(int[],int);
int sort_bubble_main()
{
    int i,t;
    int unsort_data[MAX_SIZE];
    for (i=0; i<MAX_SIZE; i++)
    {
        scanf("%d",&t);
        if(t==-999)
        {
            i--;
            break;
        }
        else
        {
            unsort_data[i]=t;
        }
    }
    printArray(unsort_data, i);
    bubble_sort(unsort_data, i);
    printArray(unsort_data, i);
    return 0;
}
void printArray(int data[],const int length)
{
    int i;
    for (i=0; i<length; i++) {
        printf("%4d",data[i]);
    }
    printf("\n");
}
void bubble_sort(int unsort_data[],const int length)
{
    int i,j,count;
    for (i=0; i<length; i++)
    {
        count=length-i-1;
        for (j=0; j<count; j++)
        {
            if(unsort_data[j]>unsort_data[j+1])
            {
                int t = unsort_data[j];
                unsort_data[j]=unsort_data[j+1];
                unsort_data[j+1]=t;
            }
        }
    }
}
#endif /* sort_bubbling_h */
