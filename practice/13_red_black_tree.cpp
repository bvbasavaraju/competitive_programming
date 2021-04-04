#include <memory>
#include <vector>

using namespace std;

class RedBlackTree_t
{
private:
  struct Node_t
  {
    int key;
    int value;

    bool isRed;
    Node_t* left;
    Node_t* right;

    Node_t(int key_, int val) : key(key_), value(val), isRed(true), left(nullptr), right(nullptr) {}
  };

  Node_t* root;

  bool IsRed(Node_t* node)
  {
    return (node != nullptr) && (node->isRed);
  }

  Node_t* RotateLeft(Node_t* node, bool updateColor)
  {
    if(node == nullptr)
    {
      return node;
    }

    Node_t* temp = node->right;
    node->right = temp->left;
    temp->left = node;
    if(updateColor)
    {
      temp->isRed = node->isRed;
      node->isRed = true;
    }

    return temp;
  }

  Node_t* RotateRight(Node_t* node, bool updateColor)
  {
    if(node == nullptr)
    {
      return node;
    }

    Node_t* temp = node->left;
    node->left = temp->right;
    temp->right = node;

    if(updateColor)
    {
      temp->isRed = node->isRed;
      node->isRed = true;
    }

    return temp;
  }

  void Recolor(Node_t* node)
  {
    if(node ==nullptr)
    {
      return;
    }

    node->isRed = true;

    if(node->left != nullptr)
    {
      node->left->isRed = false;
    }
    if(node->right != nullptr)
    {
      node->right->isRed = false;
    }
  }

  Node_t* RotateAndRecolorIfRequired(Node_t* node)
  {
    if(node == nullptr)
    {
      return node;
    }

    //Validate for Child's recolor or rotation
    if(!IsRed(node->right) && IsRed(node->left) && (node->left != nullptr) && IsRed(node->left->right))
    {
      node->left = RotateLeft(node->left, false);
    }
    if(!IsRed(node->left) && IsRed(node->right) && (node->right != nullptr) && IsRed(node->right->left))
    {
      node->right = RotateRight(node->right, false);
    }

    //validate for double left or double right red color and rotate
    if(!IsRed(node->right) && IsRed(node->left) && (node->left != nullptr) && IsRed(node->left->left))
    {
      node = RotateRight(node, true);
    }
    if(!IsRed(node->left) && IsRed(node->right) && (node->right != nullptr) && IsRed(node->right->right))
    {
      node = RotateLeft(node, true);
    }
    if(IsRed(node->left) && IsRed(node->right))
    {
      Recolor(node);
    }

    return node;
  }

  Node_t* Insert(Node_t* node, int key, int value)
  {
    if(node == nullptr)
    {
      return new Node_t(key, value);
    }

    if(key < node->key)
    {
      node->left = Insert(node->left, key, value);
    }
    else if(key > node->key)
    {
      node->right = Insert(node->right, key, value);
    }
    else
    {
      node->value = value;
    }
    
    node = RotateAndRecolorIfRequired(node);
    return node;
  }

  void Print(Node_t* node, int spacesToPrint)
  {
    if (node == nullptr)
    {
        return;
    }

    spacesToPrint += 5;

    Print(node->left, spacesToPrint);

    printf("\n");
    for (int i = 5; i < spacesToPrint; i++)
    {
        printf(" ");
    }

    printf("%d(%s)\n", node->value, node->isRed ? "R" : "B");

    Print(node->right, spacesToPrint);
  }

public:
  RedBlackTree_t()
    : root(nullptr)
  {}

  void Insert(int key, int value)
  {
    root = Insert(root, key, value);
    if(root != nullptr)
    {
      root->isRed = false;
    }
  }

  void Dispaly(void)
  {
    printf("*************************************************************\n");
    Print(root, 0);
    printf("*************************************************************\n");
  }
};

int main(void)
{
  RedBlackTree_t rbt;
  vector<int> v = {10,18,7,15,16,30,25,40,60,2,1,70};
  for(int n : v)
  {
    rbt.Insert(n, n);
    rbt.Dispaly();
  }

  return 0;
}
