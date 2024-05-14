#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int PQ[50];
int heapsize=0;
int PARENT(int i){
	return i/2;
}
int LEFT(int i){
        return 2*i;
}
int RIGHT(int i){
        return (2*i)+1;
}
void MAX_HEAPIFY(int A[], int i){
        int l=LEFT(i);
        int r=RIGHT(i);
        int largest;
        if(l<=heapsize && A[l]>A[i]){
                largest=l;
        }
        else{
                largest=i;
        }
        if(r<=heapsize && A[r]>A[largest]){
                largest=r;
        }
        if(largest!=i){
                int temp=A[i];
                A[i]=A[largest];
                A[largest]=temp;
                MAX_HEAPIFY(A,largest);
        }
}
int heap_max(){
	if (heapsize<1){
                printf("Error! Queue is empty.\n");
                return -1;
        }
	return PQ[1];
}
int extract_max(){
	if (heapsize<1){
		printf("Error! Queue Underflow.\n");
		return -1;
	}
	else{
		int max=PQ[1];
		PQ[1]=PQ[heapsize];
		heapsize=heapsize-1;
		MAX_HEAPIFY(PQ,1);
		return max;
	}
}
void increase_key(int i, int key){
	if (heapsize<i){
                printf("Error! Index not found.\n");
                return;
        }
	if(key<PQ[i]){
		printf("Error\n");
		return;
	}
	PQ[i]=key;
	while(i>1 && PQ[PARENT(i)]<PQ[i]){
		int temp=PQ[i];
		PQ[i]=PQ[PARENT(i)];
		PQ[PARENT(i)]=temp;
		i=PARENT(i);
	}
}
void insert(int key){
	heapsize=heapsize+1;
	PQ[heapsize]=INT_MIN;
	increase_key(heapsize,key);
}
void display(){
	if (heapsize<1){
                printf("Error! Queue is empty.\n");
		return;
	}
	printf("The PQ is:\n");
	for(int i=1;i<=heapsize;i++){
		printf("%d ",PQ[i]);
	}
	printf("\n");
}
int main(){
	int ch=0,key,i;
	printf("Options:\n1: Heap_max\n2: Extract_max\n3: Increase_key\n4: Insert\n5: Display\n6: Exit\n");
	do{
		printf("Enter the option:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				key=heap_max();
				if(key!=-1)
					printf("Number with highest priority: %d\n",key);
				break;
			case 2:
				key=extract_max();
				if(key!=-1)
                                        printf("Number with highest priority: %d\n",key);
				break;
			case 3:
				printf("Enter the element to be inserted:");
                                scanf("%d",&key);
				printf("Enter the position where it needs to be inserted:");
				scanf("%d",&i);
				increase_key(i,key);
				break;
			case 4:
				printf("Enter the element to be inserted:");
				scanf("%d",&key);
				insert(key);
				break;
			case 5:
				display();
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("Invalid option.");
		}
	}while(ch!=6);
}
