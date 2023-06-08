class node{
   public:
   int data;
   node *left_child, *right_child;
   friend class obst;
   node(int x){
      data = x;
      left_child = NULL;
      right_child = NULL;
   }
};
