#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#define SIZE 200

struct node *create_node(int day,int month,int year,char note[225]);
struct qnode *qcreate_node(int day,int month,int year,float stime,float etime,char sch_name[SIZE]);
void delete(char key[255]);
void enque(int day,int month,int year,float stime,float etime,char sch_name[]);
void deque(int j);
int isLeapYear( int y );
int leapYears( int y );
int todayOf( int y, int m, int d);
long days( int y, int m, int d);
void addNote(int day,int month,int year,char note[255]);
void displayNotes();
int checkSchedule(struct qnode *front,float stime,float etime);
void availableSchedule(struct qnode *front);
void printCalender(int m,int y);
struct qnode* SortedMerge(struct qnode* a, struct qnode* b);
void partition(struct qnode* source,struct qnode** frontRef, struct qnode** backRef);
void MergeSort(struct qnode** headRef);
void printqueue(int j);
void addSchedule(int d,int m,int y);

struct node {
  int day;
  int month;
  int year;
  char note[255];
	struct node *next;
};
struct qnode {//queue using linked list
  float stime,etime;
  int day,month,year;
  char sch_name[SIZE];//schedule_name
  struct qnode *next;
};

struct ll {
	struct node *start;
}s;
struct node *ptr;
struct qq {
  struct qnode *front;
  struct qnode *rear;
}q[SIZE];

int i=-1;

struct node *create_node(int day,int month,int year,char note[225])  {
	struct node *new_node=(struct node *)malloc(sizeof(struct node));
	new_node->day=day;
  new_node->month=month;
  new_node->year=year;
  strcpy(new_node->note,note);
	new_node->next=NULL;
	return(new_node);
}
struct qnode *qcreate_node(int day,int month,int year,float stime,float etime,char sch_name[SIZE]) {
	struct qnode *new_node=(struct qnode *)malloc(sizeof(struct qnode));
  new_node->day=day;
  new_node->month=month;
  new_node->year=year;
	new_node->stime=stime;
  new_node->etime=etime;
  strcpy(new_node->sch_name,sch_name);
	new_node->next=NULL;
	return(new_node);
}

void delete(char key[255])  {
  struct node *ptr,*preptr;
  ptr=s.start; preptr=NULL;
	if (s.start==NULL)
		printf("list is empty");

	else{

		while(ptr!=NULL)  {
			if (strcmp(key,ptr->note)==0)	{
				if (ptr->next==NULL&&preptr!=NULL)  {
					preptr->next=NULL;
          free(ptr);
				}
				else if (ptr==s.start&&ptr->next==NULL) {
					s.start=NULL;
          free(ptr);
				}
				else if (ptr==s.start)  {
					s.start=ptr->next;
          free(ptr);
				}
			 	else {
					preptr->next=ptr->next;
          free(ptr);
				}
			}
			if(ptr!=NULL) {
        preptr=ptr;
  		  ptr=ptr->next;
      }
		}return;
  }
}

void enque(int day,int month,int year,float stime,float etime,char sch_name[]) {
  struct qnode *new_node=qcreate_node(day,month,year,stime,etime,sch_name);
  if (q[i].rear==NULL) {
    q[i].rear=q[i].front=new_node;
  }
  else  {
    q[i].rear->next =new_node;
    q[i].rear=new_node;
  }
}

void deque(int j)  {//one condition is remaining
  struct qnode *temp;
  int k;
  if (q[j].rear==NULL) {
    printf("queue is empty");
  }
  else if(q[j].rear==q[j].front)  {
    q[j].front=NULL;
    q[j].rear=NULL;
    for(k=j;k<i;k++) {
      q[k].front=q[k+1].front;
      q[k].rear=q[k+1].rear;
      q[k+1].front=NULL;
      q[k+1].rear=NULL;
    }
    i--;
    printf("now your schedule is EMPTY\t ENJOY!!\n\n");
  }
  else {
    temp=q[j].front;
    q[j].front=q[j].front->next;
    free(temp);
    printqueue(j);

  }
}

int isLeapYear( int y ){
    return(y % 400 == 0) || ((y % 4 == 0) && (y % 100 != 0));
}

int leapYears( int y ){
    return y/4 - y/100 + y/400;
}

int todayOf( int y, int m, int d) {
    static int DayOfMonth[] =
        { -1,0,31,59,90,120,151,181,212,243,273,304,334};
    return DayOfMonth[m] + d + ((m>2 && isLeapYear(y))? 1 : 0);
}
long days( int y, int m, int d){
    int lastYear;
    lastYear = y - 1;
    return 365L * lastYear + leapYears(lastYear) + todayOf(y,m,d);
}

void addNote(int day,int month,int year,char note[255])  {
  struct node* n=create_node(day,month,year,note);
  if (s.start==NULL)  {
    s.start=n;
    ptr=n;
  }
  else  {
    ptr->next=n;
    ptr=ptr->next;
  }
}
void displayNotes() {
  if (s.start==NULL)  printf("no notes to display\n");
  else  {
    printf("here are your notes\nDAY\tMONTH\tYEAR \t\tNOTES\n");
    for(struct node *str=s.start;str!=NULL;str=str->next) {
      printf("%d\t%d\t%d \t\t%s\n",str->day,str->month,str->year,str->note);
    }
  }
  printf("\n\n");
}

int checkSchedule(struct qnode *front,float stime,float etime) {
  struct qnode *ptr=front;
  while(ptr!=NULL&&(stime!=ptr->stime&&(stime>ptr->etime||stime==ptr->etime||(stime<ptr->stime&&etime<=ptr->stime))))  {
    ptr=ptr->next;
  }
  if (ptr==NULL) return 1;
  else return 0;
}
void availableSchedule(struct qnode *front) {
  struct qnode *ptr=front;
  float avtime[SIZE]={0};
  avtime[0]=1;
  int i=1;
  while(ptr!=NULL)  {
    avtime[i]=ptr->stime;
    avtime[i+1]=ptr->etime;
    i+=2;
    ptr=ptr->next;
  }
  avtime[i]=24.00;
  for(int i=0;avtime[i]!=0;i+=2)  {
    if(avtime[i]!=avtime[i+1])  {
    printf("%0.2f--%0.2f \t",avtime[i],avtime[i+1]);
    }
  }
  printf("\n");
}


void printCalender(int m,int y) {
  const char *NameOfMonth[] = { NULL,
      "January", "February", "March", "April", "May", "June",
      "July", "August", "September", "October", "November", "December"
  };
  char Week[] = "Su   Mo   Tu   We   Th   Fr   Sa";
  int DayOfMonth[] =
      { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
  int weekOfTopDay = days(y, m, 1) % 7;
  int t=weekOfTopDay;
  printf("\n     %s %d\n%s\n", NameOfMonth[m], y, Week);
  for(int i=0;i<weekOfTopDay;i++)
    printf("     ");
    for(int i=0;i<DayOfMonth[m];i++) {
    if (i<9)
    printf("%d    ",i+1);
    else
    printf("%d   ",i+1);
    t++;
    if(t==7||t==14||t==21||t==28||t==35) printf("\n");
  }
  printf("\n");
}
struct qnode* SortedMerge(struct qnode* a, struct qnode* b) {
  struct qnode* result = NULL;
  if (a == NULL)
    return(b);
  else if (b==NULL)
    return(a);
  if (a->stime <= b->stime) {
    result = a;
    result->next = SortedMerge(a->next, b);
  }

  else  {
    result = b;
    result->next = SortedMerge(a, b->next);
  }
  return(result);
}

void partition(struct qnode* source,struct qnode** frontRef, struct qnode** backRef) {
    struct qnode* fast;
    struct qnode* slow;
    slow = source;
    fast = source->next;
    while (fast != NULL)  {
      fast = fast->next;
      if (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
      }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}


void MergeSort(struct qnode** headRef) {
  struct qnode* head = *headRef;
  struct qnode* a;
  struct qnode* b;
  if ((head == NULL) || (head->next == NULL)) {
    return;
  }
  partition(head, &a, &b);
  MergeSort(&a);
  MergeSort(&b);
  *headRef = SortedMerge(a, b);
}

void printqueue(int j) {
  if(q[j].rear==NULL)  {
    printf("Schedule is empty\n");
  }
  else  {
    struct qnode *node=q[j].front;
    MergeSort(&node);
    printf("\t %d--%d--%d\n",node->day,node->month,node->year);
    while(node!=NULL)  {
      printf("%0.2f-%0.2f\t\t%s\n",node->stime,node->etime,node->sch_name);
      node=node->next;
    }
    printf("\n\n");
  }
  return;
}

void addSchedule(int d,int m,int y) {//schedule a day(queue using LL)
  int choice=1,check=1;

  while(choice==1)  {
    printf("enter name of schedule\n");
    char sch_name[SIZE]; scanf("%s",sch_name);
    printf("enter starting time of event in 24 hrs format\n");
    float stime; scanf("%f",&stime);
    printf("enter end time of event in 24 hrs format\n");
    float etime; scanf("%f",&etime);
    if (etime<=stime)  {
      printf("end time of event should be greater than start time");
      while(etime<=stime) {
        printf("enter end time of event in 24 hrs format\n");
        scanf("%f",&etime);
      }
    }
    if(q[i].rear!=NULL)  check=checkSchedule(q[i].front,stime,etime);

    if(check==0) {
      printf("this timining slot is FULL\n These are available slots");
      availableSchedule(q[i].front);
    }
    else  {
      enque(d,m,y,stime,etime,sch_name);
      printf("To continue adding press 1\n");
      scanf("%d",&choice);
    }
  }
  printqueue(i);
}





int main()  {
  s.start=NULL;
  for(int i=0;i<SIZE;i++) {
    q[i].front=NULL;
    q[i].rear=NULL;
  }
  struct qq *ptr=&q[0];

  int day,month,year;
  char choice,note[255];
  int deq,k,kt,flag=0;
  int choice2;
  int hours,min,sec,dAy,mOnth,yEar;
  time_t now;
  time(&now);
  struct tm *local=localtime(&now);
  hours=local->tm_hour;
  min=local ->tm_min;
  sec=local->tm_sec;
  dAy=local->tm_mday;
  mOnth=local->tm_mon+1;
  yEar=local->tm_year+1900;
  if (hours<12) printf("TIme is %02d:%02d:%02dam\n",hours,min,sec);
  else printf("TIme is %02d:%02d:%02dpm\n\n",hours-12,min,sec);
  printf("Date is %02d:%02d:%d\n\n\n",dAy,mOnth,yEar);
  while (1) {
    printf("1. Print calendar of a month and schedule your day\n");//complete but correction remaining at checksc
    printf("2. mark your schedule as done\tyou cannot press 2 without adding schedule\n");//complete
    printf("3. print your schedules\n");//complete
    printf("4. Add Important Note\n");//complete
    printf("5. display Important Notes\n");//complete
    printf("6. delete an added note \n");//complete
    printf("7. EXIT\n");
    printf("Enter your choice: \n");
    scanf("\n%c", &choice);
    switch (choice) {
      case '1':
      printf("Enter the month and year: ");
      scanf("%d %d", &month, &year);
      if (month>12)
        printf("incorrect date\n");
      else  {
        printCalender(month,year);
        printf("press 1 to schedule your day\t");
        scanf("%d",&choice2);
        if (choice2==1) {
          printf("enter the day on which schedule is to be added\n");
          scanf("\n%d",&day);
          if (day>31) {
            printf("sorry but there are atmost 31 days in a month\n");
            while (day>31)  {
              printf("enter day again\n");
              scanf("\n%d",&day);
            }
          }
          i++;
          if (year<(yEar-2000)||(year==(yEar-2000)&&month<mOnth)||(year==(yEar-2000)&&month==mOnth&&day<dAy))  {
            printf("cannot schedule past day or incorrect date\n\n");
          }
          else addSchedule(day,month,year);
        }
      }
      break;
      case '2':
      printf("here is YOUR  TODAYS SCHEDULE\n\n");
      if (q[0].front==NULL) printf("you dont have any schedules\n");
      else  {
      for(k=0;k<=i;k++) {
        if(q[k].front->day==dAy&&q[k].front->month==mOnth&&q[k].front->year==(yEar-2000)) {
          flag=1;
          break;
        }
      }
        if(k>i) k=i;
        if (flag==0) printf("you have no schedules for today\n\n\n");
        else  {
          printqueue(k);
          printf("\thow many task/s you want to mark as done\t");
          scanf("%d",&deq);
          for(int j=0;j<deq;j++)  {
              deque(k);
          }
          flag=0;
        }
      }
      break;
      case '3':
      for(int j=0;j<=i;j++)  {
        printqueue(j);
      }
      break;
      case '4':
      printf("enter the day month and year on which note is to be added\t");
      scanf("%d %d %d",&day,&month,&year);
      if (day>31||month>12||year<(yEar-2000)||(year==(yEar-2000)&&month<mOnth)||(year==(yEar-2000)&&month==mOnth&&day<dAy))
        printf("incorrect or past date\n");
      else  {
        printf("enter NOTE\n");
        scanf("%s",note);
        addNote(day,month,year,note);
        printf("note added at date %d %d is %s\n",day,month,note);
      }
      break;
      case '5':
      displayNotes();
      break;
      case '6':
      displayNotes();
      printf("enter the note you want to delete\t");
      char del_note[255];
      scanf("%s",del_note);
      delete(del_note);
      break;
      case '7':
      exit(1);
    }
  }
}
