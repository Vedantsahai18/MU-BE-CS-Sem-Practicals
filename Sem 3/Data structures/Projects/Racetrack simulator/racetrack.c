/* *****NOTE*******

for some reason, using Windows gcc compiler causes glitches when displaying driver names, doesn't properly read null chars, displays garbage values. use linux gcc to see perfect results, or look at the screen caps in report.pdf, that's how it's supposed to look like.

*/

#include<stdio.h>
#include<stdlib.h>

	//CAR structure
	
	struct node
	{
		int carNum;
		int rank,posn;
		float topSpeed, handling;
		char driver[20];
		struct node *next,*prev;
	};
	 
	struct node *start; 
	float time=0;			//track params
	int lapLen=6,lapFac=1,laps=6,dev=0,goBack=0;
	FILE *fp;
	
	
	//LINKED LIST FUNCTIONS
	
	void init()							//initialise list
	{
		start=NULL; 
	}
	
	void disp()							//display racer board (list)
	{
		struct node *p;
		p=start;
		
		if(start==NULL)
		{
			printf("\nNO CARS SELECTED");
			return;
		}
		
		printf("\n");
		while(p!=NULL)						//repeat till last node
		{
			printf("%d  RANK=%d",p->posn,p->rank);		//print info part
			
			if(p->rank/10==0)			//extra space
				printf(" ");
			printf("  (%d) ",p->carNum);
			puts(p->driver);
			
			if(dev==1)
				printf("   %d  %d  %d\n\n",p->prev,p,p->next);  //debug command; to check pointers
			
			p=p->next;
		}
	}
	 
	void ins(int carNum, int rank, float topSpeed, float handling, char driver[])
	{	
		if(dev==1)
			fprintf(fp,"\nENTER ins()\n");
		
		struct node *new;
		new = (struct node *)malloc(sizeof(struct node));
		int i;
		
		new->carNum=carNum;
		new->rank=rank;
		new->topSpeed=topSpeed;
		new->handling=handling;
		for(i=0;driver[i]!='\0';i++)
			new->driver[i]=driver[i];
		new->next=NULL;
		
		if(start==NULL)
		{
			new->prev=NULL;
			new->posn=1;
			start=new;							//make start point to new node
		}
			
		else	
		{	
			struct node *p;
		
			p=start;
		
			while(p->next != NULL)				//traverse to last node 
				p=p->next;
		
			p->next=new;	
			new->prev=p;
			new->posn=p->posn+1;
		}
		if(dev==1)
			fprintf(fp, "EXIT ins()\n");
	}
	 
	void del_bg()
	{
		if(dev==1)
			fprintf(fp, "\nENTER del_bg()\n");
		struct node *p;
		p=start;
		
		start=start->next;					//make start point to second node
		if(start!=NULL)
			start->prev=NULL;
		
		free(p);
		
		printf("  REMOVED");
		
		p=start;
		while(p!=NULL)
		{
			p->posn--;
			p=p->next;
		}
		if(dev==1)
			fprintf(fp, "\nEXIT del_bg()\n");
	}
	 
	void del_en()
	{
		if(dev==1)
			fprintf(fp, "\nENTER del_en()\n");
		struct node *p;
		p=start;
		
		while(p->next!=NULL)			//traverse to last node
			p=p->next;
		
		(p->prev)->next=NULL;			//make 'next' of last, NULL
		
		free(p);
		
		printf("  REMOVED");
		if(dev==1)
			fprintf(fp, "\nEXIT del_en()\n");
	}
	 
	void del(int x)
	{
		if(dev==1)
			fprintf(fp, "\nENTER del()\n");
		int f;
		struct node *p;
		p=start;
		
		if(p==NULL)
			goto yo;
			
		while(p->carNum!=x)
		{
			p=p->next;
			if(p==NULL)
				 break;	
		}
	
yo:		if(p==NULL)							//if entire list is traversed
	  	{
	  		printf("\nCar not yet added. Could not remove\n");
	  		return;
	  	}
	  	
	  	else if(start==p)
	  	{
	  		del_bg();
	  		return;
	  	}
	  	
	  	else if(p->next==NULL)
	  	{
	  		del_en();
	  		return;
	  	}
	  
		else
		{
			f=p->posn;
		
			p->prev->next=p->next;			//replace next field and insert
			p->next->prev=p->prev;
		
			free(p);
			
			p=start;
			
			while(p->posn!=f+1)
			{
				p=p->next;
			}
			
			while(p!=NULL)
			{
				p->posn--;
				p=p->next;
			}
			printf("  REMOVED");
		}
		if(dev==1)
			fprintf(fp, "\nEXIT del()\n");
	}
	 
	int numMembers()		// count no. of members in list
	{
		int n=0;
		struct node *p;
		p=start;
		while(p!=NULL)
		{
			p=p->next;
			n++;
		}
		return n;
	}
	
	
	//RACETRACK FUNCTIONS
	
	float overtakeFactor(int r, int ps, float sp, float h, int m)		//decides whether to overtake or no
	{
		if(lapFac%3==0)
			return (sp+m)*time;
		else if(lapFac%3==1)
			return m/(r+ps);
		else
			return h/m;
	}
	
	void overtake(int ps)			//swaps cars in laps
	{
		if(dev==1)
			fprintf(fp, "\nENTER overtake()\n");
		struct node *p;
		p=start;
		
		int t;
		struct node *car1,*car2;
		
		while(p->posn!=ps)
			p=p->next;
		
		t=p->posn;
		p->posn=p->prev->posn;
		p->prev->posn=t;
		
		car2=p;					//car-swap logic
		car1=p->prev;
		
		if(p->prev->prev!=NULL)
			p->prev->prev->next=car2;
		else
			start=p;
		
		if(p->next!=NULL)
			p->next->prev=car1;
		
		car2->prev=car1->prev;
		car1->prev=p;
		
		car1->next=car2->next;
		car2->next=car1;
		
		if(dev==1)
			fprintf(fp, "EXIT overtake()\n");
	}
	
	void sortSel()				//sort current selection as per rank
	{
		if(dev==1)
			fprintf(fp, "\nENTER sortSel()\n");
		int b,i;
		struct node *p;
		p=start;
		
		if(start==NULL || start->next==NULL)
		{
			if(dev==1)
				fprintf(fp, "EXIT sortSel()\n");
			return;
		}
		
		while(p!=NULL && p->next!=NULL)
			p=p->next;
		
		b=p->posn;
		for(i=b;i>0;i--)
		{
			p=start;
			while(p->next!=NULL)
			{
				if(p->rank > p->next->rank)
					overtake(p->next->posn);
				p=p->next;
				if(p==NULL)
					break;
			}
		}	
		if(dev==1)
			fprintf(fp, "EXIT sortSel()\n");
	}
	
	void instructions()
	{
		printf("\n   THE PISTON CUP\n   ----------------\n");
		printf("    This program is a racetrack simulator that is meant\n  solely for recreational purposes and does not have any\n  real world use\n\n");
		printf("  HOW TO USE\n1.Choose from a list of available cars with\n  completely made-up data and statistics");
		printf("\n2.Choose lap settings and track settings");
		printf("\n3.View next lap by pressing ENTER\n4.Wait for the race to complete and see which car won");
		printf("\n\n  Alternatively, you can bet on a car at the beginning of the race\nwith real world money and challenge your friends for the same,\nso if you think 'bout it, this program isn't completely useless\n");
		printf("\n  Press ENTER to return to MAIN MENU");
		getchar();
		return;
	}
	
	int isPresent(int c)		//is car already selected
	{
		struct node *p;
		p=start;
		while(p!=NULL)
		{
			if(p->carNum==c)
				return 1;
			p=p->next;
		}
		return 0;
	}
	
	void printName(char a[])	//print Last name of racer
	{
		int i=0;
		while(a[i]!=' ')
			i++;
		while(a[i]!='\0')
		{
			printf("%c",a[i]);
			i++;
		}
	}
	
	int nameLen(char a[])		//timepass func; temporary use; 
	{
		int i=0,j=0;
		while(a[i]!=' ')		//calculates spaces... 
			i++;
		while(a[i]!='\0')		
		{						//...after racer's name... 
			i++;
			j++;
		}						//...in 2nd line of results
		return j;
	}
	
	int reverseNum(int n)
	{
		int r,d=0;
		while(n!=0)
		{
			r=n%10;
			d=10*d+r;
			n=n/10;
		}
		return d;
	}
	
	int ptrToRandom(int p)			//generate random 3-digit int using pointer
	{
		int t;
		t=reverseNum(p);
		while(t/1000>0)
		{
				t=t/10;
		}
		return reverseNum(t);
	}
	
	void selectCars()		// *deep narrator voice* CHOOSE YOUR DRIVERS
	{
		init();
		int car;
		char op;
		printf("\n  CHOOSE YOUR DRIVERS\n");
ros:		printf("\nCAR no.\tDRIVER\t\tNAT.\tRANK\tTOP SPEED\tHANDLING");
		printf("\n--------------------------------------------------------------------");
		printf("\n18\tPerry Wilson\tUK\t27\t150.67\t\t225.6");
		printf("\n25\tEnrico Midas\tITA\t2\t220.7\t\t197.4");
		printf("\n35\tMakunto Izichi\tJPN\t14\t201.4\t\t179.1");
		printf("\n42\tEvery Douglas\tUK\t7\t224.4\t\t168.71");
		printf("\n46\tJeremiah Muller\tNZL\t36\t178.3\t\t167.4");
		printf("\n53\tGanesh Gaitonde\tIND\t69\t180.8\t\t150.55");
		printf("\n69\tDikim Auth\tIRL\t45\t187.4\t\t170.87");
		printf("\n72\tJudas Ingot\tBRA\t55\t140.3\t\t172.54");
		printf("\n89\tMaxim Lincoln\tUSA\t33\t181.3\t\t199.4");
		printf("\n97\tLouis Auk\tRUS\t16\t210.5\t\t189.9");
		
sel:	printf("\n\n  CHOOSE ACTION\n    1. Add cars\n    2. Remove cars\n    3. View current selection\n    4. Show roster again\n    5. Race now                                          (BACK=0)\n    ");
		
		
		scanf("%d",&op);
		
		if(op==1)
		{
			/* printf("\n(Enter 0 to return to previous menu)\n"); */
add:		printf("\nEnter CAR no.   ");
			scanf("%d",&car);
			
			if(isPresent(car)==1)
			{
				printf("\nCar already added. Could not add again\n");
				goto add;
			}
			
			switch(car)
			{
				case 18: ins(18,27,150.67,225.6,"Perry Wilson"+'\0');break;
				case 25: ins(25,2,220.7,197.4,"Enrico Midas"+'\0');break;
				case 35: ins(35,14,201.4,179.1,"Makunto Izichi"+'\0');break;
				case 42: ins(42,7,224.4,168.71,"Every Douglas"+'\0');break;
				case 46: ins(46,36,178.3,167.4,"Jeremiah Muller"+'\0');break;
				case 53: ins(53,69,180.8,150.55,"Ganesh Gaitonde"+'\0');break;
				case 69: ins(69,45,187.4,170.87,"Dikim Auth"+'\0');break;
				case 72: ins(72,55,140.3,172.54,"Judas Ingot"+'\0');break;
				case 89: ins(89,33,181.3,199.4,"Maxim Lincoln"+'\0');break;
				case 97: ins(97,16,210.5,189.9,"Louis Auk"+'\0');break;
				
				case 0: goto sel;break;
				default: printf("\nSorry, that car is not available in our roster\nPlease choose a car from the list given\n");goto add; break;
			}
			sortSel();
			printf("  ADDED");
			goto add;
		}
		
		if(op==2)
		{
			/* printf("\n(Enter 0 to return to previous menu)\n"); */
rem:		printf("\nEnter CAR no.   ");
			scanf("%d",&car);
			if(car==0)
				goto sel;
			else
			{
				del(car);
				sortSel();
				goto rem;
			}
		}
		
		if(op==3)
		{
			disp();
			goto sel;
		}
		
		if(op==4)
		{
			goto ros;
		}
		
		if(op==5)
		{
			if(numMembers()<3)
			{
				printf("\nThis isn't Hot Wheels. Select atleast 3 racers");
				goto sel;
			}
			
			if(numMembers()>8)
			{
				printf("\nYou are racing with too many cars\nSwitch to a larger window size now, to avoid text wrapping\n");
				printf("\nPress ENTER to continue");
				getchar();
				getchar();
			}
			
			return;
		}
		
		if(op==0)
		{
			goBack=1;
			return;
		}
		
		if(op!=1&&op!=2&&op!=3&&op!=4&&op!=5)		// extra else coz goto f***s with menus
		{
			printf("\nPlease enter valid choice");
			goto sel;
		}
	}
	
	void selectLaps()
	{
		int l,len;
lap:	printf("\nNumber of laps? (MAX is 15)   ");
		scanf("%d",&l);
		if(l>15)
		{
			printf("Yer a rebel. I like you. lol jk. Now do as I say\n");
			goto lap;
		}
		else
			laps=l;
		
len:	printf("\nLength of lap? (between 6-18 km)  ");
		scanf("%d",&len);
		if(6<=len && len<=18)
			lapLen=len;
		else
		{
			printf("\nChoose a realistic lap length mate!\n");
			goto len;
		}
	}
	
	void lap()
	{
		struct node *p;
		p=start;
		
		while(p->next!=NULL)
		{
			if(overtakeFactor(p->rank,p->posn,p->topSpeed,p->handling,ptrToRandom((int)p)) < overtakeFactor(p->next->rank,p->next->posn,p->next->topSpeed,p->next->handling,ptrToRandom((int)p->next)))
			{
				overtake(p->next->posn);
				if(p==NULL || p->next==NULL)
					break;
			}
			p=p->next;
		}
		lapFac++;
		time=time+(lapLen/(p->topSpeed))*60+(ptrToRandom((int)p)/100);			//  time=dist/speed  ;P
	}
	
	void dispLap()
	{
		printf("\n");  
		struct node *p;
		
			p=start;		//upper track bound
			printf("   ");
			while(p!=NULL)
			{
				printf("========");
				p=p->next;
			}	
			printf("\n");
			
		
		//print odd posn cars
		
			p=start;
			printf("    ");
			while(p!=NULL)
			{
				printf("  _    _     ");
				p=p->next;
				if(p!=NULL && p->posn%2==0 && p->next!=NULL)
					p=p->next;
				
				if(p!=NULL && p->posn%2==0  && p->next==NULL)
					break;
			}	
			printf("\n");
		
			p=start;
			printf("    ");
			while(p!=NULL)
			{
				printf(" / |  | |    ");
				p=p->next;
				if(p!=NULL && p->posn%2==0 && p->next!=NULL)
					p=p->next;
				
				if(p!=NULL && p->posn%2==0  && p->next==NULL)
					break;
			}	
			printf("\n");
		
			p=start;
			printf("    ");
			while(p!=NULL)
			{
				printf("<---");
				printf("%d",(p->carNum));		//print info part
				printf("-(     ");
				p=p->next;
				if(p!=NULL && p->posn%2==0 && p->next!=NULL)
					p=p->next;
				
				if(p!=NULL && p->posn%2==0  && p->next==NULL)
					break;
			}	
			printf("\n");
		
			p=start;
			printf("    ");
			while(p!=NULL)
			{
				printf(" \\_|  |_|    ");
				p=p->next;
				if(p!=NULL && p->posn%2==0 &&  p->next!=NULL)
					p=p->next;
				
				if(p!=NULL && p->posn%2==0  && p->next==NULL)
					break;
			}	
			printf("\n");
		
		//print even posn cars
		
			p=start;
			p=p->next;
			printf("          ");
			while(p!=NULL)
			{
				printf("  _    _     ");
				p=p->next;
				if(p!=NULL && p->posn%2==1 && p->next!=NULL)
					p=p->next;
				
				if(p!=NULL && p->posn%2==1  && p->next==NULL)
					break;
			}	
			printf("\n");
		
			p=start;
			p=p->next;
			printf("          ");
			while(p!=NULL)
			{
				printf(" / |  | |    ");
				p=p->next;
				if(p!=NULL && p->posn%2==1 && p->next!=NULL)
					p=p->next;
				
				if(p!=NULL && p->posn%2==1  && p->next==NULL)
					break;
			}	
			printf("\n");
		
			p=start;
			p=p->next;
			printf("          ");
			while(p!=NULL)
			{
				printf("<---");
				printf("%d",(p->carNum));		//print info part
				printf("-(     ");
				p=p->next;
				if(p!=NULL && p->posn%2==1 && p->next!=NULL)
					p=p->next;
				
				if(p!=NULL && p->posn%2==1  && p->next==NULL)
					break;
			}	
			printf("\n");
		
			p=start;
			p=p->next;
			printf("          ");
			while(p!=NULL)
			{
				printf(" \\_|  |_|    ");
				p=p->next;
				if(p!=NULL && p->posn%2==1 &&  p->next!=NULL)
					p=p->next;
				
				if(p!=NULL && p->posn%2==1  && p->next==NULL)
					break;
			}	
			printf("\n");
		
		
			p=start;		//lower track bound
			printf("\n   ");
			while(p!=NULL)
			{
				printf("========");
				p=p->next;
			}	
			printf("\n\n");  
	}
	
	/*  vroom vroom
		  _    _
		 / |  | |
		<---42-(
		 \_|  |_|
	
	*/
	
	// printing results stand;   badass func;   take note;   DO-NOT-MODIFY;
	void results()
	{
		int i;
		struct node *p;
		p=start;
		printf("\n                     /\\        /\\");
		printf("\n                    // \\      / \\\\ ");
		printf("\n                   //   \\    /   \\\\ ");
		printf("\n                   \\   //\\  /\\\\   /");
		printf("\n                    \\ //  \\/  \\\\ /");
		printf("\n                     \\/   /\\   \\/");
		printf("\n                         /  \\");
		printf("\n\n    ~~~~~~~~~~~~~~~~~~~ RESULTS ~~~~~~~~~~~~~~~~~~~\n");
		printf("\n\n                    ");
		printName(p->driver);
		printf(" (%d)",p->carNum);
		p=p->next;
		printf("\n    		   _________________\n   ");
		printName(p->driver);
		printf(" (%d)",p->carNum);		// car num in brackets
		
		for(i=11-nameLen(p->driver);i>0;i--)
			printf(" ");
		
		p=p->next;	
		printf("|               |\n  _________________|       1       | ");
		printName(p->driver);
		printf(" (%d)",p->carNum);
		printf("\n  |                                |_________________\n  |       2                                         |\n  |                                         3       |\n\n");
		
	}
	/*
	                                          
 			                                 /\        /\
			                                // \      / \\
			                               //   \    /   \\
			                               \   //\  /\\   /
			                                \ //  \/  \\ /
			                                 \/   /\   \/
			                                     /  \
									   
	            		                ______________________
	                                   |                      |
	             ______________________|          1           |
	            |                                             |______________________
	            |          2                                                         |
	            |                                                        3           |
	
	*/
	
	void race()		// self explanatory.......meh
	{
		int i;
		
		selectCars();
		if(goBack==1)
			return;
		selectLaps();
		time=0;
		disp();
		if(dev==0)
		{
			dispLap();
			printf("\n     LAPS: %d\n",laps);
			printf("\n     Begin race? Press ENTER\n");
			getchar();
			getchar();			//extra getchar(), coz return statement in selectCars() sends ghost input;
		}
		lapFac=0;
		for(i=0;i<laps;i++)
		{
			lap();
			if(dev==0)
				dispLap();
			else
				disp();
			
			if(dev==0) printf("\n");
			printf("     LAP: %d/%d     TIME: %f min.\n",i+1,laps,time);
			
			if(dev==1) printf("\n");
			
			if(i==laps-1)
			{
				printf("\n\n");
				break;
			}
			if(dev==0)
			{
				printf("\n\n     Next lap? Press ENTER\n");
				getchar();
			}
		}
		if(dev==0)
			results();
		printf("  Race ended\n  Press ENTER to return to MAIN MENU");
		getchar();
	}
	
	void devmenu()
	{
		int lol;
		printf("\nEnter DEV mode? (yes/no) ");
		scanf("%d",&lol);
		if(lol!=5678)
			exit(0);
		dev=1;
		fp = fopen("console.txt","w+");
		printf("\nYou are now DEV\n");
	}
	
	void menu()
	{
		int op,fc=0;
		char c;
main:	if(dev==0)
		{
			printf("\n   ____________________________________________________________");
			printf("\n  |                                                            |");
			printf("\n  |                     WELCOME TO THE       	               |");
			printf("\n  |                                                            |");
			printf("\n  |    ___       ___   _____    ____                           |");
			printf("\n  |   |   \\  |  /        |     /    \\   |\\   |                 |");
			printf("\n  |   |___/  |  \\___     |     |    |   | \\  |                 |");
			printf("\n  |   |      |      \\    |     |    |   |  \\ |                 |");
			printf("\n  |   |      |   ___/    |     \\____/   |   \\|                 |");
			printf("\n  |                                                            |");
			printf("\n  |                               ____               ___       |");
			printf("\n  |                              /    \\   |    |    |   \\      |");
			printf("\n  |                              |        |    |    |___/      |");
			printf("\n  |                              |        |    |    |          |");
			printf("\n  |                              \\____/   \\____/    |          |");
			printf("\n  |                                                            |");
			printf("\n  |____________________________________________________________|");
			printf("\n");
		}
menu:	if(dev==1)
			printf("\n  DEV=1    (555 to view console)");
		printf("\n  MAIN MENU\n  1. Race     2. Instructions     3.Exit\n  ");
		scanf("%d",&op);
		
		switch(op)
		{
			case 1:
				
				race();
				goto main;
				break;
			case 2:
				instructions();
				getchar();
				goto main;
				break;
			case 3:
				printf("\n   THANK YOU FOR PLAYING\n   QUITTING...\n\n");
				if(dev==1)
					fclose(fp);
				exit(0);
				break;
			case -8637:
				devmenu();
				goto menu;
				break;
			case 555:
				rewind(fp);
				c = getc(fp);
				fc++;
				while (c!= EOF)
				{
					putchar(c);
					c = getc(fp);
					fc++;
				}
				fseek(fp,fc,SEEK_SET);
				goto menu;
				break;
			default:
				printf("\nENTER VALID OPTION\n");
				goto menu;
		}
	}
	
	/*
		________________________________________________________________________
	   |                                                                        |
	   |                           WELCOME TO THE       	                    |
	   |                                                                        |
	   |       ___       ___   _____    ____                                    |
	   |  	  |   \  |  /        |     /    \   |\   |                          |
	   |      |___/  |  \___     |     |    |   | \  |                          |
	   |      |      |      \    |     |    |   |  \ |                          |
	   |      |      |   ___/    |     \____/   |   \|                          |
	   |                                                                        |
	   |                                       ____               ___           |
	   |                                      /    \   |    |    |   \          |
	   |                                      |        |    |    |___/          |                             
	   |                                      |        |    |    |              |                              
	   |                                      \____/   \____/    |              |                             
	   |                                                                        |                               
	   |________________________________________________________________________|                                
	*/
	
	
	//MAIN... lol
	
	void main()
	{
		
		menu(); 
	
	}
