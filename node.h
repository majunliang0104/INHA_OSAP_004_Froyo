// 라이선스

#ifndef NODE_H
#define NODE_H

// Node의 경우 Abstract Class로 정의 (pure virtual function 이용)
class Node
{
public:
    virtual ~Node() {}
    virtual int GetNum() const = 0;
};

#endif