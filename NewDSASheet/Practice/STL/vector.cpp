#include<bits/stdc++.h>
using namespace std;

void print_vector(vector<int>vect1){
    for(auto it = vect1.begin(); it != vect1.end(); it++){
        cout<<"Element a vect1 : "<<*(it)<<endl;
    };
}

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

    // Insertion operation in a vector
    cout<<"------Insertion methods in a vector------"<<endl;
    vector<int> test_vector2 = {1, 2, 3, 4, 5, 6, 7};
    test_vector2.insert(test_vector2.begin(), 0); // inserting 0 at the beginning of the vector

    cout<<"After insertion of 0 at the beginning : "<<endl;
    for(auto it = test_vector2.begin(); it != test_vector2.end(); it++){
        cout<<"Element a test_vector2 : "<<*(it)<<endl;
    }

    test_vector2.insert(test_vector2.begin() + 1, 10); // inserting 10 at the 2nd index of the vector

    cout<<endl;
    cout<<"After insertion of 10 at the 2nd index : "<<endl;
    for(auto it = test_vector2.begin(); it != test_vector2.end(); it++){
        cout<<"Element a test_vector2 : "<<*(it)<<endl;
    }

    // for inserting multiple instances of a element at a time
    test_vector2.insert(test_vector2.begin() + 2, 3, 100); // inserting 100 three times at the 3rd index of the vector

    cout<<endl;
    cout<<"After insertion of 100 three times at the 3rd index : "<<endl;
    print_vector(test_vector2);

    // to know the size of the vector
    cout<<"Size of the vector : "<<test_vector2.size()<<endl;

    // Pop back operation in a vector
    cout<<"------Pop back operation in a vector------"<<endl;
    cout<<"Before pop_back() : "<<endl;
    print_vector(test_vector2);
    cout<<endl<<"After pop_back() : "<<endl;
    print_vector(test_vector2);

    // .swap() operation in a vector
    cout<<"------Swap operation in a vector------"<<endl;
    test_vector.swap(test_vector2);
    cout<<"After swap() test_vector2 is : "<<endl;
    print_vector(test_vector2);
    cout<<"After swap() test_vector is : "<<endl;
    print_vector(test_vector);

    // .clear() operation in a vector
    cout<<"------Clear operation in a vector------"<<endl;
    vector<int> clearVector = {1, 2, 3, 4, 5};
    cout<<"Before clear() : "<<endl;
    print_vector(clearVector);
    clearVector.clear();
    cout<<"After clear() : "<<endl;
    print_vector(clearVector);

    // .empty() operation in a vector
    cout<<"------Empty operation in a vector------"<<endl;
    vector<int> emptyVector = {1, 2, 3, 4, 5};
    cout<<"Before empty() : "<<endl;
    cout<<emptyVector.empty()<<endl;
    emptyVector.clear();
    cout<<"After empty() : "<<endl;
    cout<<emptyVector.empty()<<endl;
}


int main(){
    explainVector();

    return 0;
}