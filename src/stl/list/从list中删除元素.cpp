#include <iostream>
#include <list>

using namespace std;

/**
 * pop_front() 删除位于 list 容器头部的一个元素
 * pop_back() 删除位于 list 容器尾部的一个元素
 */
void usePop()
{
    list<int> values{1, 2, 3, 4};

    // 删除当前容器中首个元素
    values.pop_front(); // {2,3,4}

    // 删除当前容器最后一个元素
    values.pop_back(); // {2,3}
}

/**
 * clear() 删除 list 容器存储的所有元素
 */
void useClear()
{
    list<int> values{1, 2, 3, 4};
    values.clear(); // {}
}

/**
 * erase()
 * 该成员函数既可以删除 list 容器中指定位置处的元素，也可以删除容器中某个区域内的多个元素
 *
 * iterator erase (iterator position)
 * 删除 list 容器中 position 迭代器所指位置处的元素
 *
 * iterator erase (iterator first, iterator last)
 * 删除 list 容器中 first 迭代器和 last 迭代器限定区域内的所有元素（包括 first 指向的元素，但不包括 last 指向的元素）
 */
void useErase()
{
    list<int> values{1, 2, 3, 4, 5};
    // 指向元素1的迭代器
    auto del = values.begin();
    // 迭代器右移，改为指向元素2
    ++del;
    values.erase(del); // {1,3,4,5}

    auto last = values.end();
    last--; // 指向元素5
    // 删除1、3、4
    values.erase(values.begin(), last); // {5}

    for (auto begin = values.begin(); begin != values.end(); begin++) {
        cout << *begin << " ";
    }
    cout << endl;
}

/**
 * remove(val)
 * 删除容器中所有等于val的元素
 */
void useRemove()
{
    list<char> values{'a', 'b', 'c', 'c', 'd'};
    values.remove('c');
    for (auto begin = values.begin(); begin != values.end(); begin++) {
        cout << *begin << " ";
    }
    cout << endl;
}

// 二元谓词函数
bool funcUni(double first, double second)
{
    return (int(first) == int(second));
}

/**
 * unique() 删除容器中相邻的重复元素，只保留一份
 *
 * void unique（BinaryPredicate）传入一个二元谓词函数，根据自定义规则去重
 */
void useUnique()
{
    list<double> values{1, 1.2, 1.2, 3, 4, 4.5, 4.6};
    // 删除相邻重复的元素，仅保留一份
    values.unique(); // {1, 1.2, 3, 4, 4.5, 4.6}

    for (auto begin = values.begin(); begin != values.end(); begin++) {
        cout << *begin << " ";
    }
    cout << endl;

    values.unique(funcUni); // {1, 3, 4}

    for (auto begin = values.begin(); begin != values.end(); begin++) {
        cout << *begin << " ";
    }
    cout << endl;
}

/**
 * remove_if() 删除容器中满足条件的元素
 */
void useRemoveIf()
{
    list<int> values{15, 36, 7, 17, 20, 39, 4, 1};
    // 删除values容器中能够使lambda表达式成立的所有元素
    values.remove_if([](int value) { return value < 10; }); // {15, 36, 17, 20, 39}

    for (auto begin = values.begin(); begin != values.end(); begin++) {
        cout << *begin << " ";
    }
    cout << endl;
}

/**
 * clear() 删除list容器存储的所有元素
 */
void clear()
{
    list<int> values{1, 2, 3, 4, 5};
    values.clear(); // {}
}

int main()
{
    usePop();
    useClear();
    useErase();
    useRemove();
    useUnique();
    useRemoveIf();
    clear();
}