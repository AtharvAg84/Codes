#include<stdio.h>
#include<stdlib.h>
#define scan(n) scanf("%d",&(n))
#define MAX 15
typedef struct {
    int first , second ; 
}pair;

int V  , E ;

int** adj = NULL; 
int* visited = NULL; 

void dfs(int curr){
}

typedef struct {
    int arr[MAX];
    int top;
}s;
int isFull(s* stack){ return stack->top == MAX-1 ;}
int isEmpty(s* stack){ return stack->top == -1;}
void push(s* stack , int val){
    if(isFull(stack)) return;
    stack->arr[++stack->top] = val;
}
int pop(s* stack){
    if(isEmpty(stack)) return 0;
    return stack->arr[stack->top--];
}
int seek(s* stack){
    if(isEmpty(stack)) return 0;
    return stack->arr[stack->top];
}

int main(void){
    scan(V);    scan(E);
    adj = (int*) malloc(sizeof(int)*V);
    for(int i = 0; i<V ; i++) adj[i]= (int*) malloc(sizeof(int)*V);
    visited = (int*)malloc(sizeof(int)*V);
    
    for(int i = 0 ; i<V ; i++) for(int j = 0 ; j<V ; j++) adj[i][j] =0;
    for(int i= 0 ; i<E ; i++){
        int r , c ; 
        scan(r);
        scan(c);
        adj[r][c]=1;
    }
    // for(int i = 0 ; i<V ; i++) {
    // for(int j = 0 ; j<V ; j++) printf("%d ",adj[i][j]);
    // printf("\n");}
    s stk ; s* stack = &stk; stack->top = -1; //init
    
    int src; 
    scan(src);
    visited[src] = 1;
    push(stack , src);
    
    while(!isEmpty(stack)){
    // for(int j = 0 ; j<stack->top+1 ; j++) printf("%d ",stack->arr[j]);
    // printf("\n");
    int curr = pop(stack);
    printf("%d ", curr);
        
        // if(!visited[curr]){
        for(int i = V-1 ; i>-1 ; i--){
            if(i == curr || visited[i] || !adj[curr][i] ){}
            else{
            visited[i] = 1;
            push(stack,i);
        // }
        }
        }
    }    
    return 0;
}
