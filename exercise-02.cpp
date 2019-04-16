/*
Nama 		: Ahmad Irfan Fadholi
NPM 		: 140810180034
Deskripsi 	: Exercise-02
Tanggal		: Selasa, 16 April 2019
*/

#include <iostream>

using namespace std;
struct ElemtList
{
  char Data;
  ElemtList* next;
  ElemtList* prev;
};
 
typedef ElemtList* pointer;
typedef pointer List;
 
void createElemt(List& First, pointer& pBaru){
  pBaru = new ElemtList;
  cout << "Data : "; cin >> pBaru->Data;                                              
  pBaru->next = pBaru->prev = NULL;
}
 
void InsertFirst(List& First, pointer& pBaru){
	if(First==NULL){
  		First=pBaru;
}
	else{
		pBaru->next=First;
    	First->prev=pBaru;
    	First=pBaru;
  	}
}
 
void InsertLast(List& First, pointer& pBaru){
	pointer last;
	if(First==NULL){
	First=pBaru;
	}
 
  	else{
    	last=First;
    	while (last->next!=NULL){
      		last=last->next;
    	}
    	last->next=pBaru;
    	pBaru->prev=last;
  	}
}
 
void traversal(List& First){
  	pointer pBantu;
  	if(First==NULL){
		cout << "List Kosong!\n";}
	else{
      	pBantu=First;
      	do{
          	cout << pBantu->Data << " ";
          	pBantu=pBantu->next;
        }while (pBantu!=NULL);
      	cout << "\n";
    }
}
 
void deleteFirst(List& First, pointer& pHapus){
  	if(First==NULL){
  		cout << "List Kosong!\n";
  	}
  	else if(First->next==NULL){
      	pHapus=First;
      	First=NULL;
    }
  	else{
      	pHapus=First;
      	First=First->next;
      	pHapus->next=NULL;
    }
}
 
void deleteLast(List& First, pointer pHapus){
  	pointer Last;
  	if(First==NULL){
	  	cout << "List Kosong!\n";
	}
 
  	else if(First->next==NULL){
    	pHapus=First;
    	First=NULL;
  	}
 
 	 else{
    	Last=First;
    	while (Last->next!=NULL){Last=Last->next;}
    	pHapus=Last;
    	pHapus->prev->next=NULL;
    	pHapus->prev=NULL;
  	}
}
 
int main(){
  	pointer p;
 	List Elemt=NULL;
  	int pilihan;
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
        case 1 :
          cout << "Insert First\n";
          createElemt(Elemt, p);
          InsertFirst(Elemt, p);
          break;
       
        case 2 :
          cout << "Insert Last\n";
          createElemt(Elemt, p);
          InsertLast(Elemt, p);
          break;
 
        case 3 :
          cout << "Delete First\n";
          deleteFirst(Elemt, p);
          break;
 
        case 4 :
          cout << "Delete Last\n";
          deleteLast(Elemt,p);
          break;
 
        case 5 :
          cout << "Traversal : ";
          traversal(Elemt);
          break;
 
        default:
          break;
        }
    }while(pilihan!=0);
}
