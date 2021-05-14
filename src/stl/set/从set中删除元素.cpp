#include <iostream>
#include <set>

using namespace std;

/**
 * size_type erase (const value_type& val)
 * 删除 set 容器中值为 val 的元素， 返回一个整数，表示成功删除的元素个数
 *
 * iterator erase (const_iterator position)
 * 删除 position 迭代器指向的元素，返回被删除元素之后一个元素的迭代器
 *
 * iterator erase (const_iterator first, const_iterator last)
 * 删除 [first,last) 区间内的所有元素，返回被删除元素之后一个元素的迭代器
 */
void useErase()
{
    // 创建并初始化set容器
    set<int> mySet{1,2,3,4,5};
    cout << "mySet size = " << mySet.size() << endl;

    // 调用第一种格式的erase()方法
    set<int>::size_type num = mySet.erase(2); // 删除元素2，{1,3,4,5}
    cout << "1.mySet size = " << mySet.size() << endl;
    cout << "num = " << num << endl;

    // 调用第二种格式的erase()方法
    set<int>::iterator iter1 = mySet.erase(mySet.begin()); // 删除元素1，{3,4,5}
    cout << "2.mySet size = " << mySet.size() << endl;
    cout << "iter->" << *iter1 << endl;

    // 调用第三种格式的erase()方法
    set<int>::iterator iter2 = mySet.erase(mySet.begin(), --mySet.end()); // 删除元素3、4，{5}
    cout << "3.mySet size = " << mySet.size() << endl;
    cout << "iter->" << *iter2 << endl;
}

/**
 * clear()
 * 如果要删除set容器中所有元素，可以使用clear()
 * 该方法不需要传入任何参数，也没有任何返回值
 */
void useClear()
{
    // 创建并初始化set容器
    set<int> mySet{1, 2, 3, 4, 5};
    cout << "1.mySet size = " << mySet.size() << endl;
    // 清空mySet容器
    mySet.clear();
    cout << "2.mySet size = " << mySet.size() << endl;

}

int main()
{
    useErase();
    useClear();
}
