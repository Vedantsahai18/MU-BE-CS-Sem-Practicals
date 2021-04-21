#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
    char name[50];
    char *team;
    int apps;
    int goals;
    int assists;
    int yellow;
    int red;
    float val;
    struct node *next;
}plr;

plr *add(plr *start, int ch)
{
    char t [2];
    plr *ptr=start;
    plr *newplayer;
    newplayer=(struct node *)malloc(sizeof(struct node));
    newplayer->next=NULL;
    gets(t);
    if(ch == 1)
    {
        newplayer->team = "Mumbai City FC";
    }
    else if(ch == 2)
    {
        newplayer->team = "Jamshedpur FC";
    }
    else
    {
        newplayer->team = "ATK FC";
    }
    printf("Enter name of player:\n");
    gets(newplayer->name);
    printf("Enter number of appearances:\n");
    scanf("%d",&newplayer->apps);
    printf("Enter number of goals scored:\n");
    scanf("%d",&newplayer->goals);
    printf("Enter number of assists given:\n");
    scanf("%d",&newplayer->assists);
    printf("Enter number of yellow cards\n");
    scanf("%d",&newplayer->yellow);
    printf("Enter number of red cards\n");
    scanf("%d",&newplayer->red);
    newplayer->val = 0.5*newplayer->apps + 5*newplayer->goals + 3*newplayer->assists - newplayer->yellow - 2*newplayer->red;
    if(start==NULL)
    {
        start=newplayer;
        newplayer->next=NULL;
    }
    else
    {
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newplayer;
        newplayer->next=NULL;
    }// all new players are added at the end of last node
    return start;
}

void displayAll(plr *start)
{
    struct node *ptr=start;
    printf("Name | Apps | Goals | Assists | Yellow Cards | Red Cards | Value\n");
    while(ptr!=NULL)
    {
	printf("| %s |\n",ptr->team);        
	printf("%s | %d | %d | %d | %d | %d | %f \n", ptr->name,ptr->apps, ptr->goals, ptr->assists, ptr->yellow, ptr->red, ptr->val);
        printf("-----------------------\n");
        ptr=ptr->next;
    }
}
void display(plr *start, int ch)
{
    struct node *ptr=start;
    printf("Team | Apps | Name | Goals | Assists | Yellow Cards | Red Cards | Value\n");
    switch (ch)
    {
        case 1:
            {
                    while(ptr!=NULL)
                    {
                        if(strcmp(ptr->team, "Mumbai City FC") == 0)
                        {
                      	    printf("| %s |\n",ptr->team);      
		      	printf("%s | %d | %d | %d | %d | %d | %f \n", ptr->name, ptr->apps, ptr->goals, ptr->assists, ptr->yellow, ptr->red, ptr->val);
                            printf("-----------------------\n");
                            ptr=ptr->next;
                        }
                        else
                        {
                            ptr=ptr->next;
                        }
                    }
            }
            break;
            
        case 2:
        {
            while(ptr!=NULL)
            {
                if(strcmp(ptr->team, "Jamshedpur FC") == 0)
                {
                	 printf("| %s |\n",ptr->team);    
		 printf("%s | %d | %d | %d | %d | %d | %f \n", ptr->name, ptr->apps, ptr->goals, ptr->assists, ptr->yellow, ptr->red, ptr->val);
                    printf("-----------------------\n");
                    ptr=ptr->next;
                }
                else
                {
                    ptr=ptr->next;
                }
            }
            
        }
            break;
            
        case 3:
        {
            while(ptr!=NULL)
            {
                if(strcmp(ptr->team, "ATK FC") == 0)
                {
                     printf("| %s |\n",ptr->team); 
                    printf("%s | %d | %d | %d | %d | %d | %f \n", ptr->name, ptr->apps, ptr->goals, ptr->assists, ptr->yellow, ptr->red, ptr->val);
                    printf("-----------------------\n");
                    ptr=ptr->next;
                }
                else
                {
                    ptr=ptr->next;
                }
            }
            
        }
            break;
    }
    
}

plr *sortName(plr *start, plr *ptr)
{
    plr *current;
    /* Special case for the head end */
    if (start == NULL || strcmp(start->name, ptr->name) > 0)
    {
        ptr->next = start;
        start = ptr;
    }
    else
    {
        /* Locate the node before the point of insertion */
        current = start;
        while (current->next!=NULL && strcmp(current->name, ptr->name) < 0)
        {
            current = current->next;
        }
        ptr->next = current->next;
        current->next = ptr;
    }
    return start;
}

plr *sortApps(plr *start, plr *ptr)
{
    plr *current;
    /* Special case for the head end */
    if (start == NULL || (start)->apps < ptr->apps)
    {
        ptr->next = start;
        start = ptr;
    }
    else
    {
        /* Locate the node before the point of insertion */
        current = start;
        while (current->next!=NULL && current->next->apps > ptr->apps)

        {
            current = current->next;
        }
        ptr->next = current->next;
        current->next = ptr;
    }
    return start;
}

plr *sortGoals(plr *start, plr *ptr)
{
    plr *current;
    /* Special case for the head end */
    if (start == NULL || (start)->goals < ptr->goals)
    {
        ptr->next = start;
        start = ptr;
    }
    else
    {
        /* Locate the node before the point of insertion */
        current = start;
        while (current->next!=NULL && current->next->goals > ptr->goals)
        {
            current = current->next;
        }
        ptr->next = current->next;
        current->next = ptr;
    }
    return start;
}

plr *sortAssists(plr *start, plr *ptr)
{
    plr *current;
    /* Special case for the head end */
    if (start == NULL || (start)->assists < ptr->assists)
    {
        ptr->next = start;
        start = ptr;
    }
    else
    {
        /* Locate the node before the point of insertion */
        current = start;
        while (current->next!=NULL && current->next->assists > ptr->assists)
        {
            current = current->next;
        }
        ptr->next = current->next;
        current->next = ptr;
    }
    return start;
}

plr *sortYellow(plr *start, plr *ptr)
{
    plr *current;
    /* Special case for the head end */
    if (start == NULL || (start)->yellow < ptr->yellow)
    {
        ptr->next = start;
        start = ptr;
    }
    else
    {
        /* Locate the node before the point of insertion */
        current = start;
        while (current->next!=NULL && current->next->yellow > ptr->yellow)
        {
            current = current->next;
        }
        ptr->next = current->next;
        current->next = ptr;
    }
    return start;
}

plr *sortRed(plr *start, plr *ptr)
{
    plr *current;
    /* Special case for the head end */
    if (start == NULL || (start)->red < ptr->red)
    {
        ptr->next = start;
        start = ptr;
    }
    else
    {
        /* Locate the node before the point of insertion */
        current = start;
        while (current->next!=NULL && current->next->red > ptr->red)
        {
            current = current->next;
        }
        ptr->next = current->next;
        current->next = ptr;
    }
    return start;
}

plr *sortVal(plr *start, plr *ptr)
{
    plr *current;
    /* Special case for the head end */
    if (start == NULL || (start)->val < ptr->val)
    {
        ptr->next = start;
        start = ptr;
    }
    else
    {
        /* Locate the node before the point of insertion */
        current = start;
        while (current->next!=NULL && current->next->val > ptr->val)
        {
            current = current->next;
        }
        ptr->next = current->next;
        current->next = ptr;
    }
    return start;
}


plr *sort(plr *start, int a, int ch)
{
    // Initialize sorted linked list
    plr *sorted=NULL;
    
    // Traverse the given linked list and insert every
    // node to sorted
    plr *current = start;
     switch(a)
        {
            case 1:
            {
                while (current != NULL)
                {
                    plr *next = current->next;// Store next for next iteration
                    sorted=sortName(sorted, current);  // insert current in sorted linked list
                    current = next; // Update current
                }
                break;
            }
            
            case 2:
            {
                while (current != NULL)
                {
                    plr *next = current->next;// Store next for next iteration
                    sorted=sortApps(sorted, current);  // insert current in sorted linked list
                    current = next; // Update current
                }
                break;
            }
          
            case 3:
            {
                while (current != NULL)
                {
                    plr *next = current->next;// Store next for next iteration
                    sorted=sortGoals(sorted, current);  // insert current in sorted linked list
                    current = next; // Update current
                }
                break;
            }
                
            case 4:
            {
                while (current != NULL)
                {
                    plr *next = current->next;// Store next for next iteration
                    sorted=sortAssists(sorted, current);  // insert current in sorted linked list
                    current = next; // Update current
                }
                break;
            }
                
            case 5:
            {
                while (current != NULL)
                {
                    plr *next = current->next;// Store next for next iteration
                    sorted=sortYellow(sorted, current);  // insert current in sorted linked list
                    current = next; // Update current
                }
                break;
            }
                
            case 6:
            {
                while (current != NULL)
                {
                    plr *next = current->next;// Store next for next iteration
                    sorted=sortRed(sorted, current);  // insert current in sorted linked list
                    current = next; // Update current
                }
                break;
            }
                
            case 7:
            {
                while (current != NULL)
                {
                    plr *next = current->next;// Store next for next iteration
                    sorted=sortVal(sorted, current);  // insert current in sorted linked list
                    current = next; // Update current
                }
                break;
            }
                
        }
    
    
    // Update head_ref to point to sorted linked list
    start=sorted;
    if(ch < 4)
        display(start, ch);
    else
        displayAll(start);
    return start;
}

plr *teamRead(plr *start, int ch)
{
    int  chtm3, a;
    printf("Select\n1. To display players entered\n2. To sort by name\n3. To sort by number of appearances\n4. To sort by number of goals scored\n5. To sort by number of assists\n6. To sort by number of yellow cards\n7. To sort by number of red cards\n8. To sort by current market value\n9. To return\n");
    scanf("%d",&chtm3);
    switch(chtm3)
    {
        case 1:
        {
            a=1;
            start=sort(start, a, ch);
            break;
        }
        case 2:
        {
            a=1;
            start=sort(start, a, ch);
            break;
        }
        case 3:
        {
            a=2;
            start=sort(start, a, ch);
            break;
        }
        case 4:
        {
            a=3;
            start=sort(start, a, ch);
            break;
        }
        case 5:
        {
            a=4;
            start=sort(start, a, ch);
            break;
        }
        case 6:
        {
            a=5;
            start=sort(start, a, ch);
            break;
        }
        case 7:
        {
            a=6;
            start=sort(start, a, ch);
            break;
        }
        case 8:
        {
            a=7;
            start=sort(start, a, ch);
            break;
        }
        case 9:
        {
            break;
        }
        default:
        {
            printf("Please enter a valid choice\n");
        }
    }
    return start;
}


plr *addSelect(plr *start)
{
    int ch;
    printf("Select team\n");
    printf("1. Mumbai City FC\n");
    printf("2. Jamshedpur FC\n");
    printf("3. ATK FC\n");
    scanf("%d", &ch);
    start = add(start, ch);
    return start;
}

plr *read(plr *start)
{
    int ch;
    printf("Select\n");
    printf("1. To display statistics for Mumbai City FC\n");
    printf("2. To display statistics for Jamshedpur FC\n");
    printf("3. To display statistics for ATK FC\n");
    printf("4. To display statistics for entire database\n");
    scanf("%d", &ch);
    switch (ch)
    {
        case 1:
            {
                start = teamRead(start, ch);
                break;
            }
        case 2:
            {
                start = teamRead(start, ch);
                break;
            }
        case 3:
            {
                start = teamRead(start, ch);
                break;
            }
        case 4:
            {
                start = teamRead(start, ch);
                break;
            }
        default:
        {
            printf("Please select a valid number\n");
            break;
        }
    }
    return start;
    
}

void main()
{
    plr *start;
    start=NULL;
    int ch;
    do
    {
        printf("Enter\n");
        printf("1. To add a player\n");
        printf("2. To read database\n");
        printf("3. To exit\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
            {
                start = addSelect(start);
                break;
            }
            case 2:
            {
                start = read(start);
                break;
            }
            case 3:
            {
                break;
            }
            default:
            {
                printf("Please select a valid number\n");
            }
        }
    }while(ch!=3);
}

/*
Enter
1. To add a player
2. To read database
3. To exit
1
Select team
1. Mumbai City FC
2. Jamshedpur FC
3. ATK FC
1
Enter name of player:
Thiago Carlos
Enter number of appearances:
14
Enter number of goals scored:
2
Enter number of assists given:
3
Enter number of yellow cards
1
Enter number of red cards
0
Enter
1. To add a player
2. To read database
3. To exit
1
Select team
1. Mumbai City FC
2. Jamshedpur FC
3. ATK FC
1
Enter name of player:
Balwant Singh
Enter number of appearances:
17
Enter number of goals scored:
6
Enter number of assists given:
1
Enter number of yellow cards
0
Enter number of red cards
0
Enter
1. To add a player
2. To read database
3. To exit
1
Select team
1. Mumbai City FC
2. Jamshedpur FC
3. ATK FC
2
Enter name of player:
Jerry
Enter number of appearances:
17
Enter number of goals scored:
6
Enter number of assists given:
0
Enter number of yellow cards
1
Enter number of red cards
0
Enter
1. To add a player
2. To read database
3. To exit
1
Select team
1. Mumbai City FC
2. Jamshedpur FC
3. ATK FC
2
Enter name of player:
Farukh Choudhary
Enter number of appearances:
14
Enter number of goals scored:
2
Enter number of assists given:
1
Enter number of yellow cards
1
Enter number of red cards
0
Enter
1. To add a player
2. To read database
3. To exit
1
Select team
1. Mumbai City FC
2. Jamshedpur FC
3. ATK FC
3
Enter name of player:
Bipin Singh
Enter number of appearances:
17
Enter number of goals scored:
5
Enter number of assists given:
1
Enter number of yellow cards
1
Enter number of red cards
1
Enter
1. To add a player
2. To read database
3. To exit
1
Select team
1. Mumbai City FC
2. Jamshedpur FC
3. ATK FC
3
Enter name of player:
Jordi
Enter number of appearances:
14
Enter number of goals scored:
0
Enter number of assists given:
0
Enter number of yellow cards
2
Enter number of red cards
1
Enter
1. To add a player
2. To read database
3. To exit
2
Select
1. To display statistics for Mumbai City FC
2. To display statistics for Jamshedpur FC
3. To display statistics for ATK FC
4. To display statistics for entire database
1
Select
1. To display players entered
2. To sort by name
3. To sort by number of appearances
4. To sort by number of goals scored
5. To sort by number of assists
6. To sort by number of yellow cards
7. To sort by number of red cards
8. To sort by current market value
9. To return
3
Team | Apps | Name | Goals | Assists | Yellow Cards | Red Cards | Value
| Mumbai City FC |
Balwant Singh | 17 | 6 | 1 | 0 | 0 | 41.500000 
-----------------------
| Mumbai City FC |
Thiago Carlos | 14 | 2 | 3 | 1 | 0 | 25.000000 
-----------------------
Enter
1. To add a player
2. To read database
3. To exit
2
Select
1. To display statistics for Mumbai City FC
2. To display statistics for Jamshedpur FC
3. To display statistics for ATK FC
4. To display statistics for entire database
2
Select
1. To display players entered
2. To sort by name
3. To sort by number of appearances
4. To sort by number of goals scored
5. To sort by number of assists
6. To sort by number of yellow cards
7. To sort by number of red cards
8. To sort by current market value
9. To return
4
Team | Apps | Name | Goals | Assists | Yellow Cards | Red Cards | Value
| Jamshedpur FC |
Jerry | 17 | 6 | 0 | 1 | 0 | 37.500000 
-----------------------
| Jamshedpur FC |
Farukh Choudhary | 14 | 2 | 1 | 1 | 0 | 19.000000 
-----------------------
Enter
1. To add a player
2. To read database
3. To exit
2
Select
1. To display statistics for Mumbai City FC
2. To display statistics for Jamshedpur FC
3. To display statistics for ATK FC
4. To display statistics for entire database
3
Select
1. To display players entered
2. To sort by name
3. To sort by number of appearances
4. To sort by number of goals scored
5. To sort by number of assists
6. To sort by number of yellow cards
7. To sort by number of red cards
8. To sort by current market value
9. To return
8
Team | Apps | Name | Goals | Assists | Yellow Cards | Red Cards | Value
| ATK FC |
Bipin Singh | 17 | 5 | 1 | 1 | 1 | 33.500000 
-----------------------
| ATK FC |
Jordi | 14 | 0 | 0 | 2 | 1 | 3.000000 
-----------------------
Enter
1. To add a player
2. To read database
3. To exit
2
Select
1. To display statistics for Mumbai City FC
2. To display statistics for Jamshedpur FC
3. To display statistics for ATK FC
4. To display statistics for entire database
4
Select
1. To display players entered
2. To sort by name
3. To sort by number of appearances
4. To sort by number of goals scored
5. To sort by number of assists
6. To sort by number of yellow cards
7. To sort by number of red cards
8. To sort by current market value
9. To return
2
Name | Apps | Goals | Assists | Yellow Cards | Red Cards | Value
| Mumbai City FC |
Balwant Singh | 17 | 6 | 1 | 0 | 0 | 41.500000 
-----------------------
| Jamshedpur FC |
Jerry | 17 | 6 | 0 | 1 | 0 | 37.500000 
-----------------------
| Jamshedpur FC |
Farukh Choudhary | 14 | 2 | 1 | 1 | 0 | 19.000000 
-----------------------
| ATK FC |
Bipin Singh | 17 | 5 | 1 | 1 | 1 | 33.500000 
-----------------------
| Mumbai City FC |
Thiago Carlos | 14 | 2 | 3 | 1 | 0 | 25.000000 
-----------------------
| ATK FC |
Jordi | 14 | 0 | 0 | 2 | 1 | 3.000000 
-----------------------
Enter
1. To add a player
2. To read database
3. To exit
2
Select
1. To display statistics for Mumbai City FC
2. To display statistics for Jamshedpur FC
3. To display statistics for ATK FC
4. To display statistics for entire database
4
Select
1. To display players entered
2. To sort by name
3. To sort by number of appearances
4. To sort by number of goals scored
5. To sort by number of assists
6. To sort by number of yellow cards
7. To sort by number of red cards
8. To sort by current market value
9. To return
3
Name | Apps | Goals | Assists | Yellow Cards | Red Cards | Value
| Mumbai City FC |
Balwant Singh | 17 | 6 | 1 | 0 | 0 | 41.500000 
-----------------------
| ATK FC |
Bipin Singh | 17 | 5 | 1 | 1 | 1 | 33.500000 
-----------------------
| Jamshedpur FC |
Jerry | 17 | 6 | 0 | 1 | 0 | 37.500000 
-----------------------
| ATK FC |
Jordi | 14 | 0 | 0 | 2 | 1 | 3.000000 
-----------------------
| Mumbai City FC |
Thiago Carlos | 14 | 2 | 3 | 1 | 0 | 25.000000 
-----------------------
| Jamshedpur FC |
Farukh Choudhary | 14 | 2 | 1 | 1 | 0 | 19.000000 
-----------------------
Enter
1. To add a player
2. To read database
3. To exit
2
Select
1. To display statistics for Mumbai City FC
2. To display statistics for Jamshedpur FC
3. To display statistics for ATK FC
4. To display statistics for entire database
4
Select
1. To display players entered
2. To sort by name
3. To sort by number of appearances
4. To sort by number of goals scored
5. To sort by number of assists
6. To sort by number of yellow cards
7. To sort by number of red cards
8. To sort by current market value
9. To return
4
Name | Apps | Goals | Assists | Yellow Cards | Red Cards | Value
| Mumbai City FC |
Balwant Singh | 17 | 6 | 1 | 0 | 0 | 41.500000 
-----------------------
| Jamshedpur FC |
Jerry | 17 | 6 | 0 | 1 | 0 | 37.500000 
-----------------------
| ATK FC |
Bipin Singh | 17 | 5 | 1 | 1 | 1 | 33.500000 
-----------------------
| Jamshedpur FC |
Farukh Choudhary | 14 | 2 | 1 | 1 | 0 | 19.000000 
-----------------------
| Mumbai City FC |
Thiago Carlos | 14 | 2 | 3 | 1 | 0 | 25.000000 
-----------------------
| ATK FC |
Jordi | 14 | 0 | 0 | 2 | 1 | 3.000000 
-----------------------
Enter
1. To add a player
2. To read database
3. To exit
3
*/
