#include <stdio.h>
#include<limits.h>
#define MAX 20
int Q[MAX], front = -1, rear = -1;
int G[20][20];
int Pi[20];
char color[20];
int d[20];
void enqueue(int data) {
    if (rear == MAX - 1) {
        printf("Queue is Full\n");
	return;
    } else if (front == -1) {
        front = rear = 0;
    } else {
        rear++;
        Q[rear] = data;
    }
}
int dequeue() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return -1;
    }
    int data = Q[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    return data;
}
void BFS(int m, int s){
	for(int u=1;u<=m;u++){
		color[u]='w';
		Pi[u]=-1;
		d[u]=INT_MAX;
	}
	color[s]='g';
	d[s]=0;
	Pi[s]=-1;
	enqueue(s);
	int u;
	while(front!=-1){
		u = dequeue();
		for(int v=1;v<=m;v++){
			if(G[u][v]==1){
				if(color[v]=='w'){
					color[v]='g';
					Pi[v]=u;
					d[v]=d[u]+1;
					enqueue(v);
				}
			}
		}
		color[u]='b';
	}
}
int main(){
	int m,s,e;
	printf("Enter the no. of nodes: ");
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		for(int j=i;j<=m;j++){
			printf("Is node %d connected to %d?(1/0): ",i,j);
			scanf(" %d",&e);
			G[i][j]=e;
			G[j][i]=e;
		}
	}
	printf("Enter the source node: ");
	scanf("%d",&s);
	BFS(m,s);
	for(int i=1;i<=m;i++){
                printf("Distance of node %d from source node: %d\n",i,d[i]);
        }
}
