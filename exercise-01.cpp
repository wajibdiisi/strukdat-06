/*
Nama 		: Ahmad Irfan Fadholi
NPM 		: 140810180034
Deskripsi 	: Exercise-01
Tanggal		: Selasa, 16 April 2019
*/

#include<iostream>
using namespace std;
 
struct ElemtList{
    char Data;
    ElemtList* next;
};
 
typedef ElemtList* pointer;
typedef pointer List;

void createList(List& First){
    First=NULL;
}
 
void createElemt(List& First, pointer& pBaru){
    pBaru=new ElemtList;
    cout << "\nMasukkan Input\n";
    cin >> pBaru->Data;
    pBaru->next=NULL;
}
 
void InsertFirst(List& First, pointer& pBaru){
    if(First==NULL)
        First=pBaru;
    else{
        pBaru->next=First;
        First=pBaru;
	}
}
void insertLast(List& First, pointer& pBaru){
    pointer Last;
    if(First==NULL){
	First=pBaru;
	}
 
    else{
        Last=First;
        while(Last->next!=NULL)
            Last=Last->next;
        	Last->next=pBaru;
    }
}
 
 
void traversal(List& First){
    pointer pBantu;
    if(First==NULL)
        cout << "List Kosong\n";
    else{
        pBantu=First;
        do{
            cout << pBantu->Data << " ";
            pBantu=pBantu->next;
        }while(pBantu!=NULL);
        cout << "\n";
    }
}
 
void deleteFirst(List& First, pointer& pHapus){
  if (First==NULL) {cout << "List Kosong\n";}
 
  else if (First->next==NULL){
    pHapus=First;
    First=NULL;
  }
 
  else{
    pHapus=First;
    First=pHapus->next;
    pHapus->next=NULL;
  }
}
 
void deleteLast(List& First, pointer& pHapus){
  pointer Last, precLast;
  if(First==NULL){cout << "List Kosong\n";}
 
  else if(First->next==NULL){
    pHapus=First;
    First=NULL;
  }
  else
  {
    Last=First;
    precLast=NULL;
    while(Last->next!=NULL)
    {
        precLast=Last;
        Last=Last->next;
    }
    precLast->next=NULL;
  }

}

int main(){
    pointer p;
    List Elemt;
    createList(Elemt);
    char pilihan;
    do{
        
        cout << "\n1. Insert First"
             << "\n2. Insert Last"
             << "\n3. Delete First"
             << "\n4. Delete Last"
             << "\n5. Traversal\n"
        	 << "\n"
        	 << "Masukkan Pilihan :  ";
        	cin >> pilihan;
        switch (pilihan){
            case '1' :
                createElemt(Elemt, p);
                InsertFirst(Elemt, p);
                traversal(Elemt);
                break;
       
            case '2' :
                createElemt(Elemt, p);
                insertLast(Elemt, p);
				traversal(Elemt);
                break;
 
            case '3' :
                deleteFirst(Elemt, p);
				traversal(Elemt);
                break;
 
            case '4' :
                deleteLast(Elemt,p);
				traversal(Elemt);
                break;
 
            case '5' :
                traversal(Elemt);
                break;
 
            default:
                break;
        }
    }while(pilihan=='1'||pilihan=='2'||pilihan=='3'||pilihan=='4'||pilihan=='5');
}
 

