openblas:
	gcc -static -I/home/aviral/bin/OpenBLAS/include -o test_cblas_dgemm test_cblas_dgemm.cpp  -L/home/aviral/bin/OpenBLAS/lib -lopenblas -lpthread -lstdc++ #-lgfortran
