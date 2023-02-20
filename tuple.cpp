#include <iostream>
#include<string>

class Pair
{ 
 protected:
  int first;
  int second;

 public:
  Pair(int t, int u) : first(t), second(u) {}

  bool operator==(const Pair &rhs) const
  {
    return first == rhs.first && second == rhs.second;
  }
 //Adding function to copy object 3.1
 Pair operator=(const Pair&rhs)
  {
    first = rhs.first;
    second = rhs.second;
    return *this;
  }

  friend std::ostream &operator<<(std::ostream &os, const Pair &rhs)
  {
    os << "(" << rhs.first << ", " << rhs.second << ")";
    return os;
  }
};


//deriving class from another and overloading the operator 3.2
class Triple : public Pair
{
protected:
  int third;
public:
  Triple(int t, int u, int v) : Pair(t, u), third(v) {}

  Pair operator=(const Triple &rhs)
  {
    first = rhs.first;
    second = rhs.second;
    third = rhs.third;
    return *this;
  }

  friend std::ostream &operator<<(std::ostream &os, const Triple &rhs)
  {
    os << "(" << rhs.first << ", " << rhs.second << ", "<< rhs.third <<")";
    return os;
  }
};

int main()
{
  Pair p(1, 3);
  Pair p1(1,2);
  p1 = p;
  std::cout << p << std::endl;
  std::cout << p1 << std::endl;
  Triple t1(1, 2, 3);
  Triple t2(1, 3, 3);
  t2=t1;
  std::cout << t2 << std::endl;
}
