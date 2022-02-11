#include <stdlib.h>
#include <string.h>
#include <stdio.h>
struct Vaccine
{
    int AadharId;
    char name[100];
    char phone[100];
    int TimeSlot;
    struct Vaccine *next;

} * head;
//---------------------------------------------------------------------------------------------------------------//
void insert(int AadharId, char *name, char *phone, float TimeSlot)
{

    struct Vaccine *vaccine = (struct Vaccine *)malloc(sizeof(struct Vaccine));
    vaccine->AadharId = AadharId;
    strcpy(vaccine->name, name);
    strcpy(vaccine->phone, phone);
    vaccine->TimeSlot = TimeSlot;
    vaccine->next = NULL;

    if (head == NULL)
    {

        head = vaccine;
    }
    else
    {
        vaccine->next = head;
        head = vaccine;
    }
}
//------------------------------------------------------------------------------------------------------------------//
// searching registration data (by aadhar id)
void search(int AadharId)
{
    struct Vaccine *temp = head;
    printf("\n---------------------------------------------------------------------------\n");
    while (temp != NULL)
    {
        if (temp->AadharId == AadharId)
        {
            printf("\nName: %s\n", temp->name);
            printf("\nAadhar id: %d\n", temp->AadharId);
            printf("\nPhone: %s\n", temp->phone);
            if (temp->TimeSlot == 1)
            {
                printf("\nYour Time slot is :\n\n1->10:00 to 11:00AM", temp->TimeSlot);
                printf("\n---------------------------------------------------------------------------\n");
            }
            else if (temp->TimeSlot == 2)
            {
                printf("\nYour Time slot is :\n\n2->11:00 to 12:00PM", temp->TimeSlot);
                printf("\n---------------------------------------------------------------------------\n");
            }
            else
            {
                printf("\nYour Time slot is :\n\n2->12:00 to 1:00PM", temp->TimeSlot);
                printf("\n---------------------------------------------------------------------------\n");
            }
            return;
        }
        temp = temp->next;
    }
    printf("Vaccine with vaccine id %d is not found !!!\n", AadharId);
}
//-----------------------------------------------------------------------------------------------------------------------//
// updating member details
void update(int AadharId)
{

    struct Vaccine *temp = head;
    while (temp != NULL)
    {

        if (temp->AadharId == AadharId)
        {
            printf("\nRecord with vaccine id %d Found !!!\n", AadharId);
            printf("\nEnter new name: ");
            scanf("%s", temp->name);
            printf("\nEnter new phone number: ");
            scanf("%s", temp->phone);
            printf("\nEnter new TimeSlot: ");
            printf("\n1-> 10:00 to 11:00AM\n\n2-> 11:00 to 12:00PM\n\n3-> 12:00 to 1:00PM\n");
            printf("\nSelect Time slot :");
            scanf("%d", &temp->TimeSlot);
            printf("\nUpdation Successful!!!\n");
            printf("\n-------------------------------------------------------------------------\n");
            return;
        }
        temp = temp->next;
    }
    printf("No data found for Aadhar id %d  !!!\n", AadharId);
}
//---------------------------------------------------------------------------------------------------------------------//
// cancel- registration
void Delete(int AadharId)
{
    struct Vaccine *temp1 = head;
    struct Vaccine *temp2 = head;
    while (temp1 != NULL)
    {

        if (temp1->AadharId == AadharId)
        {

            printf("\n\nRecord with Aadhar id %d Found !!!\n\n", AadharId);

            if (temp1 == temp2)
            {

                head = head->next;
                free(temp1);
            }
            else
            {

                temp2->next = temp1->next;
                free(temp1);
            }

            printf("\nRecord Successfully Deleted !!!\n\n");
            printf("\n-------------------------------------------------------------------------\n");
            return;
        }
        temp2 = temp1;
        temp1 = temp1->next;
    }
    printf("\n\nNo data found for Aadhar id %d  !!!\n\n", AadharId);
}
//----------------------------------------------------------------------------------------------------------------------//
// display-member data
void display()
{
    struct Vaccine *temp = head;
    printf("\n---------------------------------------------------------------------------\n");
    while (temp != NULL)
    {

        printf("\nAadhar id: %d\n", temp->AadharId);
        printf("\nName: %s\n", temp->name);
        printf("\nPhone: %s\n", temp->phone);
        if (temp->TimeSlot == 1)
        {
            printf("\nYour Time slot is :\n\n1.10:00 to 11:00AM\n", temp->TimeSlot);
            printf("\n***********\n");
        }
        else if (temp->TimeSlot == 2)
        {
            printf("\nYour Time slot is :\n\n2.11:00 to 12:00PM\n", temp->TimeSlot);
            printf("\n***********\n");
        }
        else
        {
            printf("\nYour Time slot is :\n\n2.12:00 to 1:00PM\n", temp->TimeSlot);
            printf("\n***********\n");
        }
        temp = temp->next;
    }
    printf("\n---------------------------------------------------------------------------\n");
}
//--------------------------------------------------------------------------------------------------------------------------//
// driver program
int main()
{
    head = NULL;
    int choice;
    char name[100];
    char phone[100];
    int AadharId;
    float TimeSlot;
    printf("-------------------------------------------------------------------------\n");
    printf("\t\t\tVACCINE REGISTRATION\t\t\t\n");
    printf("-------------------------------------------------------------------------\n");
    printf("\n1  Register for vaccine\n2  Check registration details\n3  Cancel registration\n4  Update details\n5  Display all\n6 Exit");
    printf("\n-------------------------------------------------------------------------\n");
    do
    {
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            printf("\n\n\t\t\t*** REGISTRATION ***\t\t\t\n\n");

            printf("\nEnter aadhar id:");
            scanf("%d", &AadharId);
            printf("\nEnter name: ");
            scanf("%s", name);
            printf("\nEnter phone number: ");
            scanf("%s", phone);
            printf("\n1-> 10:00 to 11:00AM\n\n2-> 11:00 to 12:00PM\n\n3-> 12:00 to 1:00PM\n");
            printf("\nSelect Time slot :");
            scanf("%d", &TimeSlot);

            printf("\nSUCCESFULLY REGISTERED FOR VACCINATION!!\n");
            int vacId = rand();
            printf("\nYOUR SECRET CODE/VACCINE ID IS %d \n", rand());
            printf("\n-------------------------------------------------------------------------\n");
            insert(AadharId, name, phone, TimeSlot);
            break;
        case 2:

            printf("\n\n\t\t\t**REGISTRATION DETAILS***\t\t\t\n\n");

            printf("Enter Aadhar id to search: ");
            scanf("%d", &vacId);
            search(AadharId);
            break;
        case 3:

            printf("\n\n\t\t\t***CANCEL REGISTRATION***\t\t\t\n\n");

            printf("Enter Aadhar id to delete: ");
            scanf("%d", &AadharId);
            Delete(AadharId);
            break;
        case 4:

            printf("\n\n\t\t\t**UPDATE REGISTRATION DETAILS*\t\t\t\n\n");

            printf("Enter Aadhar id to update: ");
            scanf("%d", &AadharId);
            update(AadharId);
            break;
        case 5:

            printf("\n\n\t\t\t**REGISTRATION DATA*\t\t\t\n\n");

            display();
            break;

        case 6:
            printf("\nTHANK YOU FOR REGISTERING.STAY HOME!! STAY SAFE!!\n\n");
            exit(0);
        }

    } while (choice != 0);
}