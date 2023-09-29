#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

void* func1(){
    for(int i=1; i<=100; i++){
        printf("%d ", i);
    }
    printf("\n");
    printf("\n");
    
    return 0;
} 

void* func2(){
    sleep(2);
    for(char i='A'; i<='Z'; i++){
        printf("%c ", i);
    }
    printf("\n");
    printf("\n");
    
    return 0;
} 

void* func3(char str[]){
    sleep(3);
    for(int i=100; i>=0; i--){
        printf("%d ", i);
    }
    printf("\n");
    printf("\n");

    return 0;
} 

int main(int argc, char *argv[])
{
    pthread_t t1, t2, t3;
    if(pthread_create(&t1, NULL, &func1, NULL)){
        return 1;
    };
    if(pthread_create(&t2, NULL, &func2, NULL) != 0){
        return 2;
    };
    if(pthread_create(&t3, NULL, &func3, "THE") != 0){
        return 3;
    }
    if(pthread_join(t1, NULL) != 0){
        return 4;
    };
    if(pthread_join(t2, NULL) != 0){
        return 5;
    };
    if(pthread_join(t3, NULL) != 0){
        return 6;
    };

    return 0;
}
