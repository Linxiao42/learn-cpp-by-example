#include <iostream>
#include <vector>

using namespace std;

/**
 * push_back()
 * 在 vector 容器尾部添加一个元素
 */
void usePushBack()
{
    vector<int> values;
    values.push_back(1);
    values.push_back(2);

    for (int i = 0; i < values.size(); i++) {
        cout << values[i] << " ";
    }
    cout << endl;
}

/**
 * emplace_back()
 * C++ 11 新增加的，其功能和 push_back() 相同，都是在 vector 容器的尾部添加一个元素
 */
void useEmplaceBack()
{
    vector<int> values;
    values.emplace_back(1);
    values.emplace_back(2);

    for (int i = 0; i < values.size(); i++) {
        cout << values[i] << " ";
    }
    cout << endl;
}


class Test
{
public:
    Test(int n) : num(n)
    {
        cout << "调用构造函数" << endl;
    }

    Test(const Test &other) : num(other.num)
    {
        cout << "调用拷贝构造函数" << endl;
    }

    Test(Test &&other) : num(other.num)
    {
        cout << "调用移动构造函数" << endl;
    }

private:
    int num;
};

/**
 * emplace_back()和push_back()的区别
 * push_back() 向容器尾部添加元素时，首先会创建这个元素，然后再将这个元素拷贝或者移动到容器中（如果是拷贝的话，事后会自行销毁先前创建的这个元素)
 * push_back() 在底层实现时，会优先选择调用移动构造函数，如果没有才会调用拷贝构造函数
 * emplace_back() 在实现时，则是直接在容器尾部创建这个元素，省去了拷贝或移动元素的过程
 *
 * 实现了移动构造函数：
 * emplace_back:
 *  调用构造函数
 *  push_back:
 *  调用构造函数
 *  调用移动构造函数
 *
 *
 * 没有实现移动构造函数：
 * emplace_back:
 *  调用构造函数
 *  push_back:
 *  调用构造函数
 *  调用拷贝构造函数
 *
 * 在实际使用时，建议优先选用 emplace_back()
 */
void showDifference()
{
    cout << "emplace_back:" << endl;
    vector<Test> vec1;
    vec1.emplace_back(1);

    cout << "push_back:" << endl;
    vector<Test> vec2;
    vec2.push_back(2);
}

int main()
{
    usePushBack();
    useEmplaceBack();
    showDifference();
}