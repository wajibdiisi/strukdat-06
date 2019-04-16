/*
Nama 		: Ahmad Irfan Fadholi
NPM 		: 140810180034
Deskripsi 	: Exercise-01
Tanggal		: Selasa, 16 April 2019
*/
#include<iostream>

using namespace std;
struct CDLL{
  char Data;
  CDLL *next, *prev;
};

typedef CDLL* pointer;
typedef pointer List;
 
void createElemt(pointer &pBaru)
{
  	pBaru = new CDLL;
  	cout << "Data : "; cin >> pBaru->Data;
  	pBaru->next = NULL;
  	pBaru->prev = NULL;
}
void InsertFirst(List &First, pointer &pBaru){
 	pointer last;
  	if(First==NULL){
   		First=pBaru;
    	pBaru->next=pBaru;
    	pBaru->prev=pBaru;
  	}
  	else{
   		last=First;
  		while(last->next!=First){
      		last=last->next;
    		}
    	pBaru->next=First;
    	First->prev=pBaru;
    	pBaru->prev=last;
    	last->next=pBaru;
    	First=pBaru;
  	}
}
 
void InsertLast(List &First, pointer &pBaru)
{
  pointer last;
  if(First==NULL)
  {
    First=pBaru;
    pBaru->next=pBaru;
    pBaru->prev=pBaru;
  }
 
  else
  {
    last=First;
    while(last->next!=First)
    {
      last=last->next;
    }
    pBaru->prev=last;
    last->next=pBaru;
    pBaru->next=First;
    First->prev=pBaru;
  }
}
 
void deleteFirst(List &First, pointer &pHapus){
 	pointer last;
  	if(First==NULL){
	  	cout << "List Kosong!\n";
	} 
 	else if(First->next==NULL){
  		First=NULL;
	} 
  	else{
    	last=First;
    	while(last->next!=First){
      		last=last->next;
    	}
    	pHapus=First;
    	last->next=pHapus->next;
    	pHapus->next->prev=last;
    	First=pHapus->next;
    	pHapus->next=NULL;
    	pHapus->prev=NULL;
  	}
}
 
void deleteLast(List &First, pointer &pHapus){
  	pointer last;
  	if(First==NULL){
    	pHapus=NULL;
    	cout << "List Kosong!\n";
  	} 
  	else if(First->next==NULL){
	  	First=NULL;
	}
  	else{
    	last=First;
    	while(last->next!=First){
      		last=last->next;
    	}
    	pHapus=last;
    	First->prev=pHapus->prev;
    	pHapus->prev->next=First;
    	pHapus->prev=NULL;
    	pHapus->next=NULL;
  	}
}
 
void traversal(List First){
  	pointer pBantu;
  	if(First==NULL){
	  	cout << "List Kosong\n";
		} 
  	else{
    	pBantu=First;
    	cout<<"\nTraversal : ";
    do{
      	cout << pBantu->Data << " ";
      	pBantu=pBantu->next;
    }while(pBantu!=First);
    cout << "\n";
  }	
}
 
int main(){
  	List Elemt=NULL;
  	pointer p=NULL; 
  	char pilihan;
  	char s;
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
            createElemt(p);
            InsertFirst(Elemt, p);
            break;
       
          case '2' :
            createElemt(p);
            InsertLast(Elemt, p);
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
    }while(pilihan!='0');
}
