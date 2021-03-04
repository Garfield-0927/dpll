//
// Created by 86186 on 3/2/2021.
//


#include "Global.h"

// 判断字句是否为空
int IsEmpty (ClauseNode * ClauseHead){
    ClauseNode * p = ClauseHead;
    while (p){
        if (p->Num == 0){
            return 1;
        }
        p = p->NextClause;
    }
    return 0;
}

// 找出只有一个文字的子句
ClauseNode * FindUnitClause(ClauseNode * ClauseHead){
    ClauseNode * p = ClauseHead;
    while (p){
        if (p->Num == 1){
            return p;
        }
        p = p->NextClause;
    }
    return nullptr;
}


// 删除子句
void DeleteClause(ClauseNode * TargetClause, ClauseNode * &ClauseHead){
    if (!TargetClause) return;
    if (TargetClause == ClauseHead){
        ClauseHead = ClauseHead->NextClause;
    } else {
        for ( ClauseNode * p = ClauseHead; p != nullptr ; p = p->NextClause) {
            if (p->NextClause == TargetClause){
                p->NextClause = TargetClause->NextClause;
            }
        }
    }
}

// 删除包含某一文字的子句
void DeleteTheClause(int literal, ClauseNode * &ClauseHead){
    for (ClauseNode * p = ClauseHead; p != nullptr; p = p->NextClause){
        for (LiteralNode * q = p->Literal; q != nullptr; q = q->NextLiteral){
            if (q->data == literal){
                DeleteClause(p, ClauseHead);
            }else if (q->data + literal == 0){
                if (q == p->Literal) {
                    p->Literal = q->NextLiteral;
                    p->Num--;
                }else {
                    for (LiteralNode * ltemp = p->Literal; ltemp!= nullptr ; ltemp = ltemp->NextLiteral) {
                        if (ltemp->NextLiteral== q){
                            ltemp->NextLiteral = q->NextLiteral;
                            p->Num--;
                        }
                    }
                }
            }
        }
    }
}



// 保存副本
ClauseNode * CopyOfOriginal(ClauseNode * ClauseHead){
    ClauseNode * SrcHead = ClauseHead;
    ClauseNode * ReHead = new ClauseNode;
    ReHead->Num = SrcHead->Num;
    ReHead->Literal = nullptr;
    ReHead->NextClause = nullptr;
    ClauseNode* Phead = ReHead;
    LiteralNode *ReData = new LiteralNode;
    LiteralNode *FirstSrcData = SrcHead->Literal;
    ReData->data = FirstSrcData->data;
    Phead->Literal = ReData;
    for (FirstSrcData = FirstSrcData->NextLiteral;FirstSrcData != nullptr; FirstSrcData = FirstSrcData->NextLiteral) {
        LiteralNode *NewLiteralNode = new LiteralNode;
        NewLiteralNode->data = FirstSrcData->data;
        ReData->NextLiteral = NewLiteralNode;
        ReData = ReData->NextLiteral;
    }
    ReData->NextLiteral = nullptr;

    for(SrcHead = SrcHead->NextClause; SrcHead != nullptr ; SrcHead = SrcHead->NextClause) {
        ClauseNode* NewHead = new ClauseNode;
        LiteralNode* NewData = new LiteralNode;
        NewHead->Num = SrcHead->Num;
        Phead->NextClause = NewHead;
        Phead = Phead->NextClause;
        LiteralNode* SrcData = SrcHead->Literal;
        NewData->data = SrcData->data;
        Phead->Literal = NewData;
        for (SrcData = SrcData->NextLiteral;SrcData != nullptr; SrcData = SrcData->NextLiteral) {
            LiteralNode* node = new LiteralNode;
            node->data = SrcData->data;
            NewData->NextLiteral = node;
            NewData = NewData->NextLiteral;
        }
        NewData->NextLiteral = nullptr;
    }
    Phead->NextClause = nullptr;

    return ReHead;

}

ClauseNode * AddUnitClause(ClauseNode * ClauseHead, int val){
    ClauseNode * AddHead = new ClauseNode;
    LiteralNode * AddLiteral = new LiteralNode;
    AddLiteral->data = val;
    AddLiteral->NextLiteral = nullptr;
    AddHead->Num = 1;
    AddHead->NextClause = ClauseHead;
    ClauseHead = AddHead;
    AddHead->Literal = AddLiteral;

    return ClauseHead;


}





int DPLL(ClauseNode*ClauseHead, int * res){
    ClauseNode * p = ClauseHead;
    ClauseNode * UnitClause = FindUnitClause(p);
    while (UnitClause!= nullptr){
        UnitClause->Literal->data > 0 ? res[abs(UnitClause->Literal->data)-1] = 1 : res[abs(UnitClause->Literal->data) -1] = 0;
        int targetLiteral = UnitClause->Literal->data;
        DeleteClause(UnitClause, ClauseHead);
        DeleteTheClause(targetLiteral, ClauseHead);
        if (!ClauseHead) return 1;
        else if (IsEmpty(ClauseHead)) return 0;
        p = ClauseHead;
        UnitClause = FindUnitClause(p);
    }

    int chosenLiteral = ClauseHead->Literal->data;
    ClauseNode * copy = CopyOfOriginal(ClauseHead);
    ClauseNode * new1 = AddUnitClause(ClauseHead, chosenLiteral);
    if (DPLL(new1, res)) return 1;
    else {
        ClauseNode * new2 = AddUnitClause(copy, -chosenLiteral);
        return DPLL(new2, res);
    }

}