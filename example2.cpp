#include <iostream>
#include <stack>

using namespace std;

string exercise2(string str) {
    stack<char> mystack;
    char elem;

    for (unsigned i = 0; i < str.length(); i++){
        if (mystack.empty()) {
            if (str[i] == '(' or str[i] == '['){
                mystack.push(str[i]);
            } else {
                return "No\n";
            }
        }
        else{
            elem = mystack.top();
            if (str[i] == ')' && elem == '('){
                mystack.pop();
            } else if (str[i] == ']' && elem == '['){
                mystack.pop();
            } else if (str[i] == '(' || str[i] == '['){
                mystack.push(str[i]);
            } else {
            	return "No\n";
            }
        }
    }

    if (!mystack.empty()) {
        return "No\n";
    }
    return "Yes\n";
}

int main(int argc, char const *argv[])
{
    int num;
    string sequence;
    string answer;
    
    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> sequence;
        answer += exercise2(sequence);
    }

    cout << answer;

    return 0;
}
