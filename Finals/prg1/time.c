#include<stdio.h>
#include<stdlib.h>

typedef struct Time
{
 int hr,min,sec;
}Time;

void read(Time* T){
    printf("Enter the hours, minutes and seconds: \n");
    scanf("%d%d%d",&T->hr,&T->min,&T->sec);
}

void display(Time* T){
    printf("%d:%d:%d\n", T->hr,T->min,T->sec);
}

void update(Time* T){
    T->sec++;
    if(T->sec>=60){
        T->min+=(T->sec)/60;
        T->sec%=60;
        if(T->min>=60){
            T->hr+=(T->min)/60;
            T->min%=60;
            if(T->hr>=24) T->sec=T->hr=T->min=0;
        }
    }
}

Time add(Time* T1, Time* T2){
    Time T3;
    T3.hr=T1->hr + T2->hr;
    T3.min=T1->min + T2->min;
    T3.sec=T1->sec + T2->sec;

    if(T3.sec>=60){
        T3.min+=(T3.sec)/60;
        T3.sec%=60;
        if(T3.min>=60){
            T3.hr+=(T3.min)/60;
            T3.min%=60;
            if(T3.hr>=24) T3.sec=T3.hr=T3.min=0;
        }
    }
    return T3;
}

void main(){
    Time T1,T2,T3,T4,T5;
    int ch;
    while(1){
        printf("\n1. Read Time\n2. Display Time\n3. Update Time\n4. Add Time\n5. Exit\n");
        printf("-----\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                read(&T1);
                break;

            case 2:
            printf("The time is: ");
                display(&T1);
                break;

            case 3:
            printf("Time before updation is: "); display(&T1);
            update(&T1);
            printf("Time after updation is: "); display(&T1);
            break;

            case 4: 
            printf("Enter time 1: \n");
            read(&T2);
            printf("Enter time 2: \n");
            read(&T3);
            printf("Time 1 is: "); display(&T2);
            printf("Time 2 is: "); display(&T3);
            T4=add(&T2,&T3);
            printf("The time after adding T1 and T2 is ");
            display(&T4);
            break;

            case 5:
            printf("Exiting...\n");
            exit(0);

            default: printf("Invalid choice\n");
        }
    }
}
