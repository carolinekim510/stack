/*
 * COSC 2436
 * Stacks Assignment
 * Do not modify this comment
 *
 * You may modify this file ONLY where indicated below
 */

#include "main.h"

int main() {
    /**************************************************************/
    /* DO NOT MODIFY ANYTHING BETWEEN THIS LINE AND THE ONE BELOW */
    /**************************************************************/

    //this program uses rand, this is the seed (do this only once!)
    srand(time(NULL));

    // making 5 - 25 test cases
    int number_test_cases = rand() % (TEST_CASE_BASE + 1) + TEST_CASE_OFFSET;

    //making test case parallel arrays to hold test data
    int ids[number_test_cases];
    char *data[number_test_cases];
    for (int i = 0; i < number_test_cases; i++) {
        data[i] = new char[BUFFER_SIZE];
    }

    //filling arrays with test case data
    cout << "Making " << number_test_cases << " test cases..." << endl;
    make_test_cases(ids, data, number_test_cases);
    cout << "Test cases done" << endl << endl;
    display_test_cases(ids, data, number_test_cases);

    /**************************************************************/
    /* MODIFY THE FILE FROM HERE DOWN */
    /**************************************************************/

    /*
     * At this point you have two parallel arrays. A simple integer array (ids)
     * that holds random integers, and 2D character array (which is a
     * 1D array of strings) holding 'dummy' strings. Compile and run the
     * program as-is and you will see the display of these two arrays.
     */

    // declare the stack
    Stack stack;

    /*****************************************
     * Perform your stack tests starting here
     *****************************************/

    /* first call isEmpty(), peek(), and pop() to show what happens when
     * you do that on an empty stack */

    /*
     * Now perform an exhaustive series of tests on your stack. Push all the
     * cases. Pop all the cases. Randomly push and pop cases. Test peek() and
     * isEmpty() randomly and throughout the other cases. Your tests must be
     * exhaustive! Show all possible ways your stack can be used and abused,
     * and that your stack will gracefully handle ALL cases. You must use
     * automated testing (no user input). Make sure you run your program
     * many times to see what happens when the test cases are bigger, smaller,
     * or the same size as the size of your stack. Also show what happens
     * when you try and push negative ids and/or empty strings, which your
     * stack should not accept.
     */

    /************************************************
    ******* EMPTY TESTS *****************************
    ************************************************/

    // calling empty stack
    cout <<"\n\n1 ---------  Calling empty stack" << endl;
    if (stack.isEmpty()){
        cout << "hello empty" << endl;
    } else {
        cout << "It's not empty" << endl;
    }


    cout << endl;
    // Declaring the data
    Data myData;


    // peek with empty stack
    cout <<"2 ---------  Checking to peek" << endl;
    if (!stack.isEmpty()){
        cout << "peeked" << stack.peek(&myData) << endl;
    } else{
        cout << "peek underflow error: stack is empty" << endl;
    }


    cout << endl;

    //popping empty stack
    cout <<"3 ---------  Checking to pop" << endl;
    if (!stack.isEmpty()){
        cout << "popped" << stack.pop(&myData) << endl;
    } else{
        cout << "pop underflow error: stack is empty" << endl;
    }

    cout << endl;
    /************************************************
    ******** FILLING AND FULL TESTS *****************
    ************************************************/

    //pushing the data, from 2d array to MY stack.  Expecting one false
    cout <<"4 ---------  Push and filling the stack" << endl;
    if (stack.isEmpty()){
        for (int i = 0; i < number_test_cases; i++){
            string convertStr(data[i]);
            cout << stack.push(ids[i], &convertStr) << endl;
        }
    } else {
        cout << "stack is full" << endl;
    }

    cout << endl;

    //checking if stack is ever empty
    cout <<"5 ---------" << endl;
    if (stack.isEmpty()){
        cout << "hello empty" << endl;
    } else {
        cout << "It's not empty" << endl;
    }

    cout << endl;

    // chceking if there is any data to peek
    cout <<"6 --------- Checking to peek: True" << endl;
    cout << stack.peek(&myData) <<endl;

    cout << endl;

    //pushing the data, from 2d array to MY stack
    cout <<"7 --------- Peek an pop" << endl;
    for (int i = 0; i < number_test_cases; i++){
        if (!stack.isEmpty()){
            cout << "peeked: " << stack.peek(&myData) << endl;
            cout << myData.id << ": " << myData.information << endl << endl;
            cout << "popped: " << stack.pop(&myData) << endl;
        } else {
            cout << "stack underflow: stack is empty. nothing to peek or pop" << endl;
        }
    }

    cout << endl;
    cout <<"8 --------- Is it empty?" << endl;
    if (stack.isEmpty()){
        cout << "Stack is empty" << stack.isEmpty() << endl;
    } else {
        cout << "It's not empty" << stack.isEmpty() << endl;
    }
    cout << endl;



    string a = "";
    cout << "\n9 --------- Pushing Empty String" << endl;
    if (stack.isEmpty()){
        cout << stack.push(23, &a) << endl;
    }

    string b = "stacking";
    cout << "\n10 --------- Pushing Negative integer" << endl;
    if (stack.isEmpty()){
        cout << stack.push(-1, &b) << endl;
    }

    //string b = "stacking";
    cout << "\n11 --------- Pushing int and const string" << endl;
    if (stack.isEmpty()){
        cout << stack.push(1, &b) << endl;
    }

    cout << "\n12 --------- Popping last  tested element" << endl;
    cout << stack.pop(&myData) << endl;

    cout << endl;
    cout << endl;
    /************************************************
    ******** RANDOM TESTS ***************************
    ************************************************/

    cout << "13 --------------------------- Random tesing" << endl;
    cout << "Start testing..." << endl;
    cout << endl;
    cout << endl;

    // filling the stack half way with random numbers to begin random tests
    for (int i = 0; i< int(STACK_SIZE / 2); i++) {
        string convertStr(data[i]);
        if (stack.push(ids[i], &convertStr)){
            cout << "pushed ---" << ids[i] << ": " << convertStr << endl;
        } else {
            cout << "overflow error: " << i + 1 << " not pushed" << endl;
        }
    }

    cout << endl;


    for (int i = 0; i < RANDOM_TRIES; i++) {
        int choice = rand() % CHOICES + 1;
        // Purpose to get the index number so the data can be called from the 2d array
        int idx = rand() % number_test_cases / 2 ;
        // Need to create an object since the case isn't able to jump around and hold initiated object
        string convertStr;
        switch (choice) {
            case 1:
            case 2:
                //pushing
                cout << "\nStart pushing" << endl;
                convertStr = data[idx];
                if (stack.push(ids[idx], &convertStr)) {

                    cout << "It pushed... " << endl;
                } else {
                    cout << "stack overflow" << endl;
                }
                break;
            case 3:
            case 4:
                //popping
                cout << "\nStart popping" << endl;
                if (stack.pop(&myData)){
                    cout << "Popped:   " << stack.pop(&myData) << myData.id << ": " << myData.information << endl;
                } else {
                    cout << "Nothing to pop..." << stack.pop(&myData) << endl;
                }
                break;
            case 5:
                //peeking
                cout << "\nStart peeking..." << endl;
                if (stack.peek(&myData)){
                    cout << "Peeked   " << stack.peek(&myData) << myData.id << ": " << myData.information << endl;
                } else {
                    cout << "Stack underflow. " << stack.peek(&myData) << endl;
                }
                break;
            case 6:
                //isEmpty
                cout << "\nIs it empty?" << endl;
                if (stack.isEmpty()){
                    cout << "hello empty  " << stack.isEmpty() << endl;
                } else {
                    cout << "It's not empty  " << stack.isEmpty() << endl;
                }
                break;
        }
    }



    return 0;
}

