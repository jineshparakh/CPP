#include <bits/stdc++.h>
using namespace std;

int main() {
    /*
        SMA: Static Memory Allocation
        DMA: Dynamic Memory Allocation (Implemented using new and delete in C++)

        In SMA, the amount of memory allocated to the declaration statements(int x, float y, etc) is decided
        during Compile time only and cannot be changed. However, the memoery gets allocated when the program
        comes in RAM

    */
    int* x = NULL;
    // Requesting memory for a new variable. nothrow signifies that if memory does
    // not get assigned it does not throw an error
    x = new (nothrow) int;
    if (!x) {
        cout << "Could not allocate memory\n";
    } else {
        *x = 22;
        cout << "Value of x is: " << *x << endl;
    }

    float* y = new (nothrow) float(11.111);
    if (!y) {
        cout << "Could not allocate memory\n";

    } else {
        cout << "Value of y is: " << *y << endl;
    }

    // DMA for Arrays
    int n = 10;
    int* a = new int[10];
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        // *(a+i)=i+1; // same as above
    }
    cout << "Array elements are: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    // No deallocating this memory is a memory leak
    /*

    Valgrind can help to catch this.

    Without delete calls:

❯ valgrind --leak-check=full ./a.out
    ==67110== Memcheck, a memory error detector
    ==67110== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
    ==67110== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
    ==67110== Command: ./a.out
    ==67110==
    Value of x is: 22
    Value of y is: 11.111
    Array elements are: 1 2 3 4 5 6 7 8 9 10
    ==67110==
    ==67110== HEAP SUMMARY:
    ==67110==     in use at exit: 48 bytes in 3 blocks
    ==67110==   total heap usage: 5 allocs, 2 frees, 74,800 bytes allocated
    ==67110==
    ==67110== 4 bytes in 1 blocks are definitely lost in loss record 1 of 3
    ==67110==    at 0x48479E8: operator new(unsigned long, std::nothrow_t const&) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
    ==67110==    by 0x109210: main (in /home/jineshparakh/Github/CPP/Language Features/Pointers/a.out)
    ==67110==
    ==67110== 4 bytes in 1 blocks are definitely lost in loss record 2 of 3
    ==67110==    at 0x48479E8: operator new(unsigned long, std::nothrow_t const&) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
    ==67110==    by 0x109292: main (in /home/jineshparakh/Github/CPP/Language Features/Pointers/a.out)
    ==67110==
    ==67110== 40 bytes in 1 blocks are definitely lost in loss record 3 of 3
    ==67110==    at 0x48485C3: operator new[](unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
    ==67110==    by 0x10931A: main (in /home/jineshparakh/Github/CPP/Language Features/Pointers/a.out)
    ==67110==
    ==67110== LEAK SUMMARY:
    ==67110==    definitely lost: 48 bytes in 3 blocks
    ==67110==    indirectly lost: 0 bytes in 0 blocks
    ==67110==      possibly lost: 0 bytes in 0 blocks
    ==67110==    still reachable: 0 bytes in 0 blocks
    ==67110==         suppressed: 0 bytes in 0 blocks
    ==67110==
    ==67110== For lists of detected and suppressed errors, rerun with: -s
    ==67110== ERROR SUMMARY: 3 errors from 3 contexts (suppressed: 0 from 0)

    With delete calls:

❯ valgrind --leak-check=full ./a.out
    ==67730== Memcheck, a memory error detector
    ==67730== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
    ==67730== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
    ==67730== Command: ./a.out
    ==67730==
    Value of x is: 22
    Value of y is: 11.111
    Array elements are: 1 2 3 4 5 6 7 8 9 10
    ==67730==
    ==67730== HEAP SUMMARY:
    ==67730==     in use at exit: 0 bytes in 0 blocks
    ==67730==   total heap usage: 5 allocs, 5 frees, 74,800 bytes allocated
    ==67730==
    ==67730== All heap blocks were freed -- no leaks are possible
    ==67730==
    ==67730== For lists of detected and suppressed errors, rerun with: -s
    ==67730== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
    */

    // Deallocating memory for variables
    delete x;
    delete y;

    // Deallocating memory for array
    delete[] a;

    // One should never double free memory
    // It's a tcache(thread cache) error
}