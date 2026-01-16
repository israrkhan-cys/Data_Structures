#include <iostream>
using namespace std;

class Product{
    public:
   string name;
   string category;
   float price;
   int Rating;
    int Stock;

      Product(){}
    Product(string n, string cat, float p, int r, int s){
            name= n;
            category=cat;
            price=p;
            Rating=r;
            Stock=s;
    }



    void Display(){
        cout<<"Name : "<<name<<" | Category : "<<category<<" | Price: "<<price
        <<" | Rating : "<<Rating<<" | Quantity :"<<Stock<<endl;
    }
};


class Node {
public:
    Product product;
    Node* next;

    Node(Product pro){
         product =pro;
         next =nullptr;
    }
};

class Product_recomendation{
      Node *head, *tail;
  public:
   Product_recomendation(){
    head = nullptr;
    tail=nullptr;
   } 

  void Insert(Product pro){
     Node* newNode =new Node(pro);
      if(head ==nullptr){
        tail=head =newNode;  return;    
      }
      Node *tN=head;
      while(tN!=nullptr){
        if(tN->product.name==pro.name){
            cout<<"Duplicate Not inserted.";
            return;
        }
        tN=tN->next;
      }
    tail->next=newNode;
    tail=newNode;
  }

  void RecommendProductbyPrice(float min, float max){
       Node *tn=head;
       bool found =false;
       while(tn!= nullptr){
          if(tn->product.price >= min && tn->product.price <=max && tn->product.Stock>0){
            tn->product.Display();
            found=1;
          }
          tn=tn->next;
       }

    if(!found){cout<<"No products available";}
  }

  void SearchProductbyCategory(string cat){
    Node *tn=head;
    bool found=0;
       while(tn!= nullptr){
          if(tn->product.category == cat  && tn->product.Stock>0){
             tn->product.Display();
             found=1;
          }
          tn=tn->next;
       }

       if(!found){cout<<"No products available";}
  }
  void SearchProductByRating(int rat){
    Node *tn=head;
    bool found=0;
       while(tn!= nullptr){
          if(tn->product.Rating >=rat&& tn->product.Stock>0){
             tn->product.Display();
             found=1;
          }
          tn=tn->next;
       }


       if(!found){cout<<"No products available";}
  }

  void SearchProductStock(){
    Node *tn=head;
    bool found=0;
       while(tn!= nullptr){
          if(tn->product.Stock>0){
             tn->product.Display();
             found=1;
          }
          tn=tn->next;
       }

       if(!found){cout<<"No products available";}
  }

void SortProductByPrice(){
    Node *tn=head;

    while(tn->next!=nullptr){
         Node *tn2 =tn->next;
         while(tn2!=nullptr  || tn2->next != nullptr){
            if(tn->product.price > tn2->product.price){
                Product temp= tn->product;
                tn->product= tn2->product;
                tn2->product= temp;
            }
            tn2=tn2->next;
         }
         tn=tn->next;
    }
}


};


int main() {
  Product_recomendation R;

  while (true){
     cout<<"1.Add new PRoduct.\n";
     cout<<"2.Search Product By Price (min-max).\n";
     cout<<"3.Search PRoduct by Category .\n";
     cout<<"4.Search Product by  Rating. \n";
     cout<<"5.Show Product within Stock.\n ";
     cout<<"6.Sort Products by Price. \n";
     cout<<"7.Exit.\n";
     cout<<"Enter choice:";
     int choice;  cin>>choice;
     switch(choice){
        case 1:{
            string n, cat; float p; int r,s;
            cout<<"Enter Product name: ";
            cin.ignore();
            getline(cin,n);
            cout<<"Enter PRoduct Category: ";
            getline(cin, cat);
            cout<<"Enter Price of the Product : ";
            cin>>p;
            cout<<"Enter Rating for te Product: ";
            cin>>r;
            cout<<"Enter the Stock available: ";
            cin>>s;
         Product p1(n,cat,p,r,s);
           R.Insert(p1);
        }
        break;
        case 2:{
             int min, max;
             cout<<"Enter range for Product search: ";
             cin>>min>>max;
             R.RecommendProductbyPrice(min,max);
         }
         break;
        case 3:{
               string cat;
               cout<<"Enter category for Search: ";
               cin.ignore();
               getline(cin,cat);
               R.SearchProductbyCategory(cat);
        }
        break;
        case 4:{
            int Rat;
            cout<<"Enter Rating for Product search: ";
            cin>>Rat;
            R.SearchProductByRating(Rat);
        }
         break;
        case 5:{
            R.SearchProductStock();
        }  break;
          case 6:{
             R.SortProductByPrice();
             break;
          }
        case 7:{
            cout<<"Exit...";
            return 0;
        }
        default:
           cout<<"Invalid choice Try again\n";
           break;
     }


    
  }




    
    
    return 0;
}