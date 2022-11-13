#include <stdio.h>

typedef struct marks{
    int m1;
    float m2;
    char m3[10];
}marks;

int main() {
    marks m[3]={{1,2,"Vadiya"},{4,5,"Khana"},{7,8,"Bhai"}};
    marks* p = m;
    for(p=m; p<m+3; p++){
        printf("%d,%f,%s\n",p->m1,p->m2,p->m3);
        //OR
        printf("%d,%f,%s\n",(*p).m1,(*p).m2,(*p).m3);
    }
    
}