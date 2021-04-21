#include<stdio.h>
#include<malloc.h>
#include<string.h>
int flag = 0;
int counting=0;
struct tree
{
	struct node *root;
};
struct node
{
	int info;
	int balance;
	//int s;
	struct node *right, *left;
};

int count(int m)
{
    counting=counting+m;
    return counting;
}
int booking()
{
	int price = 0, n,z;
	int s, d;
	printf("Enter the number of passengers for whom you wish to book the ticket: \n");
	scanf("%d", &n);
	z=count(n);

	printf("Enter source: 1:Versova 2:JB Nagar 3:Saki Naka \n");
	scanf("%d", &s);
	printf("Enter Destination: 1:Andheri 2:Marol 3:Ghatkopar\n");
	scanf("%d", &d);
	if (s == 1)
	{
		if (d == 1)
		{
			price = 20;

		}
		else if (d == 2)
			price = 30;
		else
			price = 40;
	}
	else if (s == 2)
	{
		if (d == 1)
			price = 20;
		else if (d == 2)
			price = 10;
		else
			price = 30;
	}
	else
	{
		if (d == 1)
			price = 20;
		else if (d == 2)
			price = 10;
		else
			price = 20;
	}
	printf("Total number of booking is %d\n",z);

	return n * price;
}

int nsmart(struct tree *t, int val)
{
	int rate;
	struct node *ptr, *preptr;
	ptr = t->root;
	if (t->root == NULL) {
		return -1;
	}
	while (ptr != NULL) {

		if (val == ptr->info) {
			flag = 1;
			break;
		}
		else if (val > ptr->info) {
			preptr = ptr;
			ptr = ptr->right;

		}
		else {
			preptr = ptr;
			ptr = ptr->left;
		}
	}
	if (ptr->balance == 0)
	{
		printf("Minimum card balance should be Rs 50\n");
		printf("Recharge your smart card for 1: Rs 50 2: Rs 100 3: Rs 200 4: Rs 500 \n");
		scanf("%d", &rate);
		switch (rate)
		{
		case 1:ptr->balance = ptr->balance + 50;
			printf("Balance=%d \n",ptr -> balance);
			break;

		case 2: ptr->balance = ptr->balance + 100;
			printf("Balance=%d \n",ptr->balance);
			break;

		case 3: ptr->balance = ptr->balance + 200;
			printf("Balance=%d \n",ptr->balance);
			break;
		case 4: ptr->balance = ptr->balance + 500;
			printf("Balance=%d \n",ptr->balance);
			break;
		}
	}
	return ptr->balance;
}

int tbooking()
{
	int price, n, token = 0;
	int s, d, i,z;
	printf("Enter the number of passengers for whom you wish to book the ticket: \n");
	scanf("%d", &n);
	z=count(n);

	printf("Enter source: 1:Versova 2:Jb Nagar 3:Saki Naka \n");
	scanf("%d", &s);
	printf("Enter Destination: 1:Andheri 2:Marol 3:Ghatkopar\n");
	scanf("%d", &d);
	if (s == 1)
	{
		if (d == 1)
			price = 20;

		else if (d == 2)
			price = 30;

		else
			price = 40;


	}
	else if (s == 2)
	{
		if (d == 1)
			price = 20;

		else if (d == 2)
			price = 10;

		else
			price = 30;

	}
	else
	{
		if (d == 1)
			price = 20;
		else if (d == 2)
			price = 10;
		else
			price = 20;
	}
	printf("Number of booking is %d\n",z);

	return (n*price);

}

void insert(struct tree *t, int x)
{
	struct node *q, *prev;
	struct node *new = (struct node *)(malloc(sizeof(struct node)));
	new->info = x;
	new->balance = 0;
	new->left = new->right = NULL;
	if (t->root == NULL)
		t->root = new;
	else
	{
		q = t->root;
		while (q != NULL)
		{
			prev = q;
			if (x<q->info)
				q = q->left;
			else
				q = q->right;
		}
		if (x<prev->info)
			prev->left = new;
		else
			prev->right = new;
	}
}

void update(int b, struct tree *t, int val)
{
	struct node *ptr, *preptr;
	ptr = t->root;
	if (t->root == NULL) {
		return;
	}
	while (ptr != NULL) {

		if (val == ptr->info) {
			flag = 1;

			break;
		}
		else if (val > ptr->info) {
			preptr = ptr;
			ptr = ptr->right;

		}
		else {
			preptr = ptr;
			ptr = ptr->left;
		}
	}
	ptr->balance = b;

}

int search(struct node *root,int num)
{
	if (root == NULL)
		return 0;
	else if (num == root->info)
		return 1;
	else if (num < root->info)
		return search(root->left,num);
	else if (num > root->info)
		return search(root->right,num);
}

int countdigit(int n)
{
    int count=0;
    while(n!=0)
    {
        n=n/10;
        ++count;
    }

    return(count);
}
/*
void inorder(struct node *t)
{

	struct node *p;
	p = t;
	if (p != NULL)
	{
		inorder(p->left);
		printf("%d\t", p->info);
		printf("%d\n", p->balance);
		inorder(p->right);
	}
}
*/
/*void mobile()
{
	printf("Enter mobile no. :\n");
	scanf("%d", &mob);
	n = countdigit(mob);
}
*/
void main()
{
	char choice;
	int  type, c, b, m, a, sum;
	int token = 0, bill;
	int n;
	int mob, total, ch;
	struct tree t;
	t.root = NULL;
	while (1)
	{
		printf("Welcome to MUMBAI METRO \n");
		printf("Enter mobile no. :\n");
		scanf("%d", &mob);
		  n= countdigit(mob);
       if(n==9)
       {
           printf("Valid mobile number\n");

       }
		 else
       {
           printf("Invalid mobile number\n");
           printf("Enter the 10 digit mobile number\n");
           scanf("%d",&mob);
            n= countdigit(mob);
            if(n==9)
            {
                printf("Valid mobile number\n");
            }
            else
            {
                printf("Invalid no\n");
                break;
            }
       }//make function for mobile no.
	   flag = search(t.root, mob);
		if (flag == 1)
		{
			printf("Welcome back!\n");
		}
		if (flag == 0)
			insert(&t, mob);
		printf("Book through 1.Smart Card or 2.Token ?\n");
		scanf("%d", &type);
		if (type == 1)
		{
			printf("Enter 1:Create a new Smart Card and pay, or 2: Pay through existing card \n");
			scanf("%d", &c);
			switch (c)
			{
				case 1: {b = nsmart(&t, mob);
				total = booking();
				if (total > b)
				{
					printf("Insufficient balance\n");
					printf("Enter Exit \n");

				}
				else
				{
					printf("Price is %d\n", total);
					b = b - total;
					printf("Remaining balance is%d\n", b);
					update(b, &t, mob);
					printf("Amount PAID\n");
				}
				break;

				}

				case 2: {
				sum = nsmart(&t, mob);
				total = booking();

				if (sum > total || sum == total)
				{
					printf("Amount paid\n");
					sum = sum - total;
					update(sum, &t, mob);
					printf("Remaining amount is %d\n", sum);
				}
				else
				{
					printf("Insufficient balance\n");
					printf("Enter Exit \n");
				}

				break;
				}
			}
		}
		else
		{
			bill = tbooking();
			printf("Bill: %d\n", bill);
			printf("Collect your token\n");
		}

		printf("Enter 1: to exit, 2 : to continue\n");
		scanf("%d", &ch);
		if (ch == 1)
        {
			//printf("Customer mobile\t");
			//printf("Customer balance\n");
			//inorder(t.root);
            exit(0);

        }

	}
}

/*
Output:
Welcome to MUMBAI METRO
Enter mobile no. :
8788
Book through 1.Smart Card or 2.Token ?
1
Enter 1:Create a new Smart Card and pay, or 2: Pay through existing card
1
Minimum card balance should be Rs 50
Recharge your smart card for 1: Rs 50 2: Rs 100 3: Rs 200 4: Rs 500
1
Balance=50
Enter the number of passengers for whom you wish to book the ticket:
1
Enter source: 1:Versova 2:JB Nagar 3:Saki Naka
1
Enter Destination: 1:Andheri 2:Marol 3:Ghatkopar
1
Price is 20
Remaining balance is30
Amount PAID
Enter 1: to exit, 2 : to continue
2
Welcome to MUMBAI METRO
Enter mobile no. :
8788
Welcome back!
Book through 1.Smart Card or 2.Token ?
1
Enter 1:Create a new Smart Card and pay, or 2: Pay through existing card
2
Enter the number of passengers for whom you wish to book the ticket:
1
Enter source: 1:Versova 2:JB Nagar 3:Saki Naka
2
Enter Destination: 1:Andheri 2:Marol 3:Ghatkopar
3
Price is 20
Remaining balance is10
Enter 1: to exit, 2 : to continue
2
Welcome to MUMBAI METRO
Enter mobile no. :
567
Book through 1.Smart Card or 2.Token ?
2
Enter the number of passengers for whom you wish to book the ticket:
2
Enter source: 1:Versova 2:Jb Nagar 3:Saki Naka
1
Enter Destination: 1:Andheri 2:Marol 3:Ghatkopar
1
Bill: 40
Collect your token
Enter 1: to exit, 2 : to continue
1

*/
