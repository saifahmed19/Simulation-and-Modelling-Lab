#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int n=7; 
    int table[n][7]; 

    int totals[7]; 
    memset(totals, 0, sizeof(totals));

    cout<<"Enter arrival time, service time as Input:\n";

    for(int i=0; i<n; i++)
    {
        cin>>table[i][1]>>table[i][3];
        table[i][0] = i+1;
        totals[1]+=table[i][1];
        totals[3]+=table[i][3];
    }
    table[0][2] = table[0][1];
    totals[2]+=table[0][2];

    for(int i=1; i<n; i++)
    {
        table[i][2] = max(table[i][1], table[i-1][2]+table[i-1][3]);
        totals[2]+=table[i][2];
    }
    int nonWaitCust=0;
    for(int i=0; i<n; i++)
    {

        table[i][4]= table[i][2] + table[i][3];
        totals[4]+=table[i][4];
        //wait = service begin - arrival
        table[i][5]= table[i][2] - table[i][1];
        totals[5]+=table[i][5];
        if(table[i][5]>0) nonWaitCust++;
    }
    for(int i=0; i<n-1; i++)
    {
        table[i][6] = max(table[i+1][1] - table[i][4], 0);
        totals[6]+=table[i][6];
    }
    table[n-1][6]=0;
    totals[6]+=table[n-1][6];
    cout<<"\nTable:\nCustomer(0), Arrival time(1), service begin(2), service time(3), service end(4), wait(5), server idle time(6)\n";
    for(int i=0; i<7; i++){
        for(int j=0; j<n; j++){
            cout<<table[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\nTotal values of the columns:\n";

    for(int i=0; i<7; i++)
        cout<<totals[i]<<" ";

    float ans1 = float(totals[5])/float(n);
    float ans2 = float(nonWaitCust)/float(n);
    float ans3 = float(totals[6])/float(totals[3]);
    float ans4 = float(totals[3])/float(n);
    float ans5 = float(totals[1])/float(n);
    float ans6 = float(table[n-1][4])/float(n);

    cout<<"\n\nAverage Waiting time per customer: "<<ans1;
    cout<<"\nProbability of a customer to wait in the queue: "<<ans2;
    cout<<"\nIdle time for servers: "<<ans3;
    cout<<"\nAverage service time: "<<ans4;
    cout<<"\nAverage arrival time: "<<ans5;
    cout<<"\nAverage time customer spent in system: "<<ans6;
    cout<<"\n";
    return 0;
}