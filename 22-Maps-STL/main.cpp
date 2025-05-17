#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>

class Students{
    private:
        std::map<std::string, int> data;
    public:
        Students(){};
        ~Students(){};
        
        void registerStudents(const std::string name, const int grade){
            if (this->verifyStudent(name)) {
                data[name] += grade;
            }else {
                data.insert(std::make_pair(name, grade));
            }
        }

        int getGrade(const std::string name){            
            if (!this->verifyStudent(name)) {
                return 0;
            };
        
            return data[name];
        }
        
        void eraseGrade(const std::string name){
            if (!this->verifyStudent(name)) {
                return;
            };
            data[name] = 0;
        };
        
        bool verifyStudent(const std::string name){
            std::map<std::string, int>::iterator itr = data.find(name);
            if (itr == data.end()) {
                return false;
            }else {
                return true;
            }
        }
    
};

int main() {
    int queries;
    Students students;
    
    std::cin >> queries;
    
    for (int i = 0; i < queries; i++) {
        int operation_type;
        std::cin >> operation_type;
        
        if (operation_type == 1) { // register
            std::string name;
            int grade;
            
            std::cin >> name >> grade;
            students.registerStudents(name, grade);
        }
        
        if (operation_type == 2) { // erease
            std::string name;
            
            std::cin >> name;
            students.eraseGrade(name);
        }
        
        if (operation_type == 3) {  // print
            std::string name;
            
            std::cin >> name;
            int grade = students.getGrade(name);
            std::cout << grade << "\n";
            
        }
        
    }
    
    
    return 0;
}



