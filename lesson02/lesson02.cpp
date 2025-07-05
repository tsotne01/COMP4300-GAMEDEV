
#include <iostream>
#include <memory>

class Person
{
private:
    std::string name = "";

public:
    Person(std::string name) : name(name)
    {
    }
    const std::string getName() const
    {
        return name;
    }
};

const void sayHello(const std::shared_ptr<Person> student)
{
    std::cout << "hello," << student->getName() << std::endl;
}

int main()
{
    auto tsotne = std::make_shared<Person>("tsotne");
    std::cout << tsotne->getName() << std::endl;
    sayHello(tsotne);
    return 0;
}