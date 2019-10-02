#include<bits/stdc++.h>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;
bool checkbalanced(char *inp){
    stack<char> s;
    for(int i=0;i<strlen(inp);i++){
        if(inp[i]=='{')
            s.push('}');
        else if(inp[i]=='(')
            s.push(')');
        else if(inp[i]=='[')
            s.push(']');
        else if(inp[i]=='}' || inp[i]==')' || inp[i]==']'){
            if(s.empty()){
                return false;
            }
            else{
                if(s.top()==inp[i]){
                    s.pop();
                }
                else{
                    return false;
                }
            }
        }
    }
    if(s.empty())
        return true;
    else{
        return false;
    }
}

int main(){
   char input[100000];
   cin.getline(input,100000);
   bool ans=checkbalanced(input);
   if(ans==0){
    cout<<"false";
   }
   else{
    cout<<"true";
   }
}
