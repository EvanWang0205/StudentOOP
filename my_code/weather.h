#ifndef WEATHER_H
#define WEATHER_H
#include <vector>

#include <string>

struct GPS {
    double latitude;
    double longitude;
    GPS(double la, double lo) : latitude(la),
    longitude(lo) {}
};

std::ostream& operator<<(std::ostream& os, const GPS& gps);

class Date{
friend std::ostream& operator<<(std::ostream& os, const Date& date);
public:
    Date(int d, int m, int );
private:
    int day;
    int month;
    int year;
};

class Image;

class WReading{
friend std::ostream& operator<<(std::ostream& os, const WReading& wr);
public:
    WReading(Date dt, double temp, double hum, double ws, Image* images):
        date(dt), temperature(temp),humidity(hum),windspeed(ws), images(images){}
    
    double get_tempF();
    double get_tempC(){return temperature;};
    void display_image();

private:
    Image* images;
    Date date;
    double temperature;
    double humidity;
    double windspeed;
};

const int UNRATED = -1;
const int BAD = 0;
const int OK = 1;
const int GOOD = 2;

class Weather {
// << should output name, rating, and use the GPS << to output my_loc

    friend std::ostream& operator<<(std::ostream& os, const Weather& w);
public:
    Weather(std::string nm, GPS loc, int rating);
    std::string get_name() const;
    int get_rating() const;
    void set_rating(int new_rating);
    void add_reading(WReading wr);
    int get_heat_index();
    int get_wind_chill();
    void display_images();
private:
    std::vector<WReading> wreadings;
    std::string station_nm;
    GPS my_loc;
    int rating = UNRATED;
};

class Image {
public:
    Image(int w, int h, std::string flnm);
    // copy constructor:
    Image(const Image& img2);
    ~Image();
    Image& operator=(const Image& img2);
    int image_sz();
    
    /*
     * Setting `display() = 0` here makes this an abstract
     * class that can't be implemented.
     * */
    virtual void display();
    /*
     * If we don't want virtual method lookup, we
     * could just declare:
     * void display();
     * */
    
    int get_height() { return height; }
    int get_width() { return width; }
    
private:
    int width;
    int height;
    std::string filename;
    char* image_buf;
    void copy_fields(const Image& img2);
};

class Gif : public Image{
public:
    Gif(int w, int h, std::string flnm, int cl=0) : Image(w, h, flnm), compress_level(cl){};
    void display();
private:
    int compress_level;
};

class Png : public Image{
public:
    Png(int w, int h, std::string flnm) : Image(w,h,flnm){};
    void display();
    };

class Jpeg : public Image{
public:
    Jpeg(int w, int h, std::string flnm) : Image(w,h,flnm){};
    void display();
};

#endif

