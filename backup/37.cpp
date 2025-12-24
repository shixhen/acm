#include <iostream>
using namespace std;

#define LH 1   // 左高
#define EH 0   // 等高
#define RH -1  // 右高

class BiNode
{
public:
    int key;         // 关键值
    int bf;          // 平衡因子
    BiNode *lChild, *rChild;
    BiNode(int kValue, int bValue)
    {
        key = kValue;
        bf = bValue;
        lChild = NULL;
        rChild = NULL;
    }

    ~BiNode()
    {
        key = 0;
        bf = 0;
        lChild = NULL;
        rChild = NULL;
    }
};

// 二叉排序树
class BST
{
private:
    BiNode *root; // 根结点指针
    void rRotate(BiNode *&p);
    void lRotate(BiNode *&p);
    void leftBalance(BiNode *&t);
    void rightBalance(BiNode *&t);
    int insertAVL(BiNode *&t, int key, bool &taller); // 插入元素并做平衡处理
    void inOrder(BiNode *p);

public:
    BST();
    void insertAVL(int key); // 二叉排序树插入元素
    ~BST();
    void inOrder(); // 中序遍历
};

// 以p为根的二叉排序树作右旋处理
void BST::rRotate(BiNode *&p)
{
    BiNode *lc = p->lChild;   // lc指向p的左子树的根结点
    p->lChild = lc->rChild;   // lc的右子树挂接为p的左子树
    lc->rChild = p;           // p挂接为lc的右子树
    p = lc;                   // p指向新的根结点
}

// 以p为根的二叉排序树作左旋处理
void BST::lRotate(BiNode *&p)
{
    BiNode *rc = p->rChild;   // rc指向p的右子树的根结点
    p->rChild = rc->lChild;   // rc的左子树挂接为p的右子树
    rc->lChild = p;           // p挂接为rc的左子树
    p = rc;                   // p指向新的根结点
}

// t为根的二叉排序树作左平衡旋转处理
void BST::leftBalance(BiNode *&t)
{
    BiNode *lc = t->lChild; // lc指向t的左子树根结点
    switch (lc->bf)
    {
    case LH: // 新结点插入在t的左孩子的左子树上，作单右旋处理
        t->bf = lc->bf = EH;
        rRotate(t);
        break;
    case RH: // 新结点插入在t的左孩子的右子树上，作双旋处理
        BiNode *rd = lc->rChild; // rd指向t的左孩子的右子树根
        // 修改t及其左孩子的平衡因子
        switch (rd->bf)
        {
        case LH:
            t->bf = RH;
            lc->bf = EH;
            break;
        case EH:
            t->bf = lc->bf = EH;
            break;
        case RH:
            t->bf = EH;
            lc->bf = LH;
            break;
        }
        rd->bf = EH;
        lRotate(t->lChild); // 对t的左子树作左旋处理
        rRotate(t);         // 对t作右旋处理
    }
}

// t为根的二叉排序树作右平衡旋转处理
void BST::rightBalance(BiNode *&t)
{
    BiNode *rc = t->rChild; // rc指向t的右子树根结点
    switch (rc->bf)
    {
    case RH: // 新结点插入在t的右孩子的右子树上，作单左旋处理
        t->bf = rc->bf = EH;
        lRotate(t);
        break;
    case LH: // 新结点插入在t的右孩子的左子树上，作双旋处理
        BiNode *ld = rc->lChild; // ld指向t的右孩子的左子树根
        // 修改t及其右孩子的平衡因子
        switch (ld->bf)
        {
        case LH:
            t->bf = EH;
            rc->bf = RH;
            break;
        case EH:
            t->bf = rc->bf = EH;
            break;
        case RH:
            t->bf = LH;
            rc->bf = EH;
            break;
        }
        ld->bf = EH;
        rRotate(t->rChild); // 对t的右子树作右旋处理
        lRotate(t);         // 对t作左旋处理
    }
}

int BST::insertAVL(BiNode *&t, int key, bool &taller)
{
    if (!t) // 插入新结点，树长高
    {
        t = new BiNode(key, EH);
        taller = true;
    }
    else
    {
        if (key == t->key) // 树中已存在相同关键字的结点
        {
            taller = false;
            return 0;
        }
        if (key < t->key) // 在左子树中插入
        {
            if (!insertAVL(t->lChild, key, taller))
                return 0;
            if (taller) // 左子树长高
            {
                switch (t->bf)
                {
                case LH: // 原本左子树比右子树高，需要作左平衡处理
                    leftBalance(t);
                    taller = false;
                    break;
                case EH: // 原本左右子树等高，现因左子树增高而使树增高
                    t->bf = LH;
                    taller = true;
                    break;
                case RH: // 原本右子树比左子树高，现左右子树等高
                    t->bf = EH;
                    taller = false;
                    break;
                }
            }
        }
        else // 在右子树中插入
        {
            if (!insertAVL(t->rChild, key, taller))
                return 0;
            if (taller) // 右子树长高
            {
                switch (t->bf)
                {
                case LH: // 原本左子树比右子树高，现左右子树等高
                    t->bf = EH;
                    taller = false;
                    break;
                case EH: // 原本左右子树等高，现因右子树增高而使树增高
                    t->bf = RH;
                    taller = true;
                    break;
                case RH: // 原本右子树比左子树高，需要作右平衡处理
                    rightBalance(t);
                    taller = false;
                    break;
                }
            }
        }
    }
    return 1;
}

void BST::inOrder(BiNode *p)
{
    if (p)
    {
        inOrder(p->lChild);
        cout << p->key << ':' << p->bf << ' ';
        inOrder(p->rChild);
    }
    return;
}

// 二叉排序树初始化
BST::BST()
{
    root = NULL;
}

BST::~BST()
{
    root = NULL;
}

// 插入元素并作平衡处理
void BST::insertAVL(int key)
{
    bool taller = false;
    insertAVL(root, key, taller);
}

// 中序遍历
void BST::inOrder()
{
    inOrder(root);
}

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        // 构建二叉平衡树，并在插入元素时做平衡处理
        int n, elem;
        cin >> n;
        BST tree;
        while (n--)
        {
            cin >> elem;
            tree.insertAVL(elem);
        }
        tree.inOrder();
        cout << endl;
    }
    return 0;
}
