#include <iostream>
#include <list>

using namespace std;

/**
 *  push_front()：向 list 容器首个元素前添加新元素
 *  push_back()：向 list 容器最后一个元素后添加新元素
 */
void usePush()
{
    list<int> values{1, 2, 3};
    values.push_front(0); // {0,1,2,3}
    values.push_back(4); // {0,1,2,3,4}
}

/**
 * emplace_front()：在容器首个元素前直接生成新的元素
 * emplace_back()：在容器最后一个元素后直接生成新的元素
 */
void useEmplace()
{
    list<int> values{1, 2, 3};
    values.emplace_front(0); // {0,1,2,3}
    values.emplace_back(4); // {0,1,2,3,4}
}

int main()
{
    usePush();
    useEmplace();
}