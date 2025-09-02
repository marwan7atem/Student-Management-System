/*
 * projectc.c
 *
 *  Created on: ١٣‏/٠٨‏/٢٠٢٤
 *      Author: LENOVO
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NULL 0
struct student
{
	int id;
	char name[50];
	int age;
	float gpa;
};
struct node
{
	struct student data;
	struct node *next;
};
struct node *head=NULL;
                         /**********functions prototypes**********/
void addStudent(const struct student *const ptr);
void displayStudents(void);
void searchStudentByID(int id);
void updateStudent(int id);
float calculateAverageGPA(void);
void searchHighestGPA(void);
void deleteStudent(int id);
                         /**********functions definitions**********/
//function to add anew student to the list
void addStudent(const struct student *const ptr)
{
	//check if id already exist
	struct node *current=head;
	while(current!=NULL)
	{
		if(current->data.id==ptr->id)
		{
			printf("Error:student id already exist\n");
			return;
		}
		current=current->next;
	}
	//Attempts to allocate memory for a new node.
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("Error:memory allocation failed\n");
		return;
	}
	//copy the student data to anew node
	newnode->data.id=ptr->id;
	strcpy(newnode->data.name,ptr->name);
	newnode->data.age=ptr->age;
	newnode->data.gpa=ptr->gpa;
	//add new node to the end of the linked list
	if(head==NULL)
	{
		head=newnode;
	}
	else{
		struct node*lastnode=head;
		while(lastnode->next!=NULL)
		{
			lastnode=lastnode->next;
		}
		lastnode->next=newnode;
	}

}
//function to displays the details of all students currently in the system.
void displayStudents(void)
{
	//check if list empty
	if(head==NULL)
	{
		printf(" no students are present\n ");
		return;
	}
	// traverses the list and prints the details of each student.
	struct node *current=head;
	while(current!=NULL)
	{
		printf("Student ID: %d\n",current->data.id);
		printf("Student Name: %s\n",current->data.name);
		printf("Student Age: %d\n",current->data.age);
		printf("Student GPA: %f\n",current->data.gpa);
		current=current->next;
	}
}
// function searches for a student by their ID and displays their details if found.
void searchStudentByID(int id)
{
	// searches for a student by their ID in the linked list
	struct node *current=head;
	while(current!=NULL)
	{
		//If the student is found, it prints their details.
		if(current->data.id==id)
		{
			printf("Student ID: %d\n",current->data.id);
			printf("Student Name: %s\n",current->data.name);
			printf("Student Age: %d\n",current->data.age);
			printf("Student GPA: %f\n",current->data.gpa);
			return;
		}
		current=current->next;
	}
	//If the student is not found, it prints a message indicating the student was not found.
	printf("student not found\n");
}
// function updates the details of a student with the given ID.
void updateStudent(int id)
{
//search for the student in the linked list
	struct node *current=head;
	while(current!=NULL)
	{
		if(current->data.id==id)
		{
			//update the student's information
			char name[50];
			int age;
			float gpa;
			//get the new information
			printf("please enter new student name:");
			scanf("%s",name);
			printf("please enter new student Age:");
			scanf("%d",&age);
			printf("please enter new student GPA:");
		    scanf("%f",&gpa);
		    //update the student information
		    strcpy(current->data.name,name);
		    current->data.age=age;
		    current->data.gpa=gpa;
		    printf("student information update successfully\n");
		    return;
		}
		current=current->next;
	}
	//If the student is not found, it prints a message indicating the student was not found
	printf("student not found\n");
}
//function calculates and returns the average GPA of all students.
float calculateAverageGPA(void)
{
	float totalGPA=0.0;
	int numstudents=0;
	// traverses the list to sum the GPAs of all students and counts the number of students.
	struct node *current = head;
	while (current != NULL) {
		totalGPA=totalGPA+current->data.gpa;
		numstudents++;
		current=current->next;
	}
	//check if list is empty
	if(numstudents==0)
	{
		return 0.0;
	}
	//Calculates and returns the average GPA of all students in the linked list.
	return totalGPA / numstudents;
}
// function finds and displays the student with the highest GPA.
void searchHighestGPA(void)
{
	float highestGPA=0.0;
	struct student highestGPAStudent;
	// traverses the list, keeping track of the student with the highest GPA encountered.
	struct node *current = head;
	    while (current != NULL) {
	        if (current->data.gpa > highestGPA) {
	            highestGPA = current->data.gpa;
	            highestGPAStudent = current->data;
	        }
	        current = current->next;
	    }
	    //check if there are any students in the list
	    if (highestGPA == 0.0)
	    {
	            printf("No students are present.\n");
	            return;
	    }
	    //details of the student with the highest GPA
	    printf("Student ID: %d\n", highestGPAStudent.id);
	    printf("Student Name: %s\n", highestGPAStudent.name);
	    printf("Student Age: %d\n", highestGPAStudent.age);
	    printf("Student GPA: %.2f\n", highestGPAStudent.gpa);

}
//function deletes a student from the linked list by their ID.
void deleteStudent(int id)
{
//check if list is empty
	if(head==NULL)
	{
		printf("No student are present\n");
		return;
	}
	//iterate through the linked list to find the student with the given ID
	 struct node *current = head;
	 struct node *previous = head;
	 while(current != NULL)
	 {
	   if(current->data.id == id)
	   {
	      // if the student is found, update the pointers to remove the node from the list
	      if(previous == NULL)
	      {
	         head = current->next;
	      }
	      else
	      {
	         previous->next = current->next;
	      }
	      // free the memory allocated for the node
	      free(current);
	      printf("Student with ID %d deleted successfully\n", id);
	      return;
	   }
	   previous = current;
	   current = current->next;
	 }
	 // if the student is not found, print a message indicating the student was not found
	 printf("Student with ID %d not found\n", id);
}
                          /**********Main program**********/
int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
   int choice;

   while(1)
   {
       // Display menu options
       printf("\n1. Add a Student\n");
       printf("\t2. Display All Students\n");
       printf("\t3. Search for a Student by ID\n");
       printf("\t4. Update Student Information\n");
       printf("\t5. Delete a Student\n");
       printf("\t6. Calculate Average GPA\n");
       printf("\t7. Find Student with Highest GPA\n");
       printf("\t8. Exit\n");

       // Take users choice as input
       scanf("%d",&choice);

       switch(choice)
       {
           case 1:
               struct student ptr;

               // Get new students details from user
               printf("\nEnter new student's ID:");
               scanf("%d",&ptr.id);
               printf("\nEnter new student's name:");
               scanf("%s",ptr.name);
               printf("\nEnter new student's age:");
               scanf("%d",&ptr.age);
               printf("\nEnter new student's GPA:");
               scanf("%f",&ptr.gpa);

               // Add new student to linked list
               addStudent(&ptr);

               break;

           case 2:
               displayStudents();
               break;

           case 3:
               int id;

               // Get ID from user to search for a student
               printf("\nEnter ID to search for a student:");
               scanf("%d",&id);

               // Search for a student by ID and display details
               searchStudentByID(id);

               break;

           case 4:
               int id_update;

               // Get ID from user to update a students information
               printf("\nEnter ID to update a student:");
               scanf("%d",&id_update);

               // Update a students information
               updateStudent(id_update);

               break;

           case 5:
              int id_delete;

              // Get ID from user to delete a students record
              printf("\nEnter ID to delete a student:");
              scanf("%d",&id_delete);

              // Delete a student's record
              deleteStudent(id_delete);

              break;

           case 6:
              float averageGPA;

              // Calculate and display average GPA of all students
              averageGPA = calculateAverageGPA();
              printf("\nAverage GPA of all students: %.2f",averageGPA);

              break;

           case 7:
        	   float highestGPA;
             // Find and display details of the student with highest GPA
             searchHighestGPA();

             break;

           case 8:
             exit(0);
           default:
             printf("Invalid choice. Please choose a valid option.\n");
       }
   }
}

