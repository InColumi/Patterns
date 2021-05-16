#pragma once
/**
 * ����� �������� ������������� ����� `GetInstance`, ������� ���� ���� ���
 * �������������� ����������� � ��������� �������� �������� ���� � ��� ��
 * ��������� ������ ��� ������ ������.
 */
class Singleton
{

	/**
	 * ����������� �������� ������ ������ ���� �������, ����� �������������
	 * �������� ������� ����� �������� new.
	 */

protected:
	Singleton()
	{}

	static Singleton* singleton_;

public:

	/**
	 * �������� �� ������ ���� ������������.
	 */
	Singleton(Singleton& other) = delete;
	/**
	 * Singletons should not be assignable.
	 */
	void operator=(const Singleton&) = delete;
	/**
	 * ��� ����������� �����, ����������� �������� � ���������� ��������. ���
	 * ������ �������, �� ������ ��������� �������� � �������� ��� �
	 * ����������� ����. ��� ����������� ��������, �� ���������� ������� ������,
	 * ���������� � ����������� ����.
	 */

	static Singleton* GetInstance();
	/**
	 * �������, ����� �������� ������ ��������� ��������� ������-������, �������
	 * ����� ���� ��������� �� ��� ����������.
	 */
	void ShowInfoOnMonitor(std::string message);
};

Singleton* Singleton::singleton_ = nullptr;;

/**
 * Static methods should be defined outside the class.
 */
Singleton* Singleton::GetInstance()
{
	if(singleton_ == nullptr)
	{
		singleton_ = new Singleton();
	}
	return singleton_;
}

void Singleton::ShowInfoOnMonitor(std::string message)
{
	std::cout << "Log: " << message << '\n';
}