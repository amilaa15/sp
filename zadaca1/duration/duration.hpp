#pragma once

class Duration {

    class Duration
{
    private:
    float hours_;
    float minutes_;
    float seconds_;
    
    public:
    Duration () ;
   
    Duration (int time_sec);


//radi za ispis, al nece raditi za poredjenje
//     Duration (int h, int m, int s)
//     {
//         hours_=h;
//         minutes_=m;
//         seconds_=s;
//     }

std::vector<int> vec;
Duration (std::initializer_list<int> hms) : vec(hms);


Duration& setHour(int h) ;

Duration& setMinute(int m) ;


Duration& setSecond(int s) ;


int getHour() {return hours_;} //vraca sat, mozemo samo citati
int getMinute() {return minutes_;} //vraca minute, mozemo samo citati
int getSecond() {return seconds_;} //vraca sekunde, mozemo samo citati

Duration& operator=(const Duration& d2);


bool operator==(const Duration& d2);


bool operator!=(const Duration& d2);


bool operator>(const Duration& d2);


bool operator<(const Duration& d2);


bool operator>=(const Duration& d2);


bool operator<=(const Duration& d2);

Duration& operator-=(const Duration& d2);


Duration operator+(const Duration& d2);


Duration operator-(const Duration& d2);


Duration operator*(const Duration& d2);

};
