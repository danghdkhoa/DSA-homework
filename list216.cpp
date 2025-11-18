#include <iostream>

struct Point {
    int x, y;
};

struct NODE {
    Point data;
    NODE *pNext;
};

struct LIST {
    NODE *pHead;
    NODE *pTail;
};

void CreateEmptyList(LIST &L) {
    L.pHead = NULL;
    L.pTail = NULL;
}

NODE* createNode(int x, int y) {
    NODE *p = new NODE;
    p->data.x = x;
    p->data.y = y;
    p->pNext = NULL;
    return p;
}

void AddTail(LIST &L, NODE *p) {
    if (L.pHead == NULL) {
        L.pHead = p;
        L.pTail = p;
    } else {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

void Nhap(LIST &L) {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        NODE *p = createNode(x, y);
        AddTail(L, p);
    }
}

Point DiemGanGocToaDoNhat(LIST L) {
    NODE *p = L.pHead;
    Point minPoint = p->data;
    long long minDistance = (long long)p->data.x * p->data.x + (long long)p->data.y * p->data.y;

    p = p->pNext;
    while (p != NULL) {
        long long currentDistance = (long long)p->data.x * p->data.x + (long long)p->data.y * p->data.y;
        if (currentDistance < minDistance) {
            minDistance = currentDistance;
            minPoint = p->data;
        }
        p = p->pNext;
    }
    return minPoint;
}

void Xuat(Point p) {
    std::cout << "(" << p.x << ", " << p.y << ")";
}

int main() {
    LIST points;
    CreateEmptyList(points);
    Nhap(points);

    std::cout << "Diem gan goc toa do nhat la: ";
    Xuat(DiemGanGocToaDoNhat(points));

    return 0;
}