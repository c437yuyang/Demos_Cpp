#include <iostream>
using namespace std;
int main()
{   
    cout << __func__ << endl; //预处理变量，调试的函数名称  main
    cout << __FILE__ << endl; //当前文件名
    cout << __LINE__ << endl;
    cout << __TIME__ << endl; 
    cout << __DATE__ << endl; //当前时间

    cout << __STDC__ << endl; //C语言里面这个有
    cout << __VA_ARGS__ << endl; //这个一般没有

#ifdef __cplusplus__
    cout << "defined" << endl;
#else
    cout << "not defined " << endl;
#endif // DEBUG


    system("pause");
    return 0;
}