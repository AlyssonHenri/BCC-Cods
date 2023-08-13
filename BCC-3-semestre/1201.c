#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

typedef struct regNo{   
   struct regNo *esq;
   int info;
   struct regNo *right;
}Node;

typedef struct{
   Node *root;
}Tree;

void criar(Tree *);
bool criarNo(Node **, int);
void inserir(Tree *, int);
Node **achaRaiz(Node *, int);
bool buscar(Node *, int);
Node *min(Node *);
Node *max(Node *);
void remover(Node **, int);
void pre(Node *, Node *);
void ord(Node *, Node *);
void pos(Node *, Node *);

int main(){
   Tree tree;
   char in[13];
   int info;

   criar(&tree);

   while(fgets(in, 13, stdin) != NULL){
      switch(*(in+1)){
         case ' ':
            info = atoi(&in[2]);
            switch(*in){
               case 'I':
                  inserir(&tree, info);
                  break;
               case 'R':
                  remover(&(tree.root), info);
                  break;
               case 'P':
                  (buscar(tree.root, info)) ?
                     printf("%d existe\n", info) :
                     printf("%d nao existe\n", info);
                  break;
            }
            break;
         case 'N':
            ord(tree.root, max(tree.root));
            break;
         case 'R':
            if(tree.root != NULL){
               pre(tree.root, tree.root);
               puts("");
            }
            break;
         case 'O':
            pos(tree.root, tree.root);            
            break;
      }
   }

   return 0;
}

void criar(Tree *p_tree){
   p_tree->root = NULL;
}

bool criarNo(Node **node, int info){
   *node = (Node *)malloc(sizeof(Node));

   if(*node == NULL)
      return false;

   (*node)->info = info;
   (*node)->esq = NULL;
   (*node)->right = NULL;

   return true;
}

void inserir(Tree *p_tree, int info){
   Node **dad, *node;
   
   criarNo(&node, info);

   dad = achaRaiz(p_tree->root, info);
   if(dad == NULL)
      p_tree->root = node;
   else
      *dad = node;
}

Node **achaRaiz(Node *root, int info){
   if(root == NULL)
   /* Tree empty */
      return NULL;
   else{
      if(info <= root->info){
      /* New node must go to the root esq*/
         if(root->esq == NULL)
            return &root->esq;
         else
            return achaRaiz(root->esq, info);
      }else{
      /* New node must go to the root right*/
         if(root->right == NULL)
            return &root->right;
         else
            return achaRaiz(root->right, info);
      }
   }
}

bool buscar(Node *root, int info){
   if(root == NULL)
      return false;
   else{
      if(root->info == info)
         return true;
      else if(root->info < info)
         return buscar(root->right, info);
      else
         return buscar(root->esq, info);
   }
}

Node *min(Node *root){
    if(root == NULL)  
       return NULL;   
   else{   
      if(root->esq == NULL)  
         return root;   
      else
         return min(root->esq);       
    }   
}

Node *max(Node *root){
    if(root == NULL)  
       return NULL;   
   else{   
      if(root->right == NULL)  
         return root;
      else{
         return max(root->right);       
      }
    }   
}

void remover(Node **root, int info){   
    Node *aux;   
    if(*root != NULL){   
       if(info < (*root)->info)    
         remover(&((*root)->esq), info);    
      else{      
         if(info > (*root)->info)    
            remover(&((*root)->right), info);
         else{  
            if((*root)->esq != NULL && (*root)->right != NULL){    
               aux = max((*root)->esq);    
               (*root)->info = aux->info;   
               remover(&((*root)->esq), (*root)->info);  
            }else{  
               aux = *root;
               ((*root)->esq == NULL) ?     
                  (*root = (*root)->right) :
                  (*root = (*root)->esq);                            
               free(aux);     
            }   
         }        
      }    
   }     
}

void pre(Node *root, Node *node_root){
   if(root != NULL){
      (root == node_root) ?
         printf("%d", root->info):
         printf(" %d", root->info); 
      pre(root->esq, node_root);
      pre(root->right, node_root);
   }
}

void ord(Node *root, Node *node_max){   
   if(root != NULL){
      ord(root->esq, node_max);
      (root == node_max) ?
         printf("%d\n", root->info):
         printf("%d ", root->info);
      ord(root->right, node_max);
   }
}

void pos(Node *root, Node *node_root){
      if(root != NULL){
      pos(root->esq, node_root);
      pos(root->right, node_root);
      (root == node_root) ?
         printf("%d\n", root->info):
         printf("%d ", root->info);
   }
}