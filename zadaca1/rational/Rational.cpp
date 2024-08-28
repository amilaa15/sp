#include "Rational.hpp"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>

// std::istream& operator>> (std::istream& in, Rational& r)
// {
//   std::getline(in, r, '/');
//   if (in.peek()=='\n'){
//     in.get();
//   }
//   return in;
// }

  Rational()
  {
    numerator_=0;
    denominator_=1; 
  };

  Rational(int numerator, int denominator)
  {
    if(denominator==0)
    {
        throw std::invalid_argument("nazivnik ne smije biti 0");
    }
  };

  Rational(const char* rational)
  {
    std::string str=rational;

    std::string numeratorString="";
    std::string denominatorString="";
    
    for(auto i=0; i<rational.size(); ++i)
    {
      if(rational[i]=='/')
      {
        auto numeratorString=rational.substr(0,i);
        auto denominatorString=rational.substr(i, rational.size());
      }
    }
    std::cout << numeratorString << "/" << denominatorString << std::endl;
  };
  

  Rational(const std::string& rational)
  {
    std::string numeratorString="";
    std::string denominatorString="";

    //auto delimiter=false;
    
    for(auto i=0; i<rational.size(); ++i)
    {
      if(rational[i]=='/')
      {
        auto numeratorString=rational.substr(0,i);
        auto denominatorString=rational.substr(i, rational.size());
      }
    }
    std::cout << numeratorString << "/" << denominatorString << std::endl;
  };


  Rational(const Rational& rational)
  {
    numerator_=rational.numerator_;
    denominator_=rational.denominator_;
  };

  Rational(Rational&& rational)
  {
    numerator_=rational.numerator_;
    denominator_=rational.denominator_; 
    rational.numerator_=0;
    rational.denominator_=1;
  };

  Rational& operator=(const Rational& rational)
  {
    numerator_=rational.numerator_;
    denominator_=rational.denominator_;
    return *this;
  };

  Rational& operator=(Rational&& rational)
  {
    numerator_=rational.numerator_;
    denominator_=rational.denominator_; 
    rational.numerator_=0;
    rational.denominator_=1;
    return *this;
  };

  Rational operator+(const Rational& rational) const
  {
    Rational temp;
    temp.denominator_=denominator_*rational.denominator_;
    temp.numerator_=rational.denominator_*numerator_+denominator_*rational.numerator_;
    std::cout << "sum=" << temp.numerator_ << "/" << temp.denominator_ << std::endl;
    return temp;
  };

  Rational operator+(int numerator) const
  {
    Rational temp;
    temp.denominator_=denominator_;
    temp.numerator_=numerator_+denominator_*numerator;
    std::cout << "sum=" << temp.numerator_ << "/" << temp.denominator_<< std::endl;
    return temp;
  };

  Rational operator-(const Rational& rational) const
  {
    Rational temp;
    temp.denominator_=denominator_*rational.denominator_;
    temp.numerator_=rational.denominator_*numerator_-denominator_*rational.numerator_;
    std::cout << "sub=" << temp.numerator_ << "/" << temp.denominator_ << std::endl;
    return temp;
  };

  Rational operator-(int numerator) const
  {
    Rational temp;
    temp.denominator_=denominator_;
    temp.numerator_=numerator_-denominator_*numerator;
    std::cout << "sum=" << temp.numerator_ << "/" << temp.denominator_ << std::endl;
    return temp;
  };

  Rational operator*(const Rational& rational) const
  {
   Rational temp;
   temp.numerator_=numerator_*rational.numerator_;
   temp.denominator_=denominator_*rational.denominator_;
   std::cout << "prod=" << temp.numerator_ << "/" << temp.denominator_ << std::endl; 
   return temp;
  };

  Rational operator*(int numerator) const
  {
    Rational temp;
    temp.numerator_=numerator_*numerator;
    temp.denominator_=denominator_;
    std::cout << "prod=" << temp.numerator_ << "/" << temp.denominator_ << std::endl;
    return temp;
  };

  Rational operator/(const Rational& rational) const
  {
    if(rational.numerator_==0 || rational.denominator_==0)
    {
      throw std::invalid_argument("Dijeljenje s nulom nije definisano");
    }
    else
    {
      Rational temp;
      temp.numerator_=numerator_*rational.denominator_;
      temp.denominator_=denominator_*rational.numerator_;
      std::cout << "div=" << temp.numerator_ << "/" << temp.denominator_ << std::endl;
      return temp;
    }
  };

  Rational operator/(int numerator) const
  {
    if(numerator==0)
    {
      throw std::invalid_argument("dijeljenje s nulom nije defrinisano");
    }
    else
    {
      Rational temp;
      temp.numerator_=numerator_;
      temp.denominator_=denominator_*numerator;
      std::cout << "div=" << temp.numerator_ << "/" << temp.denominator_ << std::endl;
      return temp;
    }
  };

  Rational operator^(int exp) const
  {
    Rational temp;
    temp.numerator_=numerator_^exp;
    temp.denominator_=denominator_^exp;
    std::cout << "exp=" << temp.numerator_ << "/" << temp.denominator_ << std::endl;
    return temp;
  };

};








  




