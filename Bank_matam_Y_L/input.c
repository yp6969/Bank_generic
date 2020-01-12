#define _XOPEN_SOURCE 500
#include <string.h>
#include "input.h"
/*******************************************************************/
/**** checking and making the allocated blocks is the program ******/

static unsigned int allocated_blocks = 0;

void *checked_malloc(unsigned int size){
	void * ret;

	ret = malloc(size);
	if (!ret) {
		perror ("Memory allocation error");
		exit (1);
	}
	allocated_blocks++;
	return ret;
}


void checked_free (void *ptr)
{

	free(ptr);
	allocated_blocks--;
	return;
}

void check_for_exit() {
	if (allocated_blocks) {
		fprintf (stderr, "Memory leak: %d memory blocks still allocated \n", allocated_blocks);
		exit(1);
	}
        return;
}

/**********************************************************/
/*                      Bank inputs.                     */

/*this function is geting the name of the bank*/
void getNameOfBank(char** nameOfBank , int isInput ){
    
    char name[MAX_NAME];
    int flag=0;
    
    if(!isInput) {
        *nameOfBank = strdup( bank.nameOfBank );
        return;
    }

    do{
        if(flag){
            printf("Wrong value\n");
        }
        printf("Please ENTER name of bank\n");
        flag=1;
		fgets(name , MAX_NAME , stdin);
        name[strlen(name)-1] = '\0';
    }while(!checkNameOfBank(name));
    *nameOfBank = strdup( name );
    allocated_blocks++;
    return ;
}

/*this function is geting the nunber of the bank clients*/
int getNumberOfBankClients(){
    int num;
    int flag=0;
    do{
        if(flag){
            printf("Wrong value\n");
        }
        printf("Please ENTER number of bank clients\n");
        flag=1;
        scanf("%d" , &num);
        getchar();
    }while(!checkNumberOfBankClients(num));
    return num;
}

/*this function is geting the number of the branches*/
int getNumberOfBranch(){
  int num;
  int flag=0;
  do{
      if(flag){
          printf("Wrong value\n");
      }
      printf("Please ENTER number of branch\n");
      flag=1;
      scanf("%d" , &num);
      getchar();
  }while(!checkNumberOfBranch(num));

  return num;
}

/*this function is geting the sum of all bank clients*/
double getSumOfAllBankClients(){
  double num;
  int flag=0;
  do{
      if(flag){
          printf("Wrong value\n");
      }
      printf("Please ENTER sum of all bank clients\n");
      flag=1;
      scanf("%lf" , &num);
      getchar();
  }while(!checkSumOfAllBankClients(num));

  return num;
}

/*this function is geting the profit of the last year*/
double getProfitOfLastYear(){
  double num;
  int flag=0;
  do{
      if(flag){
          printf("Wrong value\n");
      }
      printf("Please ENTER profit of last year\n");
      flag=1;
      scanf("%lf" , &num);
      getchar();
  }while(!checkProfitOfLastYear(num));

  return num;
}

/*this function is geting the number of active loans*/
int getNumberOfActiveLoans(){
  int num;
  int flag=0;
  do{
      if(flag){
          printf("Wrong value\n");
      }
      printf("Please ENTER number of active loans\n");
      flag=1;
      scanf("%d" , &num);
      getchar();
  }while(!checkNumberOfActiveLoans(num));

  return num;

}

/**********************************************************/
/*                     Branch inputs.                    */

/*this function is geting string name of the branch with known size and replace it with lower size new one*/
void getNameOfBranch(char** nameOfBranch){
    char name[MAX_NAME];
    int flag=0;
    do{
        if(flag){
            printf("Wrong value\n");
        }
        printf("Please ENTER name of branch\n");
        flag=1;
		fgets(name , MAX_NAME , stdin);
        name[strlen(name)-1] = '\0';
    }while(!checkNameOfBank(name));
    *nameOfBranch = strdup( name );
    allocated_blocks++;
    return ;
}

/*this function is geting the branch Id number*/
int getBranchId(){
  int num;
  int flag=0;
  do{
      if(flag){
          printf("Wrong value\n");
      }
      printf("Please ENTER branch ID  (number betweene [1 - 500]\n");
      flag=1;
      scanf("%d" , &num);
      getchar();
  }while(!checkBranchId(num));
  return num;
}

/*this function is geting the number of the branch clients*/
int getNumberOfBranchClients(){
  int num;
  int flag=0;
  do{
      if(flag){
          printf("Wrong value\n");
      }
      printf("Please ENTER number\n");
      flag=1;
      scanf("%d" , &num);
      getchar();
  }while(!checkNumberOfBranchClients(num));

  return num;
}

/*this function is geting the sum of all branch clients*/
double getSumOfAllBranchClients(){
  double num;
  int flag=0;
  do{
      if(flag){
          printf("Wrong value\n");
      }
      printf("Please ENTER sun of all branch clients\n");
      flag=1;
      scanf("%lf" , &num);
      getchar();
  }while(!checkSumOfAllBranchClients(num));

  return num;

}

/*this function is geting the branch profit of the last year*/
double getBranchProfitOfLastYear(){
  double num;
  int flag=0;
  do{
      if(flag){
          printf("Wrong value\n");
      }
      printf("Please ENTER branch profit of last year\n");
      flag=1;
      scanf("%lf" , &num);
      getchar();
  }while(!checkBranchProfitOfLastYear(num));

  return num;

}

/*this function is geting number of the branch loans*/
int getNumberOfBranchLoans(){
  int num;
  int flag=0;
  do{
      if(flag){
          printf("Wrong value\n");
      }
      printf("Please ENTER number of branch loans\n");
      flag=1;
      scanf("%d" , &num);
      getchar();
  }while(!checkNumberOfBranchLoans(num));

  return num;

}

/*this function is geting the opening hour*/
int getOpenHour(){
  int num;
  int flag=0;
  do{
      if(flag){
          printf("Wrong value\n");
      }
      printf("Please ENTER a open houer\n");
      flag=1;
      scanf("%d" , &num);
      getchar();
  }while(!checkOpenHour(num));

  return num;

}

/*this function is geting the closing hour*/
int getCloseHour(){
  int num;
  int flag=0;
  do{
      if(flag){
          printf("Wrong value\n");
      }
      printf("Please ENTER a close houer\n");
      flag=1;
      scanf("%d" , &num);
      getchar();
  }while(!checkCloseHour(num));

  return num;

}
/************************************************************/
/*                     Client inputs.                      */

/*this function is geting the name of a client*/
void getFirstNameOfClient(char** firstNameOfClient){
  char name[MAX_NAME];
  int flag=0;
    do{
        if(flag){
            printf("Wrong value\n");
        }
        printf("Please ENTER first name of client\n");
        flag=1;
        fgets(name , MAX_NAME , stdin);
        name[strlen(name)-1] = '\0';
    }while(!checkNameOfClient(name));
    *firstNameOfClient = strdup(name);
    allocated_blocks++;
    return;
}
/*this function is geting string name of the branch with known size and replace it with lower size new one*/
void getLastNameOfClient(char** lastNameOfClient){
    char name[MAX_NAME];
    int flag=0;
    do{
        if(flag){
            printf("Wrong value\n");
        }
        printf("Please ENTER last name of client\n");
        flag=1;
		fgets(name , MAX_NAME , stdin);
        name[strlen(name)-1] = '\0';
    }while(!checkNameOfBank(name));
    *lastNameOfClient = strdup( name );
    allocated_blocks++;
    return ;
}

/*this function is geting the client Id number*/
int getClientId(){
  int num;
  int flag=0;
  do{
      if(flag){
          printf("Wrong value\n");
      }
      printf("Please ENTER client Id\n");
      flag=1;
      scanf("%d" , &num);
      getchar();
  }while(!checkClientId(num));

  return num;
}

/*this function is geting the account number of a client*/
int getAccountNumber(){
  int num;
  int flag=0;
  do{
      if(flag){
          printf("Wrong value\n");
      }
      printf("Please ENTER account number\n");
      flag=1;
      scanf("%d" , &num);
      getchar();
  }while(!checkAccountNumber(num));

  return num;

}

/*this function is geting the authorize exception */
double getAuthorizedException(){
  double num;
  int flag=0;
  do{
      if(flag){
          printf("Wrong value\n");
      }
      printf("Please ENTER number of authorize exception\n");
      flag=1;
      scanf("%lf" , &num);
      getchar();
  }while(!checkAuthorizedException(num));

  return num;

}

/*this function is geting the account balance*/
double getAcountBalance(){
  double num;
  int flag=0;
  do{
      if(flag){
          printf("Wrong value\n");
      }
      printf("Please ENTER account balance\n");
      flag=1;
      scanf("%lf" , &num);
      getchar();
  }while(!checkAcountBalance(num));

  return num;

}

/*this function is geting the loan balance*/
double getLoanBalance(){
  double num;
  int flag=0;
  do{
      if(flag){
          printf("Wrong value\n");
      }
      printf("Please ENTER loan balance\n");
      flag=1;
      scanf("%lf" , &num);
      getchar();
  }while(!checkLoanBalance(num));

  return num;

}

/*this function is geting the saving balance*/
double getSaveBlance(){
  double num;
  int flag=0;
  do{
      if(flag){
          printf("Wrong value\n");
      }
      printf("Please ENTER save balance\n");
      flag=1;
      scanf("%lf" , &num);
      getchar();
  }while(!checkSaveBlance(num));

  return num;

}

/*this function is geting the deposite money*/
double getDpositeMoney(){
  double num;
  int flag=0;
  do{
      if(flag){
          printf("Wrong value\n");
      }
      printf("Please ENTER number of deposite money\n");
      flag=1;
      scanf("%lf" , &num);
      getchar();
  }while(!checkDepositeMoney(num));

  return num;

}
