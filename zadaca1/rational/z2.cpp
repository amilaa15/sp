#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>
#include <ostream>
#include <fstream>

class Rational
{ 
    private:
      int numerator_;   // brojnik
      int denominator_; // nazivnik

    public:
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
    numerator_=numerator;
    denominator_=denominator;
  };


  Rational(const char* rational): Rational()
  {
    std::string str=rational;

    std::string numeratorString="";
    std::string denominatorString="";
    auto delimiter=false;


    
    for(auto i=0; i<str.size(); ++i)
    {
      if(str[i]=='/')
      {
        delimiter=true;
        continue;
        // auto numeratorString=rational.substr(0,i);
        // auto denominatorString=rational.substr(i, rational.size());
      }

      if(delimiter==false)
      {
        numeratorString+=str[i];
      }
      else
      {
        denominatorString+=str[i];
      }
    }
    this->numerator_=stoi(numeratorString);
    this->denominator_=stoi(denominatorString);

    std::cout << this->numerator_ << "/" << this->denominator_ << std::endl;
   
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

    this->numerator_=stoi(numeratorString);
    this->denominator_=stoi(denominatorString);

    std::cout << this->numerator_ << "/" << this->denominator_ << std::endl;
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
    // rational.numerator_=0;
    // rational.denominator_=1;
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
    // rational.numerator_=0;
    // rational.denominator_=1;
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

  // Get numerator
  const int numerator() const
  {
    return numerator_;
  };
  // Get denominator
  const int denominator() const
  {
    return denominator_;
  };

  std::ostream& operator<<(std::ostream& os, const Rational& rational)
  {
    os << rational.numerator() << "/" << rational.denominator(); 
    return os;
  };

std::istream& operator>>(std::ostream& in, const Rational& rational)
{
  std::string s;
  std::getline (in,s);
  rational=Rational{s};
  return in;
};

};




int main(int argc, char const *argv[])


{
    std::ifstream input{"input.txt"}; //otvori mi file

    if(!input)
    {
      std::cout << "file ne postoji" << std::endl;
      return 1;
    }

    std::string line;
    Rational rat{};

    while (input>>rat)
    {
      std::cout << rat << std::endl;
    }

    input.close();

    

    // Rational a{"3/5"};
    // Rational b{"2/3"};
    // Rational c;
    // c=a+b;
    
    return 0;
}