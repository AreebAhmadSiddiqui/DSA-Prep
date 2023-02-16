DEKHO ISMEIN HAM KYA KAR RAHE

a) EK EXAMPLE LO sirf 3 nodes ka

     20           20
    /  \   ->    /  \
   10   9      20    20

   ismein dekho man lo ki 10 aur 9 ke neech koi hai hi ni to ye kabhi bhi children sum ki property ko satify ni karega hamesha ham short pad jaenge sum mein
   isliye do child ko root ki value se initialise kardo kyunki 2*val > val aur haam jab apni traversal poora kar lete hai to wapis ate waqt left aur right dono ko fir se add kar dete hain to ye gaurantee ho gaya ki inka sum bada hi hoga agar niche se upar ae to
   
    20              22           
    /  \     ->    /  \
   10   12        10   12

   is case mein ham seedhe seedhe apni node ko change kardo taki yahan pe sahi rahe aur agar neeche koi nodes hui to unko lete hue aunga to iska sam badh hi jaega to no problem 

void reorder(node *root)
{
    if (root == NULL)
        return;
    int child = 0;
    if (root->left)
    {
        child += root->left->data;
    }
    if (root->right)
    {
        child += root->right->data;
    }

    if (child < root->data)
    {
        if (root->left)
            root->left->data = root->data;
        if (root->right)
            root->right->data = root->data;
    }

    reorder(root->left);
    reorder(root->right);

    int tot = 0;
    if (root->left)
        tot += root->left->data;
    if (root->right)
        tot += root->right->data;
    if (root->left || root->right) // for leaf node check
        root->data = tot;
}