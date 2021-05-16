#pragma once
#include "Singleton.h"
#include <unordered_map>
#include <string>
// Паттерн Прототип
//
// Назначение: Позволяет копировать объекты, не вдаваясь в подробности их
// реализации.

enum Type
{
    PROTOTYPE_1 = 0,
    PROTOTYPE_2
};

/**
 * Пример класса, имеющего возможность клонирования. Мы посмотрим как происходит
 * клонирование значений полей разных типов.
 */

class Prototype
{
protected:
    std::string prototype_name_;
    float prototype_field_;

public:
    Prototype()
    {}
    Prototype(std::string prototype_name)
        : prototype_name_(prototype_name)
    {  }
    virtual ~Prototype()
    {}
    virtual Prototype* Clone() const = 0;
    virtual void Method(float prototype_field)
    {
        this->prototype_field_ = prototype_field;
        Singleton* singleton = Singleton::GetInstance();
        std::string message = "Call Method from " + prototype_name_ + " with field : " + std::to_string(prototype_field);
        singleton->ShowInfoOnMonitor(message);
    }
};

/**
 * ConcretePrototype1 is a Sub-Class of Prototype and implement the Clone Method
 * In this example all data members of Prototype Class are in the Stack. If you
 * have pointers in your properties for ex: String* name_ ,you will need to
 * implement the Copy-Constructor to make sure you have a deep copy from the
 * clone method
 */

class ConcretePrototype1: public Prototype
{
private:
    float concrete_prototype_field1_;

public:
    ConcretePrototype1(std::string prototype_name, float concrete_prototype_field)
        : Prototype(prototype_name), concrete_prototype_field1_(concrete_prototype_field)
    {  }

    /**
     * Notice that Clone method return a Pointer to a new ConcretePrototype1
     * replica. so, the client (who call the clone method) has the responsability
     * to free that memory. I you have smart pointer knowledge you may prefer to
     * use unique_pointer here.
     */
    Prototype* Clone() const override
    {
        Singleton* singleton = Singleton::GetInstance();
        singleton->ShowInfoOnMonitor("invoke method Clone in ConcretePrototype1");
        return new ConcretePrototype1(*this);
    }
};

class ConcretePrototype2: public Prototype
{
private:
    float concrete_prototype_field2_;

public:
    ConcretePrototype2(std::string prototype_name, float concrete_prototype_field)
        : Prototype(prototype_name), concrete_prototype_field2_(concrete_prototype_field)
    {  }
    Prototype* Clone() const override
    {
        Singleton* singleton = Singleton::GetInstance();
        singleton->ShowInfoOnMonitor("invoke method Clone in ConcretePrototype2");
        return new ConcretePrototype2(*this);
    }
};

/**
 * In PrototypeFactory you have two concrete prototypes, one for each concrete
 * prototype class, so each time you want to create a bullet , you can use the
 * existing ones and clone those.
 */

class PrototypeFactory
{
private:
    std::unordered_map<Type, Prototype*, std::hash<int>> prototypes_;

public:
    PrototypeFactory()
    {
        Singleton* singleton = Singleton::GetInstance();
        singleton->ShowInfoOnMonitor("Create PrototypeFactory");
        prototypes_[Type::PROTOTYPE_1] = new ConcretePrototype1("PROTOTYPE_1 ", 50.f);
        prototypes_[Type::PROTOTYPE_2] = new ConcretePrototype2("PROTOTYPE_2 ", 60.f);
    }

    /**
     * Be carefull of free all memory allocated. Again, if you have smart pointers
     * knowelege will be better to use it here.
     */

    ~PrototypeFactory()
    {
        Singleton* singleton = Singleton::GetInstance();
        singleton->ShowInfoOnMonitor("Delete PrototypeFactory");
        delete prototypes_[Type::PROTOTYPE_1];
        delete prototypes_[Type::PROTOTYPE_2];
    }

    /**
     * Notice here that you just need to specify the type of the prototype you
     * want and the method will create from the object with this type.
     */
    Prototype* CreatePrototype(Type type)
    {
        Singleton* singleton = Singleton::GetInstance();
        singleton->ShowInfoOnMonitor("invoke CreatePrototype in PrototypeFactory");
        return prototypes_[type]->Clone();
    }
};

void Client(PrototypeFactory& prototype_factory)
{
    Singleton* singleton = Singleton::GetInstance();
    Prototype* prototype = prototype_factory.CreatePrototype(Type::PROTOTYPE_1);
    prototype->Method(90);
    delete prototype;
    prototype = prototype_factory.CreatePrototype(Type::PROTOTYPE_2);
    prototype->Method(10);

    delete prototype;
}