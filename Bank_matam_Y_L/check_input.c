/*Checking all the inputs*/
#include "check_input.h"

/**********************************************************************/
/*                          bank                                      */

/*this function is cheking if the input name of the bank is correct*/
int checkNameOfBank(char* input){
    int i;
    if(strlen(input)>MAX_NAME || strlen(input)<0){
        return FAILD;
    }
    for( i=0 ; i<strlen(input) ; i++ )
        if(isdigit(input[i])) return FAILD;
    return SUCCESS;
}

/*this function is cheking if the input number of bank clients is correct*/
int checkNumberOfBankClients(int input){
    if(input>MAX_CLIENT_OF_BANK || input<0){
        return FAILD;
    }
    return SUCCESS;
}

/*this function is cheking if the input name of the bank is correct*/
int checkNumberOfBranch(int input){
  if(input>MAX_BRANCHS || input<0){
      return FAILD;
  }

    return SUCCESS;
}

/*this function is cheking if the input sum of all bank clients is correct*/
int checkSumOfAllBankClients(double input){
    return SUCCESS;
}

/*this function is cheking if the input profit of last year is correct*/
int checkProfitOfLastYear(double input){
    return SUCCESS;
}

/*this function is cheking if the input number of active loans is correct*/
int checkNumberOfActiveLoans(int input){
  if(input>MAX_OF_ACTIVE_LOANS || input<0){
      return FAILD;
  }
    return SUCCESS;
}

/***************************************************************************/
/*                             branch                                      */

int checkNameOfBranch(char* input){
    int i ;
    if(strlen(input)>MAX_NAME || strlen(input)<=0){
        return FAILD;
    }
    for( i=0 ; i<strlen(input) ; i++ )
        if(isdigit(input[i])) return FAILD;
    return SUCCESS;
}

/*this function is cheking if the input branch Id is correct*/
int checkBranchId(int input){
  if(input>MAX_BRANCHS || input<1){
      return FAILD;
  }

    return SUCCESS;
}

/*this function is cheking if the input number of branch client is correct*/
int checkNumberOfBranchClients(int input){
  if(input>MAX_CLIENT_OF_BRANCH || input<0){
      return FAILD;
  }

    return SUCCESS;
}

/*this function is cheking if the input sum of all branch clients is correct*/
int checkSumOfAllBranchClients(double input){
    return SUCCESS;
}

/*this function is cheking if the input branch profit of the last year is correct*/
int checkBranchProfitOfLastYear(double input){
    return SUCCESS;
}

/*this function is cheking if the input number of branch loans is correct*/
int checkNumberOfBranchLoans(int input){
  if(input>MAX_BRANCH_LOANS || input<0){
      return FAILD;
  }
    return SUCCESS;
}

/*this function is cheking if the input opening hour of a branch is correct*/
int checkOpenHour(int input){
    return SUCCESS;
}
/*this function is cheking if the input closing hour of a branch is correct*/
int checkCloseHour(int input){
    return SUCCESS;
}

/****************************************************************/
/*                       client                                 */

/*this function is cheking if the input name of a client is correct*/
int checkNameOfClient(char* input){
    int i ;
    if(strlen(input)>MAX_NAME || strlen(input)<=0){
        return FAILD;
    }
    for( i=0 ; i<strlen(input) ; i++ )
        if(isdigit(input[i])) return FAILD;
    return SUCCESS;
}

/*this function is cheking if the input client Id is correct*/
int checkClientId(int input){
    if(input !=(int)input || input>MAX_ID || input<0){
        return FAILD;
  }
    return SUCCESS;
}

/*this function is cheking if the input account number of is correct*/
int checkAccountNumber(int input){
  if(input != (int)input || input>MAX_CLIENT_OF_BANK || input<0 ){
      return FAILD;
  }
    return SUCCESS;
}

/*this function is cheking if the input authorize exception is correct*/
int checkAuthorizedException(double input){
    if(input != (double)input || input>MAX_EXEPTION || input<MIN_EXEPTION ){
        return FAILD;
    }
    return SUCCESS;
}

/*this function is cheking if the input account balance is correct*/
int checkAcountBalance(double input){
    if(input == (double)input) return SUCCESS;
    return FAILD;
}

/*this function is cheking if the input loan balance is correct*/
int checkLoanBalance(double input){
    if(input == (double)input) return SUCCESS;
    return FAILD;
}

/*this function is cheking if the input save balance is correct*/
int checkSaveBlance(double input){
    if(input == (double)input) return SUCCESS;
    return FAILD;
}

/*this function is cheking if the input deposite money is correct*/
int checkDepositeMoney(double input){
    if(input == (double)input) return SUCCESS;
    return FAILD;
    
}
