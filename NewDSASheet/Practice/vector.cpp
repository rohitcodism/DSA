#include<bits/stdc++.h>
using namespace std;

void explainVector(){
    vector<int> v;

    v.push_back(11);

    v.emplace_back(12);

    vector<pair<int, int>> v2;

    v.emplace_back(20);

    vector<int> vect1(5,100); // {100, 100, 100, 100, 100}

    vector<int> vect2(5); // {0, 0, 0, 0, 0}

    vector<int> vect3(vect1); // {100, 100, 100, 100, 100}, copy of vect1

    vector<int> test_vector = {1, 2, 3, 4, 5};

    cout<<"------Vector 1------"<<endl;
    cout<<"Vector 1 : "<<vect1[0]<<endl;

    cout<<"Accessing element using .at() : "<<vect1.at(2)<<endl;

    // ------- Iterator -------
    cout<<"------Iterator------"<<endl;

    vector<int>::iterator it = vect1.begin();

    cout<<"Using begin() and iterator : "<<endl;

    cout<<"Element a 0th index of vect1"<<*it<<endl; // points to the element at index 0 of vect1

    it++; // incrementing the iterator

    cout<<*it<<endl; // points to the element at index 1 of vect1

    // .end() points to the next of the last element
    vector<int>::iterator it1 = vect1.end();

    it1--; // decrementing the iterator

    cout<<"Using end() and iterator : "<<endl;

    cout<<*it1<<endl; // points to the element at index 4 of vect1

    // .back() points to the last element

    cout<<"Using back() : "<<test_vector.back()<<endl; // 5

    // Printing the elements of vector
    cout<<"------Standard way of printing all the elements in a vector------"<<endl;
    for(vector<int>::iterator it = test_vector.begin(); it != test_vector.end(); it++){
        cout<<"element of test_vector : "<<*it<<endl; // printing each element of the test_vector
    }

    // Simpler way of printing all the elements in a vector
    cout<<"------Simpler way of printing all the elements in a vector------"<<endl;
    for(auto it = test_vector.begin(); it != test_vector.end(); it++){
        cout<<"Element a test_vector : "<<*(it)<<endl;
    }

    // Deletion operation in a vector
    cout<<"------Different types of deletion methods in a vector------"<<endl;
    
    // Deletion of single element at a time
    test_vector.erase(test_vector.begin());
    cout<<"After deletion of first element : "<<endl;
    for(auto it = test_vector.begin(); it != test_vector.end(); it++){
        cout<<"Element a test_vector : "<<*(it)<<endl;
    }

    // deletion of range of elements at a time
    test_vector.erase(test_vector.begin(), test_vector.begin() + 2); //<-- in this function, the first argument is the starting point and the second argument is the ending point, but the ending point is not included

    cout<<"After deletion of two elements : "<<endl;
    for(auto it = test_vector.begin(); it != test_vector.end(); it++){
        cout<<"Element a test_vector : "<<*(it)<<endl;
    }
}

int main(){
    explainVector();

    return 0;
}