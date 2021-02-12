#include <iostream>
#include <chrono>

using namespace std;

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