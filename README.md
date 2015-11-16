-------------------------
Parallele Systeme Übung 1
-------------------------

Speedup:

admin@PC:~$ ./slow 1000 1000 10000
Matrix sizes C[1000][10000] = A[1000][1000] x B[1000][10000]
Perform matrix multiplication...
Done in 166.072266 seconds.

admin@PC:~$ ./fast 1000 1000 10000
Matrix sizes C[1000][10000] = A[1000][1000] x B[1000][10000]
Perform matrix multiplication...
Done in 107.939453 seconds.

#Uuups with pragma omp parallel for collapse(3) before first for (even with private(i,j,k))

ubuntu-admin@Ubuntu-PC:~/parallele-sys1$ ./fastshow 3 3 3
Matrix sizes C[3][3] = A[3][3] x B[3][3]
Perform matrix multiplication...
Matrix A:
   3.0      6.0      7.0   
   5.0      3.0      5.0   
   6.0      2.0      9.0   
Matrix B:
   1.0      2.0      7.0   
   0.0      9.0      3.0   
   6.0      0.0      6.0   
Matrix C:
  45.0     60.0     81.0   
  35.0     10.0     74.0   
  60.0     30.0    102.0   

Done in 0.000000 seconds.
ubuntu-admin@Ubuntu-PC:~/parallele-sys1$ ./fastshow 3 3 3
Matrix sizes C[3][3] = A[3][3] x B[3][3]
Perform matrix multiplication...
Matrix A:
   3.0      6.0      7.0   
   5.0      3.0      5.0   
   6.0      2.0      9.0   
Matrix B:
   1.0      2.0      7.0   
   0.0      9.0      3.0   
   6.0      0.0      6.0   
Matrix C:
  45.0     60.0     81.0   
  35.0     37.0     74.0   
  60.0     30.0    102.0   

Done in 0.005859 seconds.

#Same with pragma omp parallel for collapse(2) before second for

ubuntu-admin@Ubuntu-PC:~/parallele-sys1$ ./fastshow 3 3 3
Matrix sizes C[3][3] = A[3][3] x B[3][3]
Perform matrix multiplication...
Matrix A:
   3.0      6.0      7.0   
   5.0      3.0      5.0   
   6.0      2.0      9.0   
Matrix B:
   1.0      2.0      7.0   
   0.0      9.0      3.0   
   6.0      0.0      6.0   
Matrix C:
  45.0     54.0     81.0   
  35.0     37.0     74.0   
  60.0     30.0    102.0   

Done in 0.000000 seconds.
ubuntu-admin@Ubuntu-PC:~/parallele-sys1$ ./fastshow 3 3 3
Matrix sizes C[3][3] = A[3][3] x B[3][3]
Perform matrix multiplication...
Matrix A:
   3.0      6.0      7.0   
   5.0      3.0      5.0   
   6.0      2.0      9.0   
Matrix B:
   1.0      2.0      7.0   
   0.0      9.0      3.0   
   6.0      0.0      6.0   
Matrix C:
  45.0     60.0     81.0   
  35.0     37.0     74.0   
  60.0     30.0    102.0   

Done in 0.000000 seconds.


#same here: pragma omp parallel for before third for loop

ubuntu-admin@Ubuntu-PC:~/parallele-sys1$ ./fastshow 3 3 3
Matrix sizes C[3][3] = A[3][3] x B[3][3]
Perform matrix multiplication...
Matrix A:
   3.0      6.0      7.0   
   5.0      3.0      5.0   
   6.0      2.0      9.0   
Matrix B:
   1.0      2.0      7.0   
   0.0      9.0      3.0   
   6.0      0.0      6.0   
Matrix C:
  42.0     60.0     81.0   
  35.0     37.0     74.0   
  60.0     30.0    102.0   

Done in 0.000000 seconds.
ubuntu-admin@Ubuntu-PC:~/parallele-sys1$ ./fastshow 3 3 3
Matrix sizes C[3][3] = A[3][3] x B[3][3]
Perform matrix multiplication...
Matrix A:
   3.0      6.0      7.0   
   5.0      3.0      5.0   
   6.0      2.0      9.0   
Matrix B:
   1.0      2.0      7.0   
   0.0      9.0      3.0   
   6.0      0.0      6.0   
Matrix C:
  45.0     60.0     81.0   
  35.0     37.0     74.0   
  60.0     30.0    102.0   

Done in 0.000000 seconds.




#Yay it works

ubuntu-admin@Ubuntu-PC:~/parallele-sys1$ ./matmult 1000 1000 1000
Matrix sizes C[1000][1000] = A[1000][1000] x B[1000][1000]
Perform matrix multiplication...

Done in 16.818359 seconds.
ubuntu-admin@Ubuntu-PC:~/parallele-sys1$ ./matmult 1000 1000 1000
Matrix sizes C[1000][1000] = A[1000][1000] x B[1000][1000]
Perform matrix multiplication...

Done in 9.255859 seconds.
