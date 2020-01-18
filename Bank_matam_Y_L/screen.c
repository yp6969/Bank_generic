/*********************************************************
manage all the oparation in front of the user
*********************************************************/
#include "screen.h"

/*the main manu of the system to easely navigate*/
void screenSystem(){
    int option ;
    printf("\nHello and welcome to %s's Bank\nwhere your money need to be safe!! :) \n\n", bank.nameOfBank );
    FOREVER {
        printf("******************************************\n");
        printf("\nchose youre option:\n\n");
        printf(" 1)Bank meneger\n");
        printf(" 2)Branch meneger\n");
        printf(" 3)Client\n");
        printf(" 4)Exit \n");
        printf("******************************************\n");
        scanf("%d",&option);
        getchar();
        switch(option){
            case 1:
                bankMenegerOption();
                continue;

            case 2:
                if(!(bank.numberOfBranch)){
                    printf("\nThere is no branches yet\nPlease creat one in the bank option\n\n" );
                    continue;
                }
                else{
                    branchMenegerOption();
                    continue;
                }

            case 3:
                if(!(bank.numberOfBankClients)){
                    printf("\nThere is no clients yet\nPlease creat one in the bank option\n\n" );
                    continue;
                }
                else{
                    clientOption();
                    continue;
                }
            case 4:
                printf("\nGood Bye!!!\n\n");
                return;

            default: 
                printf("\nwrong choise try again\n");
                continue;
        }
    }
    return;
}

/*menu of the bank meneger option only*/
void bankMenegerOption(){
    D_Llinked_List* list = ALLOC( D_Llinked_List , 1 );
    int option , cnt_client;
    printf("Hello %s the graitest meneger in the world\nwhat are you willing to do?\n\n" , bank.nameOfBank);
    FOREVER{
        printf("**************************************\n");
        printf(" 1)Print bank information\n");
        printf(" 2)Add new branch\n");
        printf(" 3)Client number of bank\n");
        printf(" 4)Averege number Client of bank\n");
        printf(" 5)Find client in bank\n");
        printf(" 6)Delete all Branches\n");
        printf(" 7)Delete branch\n");
        printf(" 8)Go back \n\n");
        printf("*************************************\n");
        scanf("%d",&option);
        getchar();
        switch(option){
            case 1:
                print_Bank_Parameters();
                continue;
            case 2:
                add_New_Branch_t();
                continue;
            case 3:
                printf("client number is: %d\n" , client_in_bank());
                continue;
            case 4:
                printf("The avereg is : %g \n" , average_Number_Of_Accounts_In_Branches( bank.branchHead ));
                continue;
            case 5:
            if(bank.numberOfBranch == 0 ){
                    printf("\nThere is no branches yet\nPlease creat one in the bank\n\n" );
                    continue;
                }
                else{
                    find_Client(list);
                    continue;
                }
            case 6:
                if(bank.numberOfBranch == 0 ){
                    printf("\nThere is no branches yet\nPlease creat one in the bank\n\n" );
                    continue;
                }
                else{
                    bank.branchHead = delete_All_Branchs( bank.branchHead );
                    continue;
                }
            case 7:
                if(bank.numberOfBranch == 0 ){
                    printf("\nThere is no branches yet\nPlease creat one in the bank\n\n" );
                    continue;
                }
                else{
                    printf("Choose one of the following\n");
                    print_all_Client_Id(bank.branchHead);
                    bank.branchHead = delete_Branch( bank.branchHead , getBranchId() );///////////
                    continue;
                }
            case 8:
                return;
            default:
                printf("wrong choise try again\n");
        }
    }
    return;
}

/*menu of the branch meneger option only*/
void branchMenegerOption(){
    int option , count = 0 , flag = 0 , tmpAccountBalance;
    Branch* branch;
    /* searching the spucific branch */
    do{
        if(flag) printf(" Wrong branch ID rty again ");
        printf("Choose one of the next branches\n");
        print_all_Branch_Id(bank.branchHead);
        branch = search_Branch_By_Id( bank.branchHead , getBranchId() );
        flag = 1;
    }while(!branch);
    printf("Hello Branch meneger number %d!! \nwhat are you willing to do?\n\n" , branch->branchId);
    FOREVER{
        printf("*************************************************\n");
        printf(" 1)Show Branch deatails\n");
        printf(" 2)Add new client to branch\n");
        printf(" 3)client number with given balance\n");
        printf(" 4)client number with bigger loans then balance \n");
        printf(" 5)Print client acount number and balance \n");
        printf(" 6)Delete All branch clients \n");
        printf(" 7)Delete client \n");
        printf(" 8)Go back\n");
        printf("*************************************************\n");
        scanf("%d",&option);
        getchar();
        switch(option){
            case 1:
                print_Branch_Details(branch);
                continue;
            case 2:
                add_Client_To_Branch_t(branch);
                continue;
            case 3:
                tmpAccountBalance = getAcountBalance();
                printf("The number of clients with the wanted balance is : ");
                printf(" %d \n", client_Number_With_Given_Balance(branch->clientHead , tmpAccountBalance , &get_balance ));
                continue;
            case 4:
                printf("The number of clients with the wanted balance is : ");
                printf(" %d \n", client_Number_With_Bigger_Loans_Then_Balance(branch->clientHead , &cmp_balance_loan ));
                continue;
            case 5:
                print_all_Client_Acount_Number_And_Balance(branch->clientHead);
                continue;
            case 6:
                if(branch->numberOfBranchClients == 0 ){
                    printf("\nThere is no client yet\nPlease creat one in the branch option\n\n" );
                    continue;
                }
                else{
                    branch->clientHead = delete_All_Branch_Clients(branch->clientHead);
                    continue;
                }
            case 7:
                if(branch->numberOfBranchClients == 0 ){
                    printf("\nThere is no client yet\nPlease creat one in the branch option\n\n" );
                    continue;
                }
                else{
                    printf("Choose one of the following\n");
                    print_all_Client_Id(branch->clientHead);
                    branch->clientHead = delete_Client(branch->clientHead , getClientId() );
                    continue;
                }
            case 8:
                return;
            default:
                printf("wrong choise try again\n");
        }
    }
    return;
}


/*menu of the client option only*/
void clientOption(){
    Branch* branch;
    Client* client;
    int option , flag = 0 ;
    FOREVER{
        if(flag) printf(" Wrong branch or client ID try again ");
        flag = 1;
        printf("Choose one of the next branches\n");
        print_all_Branch_Id(bank.branchHead);
        branch = search_Branch_By_Id( bank.branchHead , getBranchId() );
        if(!branch) continue;
        printf("Choose one of the next client\n");
        print_all_Client_Id(branch->clientHead);
        client = search_Client_By_Id_in_branch( branch->clientHead , getClientId() );
        if(!client) continue;
        break;
    }
    /*  chose youre option */
    printf("Hello Client %d!! \nwhat are you willing to do?\n\n", client -> accountNumber);
    FOREVER{
        printf("*************************************\n");
        printf(" 1)See client deatails\n");
        printf(" 2)Deposite money to account\n");
        printf(" 3)Deposite money to save\n");
        printf(" 4)ask for loan \n");
        printf(" 5)Repay loans\n");
        printf(" 6)Go back\n");
        printf("************************************\n");
        scanf("%d",&option);
        getchar();
        switch(option){
            case 1:
                print_Client_Details(client);
                 
                continue;
            case 2:
                depositeMoneyToClientAccount(client);
                 
                continue;
            case 3:
                depositeMoneyToSave(client);
                 
                continue;
            case 4:
                loanToClient(client , branch);
                 
                continue;
            case 5:
                repayClientLoans(client , branch);
                 
                continue;
            case 6:
                return;
            default:
                printf("\nwrong choise try again\n");
        }
    }
    return;
}
