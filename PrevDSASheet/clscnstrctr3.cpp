#include<iostream>
using namespace std;
class Rectangle{
    private :
    int length;
    int breadth;
    public :
    Rectangle(){//default Constructor
        length = 0;
        breadth = 0;
    }
    Rectangle(int l, int b){//parameterised constructor
    length = l;
    breadth  = b;
}
int  area(){//actual methods or facinatators
    return length*breadth;
}
int  peremter(){//actual methods or facinatators
    return (2*(length+breadth));
}
int  get_length(){//accessor
    return length;
}
void  set_length(int x){//mutator
    length = x;
}
~Rectangle(){//Destructor
    cout<<"Destructor"<<endl;
}
};
int main(){
    Rectangle r(10,5);
    cout<<r.area()<<endl;
    cout<<r.peremter()<<endl;
    cout<<r.get_length()<<endl;
    }

