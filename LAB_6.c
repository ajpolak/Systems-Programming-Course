/*
Name: Austin Polak, ajpolak@purdue.edu
TA: Zahra Ghorrati
Lab time: Thursday at 7:30am

Description:
Expanding from lab 5 to create linked lists to build stack and
queue data structures. 

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXCHARS 30
#define DEBUG 0


typedef struct node
{
	char FirstN[MAXCHARS];
	char LastN[MAXCHARS];
	int PUID;
	int age;
	struct node *next;
} node;

	node * temp;
	char FirstN[MAXCHARS];
	char LastN[MAXCHARS];
	int PUID;
	int age;
	node *next;
	node *current;
	node *Start;
	node *stack_startPtr;
	node *que_startPtr;

int main()
{
	void userInput();
	node * Createlistnode(char FN[], char LN[], int PUID, int age);
	void push(char FN[], char LN[], int PUID, int age);
	void pop();
	bool isEmptyStack();
	bool isEmptyQueue();
	void enqueue();
	void dequeue();
	void emptyQueue();
	void emptyStack();
	void printStack();
	void printQueue();
	int stackSize();
	int queueSize();
	int user = 0;
do{	
	
      
   
 	printf("Please enter 1 to use push funciton\n");
 	printf("Please enter 2 for the pop function\n");
 	printf("Please Enter 3 for the enqueue function\n");
  	printf("Please enter 4 for the dequeue function\n");
  	printf("Please enter 5 for the empty queue function\n");
  	printf ("Please enter 6 for the empty stack function\n");
  	printf ("Please enter 7 to print the queue\n");
  	printf ("Please enter 8 to print stack\n");
  	printf ("Pleasse enter 9 for reverse queue function\n");
  	printf ("Please enter 10 to exit\n");
 	 printf ("------------------------------\n");
 	 printf("Please enter your choice: ");
  	scanf ("%d", &user);
  
  	switch(user)
	{	
  	case 1:	                //uses push function
  	printf("Selected: %d\n", user);
  	userInput();
  	push (FirstN, LastN, PUID, age);
  	printf("\n The current amount of nodes: %d", stackSize(FirstN, LastN, PUID, age));
  	
  	if(isEmptyStack() == true)
  	{
  		printf("\n The stack has zero nodes");
  	}
  	else
  	{
  		printf("\nThe stack consist of nodes");
  	}
  	
  	printStack();
  	break;
  	
  	case 2:         	//uses pop function
  	printf("Selected: %d\n", user);
  	pop();
  	printf("\nThe current amount of nodes: %d", stackSize(FirstN, LastN, PUID, age));
  	
  		if(isEmptyStack() == true)
  	{
  		printf("\n The stack has zero nodes");
  	}
  	else
  	{
  		printf("\nThe stack consist of nodes");
  	}
  	
  	printStack();
  	break;
  	
	case 3:	            //uses enqueue function
  	printf("Selected: %d\n", user);
  	userInput();
  	queueSize(FirstN, LastN, PUID, age);
  	enqueue(FirstN, LastN, PUID, age);
  	printf("\nThe current amount of nodes: %d", stackSize(FirstN, LastN, PUID, age));
  	
  	if (isEmptyQueue() == true)
  	{
  		printf("\nThe queue has zero nodes");
  	}
  	else
  	{
  		printf("\nThe queue consist of nodes");
  	}
  	printQueue();
  	break;
  	
  	case 4:	               //uses dequeue function
  	printf("Selected: %d\n", user);
  	printf("\nThe current amount of nodes: %d", queueSize(FirstN, LastN, PUID, age));
  	
  	if (isEmptyQueue() == true)
  	{
  		printf("\nThe queue has zero nodes");
  	}
  	else
  	{
  		printf("\nThe queue has zero nodes");
  	}
  	printQueue();
  	break;
  	
  	case 5:	            //uses empty queue function
  	printf("Selected: %d\n", user);
  	emptyQueue();
  	printf("\nThe current amount of nodes: %d", queueSize());
  	
  	if (isEmptyQueue()==true)
  	{
  		printf("\nThe queue has zero nodes");
  	}
  	else
  	{
  		printf("\nThe queue consist of nodes");
  	}
  	
  	break;
  	
  	case 6:	            //uses empty stack function
  	printf("Selected: %d\n", user);
	emptyStack();
  	printf("\nThe current amount of nodes: %d", queueSize());
  	
  	if (isEmptyStack() == true)
  	{
  		printf("\nThe stack has zero nodes");
  	}
  	else
  	{
  		printf("\nThe stack has zero nodes");
  	}
  	break;
  	
	case 7:	            //uses print queue funciton
	printf("Selected: %d\n", user);
	printQueue();
  	break;
  	
 	case 8:
 	printf("Selected: %d\n", user);
 	printStack();
  	break;
  	
 	case 10:	         //exits program
 	exit(0);		
  	break;
	}
  }
  
  while (user != 10);
	return 0;		
  }

  void userInput()
  {
  	char temp;

	printf ("Please enter First Name: ");
	scanf ("%s",FirstN);
	printf ("Please enter Last Name: ");
	scanf ("%s",LastN);
	printf ("Please enter PUID: ");
	scanf ("%d",&PUID);
	printf ("Please enter Age: ");
	scanf ("%d",&age);
   }
   
   int stackSize(char FN[], char LN[], int PUID, int age)
   {
   	int count = 0;
   	struct node *stack_sizePtr = stack_startPtr;
   	while (stack_sizePtr != NULL)
   	{
   		count++;
   		stack_sizePtr = stack_sizePtr->next;
   	}
   	return count;
   }
   
   int queueSize()
   {
   	int count = 0;
   	struct node *que_sizePtr = que_startPtr;
   	while (que_sizePtr != NULL)
   	{
   		count++;
   		que_sizePtr = que_sizePtr->next;
   	}
   	return count;
   }
   
   node *Createlistnode(char FN[], char LN[], int PUID, int age)
   {
   	struct node *s = (node *) malloc(sizeof(struct node));
   	s->next = NULL;
   	strcpy(s->FirstN, FN);
   	strcpy(s->LastN, LN);
   	s->PUID = PUID;
   	s->age = age;
   	
   	return s;
   }
   
   void push(char FN[], char LN[], int PUID, int age)
   {
   	current = stack_startPtr;
   	stack_startPtr = Createlistnode(FN, LN, PUID, age);
   	stack_startPtr->next = current;
   	printf ("\nNew node created: %s, %s, %d, %d", stack_startPtr->FirstN, stack_startPtr->LastN, stack_startPtr->PUID, stack_startPtr->age);
   }
   
   void pop()
   {
   	struct node *s = stack_startPtr;
   	stack_startPtr = stack_startPtr->next;
   	s->next = NULL;
   	printf("\nNode is deleted: %s, %s, %d, %d", s->FirstN, s->LastN, s->PUID, s->age);
   	free(s);
   }
   
   bool isEmptyStack()
   {
   	int count = 0;
   	struct node *stack_sizePtr = stack_startPtr;
   	while (stack_sizePtr != NULL)
   	{
   		count++;
   		stack_sizePtr = stack_sizePtr->next;
   	}
   	
   	if (count == 0)
   	{
   		return true;
   	}
   	else
   	{
   		return false;
   	}
   }
   
   bool isEmptyQueue()
   {
   	if (que_startPtr == NULL)
   	{
   		return true;
   	}
   	else
   	{
   		return false;
   	}
   }
   
   void enqueue (char FN[], char LN[], int PUID, int age)
   {
   	if (queueSize() == 0)
   	{
   		que_startPtr = Createlistnode(FN, LN, PUID, age);
   	}
   	else
   	{
   		for (int i=0; i < queueSize()-1; i++)
   		{
   			current = current -> next;
   		}
   		current->next = Createlistnode(FN,LN,PUID,age);
   		struct node *display = current->next;
   		
   		printf("\nNew node created: %s, %s, %d, %d", display->FirstN, display->LastN, display->PUID, display->age);
   	}
   }
   
   void dequeue()
   {
   	struct node *tempPtr = que_startPtr;
   	que_startPtr = que_startPtr->next;
   	tempPtr->next = NULL;
   	printf("\nNew node created: %s, %s, %d, %d", tempPtr->FirstN, tempPtr->LastN, tempPtr->PUID, tempPtr->age);
   	
   	free(tempPtr);
   }
   
   void emptyStack()
   {
   	while (stack_startPtr->next != NULL)
   	{
   		struct node *s = stack_startPtr;
   		stack_startPtr = stack_startPtr -> next;
   		s -> next = NULL;
   		
	printf("\nNew node created: %s, %s, %d, %d", s->FirstN, s->LastN,  s->PUID, s->age);
  	free (s);
  	}
  	
  	printf("\nNew node created: %s, %s, %d, %d", stack_startPtr->FirstN, stack_startPtr->LastN,  stack_startPtr->PUID, stack_startPtr->age);
  	stack_startPtr = (node *) malloc(sizeof(struct node));
  	
   }
   
   void emptyQueue()
   {
   	while (que_startPtr->next != NULL)
   	{
   		struct node *tempPtr = que_startPtr;
   		que_startPtr = que_startPtr -> next;
   		tempPtr -> next = NULL;
   		
   		printf("Node is deleted: %s, %s, %d, %d\n", tempPtr->FirstN, tempPtr->LastN,  tempPtr->PUID, tempPtr->age);
  	free (tempPtr);
  	}
  	
  	printf("\nNode is deleted: %s, %s, %d, %d", que_startPtr->FirstN, que_startPtr->LastN,  que_startPtr->PUID, que_startPtr->age);
  	que_startPtr = NULL;
  	que_startPtr = (node *) malloc(sizeof(struct node));
  	
  }
   void printStack()
   {
   	struct node *temp_start = stack_startPtr;
   	int i = 1;
   	
   	while (temp_start != NULL)
   	{
   		printf("\nStudent %d holds: \n", i);
   		printf("============\n %s  \n", temp_start->FirstN);
   		printf("============\n %s  \n", temp_start->LastN);
   		printf("============\n %d  \n", temp_start->PUID);
   		printf("============\n %d  \n", temp_start->age);
   		temp_start = temp_start -> next;
   		i++;
   	}
   }
   
   void printQueue()
   {
   	struct node *temp_start = que_startPtr;
   	int i = 1;
   	
   	while (temp_start != NULL)
   	{
   		printf("\nStudent %d holds: \n", i);
   		printf("============\n %s  \n", temp_start->FirstN);
   		printf("============\n %s  \n", temp_start->LastN);
   		printf("============\n %d  \n", temp_start->PUID);
   		printf("============\n %d  \n", temp_start->age);
   		temp_start = temp_start -> next;
   		i++;
   	}
   }