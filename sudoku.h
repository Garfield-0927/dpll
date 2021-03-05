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
        zero_position[i][0] = rand()%3;
        zero_position[i][1] = zero_position[i][0] + rand()%3 + 1;
        for ( int j = 2 ; j < size/2; ++j) {
            if (zero_position[i][j-2] + 1 == zero_position[i][j-1]){
                zero_position[i][j] = zero_position[i][j-1] + rand()%2+2;
                if (zero_position[i][j] > size -1 ){
                    i--;
                    break;
                }
            } else {
                zero_position[i][j] = zero_position[i][j-1] + rand()%3+1;
                if (zero_position[i][j] > size -1 ){
                    i--;
                    break;
                }
            }
        }
        if (i>=1){
            for (int j = 0; j < i; ++j) {
                int k = 0;
                for (; k < size/2; ++k) {
                    if (zero_position[i][k] != zero_position[j][k]){
                        break;
                    }
                }
                if (k==size/2){
                    i--;
                }
            }
        }
    }

    // 查看0的位置
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size/2; ++j) {
            cout<<zero_position[i][j]<<" ";
        }
        cout<<endl;
    }

    // 置零
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size/2; ++j) {
            puzzle[i][zero_position[i][j]] = 0;
        }
    }


    // 查看puzzle
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout<<puzzle[i][j]<<" ";
        }
        cout<<endl;
    }








}


void CreateBinaryPuzzle(int size){



}




#endif //DPLL_SUDOKU_H
