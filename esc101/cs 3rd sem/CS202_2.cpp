#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

int main(){
    string line;
    ifstream f("Result.txt");
    ofstream f1("Puzzle.txt");
    //CPU Time
    getline(f, line);
    //Propositions
    getline(f, line);
    stringstream ss(line);
    string num;
    getline(ss, num, ' ');
    int p = 0;
    while(getline(ss, num, ' ')){
        int l = 0;
        int k = 0;
        int sign = 1;
        while(num[l] != '\0'){
            if (num[l] == '-'){
                sign = -1;
                l++;
                break;
            }
            k = k*10 + num[l] - '0';
            l++;
        }
        if(sign == 1){
            int val = k%9;
            if (val == 0)
              val = 9;
            f1<<val<<" ";
            p++;
            if (p == 9){
              f1<<endl;
              p = 0;
            }
        }
                    
    }
    f1.close();
    f.close();
    return 0;
}