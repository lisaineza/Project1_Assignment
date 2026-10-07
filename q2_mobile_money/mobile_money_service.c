#include <stdio.h>

/* Discards leftover characters after a failed scanf */
void clearInput(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main(void)
{
    double balance = 0.0, amount;
    int deposits = 0, withdrawals = 0;
    int choice, result;

    while (1)
    {
        printf("\n===== MOBILE MONEY TRANSACTION SYSTEM =====\n");
        printf("1. Deposit\n2. Withdraw\n3. Check Balance\n");
        printf("4. Transaction Summary\n5. Exit\n");
        printf("Enter choice: ");

        result = scanf("%d", &choice);
        if (result == EOF)
            break;
        if (result != 1)
        {
            clearInput();
            printf("Invalid input: please enter a number from 1 to 5.\n");
            continue;                       /* back to menu */
        }

        if (choice == 5)
        {
            printf("System terminated.\n");
            break;                          /* leave the loop */
        }

        switch (choice)
        {
        case 1:
            printf("Enter deposit amount: ");
            if (scanf("%lf", &amount) != 1)
            {
                clearInput();
                printf("Invalid input: amount must be a number.\n");
                continue;
            }
            if (amount <= 0)
            {
                printf("Transaction rejected: Amount must be positive.\n");
                continue;
            }
            balance += amount;
            deposits++;
            printf("Deposit successful.\n");
            printf("Current balance: %.0f RWF\n", balance);
            break;                          /* ends the switch case */

        case 2:
            printf("Enter withdrawal amount: ");
            if (scanf("%lf", &amount) != 1)
            {
                clearInput();
                printf("Invalid input: amount must be a number.\n");
                continue;
            }
            if (amount <= 0)
            {
                printf("Transaction rejected: Amount must be positive.\n");
                continue;
            }
            if (amount > balance)
            {
                printf("Transaction rejected: Insufficient balance.\n");
                continue;
            }
            balance -= amount;
            withdrawals++;
            printf("Withdrawal successful.\n");
            printf("Current balance: %.0f RWF\n", balance);
            break;

        case 3:
            printf("Current balance: %.0f RWF\n", balance);
            break;

        case 4:
            printf("Successful deposits   : %d\n", deposits);
            printf("Successful withdrawals: %d\n", withdrawals);
            break;

        default:
            printf("Invalid choice: select 1 to 5.\n");
            continue;
        }
    }
    return 0;
}