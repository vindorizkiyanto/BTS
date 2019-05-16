#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
using namespace std;

struct data{
	int nomor;
	
	data *kiri, *kanan;
}*root;


void push(data **current, int nomor){

	if((*current)==NULL){
		(*current) = (struct data *)malloc (sizeof(data));
		
		(*current)->nomor=nomor;
		(*current)->kiri = (*current)->kanan = NULL;

	}else if(nomor < (*current)->nomor){
		push(&(*current)->kiri, nomor);

	}else if(nomor >= (*current)->nomor){
		push(&(*current)->kanan, nomor);
	}
}


void preOrder(data **current){
	if((*current)!=NULL){
		printf("%d -> ", (*current)->nomor);
		preOrder(&(*current)->kiri);
		preOrder(&(*current)->kanan);
	}
}


void inOrder(data **current){
	if((*current)!=NULL){
		inOrder(&(*current)->kiri);
		printf("%d -> ", (*current)->nomor);
		inOrder(&(*current)->kanan);
	}
}


void postOrder(data **current){
	if((*current)!=NULL){
		postOrder(&(*current)->kiri);
		postOrder(&(*current)->kanan);
		printf("%d -> ", (*current)->nomor);
	}
}


void search(data **current, int nomor){
	
	if((*current)!=NULL){
		
		if(nomor<(*current)->nomor){
			search(&(*current)->kiri,nomor);
		
		}else if(nomor>(*current)->nomor){
			search(&(*current)->kanan,nomor);
	
		}else{
			printf("Found : %d", (*current)->nomor);
		}

	}else{
		printf("Not Found.");
	}
}

int main(){
	int n,cari,perulangan,menu,x;
do{
	cout<<"		Menu		"<<endl;
	cout<<"1.Tambah data"<<endl;
	cout<<"2.Pre order"<<endl;
	cout<<"3.In order"<<endl;
	cout<<"4.Post order"<<endl;	
	cout<<"5.Cari data"<<endl;
	
	cout<<"\n\nmasukkan pilihan :";	
	cin>>menu;
	if(menu==1){
	cout<<"Jumlah data = ";
	cin>>n;
	for(int i=1;i<=n;i++){
	cout<<"Masukan Nilai "<<i<<" = ";
	cin>>x;
	push(&root,n);;
}
}
if(menu==2){
	preOrder(&root);
	cout<<("\n");
}
if(menu==3){
	inOrder(&root);
	cout<<("\n");}
if(menu==4){
	postOrder(&root);
	cout<<("\n");;}
if(menu==5){
	cout<<"Data yang ingin dicari = ";
	cin>>cari;
	search(&root,cari);}

cout<<"Kembali ke menu?(1)";
cin>>perulangan;
system("cls");}
while(perulangan==1);


return 0;
}
