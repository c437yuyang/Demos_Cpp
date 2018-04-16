#pragma once
//�ο���stlԴ������3.2 P81

//���캯��()
//��������
//operator=()
//�������캯��
//opertor*
//operator->
//get()
//release()


//�Լ�д������More Effective C++ 9.2 �޸ĵ�

template<class T>
class auto_ptr
{
public:
	explicit auto_ptr(T* pointer = 0) :pointee_(pointer) {}
	~auto_ptr() { delete pointee_; }

	template<class U>
	auto_ptr<T>& operator=(auto_ptr<U>&other)
	{
		if (this != (&other)) //���ﲻ��Ҫ��һ�䣬���ϵĴ��붼�Ǵ�ģ�
		reset(other.release());
		return *this;
	}

	auto_ptr<T>& operator=(auto_ptr<T>& other) //��������ṩָ�����͵Ĳ��в�֪��Ϊʲô������ȥ���÷��͵�copy assignment,��ctorȴ����
	{
		if (this != &other) //����ͬ���͵������ǿ���Ҫ��
			reset(other.release());
		return *this;
	}


	//auto_ptr(auto_ptr<T>& rhs) :pointee_(rhs.release()) {}

	template<class U>
	auto_ptr(auto_ptr<U>& rhs) : pointee_(rhs.release()) {} //����ע��һ��������const��

	T&  operator*() const { return *pointee_; }
	T* operator->() const { return pointee_; } //���ﷵ��ֵ������һ�������ˣ����Բ���Ҫ����ֵ��const�������pointer_��ʼ�ղ�����Ӱ���
	//������ǵ��õ�ʱ�� obj->func() ,����ָ��Ȼ��ָ������ò���->

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
