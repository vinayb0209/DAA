#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Job{
    int id;
    int deadline;
    int profit;
};
bool compare (Job a, Job b){
    return a.profit>b.profit;
}
void printSeqProfit(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compare);
    
    //find maximum deadline
    int maxdeadline=0;
    for(int i=0;i<jobs.size();i++){
        if(jobs[i].deadline>maxdeadline)
            maxdeadline=jobs[i].deadline;
    }

    vector<int> slots(maxdeadline+1,-1);
    int profit=0;
    for(int i=0;i<jobs.size();i++){
        for(int j=jobs[i].deadline;j>0;j--){
            if(slots[j]==-1){
                slots[j]=jobs[i].id;
                profit+=jobs[i].profit;
                break;
            }
        }
    }

    //print profit and sequence
    cout<<"Maximum Profit: "<<profit<<endl;
    cout<<"Job Sequence slots: ";
    for(int i=1;i<=maxdeadline;i++){
            cout<<slots[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<Job> jobs={{1, 2, 100},{2, 1, 19},{3, 2, 27},{4, 1, 25},{5, 3, 15}};
    printSeqProfit(jobs);
// OUTPUT:
// Maximum Profit: 142`
// Job Sequence slots: 3 1 5 
    return 0;
}