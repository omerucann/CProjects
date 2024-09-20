#include <stdio.h>
#include <unistd.h>

int main()
{
    int choice;
    int deposit_money;
    int withdraw_money;
    int balance;
    int transfer;
    int back;
    int pay;
    int start;
    int i;

    start = 5;
    balance = 1000;
    choice = 0;

    while(1 & choice == 0)
    {
        printf("Welcome to UCN Bank. How can I help you ?\n");
        printf("1. I want to deposit money\n");
        printf("2. I want to withdraw money\n");
        printf("3. I want to know my balance\n");
        printf("4. I want to transfer money to another account\n");
        printf("5. I want to pay\n");
        printf("Please Enter the number of your choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("\nPlease enter the amount you want to deposit: ");
            scanf("%d", &deposit_money);

            balance = balance + deposit_money;

            for(i = start; i>=0; i--)
            {
                printf("%d\n", i);
                sleep(1);
            }
            printf("Your Balance Updated. Please Wait\n");
            sleep(3);
            choice = 0;
        }
        else if(choice == 2)
        {
            printf("Please enter the amount you want to withdraw: ");
            scanf("%d", &withdraw_money);

            if(balance - withdraw_money >= 0)
            {
                balance = balance - withdraw_money;
                printf("Your transaction is being processed, please wait.\n");

                for(i = start; i>0; i--)
                {
                    printf("%d\n", i);
                    sleep(1);
                }
                printf("Your Balance Updated. Please Wait\n");
                sleep(1);
                choice = 0;
            }
            else
            {
                printf("Insufficient funds. Please wait.\n");
                sleep(3);
                choice = 0;
            }
        }
        else if(choice == 3)
        {
            printf("Your Balance = %d\n", balance);
            printf("Press to 0 for back to main menu\n");
            scanf("%d", &choice);
        }
        else if(choice == 4)
        {
            int pref;
            long account;

            printf("Please enter the number of the account to which the transfer will be made.\n");
            printf("Account Number = ");
            scanf("%ld", &account);
            printf("Amount to be Sent: %ld Do you approve ? \n", account);
            printf("1.Yes\n");
            printf("2.No\n");
            scanf("%d", &pref);

                if(pref == 1)
                {
                    printf("Please enter the amount you want to send: ");
                    scanf("%d", &transfer);
                    if(transfer <= balance)
                    {
                        printf("Please Wait Your transfer is being carried out\n");
                        sleep(3);
                        printf("Transfer successful\n");
                        sleep(2);
                        balance = balance - transfer;
                        choice = 0;
                    }
                    else
                    {
                        printf("Insufficient Balance\n");
                        sleep(2);
                        choice = 0;
                    }
                }
                else if(pref == 2)
                {
                    choice = 0;
                }
                else
                {
                    printf("You made a wrong keystroke\n");
                    choice = 0;
                }

        }
        else if(choice == 5)
        {
            int select;
            char election;

            printf("Please select payment type\n1.Bank Payment\n2.Donation\n3.Bill Payment\n4.Tax Payments\n5.Other\n");
            scanf("%d", &select);
            if(select == 1)
            {
                printf("Enter the amount you want to pay: ");
                scanf("%d", &pay);
                printf("Amount: %d Do you approve ? y/n \n", pay);
                scanf("%s", &election);

                if(election == 'y')
                {
                    if(balance >= pay)
                    {
                        printf("Please Wait\n");
                        sleep(3);
                        printf("Payment successful\n");
                        sleep(1);
                        balance = balance - pay;
                        choice = 0;
                    }
                    else
                    {
                        printf("Insufficient funds\n");
                        sleep(2);
                        choice = 0;
                    }
                }
                else if(election == 'n')
                {
                    choice = 5;
                }
                else
                {
                    printf("You made a wrong keystroke\n");
                    choice = 5;
                }

                
            }
            else if(select == 2)
            {
                char organization[50];
                int donate;

                printf("Please enter the name of the organization to donate to: ");
                scanf("%s", &organization);
                printf("Enter the amount of donation you want to make to %s Institution: ", organization);
                scanf("%d", &donate);

                if(donate <= balance)
                {
                    printf("Your transaction is being processed, please wait.\n");
                    sleep(2);
                    printf("A donation of %d amount was made to institution %s.\n", donate, organization);
                    sleep(2);
                    balance = balance - donate;
                    choice = 0;
                }
                else
                {
                    printf("insufficient funds\n");
                    sleep(2);
                    choice = 0;
                }
            }
            else if(select == 3)
            {
                char type[50];
                int paid;

                printf("Enter the type of invoice you want to pay: ");
                scanf("%s", &type);
                printf("Enter the amount to be paid: ");
                scanf("%d", &paid);

                if(paid <= balance)
                {
                    printf("Your bill is paid\n");
                    sleep(2);
                    printf("Payment successful\n");
                    sleep(2);
                    balance = balance - paid;
                    choice = 0;
                }
                else
                {
                    printf("insufficient funds\n");
                    sleep(2);
                    choice = 0;                   
                }
            }

            else if(select == 4)
            {
                char variety[50];
                int tax;
                printf("Enter the type of tax you want to pay: ");
                scanf("%s", &variety);
                printf("enter the amount to be paid: ");
                scanf("%d", &tax);
                
                if(tax <= balance)
                {
                    printf("Your transaction is being processed\n");
                    sleep(2);
                    printf("Payment successful\n");
                    sleep(2);
                    balance = balance - tax;
                    choice = 0;
                }
                else
                {
                    printf("insufficient funds\n");
                    sleep(2);
                    choice = 0;   
                }
            }

            else if(select == 5)
            {
                char paytype[50];
                int other;

                printf("Please enter the payment type you want to make: ");
                scanf("%s", &paytype);
                printf("Enter the amount you want to pay: ");
                scanf("%d", &other);

                if(other <= balance)
                {
                    printf("Your transaction is being processed\n");
                    sleep(2);
                    printf("Payment successful\n");
                    sleep(2);
                    balance = balance - other;
                    choice = 0;                    
                }
                else
                {
                    printf("insufficient funds\n");
                    sleep(2);
                    choice = 0;   
                }
            }
        }
        else if(choice > 5 || choice < 0)
        {
            printf("You made a wrong keystroke and you are directed to the main menu.\n");
            sleep(2);
            choice = 0;
        }
    }
}
