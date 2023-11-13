// 라이선스

#ifndef SET_H
#define SET_H

#include "node.h"

class Set
{
public:
    Set() : size_(0), root_(nullptr) {}
    Set(const Set& set);
    Set& operator=(const Set& set);
    ~Set() {}

    // key를 root로 하는 subtree에서 최솟값을 갖는 node의 값과 depth를 출력
    void Minimum(const int key);

    // key를 root로 하는 subtree에서 최댓값을 갖는 node의 값과 depth를 출력
    void Maximum(const int key);
    bool IsEmpty() const { return size_ == 0; }
    int GetSize() const { return size_; }

    // 해당 key를 가지고 있는 node의 depth를 return
    int Find(const int key);

    // num을 삽입하고 해당 node의 depth를 출력
    void Insert(const int num);

    // Advanced
    // int GetRank(const int num);
    // void Erase(const int num);
private:
    // Set에 들어있는 원소의 개수
    int size_;

    // Set의 root node
    Node* root_;
};

#endif