#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Item{
    int profit;
    int weight;
    int id;
};
bool compare(Item a, Item b){
    double r1=(double)a.profit/a.weight;
    double r2=(double)b.profit/b.weight;
    return r1 > r2;
}

void FractionalKnapsack(vector<Item>& items, int n, int capacity){
    sort(items.begin(),items.end(),compare);

    double  Profit=0;
    for(int i=0;i<n;i++){
        if(items[i].weight<=capacity){
            cout<<"Item "<<items[i].id<<" is taken completely."<<endl;
            Profit+=items[i].profit;
            capacity-=items[i].weight;
        }
        else{
            double fraction=(double)capacity/items[i].weight;
            Profit += (double)items[i].profit*fraction;
            cout<<"Item "<<items[i].id<<" is taken partially: "<<fraction<<endl;
            break;
        }
    }
    cout<<"Maximum profit : "<<Profit<<endl;
}
int main(){
    vector<Item>items={{60, 10, 1},{100, 20, 2},{120, 30, 3}}; 
    int M=50;
    int n=items.size();
    FractionalKnapsack(items, n, M);
// OUTPUT:
// Item 1 is taken completely.
// Item 2 is taken completely.
// Item 3 is taken partially: 0.666667
// Maximum profit : 240
    return 0;
}