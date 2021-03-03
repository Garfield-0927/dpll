//
// Created by 86186 on 3/2/2021.
//

#include "iostream"
#include "fstream"
#include "cstring"
#include "stdlib.h"
#include "global.h"
using namespace std;
ClauseNode * openCnf(string filename){

    // 生成文件路径
    string filebase = "D:\\garfield\\study\\data structure\\dpll\\cnf\\";
    string filepath;
    filepath = filebase.append(filename);
    // cout<<filepath<<endl;


    ifstream myCnf(filepath);
    if (!myCnf.is_open()){
        cout<<"can not open cnf file"<<endl;
        exit(1);
    }else{

        // 读取cnf前面的注释内容
        cout<<"reading cnf file..."<<endl;
        char ch;
        char temp[512];
        while (ch!='p' && !myCnf.eof()){
            myCnf.getline(temp,100);
            myCnf>>ch;
        }

        // 读取变量个数以及子句个数
        string cnf;
        int VarNum, ClauseNum;
        myCnf>>cnf>>VarNum>>ClauseNum;
//      cout<<"variable number is:"<<VarNum<<endl;
//      cout<<"clause number is:"<<ClauseNum<<endl;

        // 读取每个子句
        ClauseNode * ClauseHead = new ClauseNode;
        ClauseNode * ClauseRear = ClauseHead;
        ClauseNode * ClauseEnd = new ClauseNode;


        myCnf.get();      // 读取一个换行符号
        int i = 0;      // 循环变量
        for ( ; i < ClauseNum; ++i) {

            int temp;
            myCnf>>temp;

            // first literal
            LiteralNode * LiteralFront = new LiteralNode;
            LiteralFront->data = temp;
            ClauseRear->Literal = LiteralFront;
            ClauseRear->Num = i+1;


            // 2nd && 3rd literals
            myCnf>>temp;
            while (temp!=0){
                LiteralNode * LiteralRear = new LiteralNode;
                LiteralFront->NextLiteral = LiteralRear;
                LiteralRear->data = temp;
                LiteralFront = LiteralFront->NextLiteral;
                myCnf>>temp;
            }

            LiteralFront->NextLiteral = nullptr;
            myCnf.get();
            ClauseNode * p = new ClauseNode;
            ClauseRear->NextClause = p;
            ClauseEnd = ClauseRear;
            ClauseRear = ClauseRear->NextClause;
        }
        ClauseEnd->NextClause = nullptr;


        // check the data
        ClauseNode * TempClause = ClauseHead;
        LiteralNode * TempLiteral;
        cout<<"read cnf file down, now check the data"<<endl;
        while (TempClause){
            TempLiteral = TempClause->Literal;
            while (TempLiteral){
                cout<<TempLiteral->data<<" ";
                TempLiteral = TempLiteral->NextLiteral;
            }
            cout<<endl;
            TempClause = TempClause->NextClause;
        }

        return ClauseHead;

    }


}

