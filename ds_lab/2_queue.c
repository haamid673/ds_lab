#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int queue[MAX], front=-1, rear=-1;

int main() {
    int choice, i, item;
    
    while(1){
        printf("menu");
        printf("1");
        printf("2");
        printf("3");
        printf("4");
        printf("enter choice:");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: {
                if (rear==MAX-1) {
                    printf("queue overflow");
                } else {
                    if (front==-1) {
                        front=0;
                    }
                    printf("element to be inserted");
                    scanf("%d", &item);
                    rear++;
                    queue[rear]=item;
                }
                break;
            }
            case 2: {
                if (front==-1 || front>rear) {
                    printf("queue underflow");
                } else {
                    printf("deleted is: %d", queue[front]);
                    front++;
                }
                break;
            }
            
            case 3: {
                if (front==-1 || front>rear) {
                    printf("queue empty");
                } else {
                    printf("queue is:");
                    for(i=front; i<=rear;i++) {
                        printf("%d", queue[i]);
                    }
                    printf("\n");
                }
                break;
            }
            
            case 4: {
                exit(0);
            }
            default: {
                printf("invalid");
            }
        }
    
    }
    
    return 0;
}
