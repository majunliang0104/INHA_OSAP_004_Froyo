// 라이선스

#ifndef NODE_H
#define NODE_H

// 복사 생성자, 대입 연산자 사용 방지
#define DISALLOW_COPY_AND_ASSIGN(Node) \
    Node(const Node &);                \
    void operator=(const Node &)

class Node
{
public:
    Node(int num)
        : num_(num), height_(0), 
        parent_(nullptr), left_(nullptr), 
        right_(nullptr) {}
    ~Node();
    void SetParent(Node* parent);
    void SetLeft(Node* left);
    void SetRight(Node* right);
    void SetHeight(const int height);
    int GetNum();
    int GetHeight();
    Node* GetParent();
    Node* GetLeft();
    Node* GetRight();
private:
    // 복사 생성자, 대입 연산자 사용 방지
    DISALLOW_COPY_AND_ASSIGN(Node);

    // 해당 node의 key값
    int num_;

    // 해당 node의 child 중 height_의 최댓값 + 1 (leaf node일 경우 0)
    int height_;

    // 부모 노드
    Node* parent_;

    // Left Child 노드
    Node* left_;

    // Right Child 노드
    Node* right_;
};

#endif
