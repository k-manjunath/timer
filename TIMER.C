/*
Implementation of a timer
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
typedef struct time Time;
struct time{
	int hours;
	int mins;
	int secs;
};

Time decrease_time(Time*);
Time setTime(void);
void printTime(Time);
int isZero(Time);

int main()
{
	Time* timer = (Time*)malloc(sizeof(Time));
	Time displayTime;
	clrscr();
	*timer = setTime();
	displayTime = *timer;
	while(!isZero(displayTime))
	{
		clrscr();
		printTime(displayTime);
		displayTime = decrease_time(timer);
		delay(1000);
	}
	if(isZero(*timer))
	{
		printf("\n\n\n\n\t\t\t\tThe time is Up :)\a");
	}

	getch();

	return 0;
}
Time decrease_time(Time* t)
{
	//time timeToReturn;

	if((t->secs) == 0)
	{
		if(t->mins == 0)
		{
			if(t->hours == 0)
			{
				//timeToReturn = t;
				return *t;
			}
			else
			{
				t->hours -= 1;
				t->mins = 59;
				t->secs = 59;

				//timeToReturn = t;
				return *t;
			}
		}
		else
		{
			t->mins -= 1;
			t->secs = 59;

			//timeToReturn = t;
			return *t;
		}
	}
	else
	{
		t->secs -= 1;

//		timeToReturn = t;
		return *t;
	}
}
Time setTime(void)
{
	Time input;
	printf("\t\t\t\tTIMER\n");
	printf("\t\tAll times are in HH:MM:SS format\n");
	printf("Set the time in Timer: ");
	scanf("%d:%d:%d",&(input.hours),&(input.mins),&(input.secs));

	return input;
}
void printTime(Time t)
{
	printf("Time Remaing:%.2d:%.2d:%.2d\n",t.hours,t.mins,t.secs);
}
int isZero(Time t)
{
	if(t.secs == 0 && t.mins == 0 && t.hours == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}