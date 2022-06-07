//
// Created by CTACEK on 6/4/2022.
//
#include <iostream>
#include <regex>


using namespace std;


int main() {

    string text;
//    const regex reg(R"([a,e,i,o,u,y,A,E,I,O,U,Y]*)");

    const regex reg(R"(([aeiouy])\1+(?=[aeiouy]{1}\b))");
//    const regex reg(R"((([a|e|i|o|u|y|A|E|I|O|U|Y])+?(?=[a|e|i|o|u|y|A|E|I|O|U|Y]{1})))"); / меняет все кроме последнего


    getline(cin,text);

    cout << endl << regex_replace(text, reg, "_") << '\n';

    return 0;
}
