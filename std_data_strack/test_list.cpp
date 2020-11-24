#include <vector>
#include <queue>
#include <list>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include "log_util.h"
#include <set>
#include <stdio.h>

using namespace std;

template <typename TYPE>
char *getStrForList(TYPE &_list);

int main()
{
    /**
     * 连续存储结构，每个元素在内存上是连续的；支持高效的随机访问和在尾端插入/删除操作，但其他位置的插入/删除操作效率低下；相当于一个数组，
     * 但是与数组的区别为：内存空间的扩展。vector支持不指定vector大小的存储，但是数组的扩展需要程序员自己写。
    vector的内存分配实现原理：
    STL内部实现时，首先分配一个非常大的内存空间预备进行存储，即capacity（）函数返回的大小，当超过此分配的空间时再整体重新放分配一块内存存储（VS6.0是两倍，VS2005是1.5倍），所以这给人以vector可以不指定vector即一个连续内存的大小的感觉。通常此默认的内存分配能完成大部分情况下的存储。
    扩充空间（不论多大）都应该这样做：
   （1）配置一块新空间
   （2）将旧元素一一搬往新址
   （3）把原来的空间释放还给系统
    注：vector 的数据安排以及操作方式，与array 非常相似。两者的唯一差别在于空间的利用的灵活性。Array 的扩充空间要程序员自己来写。
    */
    vector<int> vec(5, 4);
    vec[2] = 8;
    vec.push_back(3);
    LOGD("vec back %d", vec.back());
    vec.pop_back();
    for (size_t i = 0; i < vec.size(); i++)
    {
        LOGD("%d", vec.at(i));
    }
    deque<int> deq;

    deq.push_front(2);
    deq.push_back(10);
    deq.push_back(11);
    deq.push_front(1);

    for (deque<int>::iterator it = deq.begin(); it < deq.end(); ++it)
    {
        LOGD("deque %d ", *it);
    }

    list<int> lis;
    lis.push_back(3);
    lis.push_back(16);
    lis.push_back(300);
    lis.push_back(5010);
    list<int>::iterator it = lis.begin();

    lis.insert(it, 2);

    getStrForList(lis);

    set<int, less<int> > ssr;

    ssr.insert(100);
    ssr.insert(3);
    ssr.insert(4);
    ssr.insert(2);
    for (set<int, less<int> >::iterator itr = ssr.begin(); itr != ssr.end(); itr++){
        LOGD("%d",*itr);
    }

    return 0;
}

template <typename TYPE>
char *getStrForList(TYPE &_list)
{

    for (typename TYPE::iterator it = _list.begin(); it != _list.end(); ++it)
    {
        LOGD("it = %d", *it);
        int length = log10(*it) + 1;
        LOGD("%d", length);
    }
    return NULL;
}
