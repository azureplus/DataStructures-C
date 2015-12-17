//
//  binarytree.h
//  DataStructures-C
//
//  Created by dev on 15/12/17.
//  Copyright © 2015年 azurestudio. All rights reserved.
//

#ifndef binarytree_h
#define binarytree_h
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *ltree;
    struct node *rtree;
}TNode;
TNode *create(TNode*);
int depth(TNode*);
int findMax(int,int);
void postOrder(TNode *);
void inOrder(TNode*);
void preOrder(TNode*);
int binarytree_main()
{
    TNode *tree;
    printf("BinaryTree (By Recursion)\n\n");
    tree=create(tree);
    printf("\npreOrder:\n");
    preOrder(tree);
    printf("\ninOrder:\n");
    inOrder(tree);
    printf("\npostOrder:\n");
    postOrder(tree);
    printf("\nThe depth o the binary tree is: %d.\n",depth(tree));
    return 0;
}
TNode* create(TNode*p)
{
    int num;
    scanf("%d",&num);
    if(num==0)
        return NULL;
    p = (TNode*)malloc(sizeof(TNode));
    p->data = num;
    p->ltree=create(p->ltree);
    p->rtree=create(p->rtree);
    return p;
}
void preOrder(TNode*p)
{
    TNode*tree = p;
    if(tree){
        printf("%5d",p->data);
        preOrder(p->ltree);
        preOrder(p->rtree);
    }
}
void inOrder(TNode*p)
{
    TNode*tree = p;
    if(tree)
    {
        inOrder(p->ltree);
        printf("%5d",p->data);
        inOrder(p->rtree);
    }
}
void postOrder(TNode*p)
{
    TNode*tree=p;
    if(tree)
    {
        postOrder(p->ltree);
        postOrder(p->rtree);
        printf("%5d",p->data);
    }
}
int findMax(int x,int y)
{
    return (x>y?x:y);
}
int depth(TNode*p)
{
    TNode*tree=p;
    int dep=0;
    int depl,depr;
    if(!tree){
        return 0;
    }
    depl=depth(p->ltree);
    depr=depth(p->rtree);
    dep=1+findMax(depl, depr);
    return dep;
}
#endif /* binarytree_h */
