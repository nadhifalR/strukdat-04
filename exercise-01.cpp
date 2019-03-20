/*
 * Author : Nadhifal
 * NPM : 140810180048
 * Kelas : B
 * Deskripsi :
 * Tanggal : 20 Maret 2019
 */

 #include <iostream>
 #include<iomanip>
using namespace std;

struct node{
    char nama[30];
    string bidang;
    int gaji;
    node* next;
};

void insertFirst(node*& head){
    node* temp = new node;

    cout<<"Nama Pegawai : ";cin>>temp->nama;
    cin.ignore(256,'\n');
    cout<<"Bidang       : ";cin>>temp->bidang;
    cout<<"Gaji         : ";cin>>temp->gaji;
    temp->next = NULL;

    if(head==NULL){
        head=temp;
    }
    else{
        temp->next = head;
        head=temp;
    }

}

void insertLast(node*& head){
    node* tail;
    node* temp = new node;

    cout<<"Nama Pegawai : ";cin>>temp->nama;
    cout<<"Bidang       : ";cin>>temp->bidang;
    cout<<"Gaji         : ";cin>>temp->gaji;
    temp->next = NULL;

    if(head==NULL){
        head=temp;
    }
    else{
        tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        tail->next=temp;
    }
}

void deleteFirst(node*& head){
    node* temp= new node;
    if(head==NULL){
        cout<<"List Kosong "<<endl;
    }
    else if(head->next==NULL){
        head=NULL;
    }
    else{
        temp=head;
        head=head->next;
        temp=NULL;
    }
}

void deleteLast(node*& head){
    node* tail=NULL;
    node* ptail=NULL;
    node* temp= new node;
    if(head==NULL){
        cout<<"List Kosong "<<endl;
    }
    else if(head->next==NULL){
        head=NULL;
    }
    else{
        tail=head;
        while(tail->next!=NULL){
            ptail=tail;
            tail=tail->next;
        }
        tail=NULL;
        ptail->next=NULL;
    }
}

void traversal(node* head){
    int i=1;
    if(head==NULL){
        cout<<"List Kosong "<<endl;
    }
    else{
        cout<<setfill(' ')<<setw(5)<<"No"<<setw(30)<<"Nama"<<setw(18)<<"Bidang"<<setw(18)<<"Gaji"<<endl;
        while(head != NULL){
            cout<<setw(5)<<i<<setw(30)<<head->nama<<setw(18)<<head->bidang<<setw(18)<<head->gaji<<endl;
            i++;
            head=head->next;
        }
    }
}

char menu(){
    char choice;

    cout<<"Menu"<<endl<<"1. Insert First"<<endl<<"2. Insert Last"<<endl<<"3. Delete First"<<endl<<"4. Delete Last"<<endl<<"5. Traversal"<<endl<<"6. Exit"<<endl;
    cin>>choice;
    return choice;
}

main(){
    node* head = NULL;
    char choice;

    do{
        choice=menu();

        switch(choice){

        case '1':   insertFirst(head);
                    break;
        case '2':   insertLast(head);
                    break;
        case '3':   deleteFirst(head);
                    break;
        case '4':   deleteLast(head);
                    break;
        case '5':   traversal(head);
                    break;
        default: cout<<"Quit"<<endl;
        }

    }while(choice != '6');
}
