//
// Created by PC on 2019/2/27.
//

#ifndef WORKSHOP_GLOBAL_H
#define WORKSHOP_GLOBAL_H

#include <iostream>
#include <fstream>
#include <ctime>
#include "math.h"
using namespace std;
#define TRUE 1
#define FALSE 0
#define ROW 9
#define COL 9
#define NoAnwser -1
typedef int status;

typedef struct LiteralNode {
    int data = 0;
    LiteralNode *NextLiteral;
}LiteralNode;

typedef struct ClauseNode {
    int Num = 0;
    LiteralNode *Literal;
    ClauseNode *NextClause;
}ClauseNode;

struct consequence {
    int value = -1;//存真值 真时为true-1，假时为false-0
};

struct conse {
    int num = 0;
    int value = -1;//存真值 真时为true-1，假时为false-0
};

#endif //WORKSHOP_GLOBAL_H
