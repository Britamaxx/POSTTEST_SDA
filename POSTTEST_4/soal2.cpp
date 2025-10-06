#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

char pop(Node*& top) {
    if (top == nullptr) return '\0';
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            push(stackTop, ch);
            continue;
        }

        if (ch == ')' || ch == '}' || ch == ']') {
            if (stackTop == nullptr) 
            {
                return false; 
            }
            char poppedChar = pop(stackTop);
            if ((ch == ')' && poppedChar != '(') || (ch == '}' && poppedChar != '{') || (ch == ']' && poppedChar != '['))
            {
                return false; 
            }
        }
    }

    bool isBalanced = (stackTop == nullptr);
    
    return isBalanced;
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;
    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;

    return 0;
}