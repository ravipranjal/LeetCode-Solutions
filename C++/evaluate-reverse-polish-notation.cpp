#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int i =0;
        bool err = false;
        vector<int> exp;
        for (int i=0; i<tokens.size() && !err; i++ ){
            if (isNum(tokens[i])) {
                exp.push_back(value);
            } else if( isOp(tokens[i])==true ) {
                if (exp.size() < 2) {
                    return 0; //ERROR
                }
                int lhs, rhs;
                rhs = exp.back();
                exp.pop_back();
                lhs = exp.back();
                exp.pop_back();

                int evlValue;
                if (tokens[i]=="+"){
                    evlValue = lhs + rhs;    
                }else if (tokens[i]=="-"){
                    evlValue = lhs - rhs;
                }else if (tokens[i]=="*"){
                    evlValue = lhs * rhs;
                }else if (tokens[i]=="/"){
                    evlValue = lhs / rhs;
                }

                exp.push_back(evlValue);

            }else {
                return 0; //ERROR 
            }
        }

        if (exp.size()==1){
            return exp.back();
        }
        return 0;        

    }

private:
    long value;

    bool isOp(string &op) {
        return (op=="+" || op=="-" || op=="*" || op=="/");
    }

    bool isNum(string &num) {
        char *end;
        value = strtol(num.c_str(), &end, 10); 
        if (end == num.c_str() || *end != '\0' || errno == ERANGE){
            return false;
        }
        return true;
    }
};


int main()
{
    Solution s;

    char exps[5][3];
    vector<string> expression;
    int n;
    cout<<"Enter the size for expression 1: ";
    cin>>n;

    for(int i=0; i<n; i++) {
        scanf("%50s", exps[i]);
        expression.push_back(exps[i]);
    }
    cout << s.evalRPN(expression)<<endl;


    char exps2[5][3];
    expression.clear();
    cout<<"Enter the size for expression 2: ";
    cin>>n;

    for(int i=0; i<n; i++) {
        scanf("%50s", exps2[i]);
        expression.push_back(exps[i]);
    }

    cout << s.evalRPN(expression)<<endl;

    return 0;
}
