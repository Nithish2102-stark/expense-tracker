#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense
{
    int id;
    char name[50];
    char category[50];
    float amount;
    char date[20];
};
void showMenu();
int isUniqueID(struct Expense *e,int count,int id); //checking unique
void addExpense(struct Expense **e,int *count); // Add new expense
void displayExpenses(struct Expense *e,int count);// Display expenses
void searchExpense(struct Expense *e,int count); // Search expenses
void updateExpense(struct Expense *e,int count); // Update expense amount
void calculateExpense(struct Expense *e,int count); // Calculate total,average,highest expense
int main()
{
    struct Expense *expenses=malloc(0);
    int count = 0;
    int choice;
    do
    {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                addExpense(&expenses,&count);
                calculateExpense(expenses,count);   /* sample output requirement */
                break;
            }
            case 2:
            {
                displayExpenses(expenses,count);
                break;
            }
            case 3:
            {
                searchExpense(expenses,count);
                break;
            }
            case 4:
            {
                updateExpense(expenses,count);
                break;
            }
            case 5:
            {
                calculateExpense(expenses,count);
                break;
            }
            case 6:
            {
                free(expenses);
                printf("Exiting application...\n");
                break;
            }
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice!=7);
    return 0;
}

void showMenu()
{
    printf("\n_______ Startup Expense Tracker __________\n");
    printf("1. Add Expense\n");
    printf("2. Display All Expenses\n");
    printf("3. Search Expense by ID\n");
    printf("4. Update Expense Amount\n");
    printf("5. Calculate Total Expense\n");
    printf("6. Exit\n");
}

int isUniqueID(struct Expense *e,int count,int id) //checking unique
{
    for(int i=0;i<count;i++)
    {
        if(e[i].id==id)
            return 0;
    }
    return 1;
}

void addExpense(struct Expense **e,int *count) // Add new expense
{
    int id;
    float amount;
    char name[50],category[50],date[20];

    printf("Enter Expense ID: ");
    scanf("%d", &id);
    if(!isUniqueID(*e,*count,id))
    {
        printf("Expense ID already exists...\n");
        return;
    }
    printf("Enter Expense Name: ");
    scanf(" %[^\n]", name);
    printf("Enter Category: ");
    scanf(" %[^\n]", category);
    printf("Enter Amount: ");
    scanf("%f", &amount);

    if(amount<=0)
    {
        printf("Amount must be greater than zero\n");
        return;
    }
    printf("Enter Date (DD/MM/YYYY): ");
    scanf(" %[^\n]", date);
    
    *e = realloc(*e, (*count + 1) * sizeof(struct Expense));
    (*e)[*count].id = id;
    (*e)[*count].amount = amount;
    strcpy((*e)[*count].name, name);
    strcpy((*e)[*count].category, category);
    strcpy((*e)[*count].date, date);

    (*count)++;
    printf("Expense added successfully\n");
}

void displayExpenses(struct Expense *e, int count) // Display expenses
{
    if(count==0)
    {
        printf("No expenses available\n");
        return;
    }
    for(int i=0;i<count;i++)
    {
        printf("\nID       : %d",e[i].id);
        printf("\nName     : %s",e[i].name);
        printf("\nCategory : %s",e[i].category);
        printf("\nAmount   : %.2f",e[i].amount);
        printf("\nDate     : %s\n",e[i].date);
    }
}

void searchExpense(struct Expense *e, int count) // Search expenses
{
    int id;
    printf("Enter Expense ID to search: ");
    scanf("%d", &id);

    for(int i=0;i<count;i++)
    {
        if (e[i].id == id)
        {
            printf("Expense Found\n");
            printf("Name: %s\n", e[i].name);
            printf("Amount: %.2f\n", e[i].amount);
            return;
        }
    }
    printf("Expense not found\n");
}

void updateExpense(struct Expense *e, int count) // Update expense amount
{
    int id;
    float amount;
    printf("Enter Expense ID: ");
    scanf("%d", &id);

    for(int i=0;i<count;i++)
    {
        if(e[i].id==id)
        {
            printf("Enter new amount: ");
            scanf("%f", &amount);
            if(amount<=0)
            {
                printf("Invalid amount\n");
                return;
            }
            e[i].amount=amount;
            printf("Expense updated successfully\n");
            return;
        }
    }
    printf("Expense ID not found\n");
}

void calculateExpense(struct Expense *e, int count) // Calculate total,average,highest expense
{
    if(count==0)
        return;

    float total=0;
    float max=e[0].amount;
    int maxIndex=0;

    for(int i=0;i<count;i++)
    {
        total+=e[i].amount;
        if(e[i].amount>max)
        {
            max=e[i].amount;
            maxIndex=i;
        }
    }
    printf("Total Expense: %.2f\n",total);
    printf("Average Expense: %.2f\n",total/count);
    printf("Highest Expense: %.2f (%s)\n",max,e[maxIndex].name);
}
