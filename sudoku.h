//
// Created by 86186 on 3/5/2021.
//

#ifndef DPLL_SUDOKU_H
#define DPLL_SUDOKU_H

#include "Global.h"
#include "vector"
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
        // 前三个格子必定有0
        zero_position[i][0] = rand()%3;
        zero_position[i][1] = zero_position[i][0] + rand()%3 + 1;
        for ( int j = 2 ; j < size/2; ++j) {
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

            // check IsRepeat
            if (i>=1){
                // 判断是否有重复行
                for (int j = 0; j < i; ++j) {
                    int k = 0;
                    for (; k < size/2; ++k) {
                        if (zero_position[i][k] != zero_position[j][k]){
                            break;
                        }
                    }
                    if (k==size/2){
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

        if (i>1){

            for (int j = 0; j < size/2; ++j) {
                for (int k = 0; k < size/2; ++k) {
                    int count = 0;
                    if (zero_position[i][j]==zero_position[i-1][k]){
                        count++;
                    }
                    if (zero_position[i][j]==zero_position[i-2][k]){
                        count++;
                    }
                    if (count == 2){
                        flag = 0;
                        break;
                    }
                }
                if (!flag){
                    i--;
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
    int holes[16] = {-1};
    for (int i = 0; i < size; ++i) {
        int HoleNum = rand()%(3) + size/2;
        for (int j = 0; j < HoleNum; ++j) {
            holes[j] = rand()%size;
            for (int k = 0; k < j; ++k) {
                if (holes[j] == holes[k]){
                    j--;
                    break;
                }
            }
        }

//         check hole position
//        for (int l = 0; l < HoleNum; ++l) {
//            cout<<holes[l]<<" ";
//        }
//        cout<<endl;
//
//        for (int j = 0; j < HoleNum; ++j) {
//            puzzle[i][holes[j]] = -1;
//        }

    }

//    for (int i = 0; i < size; ++i) {
//        for (int j = 0; j < size; ++j) {
//            cout<<puzzle[i][j]<<" ";
//        }
//        cout<<endl;
//    }




}







void CreateBinaryPuzzle(int size){



}




#endif //DPLL_SUDOKU_H
