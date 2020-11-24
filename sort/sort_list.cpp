//
// Created by link on 2019-03-10.
//

#include "sort_list.h"

Sorter::Sorter()
{
    LOGD("Sorter");
}

Sorter::~Sorter()
{
}

void conver(int data[], int start)
{
    data[start] = !data[start];
}

void sort_byte(int data[], int start, int end)
{
    if (start >= end)
    {
        out_data(data, 2);
        return;
    }
    for (int i = end - 1; i >= 0; i--)
    {
        conver(data, i);
        sort_byte(data, start, i - 1);
        conver(data, i);
        // sort_byte(data, i + 1, end);
    }
}

void sort_a_z()
{
    int data = 1;
    for (size_t i = 1; i < pow(2, NUMBER); i++)
    {
        out_a_z(i);
    }
}

char a_z[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

void out_a_z(int data)
{

    for (int i = 0; i < NUMBER; i++)
    {
        if ((data >> i) & 0x01)
        {
            printf("%c", a_z[i]);
        }
    }
    printf("\n");
}

void all_sort(int start, int end, int data[])
{

    if (start == end)
    {
        out_data(data, end);
        return;
    }

    for (size_t i = start; i < end; i++)
    {
        swap(start, i, data);
        all_sort(start + 1, end, data);
        swap(start, i, data);
    }
}


void sort_all_number(int data[], int length)
{

    for (int i = 0; i < pow(length, length); i++)
    {
        // for (int j = 0; j < length; j++)
        // { //位数
        // }
        int tmp = i;
        int j = 0;
        while (j < length)
        {
            printf("\t%d", data[tmp % length]);
            tmp = tmp / 3;
            j++;
        }
        printf("\n");
    }
}

void all_sort_tree(int start, int end, int data)
{
}

void swap(int i1, int i2, int data[])
{
    int tmp = data[i1];
    data[i1] = data[i2];
    data[i2] = tmp;
}

void out_data(int data[], int length)
{
    for (size_t i = 0; i < length; i++)
    {
        printf("\t%d", data[i]);
    }
    printf("\n");
}