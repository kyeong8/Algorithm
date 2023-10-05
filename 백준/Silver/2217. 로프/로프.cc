#include <stdio.h>
#include <stdlib.h>
int compare (const void* first, const void* second){
    if (*(int*)first > *(int*)second) return -1; 
    else if (*(int*)first < *(int*)second) 
        return 1; else return 0; 
} 
int main(void){
    int N, i, weight;
    int *rope;
    scanf("%d", &N);
    rope = (int *)malloc(sizeof(int) * N);
    for(i = 0; i < N; i++){
        scanf("%d", &rope[i]);
    } 
    qsort(rope, N, sizeof(int), compare);
    weight = 0;
    for(i = 0; i < N; i++){
        weight = weight > rope[i] * (i + 1) ? weight : rope[i] * (i + 1);
    } 
    printf("%d\n", weight);
    free(rope);
    return 0; 
}

