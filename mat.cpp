#include <string>
#include <iostream>
#include <vector>
const int LOW = 33;
const int HIGH = 126;
using namespace std;
namespace ariel{
    string mat (int r, int c , char s1, char s2){
        
        if( r%2 == 0 || c %2 ==0 ) {
            throw std::invalid_argument{"Mat size is always odd!"};
        } 
        if(r < 1 || c < 1){
            throw std::invalid_argument{"Mat size mast be positive!"};
        }
        if(s1 < LOW || s2 < LOW){
            throw std::invalid_argument{"not printable keys"};
        }
        if(s1 > HIGH || s2 > HIGH){
            throw std::invalid_argument{"not printable keys"};
        }

        
        vector<vector<char>> carpet( c , vector<char> (r,'-'));
        string s;
        int start = 0;
        char sym = s1;
        int oc = c;
        int oor = r;
        while (r != 0 && c != 0) {
            
            for (int i = start; i < r; i++)
            {
                carpet[start][i] = sym;
            }

            for (int i = start; i < r; i++)
            {
                carpet[c-1][i] = sym;
            }

            for (int i = start + 1; i < c - 1; i++)
            {
                carpet[i][start] = sym;
            }

            for (int i = start + 1; i < c - 1; i++)
            {
                carpet[i][r - 1] = sym;
            }
            




            if (sym == s1){ 
            sym = s2;
            }
            else if (sym == s2){
            sym = s1;
            }

            c -= 1;
            r -= 1;
            start += 1;
            

        }
        
        
        
        
        for (int i = 0; i < oc ; i++)
        {
            for (int j = 0; j < oor; j++)
            {
                
                s += (carpet[i][j]);
            }   
        s += "\n";
        
        }   

        
        
        return s;
    }

}