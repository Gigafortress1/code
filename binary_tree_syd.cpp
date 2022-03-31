#include<iostream>
using namespace std;
template<class T>
class arrayQueue
{
public:
    arrayQueue(int initialCapacity = 10){
        arrayLength=initialCapacity;
        queue=new T[arrayLength];
        theFront=0;
        theBack=0;
    };
    ~arrayQueue() {delete [] queue;}
    bool empty(){return theFront == theBack;}//队列空
    int size() {return (theBack - theFront + arrayLength) % arrayLength;}//队列中元素个数
    T& front()//返回第一个元素
    {if (theFront == theBack)
            exit(1);
        return queue[(theFront + 1) % arrayLength];
    }
    T& back()//最后一个元素
    {
        if (theFront == theBack)
            exit(1);
        return queue[theBack];
    }
    void pop()//删除队首元素
    {
        if (theFront == theBack)
            exit(1);
        theFront = (theFront + 1) % arrayLength;//theFront后移
        queue[theFront].~T();  // 析构
    }
    void push(const T& theElement){//元素进队
        if ((theBack + 1) % arrayLength == theFront){//加进去以后满了
            T* newQueue = new T[2 * arrayLength];
            int start = (theFront + 1) % arrayLength;
            if (start <=1)
                copy(queue + start, queue + start + arrayLength - 1, newQueue);//整体复制
            else
            {
                copy(queue + start, queue + arrayLength, newQueue);//拆分
                copy(queue, queue + theBack + 1, newQueue + arrayLength - start);//转了一圈回到queue开头了，这里要截断加在后面
            }
            theFront = 2 * arrayLength - 1;
            theBack = arrayLength - 2;
            arrayLength *= 2;
            queue = newQueue;
        }
        theBack = (theBack + 1) % arrayLength;//否则就直接加
        queue[theBack] = theElement;
    };
private:
    int theFront;       //第一个元素位置的前一个元素下标
    int theBack;        //最后一个元素下标
    int arrayLength;    //容量
    T *queue;           //队列数组
};

template <class T>
struct binaryTreeNode
{

    T element;

    binaryTreeNode<T> *leftChild,   // left subtree
    *rightChild;  // right subtree

    binaryTreeNode() {leftChild = rightChild = NULL;}
    binaryTreeNode(int num,const T& theElement):element(theElement)
    {
        leftChild = rightChild = NULL;
    }
    binaryTreeNode(const T& theElement,
                   binaryTreeNode *theLeftChild,
                   binaryTreeNode *theRightChild)
            :element(theElement)
    {
        leftChild = theLeftChild;
        rightChild = theRightChild;
    }
};
template<class T>
class binaryTree{
public:
    binaryTree(){root=NULL;treeSize=0;}//构造函数
    bool empty() const{return treeSize==0;}
    int size() const{return treeSize;}
    binaryTreeNode<T>** rootElement(){return &root;}

    void makeTree(T* elem,int n);//构造树
    void preOrder(binaryTreeNode<T>* t);//后序
    int treeCount(binaryTreeNode<T> * t);//数节点个数;
    void levelOrder();//层次
    int height(binaryTreeNode<T> *t);//高度
    void visit(binaryTreeNode<T> *x){
        cout<<x->element<<" ";
    }
    binaryTreeNode<T> *root;
    binaryTreeNode<T> **p;
    int treeSize;
};

template<class T>
int binaryTree<T>::treeCount(binaryTreeNode<T> * t)
{
    int n=0;
    if(t!=NULL)
    {
        n=treeCount(t->leftChild)+treeCount(t->rightChild)+1;
    }

    return n;
}

template<class T>
void binaryTree<T>::preOrder(binaryTreeNode<T> *t)
{// Preorder traversal.
    if (t != NULL)
    {
        //binaryTree<T>::visit(t);
        preOrder(t->leftChild);
        preOrder(t->rightChild);
    }
}
template <class T>
void binaryTree<T>::levelOrder()//层次遍历
{
    binaryTreeNode<T> *t=root;
    arrayQueue<binaryTreeNode<T>*> q;
    while(t!=NULL){
        visit(t);
        if(t->leftChild!=NULL){
            q.push(t->leftChild);
        }
        if(t->rightChild!=NULL){
            q.push(t->rightChild);
        }
        t=q.front();
        if(q.empty()){
            return;
        }
        q.pop();
    }
}
template <class T>
int binaryTree<T>::height(binaryTreeNode<T> *t)
{
    if (t == NULL)
        return 0;                    // empty tree
    int hl = height(t->leftChild);  // height of left
    int hr = height(t->rightChild); // height of right
    if (hl > hr) { return hl; }
    else {return hr; }
}

template <class T>
void binaryTree<T>::makeTree(T* elem,int n){//建立二叉树
    p=new binaryTreeNode<T>*[n+1];
    for(int i = 0; i < n+1;i++){
        p[i] = new binaryTreeNode<T>;
    }
    root = new binaryTreeNode<T>;
    p[1]=root;
    for(int i=2;i<n+1;i++){
        p[i]->element=i;
        p[i]->leftChild=NULL;
        p[i]->rightChild=NULL;
    }
    for(int i=1;i<=n;i++){
        if(elem[2*i-2]!=-1&&elem[2*i-1]!=-1){//直接找到对应下标，对应左子树，右子树
            p[i]->leftChild=p[elem[2*i-2]];
            p[i]->rightChild=p[elem[2*i-1]];
        }
        else if(elem[2*i-2]==-1&&elem[2*i-1]!=-1){
            p[i]->rightChild=p[elem[2*i-1]];
        }
        else if(elem[2*i-2]!=-1&&elem[2*i-1]==-1){
            p[i]->leftChild=p[elem[2*i-2]];
        }
        else if(elem[2*i-2]==-1&&elem[2*i-1]==-1){
        }
    }
    root=p[1];
    treeSize=n;
}

int main(){
    int n;cin>>n;
    int *arr=new int[2*n];

    binaryTree<int> tr;
    for(int i=0;i<2*n;i++){
        cin>>arr[i];
    }
    tr.makeTree(arr,n);
    tr.levelOrder();
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<tr.treeCount(tr.p[i])<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<tr.height(tr.p[i])<<" ";

    }
}
