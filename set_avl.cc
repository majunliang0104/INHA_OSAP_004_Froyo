// 라이선스

#include "set_avl.h"

#include <iostream>

// key를 root로 하는 subtree에서 최솟값을 갖는 node의 값과 depth를 출력
void SetAVL::Minimum(const int key)
{

}

// key를 root로 하는 subtree에서 최댓값을 갖는 node의 값과 depth를 출력
void SetAVL::Maximum(const int key)
{
    NodeAVL* node = root_;
    // key를 root로 하는 node찾기
    while(node != nullptr)
    {
        if(key == node->GetNum())
            break;
        else if(key < node->GetNum())
            node = node->GetLeft();
        else
            node = node->GetRight();
    }
    // subtree에서 최댓값을 갖는 node찾기
    while(node != nullptr && node->GetRight() != nullptr)
    {
        node = node->GetRight();
    }
    std::cout << "key : " << node->GetNum() << ", depth : " << Find(key);
}

// 해당 key를 가지고 있는 node의 depth를 return
int SetAVL::Find(const int key)
{
    return 0;
}

// num을 삽입하고 해당 node의 depth를 출력
void SetAVL::Insert(const int num)
{
    
}
