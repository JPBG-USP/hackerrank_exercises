#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    map<int, string> number_names = {};
    number_names[1] = "one";
    number_names[2] = "two";
    number_names[3] = "three";
    number_names[4] = "four";
    number_names[5] = "five";
    number_names[6] = "six";
    number_names[7] = "seven";
    number_names[8] = "eight";
    number_names[9] = "nine";
    
    if( n <= 9){
        cout << number_names[n];
    }else {
        cout << "Greater than 9";
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
