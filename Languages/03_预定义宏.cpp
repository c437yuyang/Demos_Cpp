#include <iostream>
using namespace std;
int main()
{   
    cout << __func__ << endl; //预处理变量，调试的函数名称  main
    cout << __FILE__ << endl; //当前文件名
    cout << __LINE__ << endl;
    cout << __TIME__ << endl; 
    cout << __DATE__ << endl; //当前时间

    cout << __STDC__ << endl; //这个一般没有
    // cout << __VA_ARGS__ << endl; //这个一般没有

#ifdef __cplusplus
    cout << __cplusplus << endl;
#else
    cout << "not defined " << endl;
#endif // DEBUG

#ifdef _WIN32
    cout << "win32" << endl;
#endif

#ifdef _WIN64
    cout << "win64" << endl;
#endif

#ifdef _MSC_VER
#endif

#ifdef   __unix
#endif
#ifdef  __linux
#endif 


#ifdef  __GNUC__
    cout << "GCC" << endl;
#endif


    system("pause");
    return 0;
}