#include <iostream>
using namespace std;

struct NODE{
    char info;
    NODE *pNext;
};
struct queue{
    NODE *front;
    NODE *back;
};
NODE *CreatNode(int x){
    NODE *p=new NODE;
    p->info=x;
    p->pNext=NULL;
    return p;
}

void CreateEmptyQueue(queue &q) {
    q.front = NULL;
    q.back = NULL;
}

bool empty(const queue &q) {
    return q.front == NULL;
}

void enqueue(queue &q, int x) {
    NODE *p = CreatNode(x);
    if (empty(q)) {
        q.front = q.back = p;
    } else {
        q.back->pNext = p; 
        q.back = p;        
    }
}
int dequeue(queue &q) {
    if (empty(q)) return 0; 
    
    NODE *p = q.front;
    int info = p->info;
    
    q.front = q.front->pNext;
    
    if (q.front == NULL) {
        q.back = NULL;
    }
    
    delete p;
    return info;
}

int front(queue q) {
    return q.front->info;
}

int back(queue q) {
    return q.back->info;
}


#include <string>
void createQueue(queue &q) {
    CreateEmptyQueue(q);
    
    string s;
    getline(cin, s); 
    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    if (s.length() == 0) {
        cout << "Empty";
        return;
    }

    for (int i = 0; i < s.length(); i++) {
        enqueue(q, s[i]);
    }

    bool isPalindrome = true;
    for (int i = s.length() - 1; i >= 0; i--) {
        char charFromQueue = dequeue(q); 
        char charFromStr = s[i];         

        if (charFromQueue != charFromStr) {
            isPalindrome = false;
            break; 
        }
    }

    if (isPalindrome) {
        cout << "True";
    } else {
        cout << "False";
    }
}

int main() {
    queue q;
	createQueue(q);
    return 0;
}

