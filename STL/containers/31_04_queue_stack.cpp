#include <queue>
#include <stack>
#include <list>
#include <deque>

int main()
{
    std::queue<int, std::deque<int>> arr_queue; //默认使用deque实现
    std::queue<int, std::list<int>> list_queue; //也可以用list实现
    std::queue<int, std::vector<int>> vec_queue; //用vector实现会有错

    vec_queue.pop(); //不编译这一行的话可以，因为模板的特性是，用到了才编译。。。这里因为没有pop_front所以报错


    std::stack<int, std::deque<int>> arr_stack; //默认使用deque实现
    std::stack<int, std::list<int>> list_stack; //也可以用list实现
    std::stack<int, std::vector<int>> vec_stack; //stack完美用vector实现

    return 0;
}