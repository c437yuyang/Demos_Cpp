
#include "stdafx.h"
#include <iostream>
#include <atlimage.h>
using namespace std;

int main()
{
	//����̨����CImage��Ҫ#include <atlimage.h>
	{
		CImage m;
		std::wstring imgPath = _T("lena.jpg");
		m.Load(imgPath.c_str());
		std::cout << m.GetWidth() << std::endl;
	}
	::system("pause");
	return 0;
}

