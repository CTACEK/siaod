#include <iostream>
#include <string>

using namespace std;

void separate(string &s){
    int n = s.length();
    int idx = 0;
    while (idx != string::npos){
        string word(s.substr(idx, s.find_first_of(" .,:;?!") - n - 1));
        if (!word.empty())
            cout << word << endl;
        idx = s.find_first_of(" .,:;?!") + 1;
    }
}

int main(){
    string sentence;
    cout << "enter the sentence" << endl;
    getline(cin, sentence);
    separate(sentence);
    return 0;
}