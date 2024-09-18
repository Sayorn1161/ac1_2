#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

class Queue {
private:
    queue<int> q;
public:
    void enqueue(int value) {
        q.push(value);
    }

    void dequeue() {
        if (!q.empty()) {
            q.pop();
        }
    }

    int front() {
        if (!q.empty()) {
            return q.front();
        }
        return -1;
    }

    bool isEmpty() {
        return q.empty();
    }

    int size() {
        return q.size();
    }
};

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool checkBrackets(const string& str) {
    stack<char> stk;
    for (size_t i = 0; i < str.size(); ++i) {
        char ch = str[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            stk.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (stk.empty() || !isMatchingPair(stk.top(), ch)) {
                cout << "Error at position " << i << ": " << str.substr(0, i + 1) << endl;
                return false;
            }
            stk.pop();
        } else if (ch == ';') {
            break;
        }
    }
    if (!stk.empty()) {
        cout << "Error: mismatched opening brackets." << endl;
        return false;
    }
    return true;
}

int main() {
    string input = "({x-y-z}*[x+2y]-(z+4x));";
    if (checkBrackets(input)) {
        cout << "Brackets are correctly placed." << endl;
    } else {
        cout << "Brackets are incorrectly placed." << endl;
    }
    
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front of the queue: " << q.front() << endl;
    q.dequeue();
    cout << "Front of the queue after dequeue: " << q.front() << endl;

    return 0;
}
