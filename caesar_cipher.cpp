#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct {             
    int A,a=0;int B,b=1;int C,c=2;int D,d=3;int E,e=4;
    int F,f=5; int G,g=6;int H,h=7;int I,i=8;int J,j=9;
    int K,k=10;int L,l=11;int M,m=12;int N,n=13;int O,o=14;
    int P,p=15;int Q,q=16;int R,r=17;int S,s=18;int T,t=19;
    int U,u=20;int V,v=21;int W,w=22;int X,x=23;int Y,y=24;int Z,z=25;
}alfabet;   


int cheie();
char incript_litera(char ch, int key);
char decript_litera(char ch, int key);
string incriptie(string text, int key);
string decriptie(string text, int key);


int main() {
    string text;
    int alege;
    int key;

    cout << "Input text: \n";
    getline(cin, text);

    key = cheie();
    
    cout << "Choose an option \n1. Encryption \n2. Decryption \n";
    cin >> alege;
    
    if (alege == 1) {
        cout << "Encrypted text: " << '\n' << incriptie(text, key) << endl;
    } else if (alege == 2) {
        cout << "Decrypted text: " <<'\n' << decriptie(text, key) << endl;
    } else {
        cout << "INVALID" << endl;
    }
    
    return 0;
}


int cheie() {
    int key;
    while (true) {
        cout << "Select key: \n";
        if (cin >> key) {
            if (key >= 1 && key <= 25) {
                cin.ignore(); 
                return key;
            } else {
                cout << "INVALID KEY. MUST BE BETWEEN 1 and 25!" << endl;
            }
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "INVALID INPUT. KEY MUST BE A NUMBER!" << endl;
        }
    }
}

char incript_litera(char ch, int key) {
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
        return (ch >= 'A' && ch <= 'Z') ? 'A' + (alfabet.A + (ch - 'A') + key) % 26 : 'a' + (alfabet.a + (ch - 'a') + key) % 26;
    }
    return ch;
}

char decript_litera(char ch, int key) {
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
        return (ch >= 'A' && ch <= 'Z') ? 'A' + (alfabet.A + (ch - 'A') - key + 26) % 26 : 'a' + (alfabet.a + (ch - 'a') - key + 26) % 26;
    }
    return ch;
}

string incriptie(string text, int key) {
    for (char &ch : text) {
        ch = incript_litera(ch, key);
    }
    return text;
}

string decriptie(string text, int key) {
    for (char &ch : text) {
        ch = decript_litera(ch, key);
    }
    return text;
}
