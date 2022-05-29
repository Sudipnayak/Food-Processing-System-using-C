//-----------------------------------complete and in working condition-------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//-----------------------------------display menu function--------------------------------------------------------------------------------
char display_menu(void)
{
    FILE *mn;
    char ch;
    mn = fopen("menu.txt", "r");
    if (mn == NULL)
    {
        printf("Error in opening file.\n");
        exit(0);
    }

    while (1)
    {
        ch = fgetc(mn);
        if (ch == EOF)
            break;
        printf("%c", ch);
    }
    fclose(mn);
}
//----------------------------------------------function complete--------------------------------------------------------------------------
//----------------------------------------------add on menu function-----------------------------------------------------------------------
char display_add()
{
    FILE *add;
    char word;
    add = fopen("add_on_menu.txt", "r");
    if (add == NULL)
    {
        printf("Error in opening file");
        exit(0);
    }

    while (1)
    {
        word = fgetc(add);
        if (word == EOF)
            break;
        printf("%c", word);
    }
    return 0;
}
//-----------------------------------------------function complete---------------------------------------------------------------------------
int main()
{
    char in, user_name[20];
    int i = 0;
    int order;
    float total = 0, amount[60];
    struct menu
    {
        int list_no;
        int quantity;
        float price;
    } item[60];
    //------------------------------list of price-----------------------------------------
    item[0].price = 89 ;
   
    item[1].price =  99 ;
   
    item[2].price =  129;
   
    item[3].price =  159;
    
    item[4].price =  169;
    
    item[5].price =  229;
    
    item[6].price =  119;
    
    item[7].price =  129;
    
    item[8].price =  139;
    
    item[9].price =  149;
    
    item[10].price =  159;
    
    item[11].price =   189;
    
    item[12].price =   159;
    
    item[13].price =   179;
   
    item[14].price =   179;
    
    item[15].price =   189;
    
    item[16].price =   189;
    
    item[17].price =   199;
    
    item[18].price =   179;
    
    item[19].price =   149;
    
    item[20].price =   219;
    
    item[21].price =   199;
    
    item[22].price =   199;
    
    item[23].price =   219;
    
    item[24].price =   219;
    
    item[25].price =   219;
     
    item[26].price =   219;
   
    item[27].price =   229;
  
    item[28].price =   239;
  
    item[29].price =   219 ;
 
    item[30].price =   89;
   
    item[31].price =   169;
    
    item[32].price =   259;
    
    item[33].price =   239;
    
    item[34].price =   249;

    item[35].price =   39;

    item[36].price =   79;
    
    item[37].price =   29;
    
    item[38].price =   79;
    
    item[39].price =   59;
    
    item[40].price =   19;
    
    item[41].price =  49;
    
    item[42].price =  69;
    
    item[43].price =  39;
    
    item[44].price =  29;
    
    //--------------------------------------------------user detail-----------------------------------------------
    
    printf("Welcome\nPlease enter your full name - ");
    scanf("%[^\n]%*c", &user_name);

    do
    {
        //--------------------------------------------display menu-----------------------------------------------
        display_menu();
        //--------------------------------------------menu input from user--------------------------------------------
        printf("Enter your choice - ");
        scanf("%d", &order);
        if (order < 1 || order > 35)
        {
            system("clear");
            printf("Invalid Input, Try Again\n");
            continue;
        }

        printf("Enter the quanity of order- ");
        item[i].list_no = order;
        scanf("%d", &item[i].quantity);
        amount[i] = item[order - 1].price * item[i].quantity;

        total += amount[i];
        i++;
        printf("Enter y for more order- ");
        scanf("%s", &in);
        system("clear");
    } while (in == 'y');
    do
    {
        //--------------------------------------------display add on menu-----------------------------------------------
        display_add();
        //--------------------------------------------add on menu input from user--------------------------------------------
        printf("Enter your choice - ");
        scanf("%d", &order);
        if (order < 36 || order > 45)
        {
            system("clear");
            printf("Invalid Input, Try Again\n");
            continue;
        }
        if (order==14)
        {
            system("clear");
            break;
        }
        

        printf("Enter the quanity of order- ");
        item[i].list_no = order;
        scanf("%d", &item[i].quantity);
        amount[i] = item[order - 1].price * item[i].quantity;

        total += amount[i];
        i++;
        printf("Enter y for more order- ");
        scanf("%s", &in);
        system("clear");
    } while (in == 'y');

    display_menu();
    display_add();
    printf("Customer Name - %s\n\n",user_name);
    printf("| Item No | Quantity | Price | Amount |\n");
    for (int j = 0; j < i; j++)
    {
        printf("|%3d %10d %12.2f %8.2f |\n", item[j].list_no, item[j].quantity, item[item[j].list_no - 1].price, amount[j]);
    }

    printf("Your bill is - ₹ %.2f\n", total);
    printf("Thank you for vising us.\nHope we can see you again.\n");

    return 0;
}