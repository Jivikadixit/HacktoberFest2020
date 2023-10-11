//program to construct Binary tree from inorder and preorder Traversal
TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int start,int end,int &index)
{
   if(start>end) return NULL;
    TreeNode* root=new TreeNode(preorder[index++]);
     int mid=0;
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==root->val)
        {
            mid=i;break;

        }
       
    }
    root->left=solve(preorder,inorder,start,mid-1,index);
    root->right=solve(preorder,inorder,mid+1,end,index);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int index=0;
       return solve(preorder,inorder,0,n-1,index);
    }
