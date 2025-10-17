#include<bits/stdc++.h>
using namespace std;
bool proverka(vector<string > &a,vector<string > &b){
    if(a[2]==b[2]){
        if(a[1]==b[1]){
            if(a[0]<=b[0])
                return true;
            else   
                return false;
        }
        else if(a[1]<b[1])
            return true;
        else
            return false;
    }
    else if(a[2]<b[2])
        return true;
    else 
        return false;
}
void merge(vector<vector<string> > &a,int l,int r){
    int m=(l+r)/2;
    vector<vector<string> > ls(m-l+1,vector<string> (3));
    vector<vector<string> > rs(r-m,vector<string> (3));
    for(int i=0;i<m-l+1;i++)
        ls[i]=a[l+i];
    for(int i=0;i<r-m;i++)
        rs[i]=a[m+1+i];
    int i=0,j=0;
    while(i<ls.size() && j<rs.size()){
        if(proverka(ls[i],rs[j])){
            a[l+i+j]=ls[i];
            i++;
        }
        else{
            a[l+i+j]=rs[j];
            j++;
        }
    }
    while(i<ls.size()){
        a[l+i+j]=ls[i];
        i++;
    }
    while(j<rs.size()){
        a[l+i+j]=rs[j];
        j++;
    }
}
void merge_sort(vector<vector<string> > &a,int l,int r){
    if(l<r){
    merge_sort(a,l,(l+r)/2);
    merge_sort(a,(l+r)/2+1,r);
    merge(a,l,r);
}
}
int main(){
    int n;
    cin>>n;
    char s;
    string s1;
    vector<vector<string> >a(n,vector<string> (3));
    for(int i=0;i<n;i++){
        s1="";
        cin>>s; s1+=s;cin>>s; s1+=s; 
        a[i][0]=s1;
        s1="";
        cin>>s;cin>>s;s1+=s;cin>>s;s1+=s; 
        a[i][1]=s1;
        cin>>s;
        cin>>s1;
        a[i][2]=s1;
    }
    merge_sort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i][0]<<'-'<<a[i][1]<<'-'<<a[i][2]<<endl;
    }
}