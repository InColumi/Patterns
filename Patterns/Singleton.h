#pragma once
/**
 * Класс Одиночка предоставляет метод `GetInstance`, который ведёт себя как
 * альтернативный конструктор и позволяет клиентам получать один и тот же
 * экземпляр класса при каждом вызове.
 */
class Singleton
{

	/**
	 * Конструктор Одиночки всегда должен быть скрытым, чтобы предотвратить
	 * создание объекта через оператор new.
	 */

protected:
	Singleton()
	{}

	static Singleton* singleton_;

public:

	/**
	 * Одиночки не должны быть клонируемыми.
	 */
	Singleton(Singleton& other) = delete;
	/**
	 * Singletons should not be assignable.
	 */
	void operator=(const Singleton&) = delete;
	/**
	 * Это статический метод, управляющий доступом к экземпляру одиночки. При
	 * первом запуске, он создаёт экземпляр одиночки и помещает его в
	 * статическое поле. При последующих запусках, он возвращает клиенту объект,
	 * хранящийся в статическом поле.
	 */

	static Singleton* GetInstance();
	/**
	 * Наконец, любой одиночка должен содержать некоторую бизнес-логику, которая
	 * может быть выполнена на его экземпляре.
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