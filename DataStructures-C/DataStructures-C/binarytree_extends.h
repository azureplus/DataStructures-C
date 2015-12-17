//
//  binarytree_extends.h
//  DataStructures-C
//
//  Created by dev on 15/12/17.
//  Copyright © 2015年 azurestudio. All rights reserved.
//

#ifndef binarytree_extends_h
#define binarytree_extends_h
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *leftNode;
    struct node *rightNode;
}TNode;
TNode* create(TNode*);
void preOrder(TNode*);
void inOrder(TNode*);
void postOrder(TNode*);
TNode*create(TNode* p)
{
    char t;
    scanf("%c",&t);
    p=(TNode*)malloc(sizeof(TNode));
    p->data = t;
    if(t == '*')
    {
        p->leftNode = p->rightNode = NULL;
    }
    else
    {
        p->leftNode = create(p->leftNode);
        p->rightNode = create(p->rightNode);
    }
    return p;
}
void preOrder(TNode* p)
{
    if(p)
    {
        printf("%5c",p->data);
        if(p->data!='*')
        {
            preOrder(p->leftNode);
            preOrder(p->rightNode);
        }
    }
}
void binarytree_extends_main()
{
    TNode*p;
    p=create(p);
    printf("preOrder: ");
    preOrder(p);
    printf("\n");
}
#endif /* binarytree_extends_h */
