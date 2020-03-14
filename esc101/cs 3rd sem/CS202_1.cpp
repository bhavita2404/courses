#include <iostream>
#include <fstream>

using namespace std;

int main(){
    //i -> row, j -> column, k -> value
    ofstream f("Clauses.txt");
    //Each cell should have at least one entry
    int count = 0;
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            for (int k = 0; k < 9; k++){
                f<<9*9*i + 9*j + k + 1<<" ";
            }
            count++;
            f<<0<<endl;
        }
    }
    
    //Each number appears only once in each row
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            for (int k = 0; k < 9; k++){
                for (int l = j + 1; l < 9; l++){
                    f<<-(9*9*i + 9*j + k + 1)<<" "<<-(9*9*i + 9*l + k + 1)<<" "<<0<<endl;   
                    count++;
                }
            }
        }
    }
    
    //Each number appears only once in each column
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            for (int k = 0; k < 9; k++){
                for (int l = i + 1; l < 9; l++){
                    f<<-(9*9*i + 9*j + k + 1)<<" "<<-(9*9*l + 9*j + k + 1)<<" "<<0<<endl;   
                    count++;
                }
            }
        }
    }
    
    //Each number appears only once in right diagonal
    for (int i = 0; i < 9; i++){
        for (int k = 0; k < 9; k++){
            for (int l = i + 1; l < 9; l++){
                f<<-(9*9*i + 9*i + k + 1)<<" "<<-(9*9*l + 9*l + k + 1)<<" "<<0<<endl;   
                count++;
            }
        }
    }
    
    //Each number appears only once in left diagonal
    for (int i = 0; i < 9; i++){
        for (int k = 0; k < 9; k++){
            for (int l = i + 1; l < 9; l++){
                f<<-(9*9*i + 9*(8-i) + k + 1)<<" "<<-(9*9*l + 9*(8-l) + k + 1)<<" "<<0<<endl;   
                count++;
            }
        }
    }
    
    
    //Each number appears only once in each grid
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 9; k++){
                for (int r = 0; r < 3; r++){
                    for (int c = 0; c < 3; c++){
                        for (int c1 = c + 1; c1 < 3; c1++){
                            f<<-(9*9*(3*i + r) + 9*(3*j + c) + k + 1)<<-(9*9*(3*i + r) + 9*(3*j + c1) + k + 1)<<" "<<0<<endl;
                            count++;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            for (int k = 0; k < 9; k++){
                for (int r = 0; r < 3; r++){
                    for (int c = 0; c < 3; c++){
                        for (int r1 = r + 1; r1 < 3; r1++){
                            for (int c1 = 0; c1 < 3; c1++){
                                f<<-(9*9*(3*i + r) + 9*(3*j + c) + k + 1)<<-(9*9*(3*i + r1) + 9*(3*j + c1) + k + 1)<<" "<<0<<endl;
                                count++;
                            }
                        }
                    }
                }
            }
        }
    }

    int i = 0;
    string line;
    ifstream puz ("input.txt");
        if (puz.is_open()){
        while ( getline (puz,line) ){
           for (int j = 0; line[j]!='\0'; j++){
              if(line[j] != '.'){
                int k = line[j] - '0';
                f<<9*9*i + 9*j + k<<" "<<0<<endl;
                count++;
              }
            } 
          i++;
        }
    }
    
    puz.close();
    f.close();
    cout<<count;
    return 0;
}