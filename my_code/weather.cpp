#include <iostream>
#include <string>
#include "weather.h"

using namespace std;

Date::Date(int d, int m, int y){
    if((d < 1) || (d > 31)) throw (d);
    if((m < 1) || (m > 12)) throw (m);
    if((y < 1800) || (y > 2200)) throw (y);
    day = d;
    month = m;
    year = y;
}

ostream& operator<<(ostream& os, const Date& date){
    os << date.month << "/" << date.day << "/" << date.year;
    return os;
}


ostream& operator<<(ostream& os, const WReading& wr){
    os << "Date: " << wr.date << "; Humidity: " << wr.humidity << "; Temperature: " << wr.temperature << "; Windspeed: " << wr.windspeed;
    return os;
}


/*
 * Output GPS
 **/

ostream& operator<<(ostream& os, const GPS& gps){
    os << "latitude : " << gps.latitude << "; longitude: " << gps.longitude;
    return os;
}

/*
 * A constructor for weather class.
 * */
Weather::Weather(string nm, GPS loc, int rating) :
station_nm(nm), my_loc(loc), rating(rating) {
}



string Weather::get_name() const {
    return station_nm;
}

int Weather::get_rating() const{
    return rating;
}

void Weather::set_rating(int new_rating){
    rating = new_rating;
}

void Weather::add_reading(WReading wr){
    wreadings.push_back(wr);
}

void WReading::display_image(){
    images->display();
}

void Weather::display_images(){
    for (WReading i : wreadings){
        i.display_image();
    }
}


ostream& operator<<(ostream& os, const Weather& w){
    os << w.get_name() << "rating : " << w.get_rating() << "; location: "
    << w.my_loc;
    for(WReading wr : w.wreadings){
        os << "   " << wr << endl;
    }
    return os;
}

const double F_to_C = 5 / 9;
const double C_to_F = 9 / 5;

double WReading::get_tempF(){
    return temperature * C_to_F + 32;
}




// Image (copy path)


Image::Image(int w, int h, std::string flnm)
: width(w), height(h)
{
    filename = flnm;
    image_buf = new char[image_sz()];
}

// copy constructor:
Image::Image(const Image& img2) {
    height = img2.height;
    width = img2.width;
    filename = img2.filename;
    image_buf = new char[image_sz()];
    for(int i = 0; i < image_sz(); i ++){
        image_buf[i] = img2.image_buf[i];
    }
}

// destructor
Image::~Image() {
    if(image_buf != nullptr){
        delete[] image_buf;
    }
}

// assignment operator:
Image& Image::operator=(const Image& img2) {
    if (&img2 != this) {
        if(image_buf != nullptr){
            delete[] image_buf;
        }
        height = img2.height;
        width = img2.width;
        filename = img2.filename;
        image_buf = new char[image_sz()];
        for(int i = 0; i < image_sz(); i ++){
            image_buf[i] = img2.image_buf[i];
        }
    }
    return *this;
}

int Image::image_sz() {
    return width * height;
}


void Image::copy_fields(const Image& img2) {
}


/*
 * Setting `display() = 0` here makes this an abstract
 * class that can't be implemented.
 * */
void Image::display() {
    cout << "Displaying image";
}

void Gif::display(){
    cout << "Displaying Gif ";
}

void Png::display(){
    cout << "Displaying png";
}


