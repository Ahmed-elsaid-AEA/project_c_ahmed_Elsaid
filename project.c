#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10

typedef struct
{
    char user_Name[20];
    char password[20];
} User;

User users[MAX_USERS];
int user_Count = 0;

int registerUser()
{
    if (user_Count >= MAX_USERS)
    {
        printf("Registration failed. Maximum user limit reached.\n");
        return 0;
    }

    User newUser;

    printf("Enter a user_Name: ");
    scanf("%s", newUser.user_Name);

    for (int n = 0; n < user_Count; n++)
    {
        if (strcmp(users[n].user_Name, newUser.user_Name) == 0)
        {
            printf("user_Name already exists. Registration failed.\n");
            return 0;
        }
    }

    printf("Enter a password: ");
    scanf("%s", newUser.password);

    users[user_Count++] = newUser;
    printf("Registration successful.\n");

    return 1;
}

int loginUser()
{
    char user_Name[20];
    char password[20];

    printf("Enter your user_Name: ");
    scanf("%s", user_Name);

    printf("Enter your password: ");
    scanf("%s", password);

    for (int n = 0; n < user_Count; n++)
    {
        if (strcmp(users[n].user_Name, user_Name) == 0 && strcmp(users[n].password, password) == 0)
        {
            printf("Login successful. Welcome, %s!\n", user_Name);
            return 1;
        }
    }

    printf("Login failed. Incorrect user_Name or password.\n");
    return 0;
}

int main()
{
    int choice;
    int logged_In = 0;

    while (1)
    {
        printf("1. Register\n2. Login\n3. Quit\nEnter your choice: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            if (registerUser())
            {
            }
        }
        else if (choice == 2)
        {
            if (loginUser())
            {
                logged_In = 1;
            }
        }
        else if (3)
        {
            printf("see you later!\n");
            return 0;
        }
        else
        {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}