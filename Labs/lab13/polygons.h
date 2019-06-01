//
//  polygons.h
//  lab13
//
//  Created by Sriyuth Sagi on 4/25/18.
//  Copyright © 2018 Sriyuth Sagi. All rights reserved.
//

#ifndef _polygons_h_
#define _polygons_h_

#include "utilities.h"
#include <vector>
#include <algorithm>

class Polygon {
public:
    
    
    Polygon(const std::string &namei, const std::vector<Point> &pointsi) {
        
        name = namei;
        points = pointsi;
        
        if (points.size() < 2) throw 1;
        
    }
    
    
    std::string getName() {return name;}
    bool HasAllEqualSides() {
        
        std::vector<int> temp;
        Vector p1(points[points.size() - 1], points[0]);
        temp.push_back(p1.Length());
        
        for(int i = 0; i < points.size() - 1; i++) {
            Vector p(points[i], points[i + 1]);
            temp.push_back(round(p.Length()));
        }
        
        if ( std::adjacent_find( temp.begin(), temp.end(), std::not_equal_to<int>() ) == temp.end() ) {
            return true;
        }
        
        return false;
    }
    
    bool HasAllEqualAngles() {
        
        std::vector<int> temp;
        temp.push_back(round(Angle(points[points.size() - 1], points[0], points[1])));
        
        for(int i = 1; i < points.size(); i++) {
            temp.push_back(round(Angle(points[i - 1], points[i], points[i + 1])));
        }
        
        if ( std::adjacent_find( temp.begin(), temp.end(), std::not_equal_to<int>() ) == temp.end() ) {
            return true;
        }
        
        
        return false;
        
        
    }
    
    bool HasARightAngle() {
        
        if(RightAngle(Angle(points[points.size() - 1], points[0], points[1]))) return true;
        
        for(int i = 1; i < points.size(); i++) {
            if(RightAngle(Angle(points[i - 1], points[i], points[i + 1]))) return true;
        }
        
        return false;
        
    }
    
    
    
    
    virtual ~Polygon() {}

    
protected:
    
    std::string name;
    std::vector<Point> points;
    
    
};

class Triangle : public Polygon {
public:
    Triangle(const std::string &name, const std::vector<Point> &points) : Polygon(name, points) {
        if (points.size() != 3) throw 1;
    }
    
};

class IsoscelesTriangle : virtual public Triangle {
public:
    IsoscelesTriangle(const std::string &name, const std::vector<Point> &points) : Triangle(name, points) {
        Vector p1(points[0], points[1]);
        Vector p2(points[1], points[2]);
        Vector p3(points[2], points[0]);
        
        bool iso1 = EqualSides(p1.Length(), p2.Length());
        bool iso2 = EqualSides(p1.Length(), p3.Length());
        bool iso3 = EqualSides(p2.Length(), p3.Length());
        
        if(!iso1 && !iso2 && !iso3) throw 1;
     }
    
};

class RightTriangle : virtual public Triangle {
public:
    RightTriangle(const std::string &name, const std::vector<Point> &points) : Triangle(name, points) {
        
        double ang1 = Angle(points[0], points[1], points[2]);
        double ang2 = Angle(points[1], points[2], points[0]);
        double ang3 = Angle(points[2], points[0], points[1]);
        
        if (!RightAngle(ang1) && !RightAngle(ang2) && !RightAngle(ang3)) throw 1;
    }
    
};

class IsoscelesRightTriangle : public RightTriangle, public IsoscelesTriangle {
public:
    IsoscelesRightTriangle(const std::string &name, const std::vector<Point> &points) : Triangle(name, points), IsoscelesTriangle(name, points), RightTriangle(name, points) {
        Vector p1(points[0], points[1]);
        Vector p2(points[1], points[2]);
        Vector p3(points[2], points[0]);
        
        bool iso1 = EqualSides(p1.Length(), p2.Length());
        bool iso2 = EqualSides(p1.Length(), p3.Length());
        bool iso3 = EqualSides(p2.Length(), p3.Length());
        bool iso = true;
        if(!iso1 && !iso2 && !iso3) iso = false;
        
        double ang1 = Angle(points[0], points[1], points[2]);
        double ang2 = Angle(points[1], points[2], points[0]);
        double ang3 = Angle(points[2], points[0], points[1]);
        bool ang = true;
        if (!RightAngle(ang1) && !RightAngle(ang2) && !RightAngle(ang3)) ang = false;
        
        if (!iso && !ang) throw 1;
    }
    
};

class EquilateralTriangle : public IsoscelesTriangle {
public:
    EquilateralTriangle(const std::string &name, const std::vector<Point> &points) : Triangle(name, points), IsoscelesTriangle(name, points) {
        Vector p1(points[0], points[1]);
        Vector p2(points[1], points[2]);
        Vector p3(points[2], points[0]);
        
        bool iso1 = EqualSides(p1.Length(), p2.Length());
        bool iso2 = EqualSides(p1.Length(), p3.Length());
        bool iso3 = EqualSides(p2.Length(), p3.Length());
        
        if(!iso1 || !iso2 || !iso3) throw 1;
        
    }
    
};


class Quadrilateral : public Polygon {
public:
    Quadrilateral(const std::string &name, const std::vector<Point> &points) : Polygon(name, points) {
        if (points.size() != 4) throw 1;
    }
    
};

class Rectangle : public Quadrilateral {
public:
    Rectangle(const std::string &name, const std::vector<Point> &points) : Quadrilateral(name, points) {
        Vector p1(points[0], points[1]);
        Vector p2(points[1], points[2]);
        Vector p3(points[2], points[3]);
        Vector p4(points[3], points[0]);
        
        bool rect1 = EqualSides(p1.Length(), p3.Length());
        bool rect2 = EqualSides(p2.Length(), p4.Length());
        
        if(!rect1 || !rect2) throw 1;
    }
    
};

class Square : public Rectangle {
public:
    Square(const std::string &name, const std::vector<Point> &points) : Rectangle(name, points) {
        Vector p1(points[0], points[1]);
        Vector p2(points[1], points[2]);
        
        bool rect = EqualSides(p1.Length(), p2.Length());
        
        if(!rect) throw 1;
    }
    
};




#endif /* polygons_h */
