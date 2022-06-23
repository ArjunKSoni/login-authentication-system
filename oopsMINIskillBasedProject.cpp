#include<bits/stdc++.h>
#include <fstream>
using namespace std;
bool readUser(ifstream& fin,string line){
    fin.open("sample.csv");
    string k;
    while(fin){
        getline(fin,k);
        if(k==line){
            cout<<"user name already exist"<<endl;
            fin.close();
            return 1;
        }
    }fin.close();
    return 0;
}
void read(ifstream& fin,string name,string pass){
    fin.open("sample.csv");
    string k;
    while(fin){
        getline(fin,k);
        if(k==name){
            string q;
            getline(fin,q);
            if(q==pass){
                cout<<"successfully logged in"<<endl;
                cout<<"User = "<<k<<endl;
            }else cout<<"Incorrect password"<<endl;
            break;
        }
    }fin.close();
}
void write(ofstream& fout,string line){
        fout<<line<<endl;
}

int main(){
    ofstream fout;
    ifstream fin;
    cout<<"register(1)  login(2) : ";
    int val;cin>>val;
    if (val==1){
        string line;
        fout.open("sample.csv", ios::app);
        cout<<"        REGISTER TO EURA  "<<endl;
        bool tru=1;
        while(tru==1){
            cout<<"Enter user name : ";
            cin>>line;
            tru=readUser(fin,line);
        }
        write(fout,line);
        cout<<"enter password : ";
        cin>>line;
        write(fout,line);
    }else if(val==2){
        string name,pass;
        cout<<"        LOGIN  "<<endl; 
        cout<<"Enter user name : ";
        cin>>name;
        cout<<"Enter password : ";
        cin>>pass;
        read(fin,name,pass);
    }fout.close();
    return 0;
}