#include<string>
namespace std;

class Strtok_t
{
  private:
    int32_t pos;
    vector<string> input;

    string original;
    int pos_origianl;

  public:
    Strtok_t()
      : pos(0),
        pos_origianl(0)
    {}
    
    Strtok_t(char* data_, const char* delim_)
      : pos(0),
        pos_origianl(0)
    {

      original = data_;
      
      string in = "";
      int len = strlen(delim_);
      while(data_ != nullptr)
      {
        if(*data_ != *delim_)
        {
          in += data_;
          data_++;
        }
        else
        {
          input.push_back(in);
          data_ += len;
          
          in = "";
        }
      }      
    }
    
    char* getNext()
    {
      if(pos == input.size())
      {
        return nullptr;
      }
      
      return input[pos++].c_str();
    }
    
    char* getNext(char* data_, const char* delim_)
    {
      if((data_ == nullptr && pos_origianl == 0) || (data_ != nullptr) && pos_original > 0)
      {
        return nullptr;
      }
      else if(delim_ == nullptr)
      {
        return nullptr;
      }
      
      if(data_ != nullptr)
      {
        original = data_;
      }
      
      int2_t st = pos_original;
      pos_original = original.find_first_of(delim_, pos_original+1); 
      if((pos_original == std::string::npos) || (pos_original > original.size()))
      {
        return nullptr;
      }
      
      string req = original.substr(st, pos_original);
      
      pos_original += strlen(delim_);
      return req.c_str();
    }
};

int main()
{
  /*Strtok_t data("MyName - is - Basavaraju", "-");
  
  char* str = data.getNext();
  while(str != nullptr)
  {
    std::cout << str << std::endl;
    str = data.getNext();
  }*/
  
  Strtok_t data;
  char* delim = "-/*";
  char* str = data.getNext("MyName -/* is -/* Basavaraju", delim);
  
  while(str != nullptr)
  {
    std::cout << str << std::endl;
    str = data.getNext(nullptr, delim);
  }
  
  return 0;
}

//
  5
  1 - 100KM
  
  4 -> 10 km  e - 100KM, 4w ->90KM
  
    -> 3w+1 => 90 + 100KM, e - 90,
    
    20KM
    
    -> 2w+2 => 80KM, 2 =>90KM, e - 80KM
    
    30KM
    -> 1w+3 => 70KM, 3=>80KM, e - 70KM
    
    40KM
    -> 4w => 70KM, e - 60KM
    
  
