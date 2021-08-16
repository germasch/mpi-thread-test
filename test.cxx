
#include <iostream>
#include <thread>

#include <mpi.h>

void thread_fn(int i)
{
  std::cout << "Thread " << i << std::endl;
  MPI_Barrier(MPI_COMM_WORLD);
}

int main(int argc, char** argv)
{
  MPI_Init(&argc, &argv);

  for (int i = 0; i < 100; i++) {
    std::thread thread(thread_fn, i);
    thread.join();
  }

  MPI_Finalize();
  return 0;
}