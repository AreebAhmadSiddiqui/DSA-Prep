class Prg
{
public:
    vector<int> leftView(Node *root)
    {
        if (root == NULL)
            return {};
        map<int, Node *> mp;        // {lvl,node};
        queue<pair<Node *, int>> q; // {node,lvl};
        q.push({root, 0});

        while (!q.empty())
        {
            Node *node = q.front().first;
            int lvl = q.front().second;
            q.pop();

            // if (mp.find(lvl) == mp.end())
                mp[lvl] = node;

            if (node->left)
                q.push({node->left, lvl + 1});
            if (node->right)
                q.push({node->right, lvl + 1});
        }

        vector<int> ans;
        for (auto &vec : mp)
        {
            int x = vec.first;
            Node *node = vec.second;
            ans.push_back(node->data);
        }

        return ans;
    }
};