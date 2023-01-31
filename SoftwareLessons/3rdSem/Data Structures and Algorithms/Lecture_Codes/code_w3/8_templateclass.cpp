#include <cstdlib>
#include <iostream>
using namespace std;

template <class T>
class Number{
public:
    Number(T x){
        this->x=x;
    }
    T get(){
       return x; 
    }
private:
    T x;
};

int main(int argc, char** argv) {
    
    Number<string> s1("123");
    cout<<s1.get()<<endl;
    
    Number<float> *s2=new Number<float>(5.5);
    cout<<s2->get()<<endl;
    delete s2;
    return 0;
}

/*

template<class T>
class Number{
public:
    Number(T x);
    T get();
private:
    T x;
};
template<class T>
Number<T>::Number(T x){
        this->x=x;
    }
template<class T>
T Number<T>::get(){
       return x; 
 }


*/

/*
class Number{
public:
    Number(int x){
        this->x=x;
    }
    int get(){
       return x; 
    }
private:
    int x;
};
int main(int argc, char** argv) {
    Number s1(5);
    cout<<s1.get()<<endl;
    return 0;
}
 */
