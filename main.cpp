#include "Global.h"
#include "welcome.h"
#include "cnf-parser.h"
#include "dpll-slover.h"
#include "sudoku.h"
const double CLOCKS_PER_SECOND = ((clock_t)1000);
const double CLOCKS_PER_MILLISECOND = ((clock_t)1);
int main() {
    ShowMenu();
    int option = 1;
    while (option){
        cin>>option;
        if (option == 1){
            PuzzleToCnf("sudoku123456.txt", "sudoku123456.cnf");




        }else if (option == 2){
            string filename = "sud00021.cnf";
//            cin>>filename;

            int VARNUM = 0;
            ClauseNode * ClauseHead = nullptr;
            ClauseHead = openCnf(filename, VARNUM);
            int * res = (int*)malloc(VARNUM*sizeof(int));
            memset(res,-1,sizeof(res));
            for (int j = 0; j < VARNUM; ++j) {
                res[j] = -1;
            }
            clock_t start,end;
            srand(unsigned(time(NULL)));
            start = clock();
            int value = DPLL(ClauseHead, res);
            end = clock();
            if (value){
                cout << "S  Satisfiable" << endl;
                for (int i = 0; i < VARNUM; ++i) {
                    if (res[i] == -1){
                        cout << "1 ";
                    } else {
                        cout << res[i] << " ";
                    }
                }
                cout<<endl;
            } else {
                cout<<"S  No Answer"<<endl;
            }

            cout<<"T "<<(double)(end-start)/CLOCKS_PER_SECOND <<" s\n";


        }else if (!option){
            break;
        }else{
            cout<<"input error";
        }


    }

    return 0;
}