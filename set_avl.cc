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

}

// 해당 key를 가지고 있는 node의 depth를 return
int SetAVL::Find(const int key)
{
    return 0;
}

// num을 삽입하고 해당 node의 depth를 출력
void SetAVL::Insert(const int num)
{
    if (root_ == nullptr)
    {
        // Set에 아무런 원소도 없는 경우
        root_ = new NodeAVL(num);

        // 새로 삽입한 node의 height는 0
        root_->SetHeight(0);
        size_ = 1;

        // 새로 삽입한 node의 depth 출력
        // root node의 depth는 0으로 정의
        std::cout << "0\n";
    }
    else
    {
        NodeAVL* current_node = root_;
        NodeAVL* new_node = new NodeAVL(num);

        // 적절한 위치에 Node 삽입하기
        while (1)
        {
            if (num == current_node->GetNum())
            {
                // 삽입하려고 하는 원소가 이미 Set에 들어있음
                // new_node 메모리 해제
                delete new_node;
                break;
            }
            else if (num < current_node->GetNum())
            {
                // Left Child로 이동
                if (current_node->GetLeft() == nullptr)
                {
                    // Left Child가 없는 경우
                    // parent node 설정
                    new_node->SetParent(current_node);

                    // Left Child에 노드 삽입
                    current_node->SetLeft(new_node);

                    // 새로운 node의 height는 leaf 노드이므로 height는 0
                    new_node->SetHeight(0);

                    // Set에 들어있는 원소의 개수 1 증가
                    size_++;

                    // new_node부터 root node까지 모든 node의 height 갱신
                    UpdateHeightUntilRoot(new_node);

                    break;
                }
                else
                {
                    // Left Child가 있는 경우
                    // Left Child로 이동
                    current_node = current_node->GetLeft();
                }
            }
            else
            {
                // Right Child로 이동
                if (current_node->GetRight() == nullptr)
                {
                    // Right Child가 없는 경우
                    // parent node 설정
                    new_node->SetParent(current_node);

                    // Right Child에 노드 삽입
                    current_node->SetRight(new_node);

                    // 새로운 node의 height는 leaf 노드이므로 height는 0
                    new_node->SetHeight(0);
                    
                    // Set에 들어있는 원소의 개수 1 증가
                    size_++;

                    // new_node부터 root node까지 모든 node의 height 갱신
                    UpdateHeightUntilRoot(new_node);

                    break;
                }
                else
                {
                    // Right Child가 있는 경우
                    // Right Child로 이동
                    current_node = current_node->GetRight();
                }
            }
        }
    }
}

// 해당 node의 height를 재설정
void SetAVL::UpdateHeight(NodeAVL* node)
{
    // left subtree의 height
    int left_subtree_height = -1;

    // right subtree의 height
    int right_subtree_height = -1;

    if (node->GetLeft() != nullptr)
    {
        left_subtree_height = node->GetLeft()->GetHeight();
    }

    if (node->GetRight() != nullptr)
    {
        right_subtree_height = node->GetRight()->GetHeight();
    }

    if ((left_subtree_height == -1)
        && (right_subtree_height == -1))
    {
        // left subtree와 right subtree 모두 empty tree인 경우
        // parameter로 들어온 node는 leaf 노드
        // leaf 노드의 height는 0으로 정의
        node->SetHeight(0);
    }
    else
    {
        // left subtree와 right subtree 중 적어도 하나는 empty tree가 아닌 경우
        node->SetHeight(
            std::max(left_subtree_height, right_subtree_height) + 1);
    }
}

// start_node부터 root node까지 모든 node의 height 갱신
void SetAVL::UpdateHeightUntilRoot(NodeAVL* start_node)
{
    NodeAVL* current_node = start_node;
    while (1)
    {
        // current_node의 height 재설정
        UpdateHeight(current_node);

        if (current_node == root_)
        {
            // current_node가 root 노드이므로 더 이상 height를 갱신할 node가 없음
            break;
        }
        else
        {
            // 부모 노드로 이동
            current_node = current_node->GetParent();
        }
    }
}
