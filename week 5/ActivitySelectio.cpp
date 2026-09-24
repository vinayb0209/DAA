#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Activity{
    int start;
    int finish;
};
bool compare(Activity a1,Activity a2){
    return a1.finish<a2.finish;
}
void OrderofActivity(vector<Activity> &activities){
    sort(activities.begin(), activities.end(), compare);

    cout<<"Selected Activities:"<<endl;
    int i=0;
    cout<<"("<<activities[i].start<<","<<activities[i].finish<<")"<<endl;

    for(int j=1;j<activities.size();j++){
        if(activities[j].start>=activities[i].finish){
            cout<<"("<<activities[j].start<<","<<activities[j].finish<<")"<<endl;
            i=j;
        }
    }

}
int main(){
    vector<Activity> activities={{0,6},{3,4},{1,2},{5,9},{5,7},{8,9}};
    
    OrderofActivity(activities);
//  output:
// (1,2)
// (3,4)
// (5,7)
// (8,9)
    return 0;
}
