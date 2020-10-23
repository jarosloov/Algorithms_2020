#include <string>
#include <vector>
#include <iostream>

using namespace std;

size_t f(vector<string> const &lines, string const &substring){
    size_t sum = 0;
    for (auto & s : lines){
        size_t i = 0;
        for (i = s.find(substring, i); i != string::npos; i = s.find(substring, i + 1))
            sum++;
    }
    return sum;
}
size_t test() {

    vector<string> lines = { "yarik", "aaaa" };
    if (f(lines, "aa") != 3)
        return 1;
    if (f(lines, "ya") != 1)
        return 2;
    else return 0;
}


int main(){
   cout << "Mistakes: " << test();
}

//jarosloov//