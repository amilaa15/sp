#include "duration.hpp"

   Duration ()
    {
        hours_=0;
        minutes_=0;
        seconds_=0;
    };

     Duration (int time_sec)
    {
        int totalMinutes=time_sec/60;
        seconds_=time_sec%60;
        hours_=totalMinutes/60;
        minutes_=totalMinutes%60;

    };

//radi za ispis, al nece raditi za poredjenje
//     Duration (int h, int m, int s)
//     {
//         hours_=h;
//         minutes_=m;
//         seconds_=s;
//     }


    std::vector<int> vec;
    Duration (std::initializer_list<int> hms) : vec(hms)
    {
        hours_=vec[0];
        minutes_=vec[1];
        seconds_=vec[2];

        if(hours_>24 || minutes_>60 || seconds_>60)
        {
            throw std::out_of_range ("Van opsega");
        }

    };

    Duration& setHour(int h) 
    {
        hours_=h;
        return *this;
    }

    Duration& setMinute(int m) 
    {
        minutes_=m;
        if(m>60)
        {
            throw std::out_of_range ("Van opsega");
        }
    
        return *this;

    } 

    Duration& setSecond(int s) 
    {
        seconds_=s;
         if(s>60)
        {
            throw std::out_of_range ("Van opsega");
        }
    
        return *this;

    }

    int getHour() {return hours_;} //vraca sat, mozemo samo citati
    int getMinute() {return minutes_;} //vraca minute, mozemo samo citati
    int getSecond() {return seconds_;} //vraca sekunde, mozemo samo citati

    Duration& operator=(const Duration& d2)
    {
        hours_=d2.hours_;
        minutes_=d2.minutes_;
        seconds_=d2.seconds_;
        return *this;
    }

    bool operator==(const Duration& d2)
    {
        if(hours_==d2.hours_ && minutes_==d2.minutes_ && seconds_==d2.seconds_)
        {
            std::cout << "true" << std::endl;
            return true;    
        } 
        else
        {
            std::cout << "false" << std::endl;
            return false;
        }

};

    bool operator!=(const Duration& d2)
    {
        if(hours_==d2.hours_ && minutes_==d2.minutes_ && seconds_==d2.seconds_){
            std::cout << "false" << std::endl;
            return false;    
    } 
    else
    {
        std::cout << "true" << std::endl;
        return true;
    }

};


    bool operator>(const Duration& d2)
    {
        if(hours_>d2.hours_ && minutes_>d2.minutes_ && seconds_>d2.seconds_){
            std::cout << "true" << std::endl;
            return false;    
    } 
    else
    {
        std::cout << "false" << std::endl;
        return true;
    }

};

    bool operator<(const Duration& d2)
    {
        if(hours_>d2.hours_ && minutes_>d2.minutes_ && seconds_>d2.seconds_){
            std::cout << "false" << std::endl;
            return false;    
    } 
    else
    {
        std::cout << "true" << std::endl;
        return true;
    }

};


    bool operator>=(const Duration& d2)
    {
        if(hours_>=d2.hours_ && minutes_>=d2.minutes_ && seconds_>=d2.seconds_){
            std::cout << "true" << std::endl;
            return false;    
    } 
    else
    {
        std::cout << "false" << std::endl;
        return true;
    }

};

    bool operator<=(const Duration& d2)
    {
        if(hours_>=d2.hours_ && minutes_>=d2.minutes_ && seconds_>=d2.seconds_){
            std::cout << "true" << std::endl;
            return false;    
    } 
    else
    {
        std::cout << "false" << std::endl;
        return true;
    }

};

Duration& operator-=(const Duration& d2)
{
    hours_-=d2.hours_;
    minutes_-=d2.minutes_;
    seconds_-=d2.seconds_;
    std::cout << "d3=" << hours_ << ":" << minutes_ << ":" << seconds_ << ":" << std::endl;
}

Duration& operator+=(const Duration& d2)
{
    hours_+=d2.hours_;
    minutes_+=d2.minutes_;
    seconds_+=d2.seconds_;
    std::cout << "d3=" << hours_ << ":" << minutes_ << ":" << seconds_ << ":" << std::endl;
}

Duration& operator*=(const Duration& d2)
{
    hours_*=d2.hours_;
    minutes_*=d2.minutes_;
    seconds_*=d2.seconds_;
    std::cout << "d3=" << hours_ << ":" << minutes_ << ":" << seconds_ << ":" << std::endl;
}

Duration& operator/=(const Duration& d2)
{if(d2.hours_==0||d2.minutes_==0||d2.seconds_==0)
{
    std::cout<<"usuported operation "<<std::endl;
    return *this;
}
    hours_/=d2.hours_;
    minutes_/=d2.minutes_;
    seconds_/=d2.seconds_;
    std::cout << "d3=" << hours_ << ":" << minutes_ << ":" << seconds_ << ":" << std::endl;
    return *this;
}


Duration operator+(const Duration& d2)
{
    Duration temp;
    temp.hours_=hours_+d2.hours_;
    temp.minutes_=minutes_+d2.minutes_;
    temp.seconds_=seconds_+d2.seconds_;
    std::cout << "d3=" << temp.hours_ << ":" << temp.minutes_ << ":" << temp.seconds_ << ":" << std::endl;
    return temp;
}

Duration operator-(const Duration& d2)
{
    Duration temp;
    temp.hours_=hours_-d2.hours_;
    temp.minutes_=minutes_-d2.minutes_;
    temp.seconds_=seconds_-d2.seconds_;
    std::cout << "d3=" << temp.hours_ << ":" << temp.minutes_ << ":" << temp.seconds_ << ":" << std::endl;
    return temp;
}

Duration operator*(const Duration& d2)
{
    Duration temp;
    temp.hours_=hours_*d2.hours_;
    temp.minutes_=minutes_*d2.minutes_;
    temp.seconds_=seconds_*d2.seconds_;
    std::cout << "d3=" << temp.hours_ << ":" << temp.minutes_ << ":" << temp.seconds_ << ":" << std::endl;
    return temp;
}
