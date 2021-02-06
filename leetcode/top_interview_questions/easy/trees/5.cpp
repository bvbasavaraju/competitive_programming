
struct TreeNode 
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution 
{
private:  
  TreeNode* makeBst(int l, int h, const vector<int>& nums)
  {
    if(l <= h)
    {
      int m = l + (h-l)/2;
      
      TreeNode* node = new TreeNode(nums[m]);
      node->left = makeBst(l, m-1, nums);
      node->right = makeBst(m+1, h, nums);
      
      return node;
    }
    
    return nullptr;
  }
public:
  TreeNode* sortedArrayToBST(vector<int>& nums) 
  {
    return makeBst(0, nums.size()-1, nums);
  }
};