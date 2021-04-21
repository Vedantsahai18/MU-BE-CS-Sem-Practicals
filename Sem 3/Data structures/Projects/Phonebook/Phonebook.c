#include<malloc.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<strings.h>
#define MAX 25
#define MAX1 13

typedef struct Contact
{
  bool fav;
  char f_name[MAX];
  char surname[MAX];
  char email[MAX];
  char p1[MAX1];
  char p2[MAX1];
  struct Contact *next;
}contact;

contact *ptr = NULL, *preptr = NULL, *start = NULL;
int count = 0, c_no = 0;

void create()
{
  int op, f;
  ptr = preptr = start;
  contact *new_contact = (contact *)malloc(sizeof(contact));
  count ++;
  if (new_contact)
  {
    printf("\nEnter First Name: ");
    scanf("%s", (new_contact -> f_name));
    printf("Enter Surname: ");
    scanf("%s", (new_contact -> surname));
    printf("Enter Email: ");
    scanf("%s", (new_contact -> email));
    printf("Enter Phone1: ");
    scanf("%s", (new_contact -> p1));
    printf("Enter Phone2: ");
    scanf("%s", (new_contact -> p2));
    printf("Favourite? (1.Yes, 0.No): ");
    scanf("%d", &f);
    if (f==1)
      new_contact -> fav = true;
    else
      new_contact -> fav = false;
    if(start == NULL)
    {
      start = new_contact; //initialize first contact in start pointer
      new_contact -> next = NULL;
    }
    else if(ptr == start && strcasecmp(new_contact -> f_name, ptr -> f_name) <= 0)
    {
      new_contact -> next = start; //add new created at start of linked list
      start = new_contact; //start is pointed to this new created node
    }
    else //find appropriate position to add new created node
    {
      while(ptr -> next != NULL && strcasecmp(new_contact -> f_name, ptr -> next -> f_name) > 0)
      {
        preptr = ptr;
        ptr = ptr -> next;
      }
      if(ptr -> next == NULL) //insert new element (node) in last position
      {
        ptr -> next = new_contact;
        new_contact -> next = NULL;
      }
      else //insert node in middle of linked list
      {
        preptr -> next = new_contact;
        new_contact -> next = ptr;
      }
    }
  }
  else //malloc function not create dynamic memory this case showing this message
    printf("\nMemory overflow");
}





contact * search_f_n(contact *preptr, contact *ptr, char f_n[MAX])
{
  if (ptr == NULL || strcasecmp(ptr -> f_name, f_n) == 0) // If data is present in current node, return ptr
    return ptr;
  return search_f_n(ptr, ptr -> next, f_n); // Recur for remaining list
}



contact * search_sn(contact *preptr, contact *ptr, char sn[MAX])
{
  if (ptr == NULL || strcasecmp(ptr -> surname, sn) == 0) // If data is present in current node, return ptr
    return ptr;
  return search_sn(ptr, ptr -> next, sn); // Recur for remaining list
}



contact * search_em(contact *preptr, contact *ptr, char em[MAX])
{
  if (ptr == NULL || strcmp(ptr -> email, em) == 0) // If data is present in current node, return ptr
    return ptr;
  return search_em(ptr, ptr -> next, em); // Recur for remaining list
}



contact * search_p(contact *preptr, contact *ptr, char p[MAX])
{
  if (ptr == NULL || strcmp(ptr -> p1, p) == 0 || strcmp(ptr -> p2, p) == 0) // If data is present in current node, return ptr
    return ptr;
  return search_p(ptr, ptr -> next, p); // Recur for remaining list
}



contact * search_specific()
{
  bool f;
  char f_n[MAX], sn[MAX], em[MAX], p[MAX1];
  int op;
  preptr = ptr = start;
  contact *c = NULL;
  printf("\n(For Contacts With Same Data In An Entity (eg. First Name), Search By Different Entity (eg Surname, etc))\n\nSearch by 1.First Name, 2.Surname, 3.Email, 4.Phone, Enter 5.Exit\nOption: "); //Search Methods
  scanf("%d", &op);
  switch (op)
  {
    case 1:
      printf("\nEnter data to search: ");
      scanf("%s", &f_n);
      c = search_f_n(preptr, ptr, f_n);
      break;
    case 2:
      printf("\nEnter data to search: ");
      scanf("%s", &sn);
      c = search_sn(preptr, ptr,sn);
      break;
    case 3:
      printf("\nEnter data to search: ");
      scanf("%s", &em);
      c = search_em(preptr, ptr, em);
      break;
    case 4:
      printf("\nEnter data to search: ");
      scanf("%s", &p);
      c = search_p(preptr, ptr, p);
      break;
    case 5:
      exit(0);
    default:
      printf("\nInvalid Input");
      break;
  }
  return c;
}






void display(contact *c)
{
  if(c == NULL)
    printf("\nNo Such Contact");
  else
  {
    printf("\nFirst Name: %s", c -> f_name);
    printf("\nSurname   : %s", c -> surname);
    printf("\nEmail     : %s", c -> email);
    printf("\nPhone1    : %s", c -> p1);
    printf("\nPhone2    : %s", c -> p2);
    printf("\nFavourite : %s", (c -> fav) ? "Yes" : "No");
    printf("\n");
  }
}



void display_fav()
{
  ptr = start;
  while(ptr != NULL)
  {
    if(ptr -> fav == true)
    {
      display(ptr);
      ptr = ptr -> next;
    }
    else
    ptr = ptr -> next;

  }
}



void display_all()
{
  ptr = start;
  while(ptr != NULL)
  {
    display(ptr);
    ptr = ptr -> next;
  }
}



void display_specific()
{
  contact *c;
  c = search_specific();
  display(c);
}





void s_and_d_related_f_n(contact *ptr, char f_n[MAX], int n)
{
    if(strncasecmp(ptr -> f_name, f_n, n) > 0)
      return;
    else if(ptr == NULL || strncasecmp(ptr -> f_name, f_n, n) == 0) // If related data is present in current node, display current node
      display(ptr);
    if(ptr -> next != NULL)
      s_and_d_related_f_n(ptr -> next, f_n, n); // Recur for remaining list
}



void s_and_d_related_sn(contact *ptr, char sn[MAX], int n)
{
  if(strncasecmp(ptr -> surname, sn, n) > 0)
    return;
  else if(ptr == NULL || strncasecmp(ptr -> surname, sn, n) == 0) // If related data is present in current node, display current node
    display(ptr);
  if(ptr -> next != NULL)
    s_and_d_related_sn(ptr -> next, sn, n); // Recur for remaining list
}



void s_and_d_related_em(contact *ptr, char em[MAX], int n)
{
  if(strncasecmp(ptr -> email, em, n) > 0)
    return;
  else if(ptr == NULL || strncmp(ptr -> email, em, n) == 0) // If related data is present in current node, display current node
    display(ptr);
  if(ptr -> next != NULL)
    s_and_d_related_em(ptr -> next, em, n); // Recur for remaining list
}



void s_and_d_related_p(contact *ptr, char p[MAX], int n)
{
    if(strncasecmp(ptr -> p1, p, n) > 0 || strncasecmp(ptr -> p2, p, n) > 0)
      return;
    else if(ptr == NULL || strncmp(ptr -> p1, p, n) == 0 || strncmp(ptr -> p2, p, n) == 0) // If related data is present in current node, display current node
      display(ptr);
    if(ptr -> next != NULL)
      s_and_d_related_p(ptr -> next, p, n); // Recur for remaining list
}



void s_and_d_related()
{
  char f_n[MAX], sn[MAX], em[MAX], p[MAX1];
  int op, n;
  ptr = start;
  printf("\nSearch by 1.First Name, 2.Surname, 3.Email, 4.Phone, Enter 5.Exit\nOption: "); //Search Methods
  scanf("%d", &op);
  switch (op)
  {
    case 1:
      printf("\nEnter data to search: ");
      scanf("%s", &f_n);
      n = strlen(f_n);
      s_and_d_related_f_n(ptr, f_n, n);
      break;
    case 2:
      printf("\nEnter data to search: ");
      scanf("%s", &sn);
      n = strlen(sn);
      s_and_d_related_sn(ptr, sn, n);
      break;
    case 3:
      printf("\nEnter data to search: ");
      scanf("%s", &em);
      n = strlen(em);
      s_and_d_related_em(ptr, em, n);
      break;
    case 4:
      printf("\nEnter data to search: ");
      scanf("%s", &p);
      n = strlen(p);
      s_and_d_related_p(ptr, p, n);
      break;
    case 5:
      exit(0);
    default:
      printf("\nInvalid Input");
      break;
  }
}






void modify()
{
  int op, op1, f;
  contact *c;
  c = search_specific();
  printf("\nModify 1.First Name, 2.Surname, 3.Email, 4.Phone, 5.Favourite\nEnter 6.Exit\nOption: ");
  scanf("%d", &op);
  switch (op)
  {
    case 1:
      printf("\nFirst Name: %s", c -> f_name);
      printf("\nEnter new data: ");
      scanf("%s", (c -> f_name));
      break;
    case 2:
      printf("\nSurname: %s", c -> surname);
      printf("\nEnter new data: ");
      scanf("%s", (c -> surname));
      break;
    case 3:
      printf("\nEmail: %s", c -> email);
      printf("\nEnter new data: ");
      scanf("%s", (c -> email));
      break;
    case 4:
      printf("\nPhone1 = %d, Phone2 = %d", (c -> p1), (c-> p2));
      printf("\nModify 1.Phone1, 2.Phone2, 3.Exit\nOption: ");
      scanf("%d", &op1);
      switch (op1)
      {
        case 1:
          printf("\nEnter new data: ");
          scanf("%s", (c -> p1));
          break;
        case 2:
          printf("\nEnter new data: ");
          scanf("%s", (c -> p2));
          break;
        case 3:
          break;
        default:
          printf("\nInvalid Input");
          break;
      }
      break;
    case 5:
      printf("\nFavourite: ", (c -> fav) ? "Yes" : "No");
      printf("\nEnter new data (1.Yes, 0.No): ");
      scanf("%d", &f);
      if (f == 1)
        c -> fav = true;
      break;
    case 6:
      exit(0);
  }
}





void delete()
{
  contact *c;
  ptr = start;
  preptr = ptr;
  c = search_specific();
  if(c == NULL)
    printf("\nNo Contact Found");
  else
  {
    if(c == start)
    {
      if(start -> next == NULL)
      {
        start = NULL;
        free(c);
      }
      else
      {
        start = start -> next;
        free(c);
      }
    }
    else if(c -> next == NULL)
    {
      preptr -> next = NULL;
      free(c);
    }
    else
    {
      preptr -> next = c -> next;
      free(c);
    }
    count--;
  }
}





void createFile()
{
  FILE *fp;
  int i = 0;
  ptr = start;
  fp = fopen("Contactsi.txt", "w");
  while(ptr != NULL)
  {
    fprintf(fp, "Contact No.: c_no\nFirst Name: %s\n   Surname   : %s\n   Email     : %s\n   Phone1    : %s\n   Phone2    : %s\n   Favourite : %s\n", ptr -> f_name, ptr -> surname, ptr -> email, ptr -> p1, ptr -> p2, ((ptr -> fav) ? "Yes" : "No"));
    ptr = ptr -> next;
    c_no++;
  }
  fclose(fp);
}





int main()
{
  int opt, opt1;
  contact *c;
  printf("PHONEBOOK\n1.Search, 2.Display, 3.Create, 4.Modify, 5.Delete, 6.No. of Contacts, 7.Save in a File, 8.Exit\nOption: ");
  scanf("%d", &opt);
  while(opt != 8)
  {
    switch(opt)
    {
      case 1:
      printf("\n1.Search Specific, 2.Search Similar\nOption: ");
      scanf("%d", &opt1);
      switch (opt1)
      {
        case 1:
          c = search_specific();
          display(c);
          break;
        case 2:
          s_and_d_related();
          break;
        default:
          printf("\nInvalid Option\n");
          break;
      }
      case 2:
        printf("\n1.Display Specific, 2.Display Favourite, 3.Display All\nOption: ");
        scanf("%d", &opt1);
        switch (opt1)
        {
          case 1:
            display_specific();
            break;
          case 2:
            display_fav();
            break;
          case 3:
            display_all();
            break;
          default:
            printf("\nInvalid Option\n");
            break;
        }
        break;
      case 3:
        create();
        break;
      case 4:
        modify();
        break;
      case 5:
        delete();
        break;
      case 6:
        printf("\nTotal Contacts: %d\n", count);
        break;
      case 7:
        createFile();
        break;
      default:
        printf("\nInvalid Option\n");
        break;
    }
    printf("\nPHONEBOOK\n1.Search, 2.Display, 3.Create, 4.Modify, 5.Delete, 6.No. of Contacts, 7.Save in a File, 8.Exit\nOption: ");
    scanf("%d", &opt);
  }
  return 0;
}
