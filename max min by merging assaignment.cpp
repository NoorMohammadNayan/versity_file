

#include<bits/stdc++.h>
using namespace std;

int max_left=-1000000,min_left=1000000;
int max_right=-1000000,min_right=1000000;

int max_value=-1000000,min_value=1000000;


void merging(int arr[],int start,int mid,int eend){

    for(int i=start;i<=mid;i++)
    {
        max_left=max(max_left,arr[i]);
        min_left=min(min_left,arr[i]);
    }



    for(int i=mid+1;i<=eend;i++)
    {
        max_right=max(max_right,arr[i]);
        min_right=min(min_right,arr[i]);
    }


    max_value=max(max_left,max_right);
    min_value=min(min_left,min_right);
}



void merge_sort(int arr[],int start,int eend)
{
    int mid;
    if(start<eend){
        mid=(start+eend)/2;

        cout<<"Rnage : start_index ;"<<start<<" end_index :"<<eend<<"    max : "<<max_value<<"    min : "<<min_value<<endl;

        merge_sort(arr,start,mid);
        cout<<"Rnage : start_index ;"<<start<<" end_index :"<<eend<<"    max : "<<max_value<<"    min : "<<min_value<<endl;

        merge_sort(arr,mid+1,eend);
        cout<<"Rnage : start_index ;"<<start<<" end_index :"<<eend<<"    max : "<<max_value<<"    min : "<<min_value<<endl;

        merging(arr,start,mid,eend);
        cout<<"Rnage : start_index ;"<<start<<" end_index :"<<eend<<"    max : "<<max_value<<"    min : "<<min_value<<endl;
        cout<<"                -------------------------              "<<endl;
    }

}



int main()
{

    int n,m;
    int arr[200005];
    cout<<"                   By merging finding max and min value : "<<endl;

    cout<<"enter how many elements in array :";cin>>n;

    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<"****************************\n\n";

    time_t S=clock();
    merge_sort(arr,0,n-1);

    time_t E=clock();


    cout<<"max_value : "<<max_value<<"   min_ value : "<<min_value<<endl;

    cout<<" required time : "<<double(E-S)/1000<<endl;


    return 0;
}
