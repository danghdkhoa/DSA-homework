#include <iostream>
using namespace std;

struct NODE{
    int info;
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

void createQueue(queue &q) {
    CreateEmptyQueue(q);
    
    int x;
    int temp_result[1000];
    int count = 0;

    while (true) {
        cin >> x;
        
        if (x == -1) break;

        if (x == 0) {
            if (!empty(q)) {

                temp_result[count++] = dequeue(q);
            }
        } 
        else {
            enqueue(q, x);
        }
    }


    cout << "output: ";
    for (int i = 0; i < count; i++) {
        cout << temp_result[i] << " ";
    }
    cout << endl;


    cout << "front: ";
    if (!empty(q)) {
        cout << front(q);
    }
    cout << endl;

    cout << "back: ";
    if (!empty(q)) {
        cout << back(q);
    }
}

int main() {
    queue q;
	createQueue(q);
    return 0;
}
