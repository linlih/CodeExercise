/*
参考链接：https://www.nowcoder.com/questionTerminal/5f44c42fd21a42b8aeb889ab83b17ad0 作者：Cataliar
*/
#include <stdio.h>
#include <memory.h>
 
#define LIMIT 100002
 
struct linknode {
    int data;
    int next;
};
 
int reversek(struct linknode *, int, int);
 
int main(void) {
    struct linknode list[LIMIT];
    int faddr, n, k;
    int addr, data, next;
    int i, j, count = 0;
 
    scanf("%d %d %d", &faddr, &n, &k);
    memset(list, 0, LIMIT * sizeof(struct linknode));
    list[LIMIT-1].next = faddr;  //head node
    for(i = 0; i < n; ++i) {
        scanf("%d %d %d", &addr, &data, &next);
        list[addr].data = data;
        list[addr].next = next;
    }
    for(i = list[LIMIT-1].next; i != -1; i = list[i].next)
        ++count; //count valid nodes
    for(j = count / k, i = LIMIT - 1; j > 0 && i != -1; --j)
        i = reversek(list, i, k); //reverse every k nodes
    for(i = list[LIMIT-1].next; list[i].next != -1; i = list[i].next)
        printf("%05d %d %05d\n", i, list[i].data, list[i].next);
    printf("%05d %d %d\n", i, list[i].data, list[i].next);
    return 0;
}
 
int reversek(struct linknode *list, int head, int k) {
    int i, j, p;
    int nexthead;
    for(j = 0, p = list[head].next; j < k && p != -1; ++j) //find tail
        p = list[p].next;
    nexthead = list[head].next;
    list[head].next = p;
    for(j = 0, i = nexthead; j < k && i != -1; ++j) {
        p = list[i].next;
        list[i].next = list[head].next; //insert at the head
        list[head].next = i;
        i = p;
    }
    return nexthead;
}