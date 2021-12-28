#ifndef CYCLEBUFFER_H_
#define CYCLEBUFFER_H_

#define BUFFER_SIZE 16 //缓冲区的长度,可以修改

typedef unsigned char u8;
typedef unsigned int u32;

struct cycle_buffer
{
    u32 validLen;    //已使用的数据长度
    u8 *pHead ;      //环形存储区的首地址
    u8 *pTail ;      //环形存储区的结尾地址
    u8 *pValid ;     //已使用的缓冲区的首地址
    u8 *pValidTail; //已使用的缓冲区的尾地址
    u32 length;       //总长度
};
typedef struct cycle_buffer* pCycleBuffer;

pCycleBuffer initCyclebuffer(u32 length);
int wirteCyclebuffer(pCycleBuffer pcb, u8 *buffer, u32 len);
int readCyclebuffer(pCycleBuffer pcb, u8 *buffer, u32 len);
u32 getCyclebufferValidLen(pCycleBuffer pcb);
void releaseCyclebuffer(pCycleBuffer pcb);



#endif /* CYCLEBUFFER_H_ */