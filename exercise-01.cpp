/*
Nama Program		: Exercise-01
Nama				: Daniel Rama H.
NPM					: 140810180045
Tanggal Pembuatan	: 25-05-2019
Deskripsi			: Linked List
*/

#include<iostream>
using namespace std;

struct Pegawai{
	char nama[20];
	char bid[20];
	int gaji;
	Pegawai* next;
};

typedef Pegawai* pointer;
typedef pointer List;

void createList (List& First){
	First = NULL;
}

void createElmt (pointer& pBaru){
	pBaru= new Pegawai;
	cout << "Nama		: ";cin.ignore();cin.getline(pBaru->nama, 20);
	cout << "Bidang		: ";cin.ignore();cin.getline(pBaru->bid, 20);
	cout << "Gaji		: ";cin >> pBaru->gaji;

	pBaru->next=NULL;
}

void insertFirst (List& First, pointer pBaru){
	if (First==NULL)
	First=pBaru;
	else{
		pBaru->next=First;
		First=pBaru;
	}
	cout<<"Data Berhasil di Input"<<endl<<endl;
}

void traversal (List First){
	pointer pBantu;
	if (First==NULL){
  		cout << "List Kosong"<<endl;
		}
 	else{
		pBantu=First;
		do{
			cout << "Nama		: "<<pBantu->nama<<endl;
			cout << "Bidang		: "<<pBantu->bid<<endl;
			cout << "Gaji		: "<<pBantu->gaji<<endl<<endl;
			pBantu = pBantu->next;}
			while(pBantu != NULL);{
			cout << endl;
		}
	}
}

void deleteFirst(List& First, pointer& pHapus){
	if (First==NULL){
		pHapus=NULL;
		cout<<"List kosong, tidak ada yang dihapus"<<endl;
		}
	else if (First->next==NULL){
		pHapus=First;
		First=NULL;
		cout<<"Data Berhasil di Hapus"<<endl<<endl;
		}
	else {
		pHapus=First;
		First=First->next;
		pHapus->next=NULL;
		cout<<"Data Berhasil di Hapus"<<endl<<endl;
		}
}

void insertLast(List& First, pointer pBaru){
	pointer last;
	if (First==NULL){
		First=pBaru;
		}
	else {
		last=First;
		while (last->next!=NULL){
		last=last->next;
		}
	last->next=pBaru;
	}
	cout<<"Data Berhasil di Input"<<endl<<endl;
}

void deleteLast(List& First, pointer& pHapus){
	pointer last,precLast;
	if (First==NULL){
		pHapus=NULL;
		cout<<"List kosong, tidak ada yang dihapus"<<endl;
		}
	else if (First->next==NULL){
		pHapus=First;
		First=NULL;
		cout<<"Data Berhasil di Hapus"<<endl<<endl;
		}
	else {
		last=First;
		precLast=NULL;
		while (last->next!=NULL){
		precLast=last;
		last=last->next;
		}
	pHapus=last;
	precLast->next=NULL;
	cout<<"Data Berhasil di Hapus"<<endl<<endl;
	}
}


int main(){
	pointer p;
	List pgw;
	int pil;
	createList(pgw);

	while(1){
		cout<<"MENU"<<endl;
		cout<<"1. Insert First"<<endl;
		cout<<"2. Insert Last"<<endl;
		cout<<"3. Delete First"<<endl;
		cout<<"4. Delete Last"<<endl;
		cout<<"5. Traversal"<<endl;
		cout<<"6. Exit"<<endl;
		cout<<"Input : ";cin>>pil;
		cout<<endl;

		switch(pil){
			case 1:
				createElmt(p);
				insertFirst(pgw, p);
				break;
			case 2:
				createElmt(p);
				insertLast(pgw,p);
				break;
			case 3:
				deleteFirst(pgw, p);
				break;
			case 4:
				deleteLast(pgw,p);
				break;
			case 5:
				traversal(pgw);
				break;
			case 6:
				return 0;
		}
	}

}
