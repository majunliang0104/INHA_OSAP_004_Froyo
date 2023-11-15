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

    // Basic 기능
    // key를 root로 하는 subtree에서 최솟값을 갖는 node의 값과 depth를 출력
    void Minimum(const int key);

    // key를 root로 하는 subtree에서 최댓값을 갖는 node의 값과 depth를 출력
    void Maximum(const int key);

    // Set이 비어있으면 1, 그렇지 않으면 0을 return
    bool IsEmpty() const { return size_ == 0; }

    // Set에 들어있는 원소의 개수 return
    int GetSize() const { return size_; }

    // 해당 key를 가지고 있는 node의 depth를 return
    int Find(const int key);

    // num을 삽입하고 해당 node의 depth를 출력
    void Insert(const int num);

    // Advanced 기능
    // 해당 key를 가지고 있는 node의 depth와 rank를 출력
    // rank: Set에서 해당 node보다 작은 key 값을 가진 node의 개수 + 1
    // int GetRank(const int key);
    
    // 해당 key를 가지고 있는 node의 depth를 출력하고 해당 노드를 삭제
    // void Erase(const int key);
private:
    // Set에 들어있는 원소의 개수
    int size_;

    // Set의 root node
    Node* root_;
};

#endif