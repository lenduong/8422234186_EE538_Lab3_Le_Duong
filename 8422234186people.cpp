/*
Q2 Pseudocode
1. Define abstract class Person with private name and age data.
2. Give Person const getters, a pure virtual displayInfo function, a virtual
   introduce function, and a virtual destructor.
3. Publicly derive Student and Teacher from Person.
4. Initialize the Person part and each derived class's data in constructor
   initialization lists.
5. Override displayInfo in each derived class using the exact required format.

Q3 Pseudocode
1. Read n, then repeat n times: read a role and its fields.
2. Construct the matching Student or Teacher and store its address as Person*.
3. Traverse the Person pointers in input order.
4. For each pointer, call displayInfo and then introduce so virtual dispatch
   selects the appropriate derived implementations.
5. Delete each object through its Person pointer; the virtual destructor makes
   destruction safe.
*/

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

class Person {
private:
    std::string name;
    int age;

public:
    Person(const std::string& name, int age);
    const std::string& getName() const;
    int getAge() const;
    virtual void displayInfo(std::ostream& out) const = 0;
    virtual void introduce(std::ostream& out) const;
    virtual ~Person() = default;
};

class Student : public Person {
private:
    std::string studentID;
    double gpa;

public:
    Student(const std::string& name, int age,
            const std::string& studentID, double gpa);
    void displayInfo(std::ostream& out) const override;
    void introduce(std::ostream& out) const override;
};

class Teacher : public Person {
private:
    std::string subject;
    int yearsOfExperience;

public:
    Teacher(const std::string& name, int age,
            const std::string& subject, int yearsOfExperience);
    void displayInfo(std::ostream& out) const override;
    void introduce(std::ostream& out) const override;
};

Person::Person(const std::string& name, int age)
    : name(name), age(age) {
}

const std::string& Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}

void Person::introduce(std::ostream& out) const {
    out << "I am a person. My name is " << getName() << ".\n";
}

Student::Student(const std::string& name, int age,
                 const std::string& studentID, double gpa)
    : Person(name, age), studentID(studentID), gpa(gpa) {
}

void Student::displayInfo(std::ostream& out) const {
    out << "Student: " << getName()
        << ", Age: " << getAge()
        << ", ID: " << studentID
        << ", GPA: " << std::fixed << std::setprecision(1) << gpa
        << '\n';
}

void Student::introduce(std::ostream& out) const {
    out << "I am a student. My name is " << getName() << ".\n";
}

Teacher::Teacher(const std::string& name, int age,
                 const std::string& subject, int yearsOfExperience)
    : Person(name, age),
      subject(subject),
      yearsOfExperience(yearsOfExperience) {
}

void Teacher::displayInfo(std::ostream& out) const {
    out << "Teacher: " << getName()
        << ", Age: " << getAge()
        << ", Subject: " << subject
        << ", Experience: " << yearsOfExperience << " years\n";
}

void Teacher::introduce(std::ostream& out) const {
    out << "I am a teacher. My name is " << getName() << ".\n";
}

int main() {
    int numberOfPeople;
    std::cin >> numberOfPeople;

    std::vector<Person*> people;
    people.reserve(numberOfPeople);

    for (int index = 0; index < numberOfPeople; ++index) {
        std::string role;
        std::string name;
        int age;

        std::cin >> role >> name >> age;

        if (role == "Student") {
            std::string studentID;
            double gpa;
            std::cin >> studentID >> gpa;
            people.push_back(new Student(name, age, studentID, gpa));
        } else {
            std::string subject;
            int yearsOfExperience;
            std::cin >> subject >> yearsOfExperience;
            people.push_back(
                new Teacher(name, age, subject, yearsOfExperience));
        }
    }

    for (Person* person : people) {
        person->displayInfo(std::cout);
        person->introduce(std::cout);
        delete person;
    }

    return 0;
}
