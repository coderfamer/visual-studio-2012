#include <iostream>
#include <string>
#include <typeinfo>
#include <strstream>
using namespace std;

//��ģ�嶨����class��typenameô������
//ģ��������Ͷ���ֻ����ȫ�֡������ռ�����෶Χ�ڽ���
template<typename T1, typename T2>
class A
{
public:
	void f(T1 a, T2 b);
};

template<typename T1, typename T2>
void A<T1, T2>::f(T1 a, T2 b)
{
	cout << "class A --------->T1: " << a << ";T2: " << b << endl;
}

//������ģ���Ĭ������ʵ�Σ�Ĭ�������ββ������ں���ģ��
template<typename T3, typename T4 = int> // T4 Ĭ��ģ�������β�
class B
{
private:
	T3 t3;
	T4 t4;
public:
	B(T3 a, T4 b);
	void show();
};

//����ģ���ⲿ�������Ĭ�����͵��β�ʱ����template���βα���Ĭ����Ӧ��ʡ��
template<typename T3, typename T4>
B<T3, T4>::B(T3 a, T4 b) : t3(a), t4(b)
{}

template<typename T3, typename T4>
void B<T3, T4>::show()
{
	cout << "class B --------->T3: " << t3 << "; T4: " << t4 <<  endl;
}

//======================================================================================================
//������ģ�����
//�������β�ֻ�������͡�ָ�������
template<typename T5, int a>
class C
{
private:
	T5 max[a];
public:
	void cshow()
	{
		cout << "class c --------->T5: " << typeid(T5).name() << endl;
	}
};


template<typename t_print>
class  Printer {
public:
	explicit Printer(const t_print& param) : t(param) {}
	string && to_string();
	void print()
	{
		cout << t << endl;
	}
private:
	t_print t;
};

template<typename t_print>
string && Printer<t_print>::to_string()
{
	strstream ss;
	ss << t;
	return move(string(ss.str()));
}

//========================================================================================
//��ģ���еĳ�Ա����ģ��
template<typename t_print2>
class Printer2
{
public:
	explicit Printer2(const t_print2& param) : t(param) {}
	template<typename U>
	void add_and_print(const U& u);
private:
	t_print2 t;
};

//Ҫ������template˵��
template<typename t_print2>
template<typename U>
void Printer2<t_print2>::add_and_print(const U& u)
{
	cout << t + u << endl;
}

//=============================================================================================
//��ģ���п�������static��Ա�������ⶨ���ʱ��Ҫ����template��صĹؼ���
//ÿ����ͬ��ģ��ʵ��������һ�����е�static��Ա����
template<typename t_print3>
class Printer3
{
public:
	explicit Printer3(const t_print3& param) : t(param) {}
	static int s_value;
	void print3();
private:
	t_print3 t;
};

template<typename t_print3>
int Printer3<t_print3>::s_value = 1;

template<typename t_print3>
void Printer3<t_print3>::print3()
{
	cout << s_value << endl;
}

int main()
{
	A<int, int> a1;
	a1.f(2, 3);
	A<int, char> a2;
	a2.f(2, 'a');
	A<string, int> a3;
	a3.f("hello world!", 5);

	B<char, char> b1('a', 'b');
	b1.show();
	B<char> b2('c', 6);
	b2.show();
	B<string, string> b3("��", "��");

	const int i = 5;
	C<int, i> c1;
	c1.cshow();
	C<char, i> c2;
	c2.cshow();

	Printer<int> p(20);
	p.print();

	//=============================
	//Printer2
	Printer2<int> p2(30);
	p2.add_and_print(1.1);
	
	//================================
	//static��Ա����ʵ���������,��ͬ��ʵ���в�ͬ��static��Ա��ֻ����ͬ���͵�ʵ����static��Ա�Ż���Ӱ��
	//���� int�͵�ʵ��ֵ��ı䣬��doubleʵ����ֵ����ı�
	Printer3<int> p3_1(10);
	Printer3<int> p3_2(100);
	Printer3<double> p3_3(1.0);
	p3_1.s_value += 3;
	p3_1.print3();
	p3_2.print3();
	p3_3.print3();
	return 0;
}