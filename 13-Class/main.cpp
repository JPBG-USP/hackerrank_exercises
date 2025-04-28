#include <iostream>
#include <sstream>

class Student
{
private:
    int age;
    int standard;
    std::string first_name;
    std::string last_name;

public:
    Student();
    ~Student();
    void set_age(int age){ this->age = age; };
    void set_standard(int standard) { this->standard = standard; };
    void set_first_name(std::string first_name){ this->first_name = first_name; };
    void set_last_name(std::string last_name){ this->last_name = last_name; };

    int get_age(){ return this->age; };
    int get_standard(){ return this->standard; };
    std::string get_first_name(){ return this->first_name; };
    std::string get_last_name(){ return this->last_name; };
    std::string to_string(){
        std::stringstream ss;
        ss << age << "," << first_name << "," << last_name << "," << standard;
        return ss.str();
    };

};

Student::Student(/* args */)
{
}

Student::~Student()
{
}


int main() {
    int age, standard;
    std::string first_name, last_name;
    
    std::cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    std::cout << st.get_age() << "\n";
    std::cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    std::cout << st.get_standard() << "\n";
    std::cout << "\n";
    std::cout << st.to_string();
    
    return 0;
}