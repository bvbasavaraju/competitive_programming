#include <memory>

using namespace std;

/*
    Note:
        Keys should be unique.
        If Key is already present in the tree then, it will replace the value

        Feature:
            + If there are 2^n entries, then tree will always be balanced.
            + Worst case of Time complexity - Big(O)
                + Insert -> 2 * Log(n)
                + Search -> 2 * Log(n)
                + Delete -> 2 * Log(n)

        References:
          + https://www.cs.princeton.edu/~rs/talks/LLRB/RedBlack.pdf
          + Coursera -> Algorithms, Part I 
                        by Robert Sedgewick
*/

class RedBlackTree_t
{
private:
    enum Color_t
    {
        BLACK = 0,
        RED = 1,
    };

    struct Node_t
    {
        int val;
        int key;
        Color_t color;
        shared_ptr<Node_t> left;
        shared_ptr<Node_t> right;

        Node_t(int val_, int key_, Color_t color_)
        {
            val = val_;
            key = key_;
            color = color_;
            left = nullptr;
            right = nullptr;
        }
    };

    shared_ptr<Node_t> root;
    int spaceCountForDisplay;

    bool IsRed(shared_ptr<Node_t> node)
    {
        if (node == nullptr)
        {
            return false;
        }

        return (node->color == Color_t::RED);
    }

    shared_ptr<Node_t> RotateLeft(shared_ptr<Node_t> node)
    {
        if ((node == nullptr) || (node->right == nullptr) || (node->right->color != Color_t::RED))
        {
            return node;
        }

        shared_ptr<Node_t> temp = node->right;
        node->right = temp->left;
        temp->left = node;
        temp->color = node->color;
        node->color = Color_t::RED;

        return temp;
    }

    shared_ptr<Node_t> RotateRight(shared_ptr<Node_t> node)
    {
        if (node == nullptr)
        {
            return node;
        }

        shared_ptr<Node_t> temp = node->left;
        node->left = temp->right;
        temp->right = node;
        temp->color = node->color;
        node->color = Color_t::RED;

        return temp;
    }

    void FlipColors(shared_ptr<Node_t> node)
    {
        if (node == nullptr)
        {
            return;
        }

        node->color = Color_t::RED;

        if (node->left != nullptr)
        {
            node->left->color = Color_t::BLACK;
        }

        if (node->right != nullptr)
        {
            node->right->color = Color_t::BLACK;
        }
    }

    shared_ptr<Node_t> RotateOrFlipColorIfRequired(shared_ptr<Node_t> node)
    {
        if (node == nullptr)
        {
            return node;
        }

        if (IsRed(node->right) && !IsRed(node->left))
        {
            node = RotateLeft(node);
        }
        if (IsRed(node->left) && ((node->left != nullptr) && IsRed(node->left->left)))
        {
            node = RotateRight(node);
        }
        if (IsRed(node->left) && IsRed(node->right))
        {
            FlipColors(node);
        }

        return node;
    }

    shared_ptr<Node_t> Add(shared_ptr<Node_t> node, int val, int key)
    {
        if (node == nullptr)
        {
            return make_shared<Node_t>(val, key, Color_t::RED);
        }

        if (key < node->key)
        {
            node->left = Add(node->left, val, key);
        }
        else if (key > node->key)
        {
            node->right = Add(node->right, val, key);
        }
        else
        {
            node->val = val;
        }

        node = RotateOrFlipColorIfRequired(node);
        return node;
    }

    shared_ptr<Node_t> Find(shared_ptr<Node_t> node, int key)
    {
        if (node == nullptr)
        {
            return node;
        }

        if (key < node->key)
        {
            node = Find(node->left, key);
        }
        else if (key > node->key)
        {
            node = Find(node->right, key);
        }

        return node;
    }

    shared_ptr<Node_t> MoveRedLeft(shared_ptr<Node_t> node)
    {
      if(node == nullptr)
      {
        return node;
      }

      FlipColors(node);
      if((node->right != nullptr) && IsRed(node->right->left))
      {
        node->right = RotateRight(node->right);
        node = RotateLeft(node);
        FlipColors(node);
      }

      return node;
    }

    shared_ptr<Node_t> MoveRedRight(shared_ptr<Node_t> node)
    {
      if(node == nullptr)
      {
        return node;
      }

      FlipColors(node);
      if((node->left != nullptr) && IsRed(node->left->left))
      {
        node = RotateLeft(node);
        FlipColors(node);
      }

      return node;
    }

    shared_ptr<Node_t> MinimumChildNode(shared_ptr<Node_t> node)
    {
        if ((node == nullptr) || ((node->left == nullptr) && (node->right == nullptr)))
        {
            return node;
        }

        if (node->left == nullptr)
        {
            return node->right;
        }

        node->left = MinimumChildNode(node->left);
        if (node->left != nullptr)
        {
            node->left->color = Color_t::RED;
            node->left = RotateOrFlipColorIfRequired(node->left);
        }
        return node;
    }

    shared_ptr<Node_t> DeleteMinimum(shared_ptr<Node_t> node)
    {
        if (node == nullptr)
        {
            return node;
        }

        if (node->left == nullptr)
        {
            return node->right;
        }

        node->left = DeleteMinimum(node->left);
        if (node->left != nullptr)
        {
            node->left->color = Color_t::RED;
            node->left = RotateOrFlipColorIfRequired(node->left);
        }
        return node;
    }

    shared_ptr<Node_t> Delete(shared_ptr<Node_t> node, int key)
    {
        if (node == nullptr)
        {
            return node;
        }

        int compareResult = (key < node->key) ? -1 : ((key > node->key) ? 1 : 0 );
        if (compareResult)
        {
          if(!IsRed(node->left) && (node->left != nullptr) && !IsRed(node->left->left))
          {
            node = MoveRedLeft(node);
          }

          node->left = Delete(node->left, key);
        }
        // else if (key > node->key)
        // {
        //     node->right = Delete(node->right, key);
        // }
        else
        {
          if(IsRed(node->left))
          {
            node = RotateRight(node);
          }

          if((compareResult == 0) && (node->right == nullptr))
          {
            return nullptr;
          }

          if(!IsRed(node->right) && (node->right != nullptr) && !IsRed(node->right->left))
          {
            node = MoveRedRight(node);
          }

          if(compareResult == 0)
          {
            node = MinimumChildNode(node->right);
            node->right = DeleteMinimum(node->right);
          }
          else
          {
            node->right = Delete(node->right, key);
          }
          

            // if (node->right == nullptr)
            // {
            //     return node->left;
            // }
            // if (node->left == nullptr)
            // {
            //     return node->right;
            // }

            // shared_ptr<Node_t> temp = node;
            // node = MinimumChildNode(temp->right);
            // node->right = DeleteMinimum(temp->right);
            // node->left = temp->left;
            // node->color = Color_t::RED;
            // node = RotateOrFlipColorIfRequired(node);
        }

        return RotateOrFlipColorIfRequired(node);
    }

    void Print(shared_ptr<Node_t> node, int spacesToPrint)
    {
        if (node == nullptr)
        {
            return;
        }

        spacesToPrint += spaceCountForDisplay;

        Print(node->left, spacesToPrint);

        printf("\n");
        for (int i = spaceCountForDisplay; i < spacesToPrint; i++)
        {
            printf(" ");
        }

        printf("%d\n", node->val);

        Print(node->right, spacesToPrint);
    }

public:
    RedBlackTree_t() : spaceCountForDisplay(5)
    {
    }

    ~RedBlackTree_t() {}

    void Initialise(int spaceCountForDisplay_)
    {
        spaceCountForDisplay = spaceCountForDisplay_;
    }

    void Add(int val, int key)
    {
        root = Add(root, val, key);
    }

    int Find(int key)
    {
        shared_ptr<Node_t> node = Find(root, key);
        if (node == nullptr)
        {
            return 0;
        }

        return node->val;
    }

    //TODO: Not working. To fix!!
    void Delete(int key)
    {
        root = Delete(root, key);
    }

    void Display(void)
    {
        Print(root, 0);
    }
};

int main()
{
    RedBlackTree_t redBlackTree;

    for (int i = 1; i < 16; i++)
    {
        redBlackTree.Add(i, i);
    }

    // redBlackTree.Add(10, 10);
    // redBlackTree.Add(18, 18);
    // redBlackTree.Add(7, 7);
    // redBlackTree.Add(15, 15);
    // redBlackTree.Add(16, 16);
    // redBlackTree.Add(30, 30);
    // redBlackTree.Add(25, 25);
    // redBlackTree.Add(40, 40);
    // redBlackTree.Add(60, 60);
    // redBlackTree.Add(2, 2);
    // redBlackTree.Add(1, 1);
    // redBlackTree.Add(70, 70);


    //redBlackTree.Delete(12);

    redBlackTree.Display();
    return 0;
}