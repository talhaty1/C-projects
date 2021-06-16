#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <windows.h>
#define twopi 6.28
#define pi 3.14
using namespace std;

class DONUT{
    int resolution, width, height, radius, center, x, y, z, K2, index;
    float A, B, x_, y_ , z_ , ooz, cosTheta, sinTheta, cosPhi, sinPhi, cosA, sinA, Theta, Phi, sinB, cosB, luminance, *z_buffer;
    char *array, print;

public:
    DONUT()
    :resolution(3500), width(100), height(35), A(0), B(0), ooz(0), 
     Phi(0), Theta(0), K2(5), center(8), radius(4), z(20) {}
    ~DONUT(){
        delete[] array;
        delete[] z_buffer;
    }
    void setValues();
    void printDonut();
};

int main(){
    system("Color 04");
    DONUT d;
    d.setValues();
    d.printDonut();
}

void DONUT::printDonut(){
    array = new char[resolution];
    z_buffer = new float[resolution];
    while(true){
        for(int i=0; i<resolution; i++){
            array[i]=' ';
            z_buffer[i]=0;
        }
        for(Theta=0; Theta<twopi; Theta+=0.01){
            for(Phi=0; Phi<twopi; Phi+=0.05){
                cosTheta = cos(Theta);
                sinTheta = sin(Theta);
                cosPhi = cos(Phi);
                sinPhi = sin(Phi);
                cosA = cos(A);
                sinA = sin(A);
                cosB = cos(B);
                sinB = sin(B);

                x_ = ((center + (radius * cosTheta)) * (cosB * cosPhi + sinA * sinB * sinPhi)) - 
                     (radius * cosA * sinB * sinTheta);

                y_ = ((center + radius * cosTheta) * (cosPhi * sinB - cosB * sinA * sinPhi)) + 
                     (radius * cosA * cosB * sinTheta);

                z_ = (z+K2)/2+(cosA * (center + radius * cosTheta) * sinPhi) + (radius * sinA * sinTheta);
                
                luminance = ((cosPhi * cosTheta * sinB) - (cosA * cosTheta * sinPhi) - (sinA * sinTheta) + 
                                (cosB * (cosA * sinTheta - cosTheta * sinA * sinPhi)));
                
                ooz = (1/z_);
                x = (width/2)+(z * x_)/(K2+z_);
                y = (height/2)+(z * y_)/(K2 + z_);
                index = x + (width*y);
                
                if(x<width && y<height  && x>0 && y>0 && ooz > z_buffer[index]){   
                    int lum =8* (luminance);
                    z_buffer[index] = ooz;
                    array[index] = ".,-~:;=!*#$@"[luminance>0 ? lum : 0];
                }
            }
        }
        for(int i=0; i<resolution; i++){
            print = (i % width ? array[i] : '\n');
            cout<<print;
        }
        A+=0.1;
        B+=0.1;
        system("cls");
    }
}

void DONUT::setValues(){
    bool option;
    cout<<"ENTER 0 to change default value OR Press any other key to continue with default values: ";
    cin>>option;
    if(!option){
        cout<<"ENTER WIDTH OF SCREEN: ";
        cin>>width;
        cout<<"ENETR HEIGHT OF SCREEN: ";
        cin>>height;
        cout<<"ENTER CENTER: ";
        cin>>center;
        cout<<"ENTER RADIUS: ";
        cin>>radius;
        cout<<"ENTER K2 (distance from viewer): ";
        cin>>K2;
        cout<<"ENTER z (K2) : ";
        cin>>z;
        resolution = width * height;
    }
    else
        return;
}