#include<bits/stdc++.h>

using namespace std;

struct dishes{
    string dish_name;
    float dish_price;
    int veg_nonveg;
    dishes *next;
};

struct category{
    string cat_name;
    category *next;
    dishes *head_dishes;
};


category* createList()
{
    category* head = NULL;
    category* tmp;

    vector<string> arr = {"Starters","Mains","Desserts"};
 
   
    for (int i = 0; i < 3; i++) {
       
        if (head == NULL) {
            tmp = head = new category();
        }
        else {
            tmp->next = new category();
            tmp = tmp->next;
        }

        tmp->cat_name = arr[i];
        tmp->next = NULL;
        tmp->head_dishes = NULL;
    }
    return head;
}

void insert(string cat,string dn,category* c){
    int price,v;
    cin>>price>>v;
    while(c!=NULL && c->cat_name!=cat){
        c=c->next;
    }

    if(c!=NULL){

        dishes *d = new dishes();
        d->dish_name = dn;
        d->dish_price=price;
        d->veg_nonveg=v;
        d->next = c->head_dishes;
        c->head_dishes=d;
    }
    else{
        cout<<"Category is not present"<<endl;
    }
}

void solve(){

    // typedef struct category_name category;
    // typedef struct dishes_cat dishes;

   category *c = createList();
   
   int cnt = 4;
   while(cnt--){
      string cat, dish;
      cin>>cat>>dish;
      insert(cat,dish,c);
   }
   while(c!=NULL){
     dishes *d=c->head_dishes;
     int cheap=INT_MAX,exp=INT_MIN;
     while(d!=NULL){
        cheap=min((float)1.0*cheap,d->dish_price);
        exp=max((float)1.0*exp,d->dish_price);
        d=d->next;
     }
     cout<<"cat-name "<<c->cat_name<<" expensive dish is "<<exp<<" cheap dish is "<<cheap<<endl;
     c=c->next;
   }
}

int main()
{
  int t;
  t = 1;
  int tc = 1;
  while (t--) {
    solve();
    tc++;
  }
}