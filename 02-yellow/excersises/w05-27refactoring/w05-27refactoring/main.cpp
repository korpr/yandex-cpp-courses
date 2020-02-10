#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Person{
public:
    Person(string type, string name):Type(type),Name(name){}
    virtual void DoSomething(const string& action) const{
        cout << Type << ": " << Name << " "<< action << endl;
    }
    virtual void Walk(const string& destination) const{
        DoSomething("walks to: " + destination);
    }
    virtual string GetType() const{
        return Type;
    }
    virtual string GetName() const{
        return Name;
    }
    
private:
    const string Type;
    const string Name;
};

class Student: public Person {
public:
    
    Student(string name, string favouriteSong):Person("Student", name),FavouriteSong(favouriteSong) {
    }
    
    void Learn() {
        DoSomething("learns");
    }
    
    void SingSong() const{
        stringstream is;
        is << "sings a song: " << FavouriteSong;
        DoSomething(is.str());
    }
    void Walk(const string& destination) const override {
        Person::Walk(destination);
        SingSong();
    }
private:
    string FavouriteSong;
};


class Teacher:public Person {
public:
    
    Teacher(string name, string subject):Person("Teacher", name), Subject(subject) {}
    
    void Teach() {
        stringstream is;
        is << "teaches: " << Subject;
        DoSomething(is.str());
    }
    
private:
    string Subject;
};


class Policeman: public Person {
public:
    Policeman(string name):Person("Policeman", name) {}
    
    void Check(const Person& p) {
        stringstream is;
        is << "checks: " << p.GetType() << ". ";
        is << p.GetType() << "'s name is: " << p.GetName();
        DoSomething(is.str());
        
    }
    
public:
    string Name;
};

void VisitPlaces(Person& person, vector<string> places) {
    for (auto p : places) {
        person.Walk(p);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    s.Learn();
    Policeman p("Bob");
    t.Teach();
    
    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
