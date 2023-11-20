// 라이선스

#ifndef SET_AVL_H
#define SET_AVL_H

#include "node_avl.h"
#include "set.h"

class SetAVL : public Set
{
public:
    SetAVL() : size_(0), root_(nullptr) {}
    // SetAVL(const SetAVL& setavl);
    // SetAVL& operator=(const SetAVL& setavl);
    ~SetAVL() {}

    // Basic 기능
    // key를 root로 하는 subtree에서 최솟값을 갖는 node의 값과 depth를 출력
    void Minimum(const int key) override final;

    // key를 root로 하는 subtree에서 최댓값을 갖는 node의 값과 depth를 출력
    void Maximum(const int key) override final;

    // Set이 비어있으면 1, 그렇지 않으면 0을 return
    bool IsEmpty() const override final { return size_ == 0; }

    // Set에 들어있는 원소의 개수 return
    int GetSize() const override final { return size_; }

    // 해당 key를 가지고 있는 node의 depth를 return
    int Find(const int key) override final;

    // num을 삽입하고 해당 node의 depth를 출력
    void Insert(const int num) override final;

    // Advanced 기능
    // 해당 key를 가지고 있는 node의 depth와 rank를 출력
    // rank: Set에서 해당 node보다 작은 key 값을 가진 node의 개수 + 1
    // void GetRank(const int num) override final;

    // 해당 key를 가지고 있는 node의 depth를 출력하고 해당 노드를 삭제
    // void Erase(const int num) override final;
private:
    // Set에 들어있는 원소의 개수
    int size_;

    // Set의 root node
    NodeAVL* root_;
};

#endif