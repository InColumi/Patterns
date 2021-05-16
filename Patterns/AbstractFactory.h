#pragma once
#include "Singleton.h"
/**
 * ��������� �������� ��������� ��������, ������� ������ ��������� ���
 * ���������� ��������.
 */

class Product
{
public:
	virtual ~Product()
	{}
	virtual std::string Operation() const = 0;
};

/**
 * ���������� �������� ������������� ��������� ���������� ���������� ��������.
 */
class ConcreteProduct1: public Product
{
public:
	std::string Operation() const override
	{
		Singleton* singleton = Singleton::GetInstance();
		singleton->ShowInfoOnMonitor("invoke Operation in ConcreteProduct1");
		return "{Result of the ConcreteProduct1}";
	}
};
class ConcreteProduct2: public Product
{
public:
	std::string Operation() const override
	{
		Singleton* singleton = Singleton::GetInstance();
		singleton->ShowInfoOnMonitor("invoke Operation in ConcreteProduct2");
		return "{Result of the ConcreteProduct2}";
	}
};

/**
 * ����� ��������� ��������� ��������� �����, ������� ������ ���������� ������
 * ������ �������. ��������� ��������� ������ ������������� ���������� �����
 * ������.
 */

class Creator
{
	/**
	 * �������� ��������, ��� ��������� ����� ����� ���������� ����������
	 * ���������� ������ �� ���������.
	 */
public:
	virtual ~Creator()
	{};
	virtual Product* FactoryMethod() const = 0;
	/**
	 * ����� ��������, ���, �������� �� ��������, �������� ����������� ���������
	 * �� ����������� � �������� ���������. ������ �� �������� ��������� �������
	 * ������-������, ������� �������� �� �������� ���������, ������������
	 * ��������� �������. ��������� ����� �������� �������� ��� ������-������,
	 * ������������� ��������� ����� � ��������� �� ���� ������ ��� ��������.
	 */

	std::string SomeOperation() const
	{
		Singleton* singleton = Singleton::GetInstance();
		singleton->ShowInfoOnMonitor("invoke SomeOperation in Creator");
		// �������� ��������� �����, ����� �������� ������-�������.
		Product* product = this->FactoryMethod();
		// �����, �������� � ���� ���������.
		std::string result = "Creator: The same creator's code has just worked with " + product->Operation();
		delete product;
		return result;
	}
};

/**
 * ���������� ��������� �������������� ��������� ����� ��� ����, ����� ��������
 * ��� ��������������� ��������.
 */
class ConcreteCreator1: public Creator
{
	/**
	 * �������� ��������, ��� ��������� ������ ��-�������� ���������� ���
	 * ������������ ��������, ���� ���������� �� ������ ������������ ����������
	 * �������. ����� �������, ��������� ����� ���������� ����������� ��
	 * ���������� ������� ���������.
	 */
public:
	Product* FactoryMethod() const override
	{
		Singleton* singleton = Singleton::GetInstance();
		singleton->ShowInfoOnMonitor("invoke FactoryMethod in ConcreteCreator1");
		return new ConcreteProduct1();
	}
};

class ConcreteCreator2: public Creator
{
public:
	Product* FactoryMethod() const override
	{
		Singleton* singleton = Singleton::GetInstance();
		singleton->ShowInfoOnMonitor("invoke FactoryMethod in ConcreteCreator2");
		return new ConcreteProduct2();
	}
};

/**
 * ���������� ��� �������� � ����������� ����������� ���������, ���� � ����� ���
 * ������� ���������. ���� ������ ���������� �������� � ���������� ����� �������
 * ���������, �� ������ �������� ��� ����� �������� ���������.
 */
void ClientCode(const Creator& creator)
{
	// ...
	std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
		<< creator.SomeOperation() << std::endl;
	// ...
}

/**
 * ���������� �������� ��� ��������� � ����������� �� ������������ ��� �����.
 */
