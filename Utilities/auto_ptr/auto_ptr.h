#pragma once
//参考自stl源码剖析3.2 P81

//构造函数()
//析构函数
//operator=()
//拷贝构造函数
//opertor*
//operator->
//get()
//release()


//自己写完后参照More Effective C++ 9.2 修改的

template<class T>
class auto_ptr
{
public:
	explicit auto_ptr(T* pointer = 0) :pointee_(pointer) {}
	~auto_ptr() { delete pointee_; }

	template<class U>
	auto_ptr<T>& operator=(auto_ptr<U>&other)
	{
		if (this != (&other)) //这里不能要这一句，书上的代码都是错的？
		reset(other.release());
		return *this;
	}

	auto_ptr<T>& operator=(auto_ptr<T>& other) //这里必须提供指定类型的才行不知道为什么，不会去调用泛型的copy assignment,而ctor却可以
	{
		if (this != &other) //但是同类型的这里是可以要的
			reset(other.release());
		return *this;
	}


	//auto_ptr(auto_ptr<T>& rhs) :pointee_(rhs.release()) {}

	template<class U>
	auto_ptr(auto_ptr<U>& rhs) : pointee_(rhs.release()) {} //这里注意一定不能是const的

	T&  operator*() const { return *pointee_; }
	T* operator->() const { return pointee_; } //这里返回值是另外一个对象了，所以不需要返回值是const，里面的pointer_是始终不会受影响的
	//这里就是调用的时候 obj->func() ,返回指针然后指针的内置操作->

	T* get() const { return pointee_; }

	T* release()
	{
		T*p = get();
		pointee_ = NULL;
		return p;
	}

	void reset(T* pointer)
	{
		if (pointer != pointee_)
		{
			delete pointee_;
			pointee_ = pointer;
		}
	}

	//template<class U>
	//operator auto_ptr<U>() { return auto_ptr<U>(pointee_); }

private:
	T * pointee_;
};
