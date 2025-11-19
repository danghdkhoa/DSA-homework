#include <iostream>
using namespace std;
struct NODE{
    int info;
    NODE *pNext;
};

struct stack{
    NODE *top;
};

NODE* CreateNode(int x) {
    NODE *p = new NODE;
    p->info = x;
    p->pNext = NULL;
    return p;
}

void CreateEmptyStack(stack &s) {
    s.top = NULL;
}

bool empty(const stack &s) {
    return s.top == NULL;
}

void push(stack &s, int x) {
    NODE *p = CreateNode(x);
    if (empty(s)) {
        s.top = p;
    } else {
        p->pNext = s.top;
        s.top = p;
    }
}

int top(stack s) {
    return s.top->info;
}

void pop(stack &s) {
    if (empty(s)) return;
    NODE *p = s.top;
    s.top = s.top->pNext;
    delete p;
}

void Testing_Push_Pop_Top_Stack(stack &s) {
    CreateEmptyStack(s);
    
    int x;
    int temp_result[1000];
    int count = 0;        

    while (true) {
        cin >> x;
        
        if (x == -1) break;


        if (x == 0) {
            if (!empty(s)) {
                temp_result[count] = top(s);
                count++;
                pop(s);
            }
        } 

        else {
            push(s, x);
        }
    }

    cout << "output: ";
    for (int i = 0; i < count; i++) {
        cout << temp_result[i] << " ";
    }
    
    cout << endl << "top: ";
    if (!empty(s)) {
        cout << top(s);
    }
}


int main() {
    stack s;
	Testing_Push_Pop_Top_Stack(s);
    return 0;
}
