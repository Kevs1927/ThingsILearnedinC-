#include <iostream>

using namespace std;

int main(){
    string word = "John Doe";
    int size = word.length();
    int start{0};
    for (int i=0; i<=size; i++){
        if(word[i] == ' ' || word[i] == '\0'){
            int end{i-1};
            while(start<end){
                char temp = word[start];
                word[start] = word[end];
                word[end] = temp;
                start++;
                end--;
            }
            start = i+1;
        }
    }
    for (const auto &x : word){
        cout << x;
    }
}