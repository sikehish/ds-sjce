#include<stdio.h>
#include<stdlib.h>

// https://stackoverflow.com/questions/18496282/why-do-i-get-a-label-can-only-be-part-of-a-statement-and-a-declaration-is-not-a
// GOT THIS ERROR

typedef struct DISTANCE{
    int meter,centimetre;
}dis;

dis read(dis);
void write(dis);
dis add(dis*, dis*);

int main(){
    dis d1,d2,d3;
    dis(*ptr)();
    int choice;

    while(1){
        printf("Enter the choice\n 1.Read\n 2.Display\n 3.Add\n 4.Exit\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                    d1=read(d1);
                    d2=read(d2);
                    break;
            case 2:
                    write(d1);
                    write(d2);
                    break;
            case 3:
                    ptr=add;
                    d3=ptr(&d1,&d2);
                    write(d3);

                    break;
            case 4: 
                    printf("Exiting..");
                    exit(0);
            default: printf("Invalid choice. Try again\n");
        }

    }

}

dis read(dis d){
    printf("Enter the distance in meter\n");
    scanf("%d",&d.meter);
    printf("Enter the distance in centimetre\n");
    scanf("%d",&d.centimetre);
    return d;
}

void write(dis d){
    printf("The distance is: %dm and %dcm\n",d.meter,d.centimetre);
}

dis add(dis* a, dis* b)
{
    dis d3;
    d3.meter=a->meter+b->meter;
    d3.centimetre=a->centimetre+b->centimetre;

    if(d3.centimetre>=100) {
        d3.meter+=(d3.centimetre/100);
        d3.centimetre%=100;
    }

    return d3;
}

