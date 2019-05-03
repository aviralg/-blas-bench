#include <cblas.h>
#include <ctime>
#include <chrono>
#include <iostream>

void test(int size) {

    auto start = std::chrono::steady_clock::now();

    long int i = 0;
    double * A = new double[size * size];
    double * B = new double[size * size];
    double * C = new double[size * size];

    for(long int i = 0; i < size * size; ++i) {
        A[i] = rand();
        B[i] = rand();
        C[i] = rand();
    }

    cblas_dgemm(CblasColMajor, CblasNoTrans, CblasNoTrans, size, size, size, 2, A, size, B, size, 2, C, size);

    auto end = std::chrono::steady_clock::now();

    long int duration = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();

    long int operations = 2 * size * size * size;

    double flops = static_cast<double>(operations) / duration;

    std::cout << size << "," << duration << "," << flops << std::endl;

    delete A;
    delete B;
    delete C;
}

int main() {

  /* initialize random number generator */
  srand(time(NULL));
  std::cout << "Size" << "," << "Duration" << "," << "Flops" << std::endl;
  test(10);
  test(100);
  test(1000);
  test(10000);
  /* Process is killed on larger powers of 10. */

  return 0;
}
