//
//  graphic_search.h
//  DataStructures-C
//
//  Created by dev on 15/12/17.
//  Copyright © 2015年 azurestudio. All rights reserved.
//

#ifndef graphic_search_h
#define graphic_search_h

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define M 100
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define QUEUE_SIZE 101
typedef struct ArcNode
{
    int adjvex;               //该弧所指向的顶点的位置
    struct ArcNode *nextarc;  //指向下一条弧的指针
}ArcNode;
typedef char VerterType;          //表示弧的节点
typedef struct VNode
{
    VerterType data;          //顶点信息
    ArcNode *firstarc;       //指向第一条衣服该顶点的弧的指针
}VNOde,AdjList[M];
typedef struct
{
    AdjList vertices;        //图的顶点信息
    int vexnum,arcnum;       //图的当前顶点数和弧数
}ALGraph;

typedef struct{
    int *base;
    int front;
    int rear;
}queue;                        //队列结构体
void InitQueue(queue q){      //初始化队列
    q.base=(int *)malloc(QUEUE_SIZE*sizeof(int));
    q.front=q.rear=0;
}
int  EnQueue(queue q,int e){ //入队
    q.base[q.rear]=e;
    q.rear=(q.rear+1)%QUEUE_SIZE;
    return 1;
}
int DeQueue(queue q,int e){//出队
    e=q.base[q.front];
    q.front=(q.front+1)%QUEUE_SIZE;
    return 1;
}
int visited[M];//便于记录是否已经访问

int LocateVex(ALGraph G,VerterType u)  //找到一顶点u有弧相接的顶点并返回顶点编号
{
    int i;
    for(i=0;i<G.vexnum;++i)
    {
        if(u == G.vertices[i].data)
            return i;
    }
    return -1;
}

int Createg(ALGraph G)             //构建图的邻接表的存储方式
{
    int v,a,m,i,j,weight[M];
    ArcNode *p,*q;
    VerterType t,h;
    printf("请输入顶点数:  ");
    scanf("%d",&v);
    if(v<0)
        return ERROR;
    G.vexnum=v;
    fflush(stdin);
    printf("请输入弧数：   ");
    scanf("%d",&a);
    if(a<0)
        return ERROR;
    G.arcnum=a;
    fflush(stdin);
    printf("请输入%d个顶点\n",v);
    for(m=0;m<v;m++)
    {
        printf("请输入顶点%d:  ",m);
        G.vertices[m].data=getchar();
        G.vertices[m].firstarc=NULL;
        fflush(stdin);
    }
    printf("请输入%d条弧\n",a);
    fflush(stdin);
    for(m=0;m<a;m++)
    {
        printf("请输入弧%d:   ",m);
        scanf("%c %c %d",&t,&h,&weight[m]);
        i=LocateVex(G ,t);
        j=LocateVex(G ,h);
        if(i<0)
            return ERROR;
        if(j<0)
            return ERROR;
        p=(ArcNode *)malloc(sizeof(ArcNode));
        if(!G.vertices[i].firstarc)
            G.vertices[i].firstarc=p;
        else
        {
            q=G.vertices[i].firstarc;
            while(q->nextarc)
                q=q->nextarc;
            q->nextarc=p;
        }
        p->adjvex=j;
        p->nextarc=NULL;
        fflush(stdin);
    }
    return OK;
}
VerterType   ReturnValue(ALGraph G,int i)  //返回编号为i的图节点信息
{
    if(i>=0&&i<G.vexnum)
        return G.vertices[i].data;
    else
    {
        printf("ERROR!\n");
        exit(i);
    }
}
int ReturnFirstNeighbor(ALGraph G,int v)     //返回与顶点v有弧相接的顶点编号
{
    ArcNode *p;
    if(v!=-1)
    {
        p=G.vertices[v].firstarc;
        if(p!=NULL)
            return p->adjvex;
        return -1;
    }
    return -1;
}
int ReturnNextNeighbor(ALGraph G,int vi,int vj)
{
    ArcNode *p;
    if(vi!=-1)
    {
        p=G.vertices[vi].firstarc;
        while(p!=NULL)
        {
            if(p->adjvex==vj&&p->nextarc!=NULL)
                return p->nextarc->adjvex;
            else
                p=p->nextarc;
        }
    }
    return -1;
}
void dfs(ALGraph G,int v)
{
    int u;
    printf("%c ",ReturnValue(G,v));
    visited[v]=TRUE;
    u=ReturnFirstNeighbor(G,v);
    while(u!=-1)
    {
        if(!visited[u])
            dfs(G,u);
        u=ReturnNextNeighbor(G,v,u);
    }
}
void DFS(ALGraph G) //深度遍历
{
    int i;
    for(i=0;i<G.vexnum;i++)
        visited[i]=FALSE;
    for(i=0;i<G.vexnum;i++)
    {
        if(!visited[i])
            dfs(G,i);
    }
}
void BFS(ALGraph G){   //广度遍历
    int k;
    for(int v=0;v<G.vexnum;v++)
        visited[v]=FALSE;
    queue q;
    InitQueue(q);
    for(int i=0;i<G.vexnum;i++)
    {
        if(!visited[i])
        {
            visited[i]=TRUE;
            printf("%c ",G.vertices[i].data);
            EnQueue(q,i);
            while(q.front!=q.rear)
            {
                DeQueue(q,k);
                for(int w=ReturnFirstNeighbor(G,k);w>=0;w=ReturnNextNeighbor(G,k,w))
                {
                    if(!visited[w])
                    {
                        visited[w]=TRUE;
                        printf("%c ",G.vertices[w].data);
                        EnQueue(q,w);
                    }
                }
            }
        }
    }
}

void printfAdjList(ALGraph G)
{
    int i;
    ArcNode *p;
    printf("%s,%s,%s\n","编号","顶点","相邻边编号");
    for (i=0;i<G.vexnum;++i)
    {
        printf(" %d %c  ",i,G.vertices[i].data);
        for(p=G.vertices[i].firstarc;p;p=p->nextarc)
            printf(" %d %c  ", p->adjvex,G.vertices[p->adjvex].data);
        printf("\n");
    }
}

int graphic_search_main()
{
    char str[128];
    scanf( "%[^\n]", str );
    printf( "%s\n", str );
    ALGraph G;
    Createg(G);
    printf("\n邻接表为:");
    printfAdjList(G);
    printf("深度遍历:");
    DFS(G);
    printf("\n广度遍历:");
    BFS(G);
    printf("\n");
    system("pause");
    return 0;
}




#endif /* graphic_search_h */
