#include <iostream>
#include <cstdlib>

using namespace std;

int FaceGenCmd(int curFace, int D){
    int rotate = D-curFace;
    
    if (rotate<0) 
      rotate+=4;
      
    for(int i=0; i<abs(rotate); i++){
        cout << 'R';
    }
    return rotate;
}


int main(){
    char cmd[101];
    int Face = 0, D = 0;  //Face 0=N, 1=E, 2=S, 3=W
    cin >> cmd;
    for(int i=0; cmd[i]!='\0'&&i<100; i++){
        switch (cmd[i])
        {
        case 'N':
            D = D + FaceGenCmd(Face, 0);
            Face = 0;
            cout << 'F';
            D++;
            break;
        case 'S':
            D = D + FaceGenCmd(Face, 2);
            Face = 2;
            cout << 'F';
            D++;
            break;
        case 'E':
            D = D + FaceGenCmd(Face, 1);
            Face = 1;
            cout << 'F';
            D++;
            break;
        case 'W':
            D = D + FaceGenCmd(Face, 3);
            Face = 3;
            cout << 'F';
            D++;
            break;
        case 'Z':
            cout << 'Z';
            Face = 0;
            D++;
            break;
        }
    }
    cout << endl;
}