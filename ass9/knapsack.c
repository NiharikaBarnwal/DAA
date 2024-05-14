#include<stdio.h>
typedef struct item{
	int ino;
	int value;
	int weight;
}item;
item I[20];
int W;
float V_W[20];
float X[20];
void sort_item(int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(V_W[i]>V_W[j]){
				float temp=V_W[i];
				V_W[i]=V_W[j];
				V_W[j]=temp;
				item t=I[i];
				I[i]=I[j];
				I[j]=t;
			}
		}
	}
}
void FRACTIONAL_KNAPSACK(int n){
	sort_item(n);
	for(int i=0;i<n;i++){
		X[i]=0;
	}
	int w=0;
	int i=0;
	while(w+I[i].weight<=W){
		X[i]=1;
		w=w+I[i].weight;
		i=i+1;
	}
	X[i]=(float)(W-w)/I[i].weight;
}
int main(){
	int n;
	printf("Enter the no. of items: ");
	scanf("%d",&n);
	printf("Enter the value of the items: ");
	for(int i=0;i<n;i++){
		I[i].ino=i+1;
		scanf("%d",&I[i].value);
	}
	printf("Enter the weight of the items: ");
	for(int i=0;i<n;i++){
                scanf("%d",&I[i].weight);
		V_W[i]=(float)I[i].value/I[i].weight;
	}
	printf("Enter the total weigth: ");
	scanf("%d",&W);
	FRACTIONAL_KNAPSACK(n);
	printf("The items are selected as follows:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==I[j].ino){
				printf("Item %d : proportion = %.2f\n",I[j].ino,X[j]);
			}	
		}
	}
}
