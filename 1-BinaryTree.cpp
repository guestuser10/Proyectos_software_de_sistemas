

#include <iostream>
using namespace std;

class node{
    public:
        int value;
        node* rhs;
        node* lhs;
        node(int val) : value(val), lhs(nullptr), rhs(nullptr) {}
};

node* insert(node* x, int y){
    if(x == nullptr){
        return new node(y);
    }
    if(y < x->value){
        x->lhs = insert(x->lhs, y);
    }
    if(y > x->value){
        x->rhs = insert(x->rhs, y);
    }
    return x;
};

void inorder(node* x){
    if(x != nullptr){
        inorder(x->lhs);
        cout<< x->value << " ";
        inorder(x->rhs);
    }
};


void preorder(node* x){
    if(x != nullptr){
        cout<< x->value << " ";
        preorder(x->lhs);
        preorder(x->rhs);
    }
};

void postorder(node* x){
    if(x != nullptr){
        postorder(x->lhs);
        postorder(x->rhs);
        cout<< x->value << " ";
    }
};

node* addnodes(node* &raiz){
    int x;
    cout<<"escriba el volor deseado\n>";
            cin>>x;
            raiz = insert(raiz,x);
    cout<<"añadir otro?\n1.-si\npress other key to exit\n>";
    cin>>x;
    if(x==1){
        addnodes(raiz);
    }
    return raiz;
}

void addsample(node* &raiz){
    raiz = insert(raiz, 10);
    raiz = insert(raiz, 7);
    raiz = insert(raiz, 6);
    raiz = insert(raiz, 8);
    raiz = insert(raiz, 15);
    raiz = insert(raiz, 13);
    raiz = insert(raiz, 16);
    raiz = insert(raiz, 17);
};



node* find(node* x, int y){
    if(x == nullptr || y == x->value){
        return x;
    }
    if(y < x->value){
        return find(x->lhs, y);
    }
    return find(x->rhs, y);
};

/* 
dejo el codigo antes de modicarlo como referencia de los cambios de la clase

void validar(node* x){
    if(x->value < x->lhs->value){
        validar(x->lhs);
    }
    if(x->value > x->rhs->value){
        validar(x->rhs);
    }
    cout<< "invalido";
    return;
}
*/
void validar(node* x){
    if (x == nullptr) {
        return;
    }
    if (x->lhs != nullptr && x->value <= x->lhs->value) {
       cout << "invalido\n";
       return;
    }
    if (x->rhs != nullptr && x->value >= x->rhs->value) {
        cout << "invalido\n";
        return;
    }
    validar(x->lhs);
    validar(x->rhs);
}

int main()
{
    
    int x;
    node* raiz = new node(10);
    raiz->lhs = new node(9);
    raiz->rhs = new node(15);
    
    validar(raiz);
    
    /*
    addnodes(raiz);
    addsample(raiz);
    cout<< "pre-order: ";
    preorder(raiz);
    cout<< "\nin-order: ";
    inorder(raiz);
    cout<< "\npost-order: ";
    postorder(raiz);
    
    cout<<"\n\nvalor a buscar\n>";
    cin>>x;
    
    node* result = find(raiz,x);
    cout<<"value: "<<result->value<<"\nlhs: "<<result->lhs->value<<"\nrhs: "<<result->rhs->value;
    
    return 0;
    */
}
