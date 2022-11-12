#include <iostream>
using namespace std; 


int fact(int n);


int main(){
    int num;
    cout<<"n:"<<endl;
    cin>>num;
    cout<<fact(num);

}


int fact(int n){
    int resp=1;
    for(int x=1; x<=n; x++){
        resp = resp * x;
    }
    return resp;
}

