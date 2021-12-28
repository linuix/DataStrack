#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "cycle_buffer.h"

/*
 * 初始化环形缓冲区
 * 环形缓冲区这里可以是malloc申请的内存,也可以是Flash存储介质
 * */
pCycleBuffer initCyclebuffer(u32 length)
{

    if (length <= 0)
    {
        length = BUFFER_SIZE;
    }
    pCycleBuffer pcb = malloc(sizeof(pCycleBuffer));
    if (pcb->pHead == NULL)
    {
        pcb->pHead = (u8 *)malloc(length);
    }
    pcb->pValid = pcb->pValidTail = pcb->pHead;
    pcb->pTail = pcb->pHead + length;
    pcb->validLen = 0;
    pcb->length = length;
    return pcb;
}

/*
 * function:向缓冲区中写入数据
 * param:@buffer 写入的数据指针
 * 		 @addLen 写入的数据长度
 * return:-1:写入长度过大
 * 		  -2:缓冲区没有初始化
 * */
int wirteCyclebuffer(pCycleBuffer pcb, u8 *buffer, u32 addLen)
{
    if (addLen > pcb->length)
        return -2;
    if (pcb->pHead == NULL)
        return -1;
    assert(buffer);

    //将要存入的数据copy到pValidTail处
    if (pcb->pValidTail + addLen > pcb->pTail) //需要分成两段copy
    {
        int len1 = pcb->pTail - pcb->pValidTail;
        int len2 = addLen - len1;
        memcpy(pcb->pValidTail, buffer, len1);
        memcpy(pcb->pHead, buffer + len1, len2);
        pcb->pValidTail = pcb->pHead + len2; //新的有效数据区结尾指针
    }
    else
    {
        memcpy(pcb->pValidTail, buffer, addLen);
        pcb->pValidTail += addLen; //新的有效数据区结尾指针
    }

    //需重新计算已使用区的起始位置
    if (pcb->validLen + addLen > BUFFER_SIZE)
    {
        int moveLen = pcb->validLen + addLen - BUFFER_SIZE; //有效指针将要移动的长度
        if (pcb->pValid + moveLen > pcb->pTail)             //需要分成两段计算
        {
            int len1 = pcb->pTail - pcb->pValid;
            int len2 = moveLen - len1;
            pcb->pValid = pcb->pHead + len2;
        }
        else
        {
            pcb->pValid = pcb->pValid + moveLen;
        }
        pcb->validLen = BUFFER_SIZE;
    }
    else
    {
        pcb->validLen += addLen;
    }

    return 0;
}

/*
 * function:从缓冲区内取出数据
 * param   :@buffer:接受读取数据的buffer
 *		    @len:将要读取的数据的长度
 * return  :-1:没有初始化
 *	 	    >0:实际读取的长度
 * */
int readCyclebuffer(pCycleBuffer pcb, u8 *buffer, u32 len)
{
    if (pcb->pHead == NULL)
        return -1;

    // assert(buffer);

    if (pcb->validLen == 0)
        return 0;

    if (len > pcb->validLen)
        len = pcb->validLen;

    if (pcb->pValid + len > pcb->pTail) //需要分成两段copy
    {
        int len1 = pcb->pTail - pcb->pValid;
        int len2 = len - len1;
        memcpy(buffer, pcb->pValid, len1);       //第一段
        memcpy(buffer + len1, pcb->pHead, len2); //第二段，绕到整个存储区的开头
        pcb->pValid = pcb->pHead + len2;         //更新已使用缓冲区的起始
    }
    else
    {
        memcpy(buffer, pcb->pValid, len);
        pcb->pValid = pcb->pValid + len; //更新已使用缓冲区的起始
    }
    pcb->validLen -= len; //更新已使用缓冲区的长度

    return len;
}

/*
 * function:获取已使用缓冲区的长度
 * return  :已使用的buffer长度
 * */
u32 getCyclebufferValidLen(pCycleBuffer pcb)
{
    return pcb->validLen;
}

/*
 * function:释放环形缓冲区
 * */
void releaseCyclebuffer(pCycleBuffer pcb)
{
    if (pcb != NULL)
    {
        if (pcb->pHead != NULL)
            free(pcb->pHead);
        pcb->pHead = NULL;
        free(pcb);
        pcb = NULL;
    }
}