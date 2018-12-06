#include <iostream>
#include <string.h>

using namespace std;

struct Tumpukan{
    int no_punggung;
    char nama[50],posisi[20];
    Tumpukan *next;
};
Tumpukan *top;

class Stack{
public:
    void push(int no_punggung, char nama[], char posisi[]);
    void pop();
    void displayStack();
};

void Stack::push(int no, char nama[], char posisi[]) {
    struct Tumpukan *newNode = new Tumpukan;
    newNode->no_punggung=no;
    strcpy(newNode->nama,nama);
    strcpy(newNode->posisi,posisi);
    newNode->next=top;
    top=newNode;
}

void Stack::pop() {
    if(top==NULL){
        cout<<"Stack Kosong"<<endl;
        return;
    }
    cout<<top->nama<<"Sudah Dihapus"<<endl;
    top=top->next;
}

void Stack::displayStack() {
    if(top==NULL){
        cout<<"Stack Kosong"<<endl;
        return;
    }
    
    struct Tumpukan *temp=top;
    while (temp!=NULL){
        cout<<"No punggung: "<<temp->no_punggung<<endl;
        cout<<"Nama: "<<temp->nama<<endl;
        cout<<"Posisi: "<<temp->posisi<<endl<<endl;
        temp=temp->next;
    }
}

int main() {
    Stack stack;
    int pilih;
    while (true){
        cout<<"-----------------"<<endl;
        cout<<"Menu"<<endl;
        cout<<"-----------------"<<endl;
        cout<<"1. Push stack"<<endl;
        cout<<"2. Pop stack"<<endl;
        cout<<"3. Display Stack"<<endl;
        cout<<"4. Exit program"<<endl;
        cout<<"Masukkan Pilihan : ";cin>>pilih;
        switch (pilih){
            case 1: {
                Tumpukan node;
                cout << "Data Pemain" << endl;
                cout << "----------------------" << endl;
                cout << "Masukkan Nomor Punggung : ";
                cin>>node.no_punggung;
                cout << "Masukkan Nama			 : ";
                cin.ignore(1);
                cin.getline(node.nama,50);
                cout << "Masukkan Posisi		: ";
                cin.getline(node.posisi,20);
                stack.push(node.no_punggung, node.nama, node.posisi);
                break;
            }
            case 2:
                stack.pop();
                break;
            case 3:
                stack.displayStack();
                break;
            case 4:
                exit(0);
            default:
                cout<<"Pilihan yang anda masukkan salah";
                break;
        }
    }
}
