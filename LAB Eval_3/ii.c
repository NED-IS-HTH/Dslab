// finding the first non- repeating element in an integer queue

#include <stdio.h>
#include <stdlib.h>

void finder(int queue[],int F,int R)
{
    int count=1;
    if (F==-1 && R==-1)
    {
        printf("The queue is empty\n");
        return;
    }
    else if(F==R)
    {
        printf("%d ",queue[F]);
        return;
    }
    for(int i=F; i<=R; i--)
    {
        for(int j=F; j<=R; j++)
        {
            if(queue[i]==queue[j] && i!=j)
            {
                count++;
                break;
            }    
        }
        if(count==1)
        {
            printf("The first non-repeating element is %d\n",queue[i]);
            return;
        }
    }
}

int main()
{
    int queue[10],F=-1,R=-1;

    for(int i=0; i<10; i++)
    {
        queue[i]=rand()%100;
        if(F==-1)
            F=0;
        R=i;
    }
    printf("The queue is:\n");
    for(int i=F; i<=R; i++)
    {
        printf("%d ",queue[i]);
    }
    printf("\n");

    finder(queue,F,R);
    return 0;
}