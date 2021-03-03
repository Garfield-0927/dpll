#include "Global.h"
#include "welcome.h"
#include "cnf-parser.h"

int main() {
    ShowMenu();
    int option = 1;
    while (option){
        cin>>option;
        if (option == 1){

        }else if (option == 2){
            string filename = "sud00009.cnf";
//            cin>>filename;
            ClauseNode * ClauseHead = nullptr;
            ClauseHead = openCnf(filename);



        }else if (!option){
            break;
        }else{
            cout<<"input error";
        }


    }

    return 0;
}