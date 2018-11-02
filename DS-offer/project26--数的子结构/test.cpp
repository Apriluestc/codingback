#include <iostream>
struct BinaryTree
{
    double m_nValue;    //  浮点数存储不可以用 "==" 直接判断j
    BinaryTree* m_left;
    BinaryTree* m_right;
};
bool Equal(double num1, double num2)    //判断浮点数不能直接用等号判断
{
    if((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
    {
        return true;    //num1 和 num2 相等则 true
    }
    else
    {
        return false;
    }
}
bool Find(BinaryTree* root1, BinaryTree* root2)
{
    if(root2 == NULL)
    {
        return true;    //  l空树是任意数的子数
    }
    if(root1 == NULL)
    {
        return false;
    }
    if(!Equal(root1->m_nValue, root2->m_nValue))    /* if(!(true) == 0){false;} */
    {
        return false;
    }
    return Find(root1->m_left, root2->m_left) && Find(root1->m_right, root2->m_right);   //递归遍历左右子树
}
bool HasSubtree(BinaryTree* root1, BinaryTree* root2)
{
    bool result = false;
    if(root1 != NULL && root2 != NULL)
    {
        if(Equal(root1->m_nValue, root2->m_nValue))
        {
            result = Find(root1, root2);
        }
        if(!result)
        {
            result = HasSubtree(root1->m_left, root2);
        }
        if(!result)
        {
            result = HasSubtree(root1->m_right, root2);
        }
    }
    return result;
}
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

