#include <iostream>
#include "AbstractFactory.h"
#include "Prototype.h"
#include "Singleton.h"

int main()
{
	std::cout << "-----------------------------Abstract Factory-----------------------------\n";
	std::cout << "App: Launched with the ConcreteCreator2.\n";
	Singleton* singleton = Singleton::GetInstance();
	singleton->ShowInfoOnMonitor("Launched with the ConcreteCreator1.");
	
	Creator* creator1 = new ConcreteCreator1();
	singleton->ShowInfoOnMonitor("Create creator1");

	ClientCode(*creator1);
	singleton->ShowInfoOnMonitor("invoke method ClientCode");
	
	std::cout << "App: Launched with the ConcreteCreator2.\n";
	Creator* creator2 = new ConcreteCreator2();
	singleton->ShowInfoOnMonitor("Create creator2");
	
	ClientCode(*creator2);
	singleton->ShowInfoOnMonitor("invoke method ClientCode");

	try
	{
		delete creator1;
		singleton->ShowInfoOnMonitor("delete creator1");
	}
	catch(...)
	{
		singleton->ShowInfoOnMonitor("Error with delete creator1");
	}

	try
	{
		delete creator2;
		singleton->ShowInfoOnMonitor("delete creator2");
	}
	catch(...)
	{
		singleton->ShowInfoOnMonitor("Error with delete creator2");
	}
	
	std::cout << "-----------------------------End Abstract Factory-----------------------------\n";
	std::cout << "-----------------------------Prototype-----------------------------\n";

	PrototypeFactory* prototype_factory = new PrototypeFactory();
	try
	{
		Client(*prototype_factory);
	}
	catch(...)
	{
		singleton->ShowInfoOnMonitor("Error with Client(*prototype_factory)");
	}
	
	try
	{
		delete prototype_factory;
		singleton->ShowInfoOnMonitor("delete prototype_factory");
	}
	catch(...)
	{
		singleton->ShowInfoOnMonitor("Error with delete prototype_factory");
	}

	delete prototype_factory;
	std::cout << "-----------------------------End Prototype-----------------------------\n";

	return 0;
}