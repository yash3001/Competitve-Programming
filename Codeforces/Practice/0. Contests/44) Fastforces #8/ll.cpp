/* @author -> gamma30 */
#include <bits/stdc++.h>

struct dishes 
{ 
    string dish_name; 
    float dish_price; 
    int veg_nonveg;
    dishes *next_event; 
};

struct food_cat
{ 
    string cat_name; 
    food_cat *next_cat; 
    dishes *head_dishes; 
};

using namespace std;

int main(){
    food_cat *headCat = NULL;
    string catname; cin>>catname;
    string dishname; cin>>dishname;
    float disprice; cin>>dishprice;
    int type; cin>>type;

    if(headCat == NULL){
        cout<<"error";
        return 0; 
    }
    else{
        food_cat *temp = headCat;
        while(temp != NULL){
            if(temp->cat_name == catname){
                break;
            }
            temp = temp->next_cat;
        }
        if(temp == NULL){
            cout<<"error";
            return 0;
        }
        else{
            if(temp->head_dishes == NULL){
                temp->head_dishes = new dishes;
                temp->head_dishes->dish_name = dishname;
                temp->head_dishes->dish_price = dishprice;
                temp->head_dishes->veg_nonveg = type;
            }
            else{
                dishes *disHeadTemp = temp->head_dishes;
                while(disHeadTemp ->next_event != NULL){
                    disHeadTemp->next_event;
                }
                disHeadTemp = new dishes;
                disHeadTemp->dish_name = dishname;
                disHeadTemp->dish_price = dishprice;
                disHeadTemp->veg_nonveg = type;
            }
        }
    }
    return 0;
}