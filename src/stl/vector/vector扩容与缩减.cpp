#include <iostream>
#include <vector>

using namespace std;

/**
 * 演示vector扩容过程
 * 使用 push_back()、insert()、emplace() 等成员方法向 vector 容器中添加新元素时
 * 如果当前容器已满（即 size() == capacity()），则它会自行扩容以满足添加新元素的需求
 * 当然，还可以调用 reserve() 成员方法来手动提升当前 vector 容器的容量
 *
 * 除了可以添加元素外，vector 模板类中还提供了 pop_back()、erase()、clear() 等成员方法，可以轻松实现删除容器中已存储的元素
 * 但需要注意得是，借助这些成员方法只能删除指定的元素，容器的容量并不会因此而改变
 */
void increase()
{
    vector<int> values;
    cout << "1.当前values大小：" << values.size() << ", 当前values容量：" << values.capacity() << endl;

    // 添加10个元素
    for (int i = 1; i <= 10; i++) {
        values.push_back(i);
    }
    cout << "2.当前values大小：" << values.size() << ", 当前values容量：" << values.capacity() << endl;

    // 手动为values扩容
    values.reserve(1000);
    cout << "3.当前values大小：" << values.size() << ", 当前values容量：" << values.capacity() << endl;
}

/**
 * shrink_to_fit()
 * 将当前 vector 容器的容量缩减至和实际存储元素的个数相等
 */
void shrink()
{
    vector<int> values;

    // 添加10个元素
    for (int i = 1; i <= 10; i++) {
        values.push_back(i);
    }

    // 手动为values扩容
    values.reserve(1000);

    cout << "1.当前values大小：" << values.size() << ", 当前values容量：" << values.capacity() << endl;

    values.shrink_to_fit();

    cout << "2.当前values大小：" << values.size() << ", 当前values容量：" << values.capacity() << endl;
}

/**
 * 使用swap()方法去除vector多余容量
 * 该方法的基础功能是交换 2 个相同类型的 vector 容器（交换容量和存储的所有元素），但其也能用于去除 vector 容器多余的容量
 *
 * vector<T>(x).swap(x);
 * 如果想用 swap() 成员方法去除当前 vector 容器多余的容量时，可以套用上面的语法格式
 */
void useSwapShrink()
{
    vector<int> values;

    // 添加10个元素
    for (int i = 1; i <= 10; i++) {
        values.push_back(i);
    }

    // 手动为values扩容
    values.reserve(1000);

    cout << "1.当前values大小：" << values.size() << ", 当前values容量：" << values.capacity() << endl;

    vector<int>(values).swap(values);

    cout << "2.当前values大小：" << values.size() << ", 当前values容量：" << values.capacity() << endl;
}

/**
 * 使用swap()方法清空vector
 * vector<T>().swap(x);
 * 当 swap() 成员方法用于清空 vector 容器时，可以套用以上语法格式
 */
void useSwapClear()
{
    vector<int> values;

    // 添加10个元素
    for (int i = 1; i <= 10; i++) {
        values.push_back(i);
    }

    // 手动为values扩容
    values.reserve(1000);

    cout << "1.当前values大小：" << values.size() << ", 当前values容量：" << values.capacity() << endl;

    vector<int>().swap(values);

    cout << "2.当前values大小：" << values.size() << ", 当前values容量：" << values.capacity() << endl;
}

int main()
{
    increase();
    shrink();
    useSwapShrink();
    useSwapClear();
}