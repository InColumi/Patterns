#include <iostream>
#include "AbstractFactory.h"
#include "Singleton.h"

int main()
{
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

	delete creator1;
	singleton->ShowInfoOnMonitor("delete creator1");
	delete creator2;
	singleton->ShowInfoOnMonitor("delete creator2");
	return 0;
}