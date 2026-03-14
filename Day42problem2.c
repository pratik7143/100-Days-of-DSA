#include <stdlib.h>
typedef struct {
    int maxHeap[50000];
    int minHeap[50000];
    int maxSize;
    int minSize;
} MedianFinder;
void maxPush(MedianFinder* obj, int val){
    int i = obj->maxSize++;
    obj->maxHeap[i] = val;
    while(i>0){
        int p=(i-1)/2;
        if(obj->maxHeap[p] >= obj->maxHeap[i]) break;
        int t=obj->maxHeap[p];
        obj->maxHeap[p]=obj->maxHeap[i];
        obj->maxHeap[i]=t;
        i=p;
    }
}
int maxPop(MedianFinder* obj){
    int top=obj->maxHeap[0];
    obj->maxHeap[0]=obj->maxHeap[--obj->maxSize];
    int i=0;
    while(1){
        int l=2*i+1,r=2*i+2,largest=i;
        if(l<obj->maxSize && obj->maxHeap[l]>obj->maxHeap[largest]) largest=l;
        if(r<obj->maxSize && obj->maxHeap[r]>obj->maxHeap[largest]) largest=r;

        if(largest==i) break;

        int t=obj->maxHeap[i];
        obj->maxHeap[i]=obj->maxHeap[largest];
        obj->maxHeap[largest]=t;
        i=largest;
    }

    return top;
}

/* ---------- MIN HEAP ---------- */

void minPush(MedianFinder* obj, int val){
    int i=obj->minSize++;
    obj->minHeap[i]=val;

    while(i>0){
        int p=(i-1)/2;
        if(obj->minHeap[p] <= obj->minHeap[i]) break;

        int t=obj->minHeap[p];
        obj->minHeap[p]=obj->minHeap[i];
        obj->minHeap[i]=t;

        i=p;
    }
}

int minPop(MedianFinder* obj){
    int top=obj->minHeap[0];
    obj->minHeap[0]=obj->minHeap[--obj->minSize];

    int i=0;
    while(1){
        int l=2*i+1,r=2*i+2,small=i;

        if(l<obj->minSize && obj->minHeap[l]<obj->minHeap[small]) small=l;
        if(r<obj->minSize && obj->minHeap[r]<obj->minHeap[small]) small=r;

        if(small==i) break;

        int t=obj->minHeap[i];
        obj->minHeap[i]=obj->minHeap[small];
        obj->minHeap[small]=t;

        i=small;
    }

    return top;
}

/* ---------- MAIN FUNCTIONS ---------- */

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = malloc(sizeof(MedianFinder));
    obj->maxSize=0;
    obj->minSize=0;
    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {

    if(obj->maxSize==0 || num<=obj->maxHeap[0])
        maxPush(obj,num);
    else
        minPush(obj,num);

    if(obj->maxSize > obj->minSize+1)
        minPush(obj,maxPop(obj));

    if(obj->minSize > obj->maxSize)
        maxPush(obj,minPop(obj));
}

double medianFinderFindMedian(MedianFinder* obj) {

    if(obj->maxSize>obj->minSize)
        return obj->maxHeap[0];

    return (obj->maxHeap[0]+obj->minHeap[0])/2.0;
}

void medianFinderFree(MedianFinder* obj) {
    free(obj);
}
