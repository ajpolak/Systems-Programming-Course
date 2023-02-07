/*
Name: Austin Polak, ajpolak@purdue.edu
TA: Zahra Ghorrati
Lab time: Thursday at 7:30am

Description:
This program is the development of linked lists to build data structures.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXFNAME 30
#define MAXLNAME 30

typedef struct node // structure variables
{
	char FirstN[MAXFNAME];
	char LastN[MAXLNAME];
	int PUID;
	int age;
	struct node *next;
} node;

struct node *first = NULL;
struct node *last = NULL;

int list = 0; // amount of linked list
char FirstN[MAXFNAME];
char LastN[MAXLNAME];
int PUID;
int age;
void userInput(); // declaring functions
void Display();
node *CreateListNoNodes();
node *CreateListNode(char FN[], char LN[], int PUID, int age);
void InsertFront(char FN[], char LN[], int PUID, int age);
void InsertMiddle();
void InsertEnd();
void DeleteFront();
void DeleteMiddle(int i);
void DeleteEnd();
void Search();

int main()
{
	int user = 0; // user input

	do
	{ // interface for user choices
		printf("Enter 1 to develop CreateListNoNodes\n");
		printf("Enter 2 to develop CreateListNode\n");
		printf("Enter 3 to InsertFront\n");
		printf("Enter 4 to InsertMiddle\n");
		printf("Enter 5 to InsertEnd\n");
		printf("Enter 6 to DeleteFront\n");
		printf("Enter 7 to DeleteMiddle\n");
		printf("Enter 8 to DeleteEnd\n");
		printf("Enter 9 to use Traverse\n");
		printf("Enter 10 to Search\n");
		printf("Enter 11 to exit\n");
		printf("------------------------------\n");
		printf("Input your decision: ");
		scanf("%d", &user);

		switch (user)
		{
		case 1:
			printf("Selected: %d\n", user);

			if (list == 0)
			{
				CreateListNoNodes();
			}
			else
			{
				printf("List is already created.\n");
			}
			printf("List with no nodes has been created.\n");
			break;
		case 2:
			printf("Selected: %d\n", user);

			if (list == 0)
			{
				userInput();
				last = CreateListNode(FirstN, LastN, PUID, age);
				printf("List with a node has been created.\n");
			}
			else
			{
				printf("Sorry, list is already created\n");
			}
			break;
		case 3:
			printf("Selected: %d\n", user);
			userInput();
			InsertFront(FirstN, LastN, PUID, age);
			Display();
			break;
		case 4:
			printf("Selected: %d\n", user);
			userInput();
			int i;
			printf("Please enter an index: ");
			scanf("%d", &i);
			InsertMiddle(i, FirstN, LastN, PUID, age);
			Display();
			break;
		case 5:
			printf("Selected: %d\n", user);
			userInput();
			InsertEnd(last, FirstN, LastN, PUID, age);
			Display();
			break;
		case 6:
			printf("Selected: %d\n", user);
			DeleteFront();
			Display();
			break;
		case 7:
			printf("Selected: %d\n", user);
			printf("Please enter an index: ");
			scanf("%d", &i);
			DeleteMiddle(i);
			Display();
			break;
		case 8:
			printf("Selected: %d\n", user);
			DeleteEnd();
			Display();
			break;
		case 9:
			printf("Selected: %d\n", user);
			Display();
			break;
		case 10:
			printf("Selected: %d\n", user);
			printf("Which index would you perfer to locate? (end begins with 0)\n");
			scanf("%d", &i);
			Search(i);
			break;
		case 11:
			exit(0);
			break;
		}
	} while (user != 11);
	return 0;
}

void userInput()			//Inputs for user after first choice
{
	char store;
	printf("Please enter your first name: ");
	scanf("%s", FirstN);

	printf("Please enter your last name: ");
	scanf("%s", LastN);

	printf("Please enter your PUID: ");
	scanf("%d", &PUID);

	printf("Please enter your age: ");
	scanf("%d", &age);

	printf("The node is: %s, %s, %d, %d\n", FirstN, LastN, PUID, age);
}

void Display()			
{
	struct node *data = last;
	int i = 1;
	if (data == NULL)
	{
		printf("No data\n");
		return;
	}

	while (data != NULL)
	{
		printf("\nStudent %d information: \n", i);
		printf("============\n %s \n", data->FirstN);
		printf("============\n %s \n", data->LastN);
		printf("============\n %d \n", data->PUID);
		printf("============\n %d \n", data->age);
		printf("############ \n");
		data = data->next;
		i++;
	}
}

node *CreateListNoNodes()		//Create linked list with no nodes
{

	struct node *last;
	list = 1;
	return last;
}

node *CreateListNode(char FN[], char LN[], int PUID, int age)		//Create linked list with a single node
{

	struct node *s = CreateListNoNodes();
	s = (node *)malloc(sizeof(struct node));
	s->next = NULL;
	strcpy(s->FirstN, FN);
	strcpy(s->LastN, LN);
	s->PUID = PUID;
	s->age = age;

	list = 1;
	return s;
}

void InsertFront(char FN[], char LN[], int PUID, int age)	//Insert in node in front of the linked list
{
	first = last;
	last = CreateListNode(FN, LN, PUID, age);
	last->next = first;
	printf("New node created: %s, %s, %d, %d\n", last->FirstN, last->LastN, last->PUID, last->age);
}

void InsertMiddle(int i, char FN[], char LN[], int PUID, int age) //Insert node in the middle of the linked list
{
	int cnt = 0;
	first = last;

	if (i == 0 && cnt == 0)
	{
		InsertFront(FN, LN, PUID, age);
	}
	else
	{
		while (first->next != NULL)
		{
			first = first->next;
			cnt++;
		}
		if (i > cnt + 1)
		{
			printf("\nIndex out of bounds! Please retry: \n");
			return;
		}
		else
		{
			first = last;
			cnt = 0;
		}
		while (cnt != i)
		{
			first = first->next;
			cnt++;
		}

		struct node *instance = first;

		first = last;
		cnt = 0;
		int instancei = i - 1;
		while (cnt != instancei)
		{
			first = first->next;
			cnt++;
		}

		struct node *new = CreateListNode(FN, LN, PUID, age);
		first->next = new;
		new->next = instance;

		printf("New node created: %s, %s, %d, %d\n", new->FirstN, new->LastN, new->PUID, new->age);
	}
}

void InsertEnd(node *last, char FN[], char LN[], int PUID, int age) //Insert node at the end of the linked list
{
	first = last;
	while (first->next != NULL)
	{
		first = first->next;
	}
	first->next = CreateListNode(FN, LN, PUID, age);
	struct node *Display_N = first->next;
	printf("New  node created: %s, %s, %d, %d\n", Display_N->FirstN, Display_N->LastN, Display_N->PUID, Display_N->age);
}

void DeleteFront()		//Delete node in the front of linked list
{
	struct node *ptr = last;
	last = last->next;
	ptr->next = NULL;
	printf("Node deleted sucessfully: %s, %s, %d, %d\n", ptr->FirstN, ptr->LastN, ptr->PUID, ptr->age);
	free(ptr);
}

void DeleteMiddle(int i)		//Delete node in the middle of linked list
{
	int p = 0;
	first = last;

	while (first->next != NULL)
	{
		first = first->next;
		p++;
	}
	if (i > p + 1)
	{
		printf("Index is out of the range! Please try again: \n");
	}
	else
	{
		first = last;
		p = 0;
	}
	while (p != i)
	{
		first = first->next;
		p++;
	}
	int new_cnt = 0;
	struct node *instance = last;
	while (new_cnt != i - 1)
	{
		instance = instance->next;
		new_cnt++;
	}
	instance->next = first->next;
	printf("Node was successfully deleted: %s, %s, %d, %d\n", first->FirstN, first->LastN, first->PUID, first->age);
	first->next = NULL;
	free(first);
}

void DeleteEnd()		//Delete node at the end of list
{
	struct node *instance = last;
	if (last == NULL)
	{
		printf("There is no node within created list\n");
		return;
	}
	int cnt = 1;
	while (instance->next != NULL)
	{
		instance = instance->next;
		cnt++;
	}
	printf("cnt: %d\n", cnt);

	struct node *End = instance;
	instance = last;
	if (cnt == 1)
	{
		last == NULL;
		printf("Deleted!\n");
		return;
	}
	for (int i = 0; i < cnt; i++)
	{
		if (i == cnt)
		{
			struct node *Delete = instance->next;
			printf("Node was deleted successfully: %s, %s, %d, %d\n", Delete->FirstN, Delete->LastN, Delete->PUID, Delete->age);

			instance->next = NULL;
			free(Delete);
			break;
		}
		else
		{
			instance = instance->next;
		}
	}
}

void Search(int i)		//search for nodes by PUID
{
	int p = 0;
	first = last;

	while (first->next != NULL)
	{
		first = first->next;
		p++;
	}
	int length = p;

	if (i > p + 1)
	{
		printf("Index is out of the range. Please try again: \n");
		return;
	}
	else
	{
		first = last;
		p = 0;
	}
	while (p != i)
	{
		first = first->next;
		p++;
	}

	int newp = 0;
	first = last;
	while (newp != p)
	{
		first = first->next;
		newp++;
	}
	if (i > length)
	{
		return;
	}
	else
	{
		printf("The node with the desired index %d includes: %s %s %d %d\n", i, first->FirstN, first->LastN, first->PUID, first->age);
	}
}