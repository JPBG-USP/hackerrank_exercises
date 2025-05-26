#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person{
    protected:
        std::string name;
        int age;
    public:
        Person(){};
        ~Person(){};
        
        virtual void getdata(){};
        virtual void putdata(){};
};

class Professor: public Person{
    private:
        static int cur_id_;
        int cur_id;
        int publication;
    public:
        Professor(){};
        ~Professor(){};
        
        void getdata() override{
            cur_id_++;
            this->cur_id = cur_id_;
            std::cin >> name >> age >> publication;
        };
        
        void putdata() override{
            std::cout << name << " " << age << " " << publication << " " << cur_id << std::endl;
        };
};

class Student: public Person{
    private:
        int marks[6];
        static int cur_id_;
        int cur_id;
    
    public:
        Student(){};
        ~Student(){};
        
        void getdata() override{
            cur_id_++;
            this->cur_id = cur_id_;
            std::cin >> name >> age;
            for (int i = 0; i < 6; i++) {
                std::cin >> marks[i];
            }
        };
        
        void putdata() override{
            std::cout << name << " " << age << " " << this->sumMarks() << " " << cur_id << std::endl;
        };
        
        int sumMarks(){
            int sum = 0;
            for (int i = 0; i < 6 ; i++) {
                sum += marks[i];
            }
            return sum;
        }
};

int Professor::cur_id_ = 0;
int Student::cur_id_ = 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
