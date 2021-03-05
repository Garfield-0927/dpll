//
// Created by 86186 on 3/5/2021.
//

#ifndef DPLL_SUDOKU_H
#define DPLL_SUDOKU_H

#include "Global.h"
#include "vector"
#include "math.h"
#include "string"
void GenerateFullPuzzle(int size){
    vector<int> Row(size);
    vector<vector<int>> puzzle(size, Row);
    // 二维数组初始化
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            puzzle[i][j] = 1;
        }
    }

    // 随机每行每列哪个位置为0
    srand(time(NULL));
    vector<int> zero(size/2);
    vector<vector<int>> zero_position(size, zero);
    for (int i = 0; i < size; ++i) {
        int flag = 1;
        for ( int j = 0 ; j < size/2; ++j) {
            // 前三个格子必定有0
            if (j==0){
                zero_position[i][j] = rand()%3;
            } else if (j == 1) {
                zero_position[i][j] = zero_position[i][j-1] + rand()%3 + 1;
            } else {
                // 行中已经有连续两个零的处理方法
                if (zero_position[i][j-2] + 1 == zero_position[i][j-1]){
                    zero_position[i][j] = zero_position[i][j-1] + rand()%2+2;
                    if (zero_position[i][j] > size -1 ){
                        i--;
                        flag = 0;
                        break;
                    }
                } else {
                    zero_position[i][j] = zero_position[i][j-1] + rand()%3+1;
                    // 越界，重新生成
                    if (zero_position[i][j] > size -1 ){
                        i--;
                        flag = 0;
                        break;
                    }
                }
            }

        }

        if (flag){
            for (int j = 0; j < i; ++j) {
                int k = 0;
                for (; k < size/2; ++k) {
                    if (zero_position[i][k]!=zero_position[j][k]){
                        break;
                    }
                }
                if (k == size/2){
                    flag = 0;
                    i--;
                    break;
                }
            }
        }

        if (flag && i>1){
            for (int j = 0; j < size/2; ++j) {
                for (int k = 0; k < size/2; ++k) {
                    int count = 0;
                    if (zero_position[i][j] == zero_position[i-1][k]){
                        ++count;
                    }
                    if (zero_position[i][j] == zero_position[i-2][k]){
                        ++count;
                    }
                    if (count == 2){
                        i--;
                        flag = 0;
                        break;
                    }
                }
                if (!flag){
                    break;
                }
            }

        }
    }


    // 置零
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size/2; ++j) {
            puzzle[i][zero_position[i][j]] = 0;
        }
    }
//     查看0的位置
    for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size/2; ++j) {
                cout<<zero_position[i][j]<<" ";
            }
            cout<<endl;
        }
//     查看puzzle
    for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cout<<puzzle[i][j]<<" ";
            }
            cout<<endl;
        }



    // 将完整的数独存入文件
    string filebase = "D:\\garfield\\study\\data structure\\dpll\\sudoku\\";
    string filepath;
    filepath = filebase.append("sudoku123456-answer.txt");
    ofstream file(filepath);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            file<<puzzle[i][j]<<" ";
        }
        file<<'\n';
    }
    file.close();



    // 进行挖洞
//    int holes[16] = {-1};
//    for (int i = 0; i < size; ++i) {
//        int HoleNum = rand()%(3) + size/2;
//        for (int j = 0; j < HoleNum; ++j) {
//            holes[j] = rand()%size;
//            for (int k = 0; k < j; ++k) {
//                if (holes[j] == holes[k]){
//                    j--;
//                    break;
//                }
//            }
//        }
//
////         check hole position
//        for (int l = 0; l < HoleNum; ++l) {
//            cout<<holes[l]<<" ";
//        }
//        cout<<endl;
//
//        for (int j = 0; j < HoleNum; ++j) {
//            puzzle[i][holes[j]] = -1;
//        }
//
//    }

//    for (int i = 0; i < size; ++i) {
//        for (int j = 0; j < size; ++j) {
//            cout<<puzzle[i][j]<<" ";
//        }
//        cout<<endl;
//    }




}
void CreateBinaryPuzzle(int size){
}

void combination(short cnf[][20], int &known, int array[]){
    for (int i = 0; i < 6; ++i) {
        for (int j = i+1; j < 6; ++j) {
            for (int k = j+1; k < 6; ++k) {
                for (int m = k+1; m < 6; ++m) {
                    cnf[known][0] = array[i];
                    cnf[known][1] = array[j];
                    cnf[known][2] = array[k];
                    cnf[known][3] = array[m];
                    cnf[known][4] = 0;
                    known++;
                    cnf[known][0] = -array[i];
                    cnf[known][1] = -array[j];
                    cnf[known][2] = -array[k];
                    cnf[known][3] = -array[m];
                    cnf[known][4] = 0;
                    known++;
                }
            }
        }
    }
}


void PuzzleToCnf(string filename, string outputCnf){

    // read sudoku
    string sudopathPrefix = "D:\\garfield\\study\\data structure\\dpll\\sudoku\\";
    string sudopath = sudopathPrefix.append(filename);
    ifstream sudoFile(sudopath);
    string sudo;
    int size,i,known=0;
    int puzzlecell[256] = {-1};
    for ( i = 0; !sudoFile.eof() ; ++i) {
        char ch;
        sudoFile>>ch;
        if (ch == '.'){
            puzzlecell[i] = -1;
        } else if (ch=='1'||ch=='0') {
            puzzlecell[i] = ch - '0';
        } else {
            i--;
        }
    }
    size = sqrt(i-1);
    cout<< "size is: "<< size <<endl;
//    for (int j = 0; j < size*size; ++j) {
//        cout << puzzlecell[j] << " ";
//    }


    // to cnf
    short cnf[51200][20];

    // 处理已知的cell
    for (int i = 0; i < size*size; ++i) {
        if (puzzlecell[i]==-1){
            continue;
        } else if (puzzlecell[i]==0){
            cnf[known][0] = -(i+1);
            cnf[known][1] = 0;
            known++;
        } else {
            cnf[known][0] = i+1;
            cnf[known][1] = 0;
            known++;
        }
    }


    // 处理没有三个连续的0或1
    // 处理行
    for (int i = 1; i < size*size; ++i) {
        if (!((i+1)%size)){
            i+=1;
        }else {
            cnf[known][0] = i;
            cnf[known][1] = i+1;
            cnf[known][2] = i+2;
            cnf[known][3] = 0;
            known++;
            cnf[known][0] = -i;
            cnf[known][1] = -(i+1);
            cnf[known][2] = -(i+2);
            cnf[known][3] = 0;
            known++;
        }
    }
    // 处理列
    for (int i = 1; i <= (size*(size-3)+size); ++i) {
        cnf[known][0] = i;
        cnf[known][1] = i+size;
        cnf[known][2] = i+2*size;
        cnf[known][3] = 0;
        known++;
        cnf[known][0] = -(i);
        cnf[known][1] = -(i+size);
        cnf[known][2] = -(i+2*size);
        cnf[known][3] = 0;
        known++;
    }
    

    // 处理每行每列有相同的0和1
    int temp[6][6];
    for (int l = 0; l < 6 ; ++l) {
        for (int j = 0; j < 6; ++j) {
            temp[l][j] = l*6+j+1;
        }
    }

    // 处理行
    for (int i = 0; i < 6; ++i) {
        combination(cnf,known,temp[i]);
    }

    // 处理列
    for (int i = 0; i < 6; ++i) {
        for (int j = i+1; j < 6; ++j) {
            int zjh = temp[i][j];
            temp[i][j] = temp[j][i];
            temp[j][i] = zjh;
        }
    }
    for (int i = 0; i < 6; ++i) {
        combination(cnf,known,temp[i]);
    }







    cout << endl;
    for (int k = 0; k < known; ++k) {
        for (int j = 0; cnf[k][j] !=0 ; ++j) {
            cout<<cnf[k][j]<<" ";
        }
        cout<<endl;
    }



    // To  File
    string outputPrefix = "D:\\garfield\\study\\data structure\\dpll\\sudoku\\cnf\\";
    string outpath;
    outpath = outputPrefix.append(outputCnf);
    ofstream myCnf(outpath);
    int test[10] = {1,2,3,4,5,6,7,8,9,0};
    for (int i = 0; i < 10; ++i) {
        myCnf<<test[i]<<" ";
    }
    myCnf.close();

}


#endif //DPLL_SUDOKU_H
