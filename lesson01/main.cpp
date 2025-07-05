#include <iostream>

#include <vector>

class Student
{
private:
    std::string name = "default_name";
    std::string surname = "default_surname";
    int age = 17;

public:
    Student(const std::string &name, const std::string &surname, int age)
        : name(name), surname(surname), age(age)
    {
    }
    int getAge() const
    {
        return age;
    }

    std::string getName() const
    {
        return name;
    }

    void print() const
    {
        std::cout << "Name: " << name << ", Surname: " << surname << ", Age: " << age << std::endl;
    }
};



class Course
{
private:
    std::string name;
    std::vector<Student> students;
public:
    Course(const std::string &name) : name(name) {}
    void addStudent(const Student &student)
    {
        students.push_back(student);
    }
    const std::vector<Student> getStudents() const
    {
        return students;
    }
    const void print() const
    {
        std::cout << "Course: " << name << std::endl;
        for (const auto &student : students)
        {
            student.print();
        }
    }
};




int main(int argc, char *argv[])
{
    std::string name = "tsotne";
    std::string surname = "chkhenkeli";
    std::vector<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.pop_back();
    numbers.push_back(2);
    numbers.push_back(3);
    std::cout << numbers.size() << std::endl;
    for (size_t i = 0; i < numbers.size(); ++i)
    {
        std::cout << numbers[i] << " ";
    }

    std::vector<float> floats;
    floats.push_back(1.1f);
    floats.push_back(2.2f);
    floats.push_back(3.3f);

    // copies the contents of floats to a new vector dangerous with large vectors
    for (auto f : floats)
    {
        std::cout << f << " ";
    }


    std::cout << "Hello, " << name << " " << surname << "!" << std::endl;

    const Student student("name", "surname", 17);
    std::cout << "Student age: " << student.getAge() << std::endl;
    std::cout << "Student name: " << student.getName() << std::endl;

    student.print();
    Student student2("tsotne", "chkhenkeli", 99);
    Course course("C++ Programming");
    course.addStudent(student);
    course.addStudent(student2);

    course.print();


    return 0;
}