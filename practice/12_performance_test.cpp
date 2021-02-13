#include <iostream>
#include <chrono>

using namespace std;

/*
  This test shows the capability of the CPU (core) n single threaded.
  If the CPU has good number of Instruction decoder (4 or 8) then the CPU will be able to execute more instructions per cycle.
  Basically instruction pipelining is much better if this program executes faster.

  For M1 it is 8 channel wide instructions decodeer. ans in 1 Core there can only be 1 thread. Unlike x86!
  So, Hyperthreading is not possible in M1!!.
*/

class DummyClass_t
{
private:
  uint32_t i = 0;
public:
  DummyClass_t(uint32_t i_) : i(i_)
  {}
  
  ~DummyClass_t() 
  {}
};

int main()
{
  auto start = std::chrono::system_clock::now();
  {
    for(uint32_t i = 0; i < 10000000; ++i)
    {
      DummyClass_t* dc = new DummyClass_t(i);
      delete dc;
    }
  }
  auto end = std::chrono::system_clock::now();

  std::chrono::duration<double> elapsed_seconds = end-start;
  std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

  return 0;
}