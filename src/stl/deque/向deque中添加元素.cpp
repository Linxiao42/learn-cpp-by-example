#include <iostream>
#include <deque>

using namespace std;

/**
 * push_back()
 * 在容器现有元素的尾部添加一个元素，和 emplace_back() 不同，该函数添加新元素的过程是，先构造元素，然后再将该元素移动或复制到容器的尾部
 */
void usePushBack()
{
    // 初始化一个空deque容器
    deque<int> d;

    // 向d容器中的尾部依次添加 1，2，3
    d.push_back(1); // {1}
    d.push_back(2); // {1,2}
    d.push_back(3); // {1,2,3}
}

/**
 * push_front()
 * 在容器现有元素的头部添加一个元素，和 emplace_front() 不同，该函数添加新元素的过程是，先构造元素，然后再将该元素移动或复制到容器的头部
 */
void usePushFront()
{
    // 初始化一个空deque容器
    deque<int> d;

    // 向d容器中的尾部添加3
    d.push_back(3); // {3}

    // 向d容器的头部依次添加2，1
    d.push_front(2); // {2,3}
    d.push_front(1); // {1,2,3}
}

/**
 * emplace_back()
 * C++ 11 新添加的成员函数，其功能是在容器尾部生成一个元素。和 push_back() 不同，该函数直接在容器头部构造元素，省去了复制或移动元素的过程
 */
void useEmplaceBack()
{
    // 初始化一个空deque容器
    deque<int> d;

    // 向d容器中的尾部依次添加 1，2，3
    d.emplace_back(1); // {1}
    d.emplace_back(2); // {1,2}
    d.emplace_back(3); // {1,2,3}
}

/**
 * emplace_front()
 * C++ 11 新添加的成员函数，其功能是在容器头部生成一个元素。和 push_front() 不同，该函数直接在容器头部构造元素，省去了复制或移动元素的过程
 */
void useEmplaceFront()
{
    // 初始化一个空deque容器
    deque<int> d;

    // 向d容器中的尾部添加3
    d.emplace_back(3); // {3}

    // 向d容器的头部依次添加2，1
    d.emplace_front(2); // {2,3}
    d.emplace_front(1); // {1,2,3}
}

int main()
{
    usePushBack();
    usePushFront();
    useEmplaceBack();
    useEmplaceFront();
}