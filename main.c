#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int choice;
char name[20];
int phone;
char email[20];

// ender variables
int ender_choice;

int main()
{

	printf("\n\t\t Welcome to Contact Managment System.\n\n");

	// Choice
	printf("\t\t======================");
	printf("\n\t\t [1] Add new contact");
	printf("\n\t\t [2] List all contacts");
	printf("\n\t\t [3] Edit a contact");
	printf("\n\t\t [4] Delete a contact");
	printf("\n\t\t [0] Exit program");
	printf("\n\t\t======================");

	// enter your choice
	printf("\n\n\t\t Enter your choice: ");
	scanf("%d", &choice);

	switch (choice)
	{
	case 0:
		exit(0);
		break;

	case 1:
		system("cls");
		printf("Enter name: ");
		scanf("%s", name);
		printf("Enter phone number: ");
		scanf("%d", &phone);
		printf("Enter email address: ");
		scanf("%s", email);

		FILE *contacts_file = fopen("contacts.dll", "a");
		fprintf(contacts_file, "%s\t%d\t%s\n", name, phone, email);
		fclose(contacts_file);

		// ender
		printf("\n\nMain menu [1]");
		printf("\tExit [Any key]\n\t");
		scanf("%d", &ender_choice);
		break;

	case 2:
	{
		char line[1000];
		system("cls");

		FILE *contacts_file = fopen("contacts.dll", "r");
		printf("\tList of contacts\n\n");

		while (fgets(line, sizeof(line), contacts_file) != NULL)
		{
			printf("%s", line);
		}

		fclose(contacts_file);
		break;
	}
	}

	if (ender_choice == 1)
	{
		system("cls");
		main();
	}
	else if (ender_choice == 0)
	{
		exit(0);
	}

	return 0;
}