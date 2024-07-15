#include "../include/vec.h"

#include <iostream>
#include <math.h>

using namespace la;

// ===========================================================================================
// VEC3 IMPLEMENTATION
// constructor functions------------------------
vec3::vec3()
    :x(1.0f), y(1.0f), z(1.0f)
{}
vec3::vec3(float X , float Y , float Z)
    : x(X), y(Y), z(Z)
{}
vec3::vec3(vec4 vec)
    : x(vec.x) , y(vec.y) , z(vec.z)
{}



// operator overloads------------------------
vec3 vec3::operator-(vec3 vec)
{
    return vec3(
        x - vec.x,
        y - vec.y,
        z - vec.z
    );
}
vec3 vec3::operator+(vec3 vec)
{
    return vec3(
        x + vec.x,
        y + vec.y,
        z + vec.z
    );
}
vec3 vec3::operator*(float factor)
{
    return vec3(
        x * factor,
        y * factor,
        z * factor
    );
}
vec3 vec3::operator/(float factor)
{
    return vec3(
        x / factor,
        y / factor,
        z / factor
    );
}


void vec3::operator-=(vec3 vec)
{
    x += vec.x;
    y += vec.y;
    z += vec.z;
}
void vec3::operator+=(vec3 vec)
{
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;
}
void vec3::operator*=(float factor)
{
    x *= factor;
    y *= factor;
    z *= factor;
}
void vec3::operator/=(float factor)
{
    x /= factor;
    y /= factor;
    z /= factor;
}


float vec3::operator[](int index)
{
    switch(index){
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z; 
    }
    return -1.0f;
}


vec3 vec3::operator*(mat4 mat)
{
    vec3 new_vec = vec3();

    new_vec.x = (x * mat.array[0]) + (y * mat.array[4]) + (z * mat.array[8]);
    new_vec.y = (x * mat.array[1]) + (y * mat.array[5]) + (z * mat.array[9]);
    new_vec.z = (x * mat.array[2]) + (y * mat.array[6]) + (z * mat.array[10]);

    return new_vec;
}
vec3 vec3::operator*(vec3 vec)
{
    return vec3(
        y*vec.z + z*vec.y ,
        z*vec.x + x*vec.z , 
        x*vec.y + y*vec.x
    );
}



// linear algebra functions------------------------
float vec3::MagnitudeSq() { return (x*x + y*y + z*z); }
float vec3::Magnitude() { return pow(x*x + y*y + z*z , 0.5); }
float vec3::DistanceFrom(vec3 refPoint)
{
    return pow(
        pow(refPoint.x - x , 2.0) + 
        pow(refPoint.y - y , 2.0) + 
        pow(refPoint.z - z , 2.0) ,
        0.5
    );
}
vec3 vec3::CrossProduct(vec3 vec)
{
    return vec3(
        y*vec.z + z*vec.y ,
        z*vec.x + x*vec.z , 
        x*vec.y + y*vec.x
    );
}
float vec3::DotProduct(vec3 vec) { return (vec.x*x + vec.y*y + vec.z*z); }
vec3 vec3::Normalize() { return *this / Magnitude(); }
vec3 vec3::ProjectVec(vec3 ontoVec)
{
    vec3 ontoUnitVec = ontoVec.Normalize();
    float mag = ontoVec.DotProduct(*this) / ontoVec.Magnitude();
    return ontoUnitVec * mag;
}



// utility functions------------------------
void vec3::PrintVec() { std::cout << '{' << x << ',' << y << ',' << z << '}' << '\n'; }

// color functions
vec3 vec3::ReflectColor(vec3 mat_color)
{
    return vec3(
        x*mat_color.x ,
        y*mat_color.y ,
        z*mat_color.z
    );
}
vec3 vec3::FloatToUint()
{
    return vec3(
        round(x * 255.0f),
        round(y * 255.0f),
        round(z * 255.0f)
    );
}
vec3 vec3::UintToFloat()
{
    return vec3(
        x / 255.0f,
        y / 255.0f,
        z / 255.0f
    );
}
// ===========================================================================================















// ===========================================================================================
// VEC4 IMPLEMENTATION
// constructor functions------------------------
vec4::vec4()
    : x(1.0f) , y(1.0f) , z(1.0f) , w(1.0f)
{}

vec4::vec4(float X , float Y , float Z , float W)
    : x(X) , y(Y) , z(Z) , w(W)
{}

vec4::vec4(vec3 vec)
    : x(vec.x) , y(vec.y) , z(vec.z) , w(1.0f)
{}

vec4::vec4(vec3 vec , float W)
    : x(vec.x) , y(vec.y) , z(vec.z) , w(W)
{}



// operator overloads------------------------
vec4 vec4::operator-(vec4 vec)
{
    return vec3(
        x - vec.x,
        y - vec.y,
        z - vec.z
    );
}
vec4 vec4::operator+(vec4 vec)
{
    return vec3(
        x + vec.x,
        y + vec.y,
        z + vec.z
    );
}
vec4 vec4::operator*(float factor)
{
    return vec3(
        x * factor,
        y * factor,
        z * factor
    );
}
vec4 vec4::operator/(float factor)
{
    return vec3(
        x / factor,
        y / factor,
        z / factor
    );
}


void vec4::operator-=(vec4 vec)
{
    x += vec.x;
    y += vec.y;
    z += vec.z;
}
void vec4::operator+=(vec4 vec)
{
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;
}
void vec4::operator*=(float factor)
{
    x *= factor;
    y *= factor;
    z *= factor;
}
void vec4::operator/=(float factor)
{
    x /= factor;
    y /= factor;
    z /= factor;
}


float vec4::operator[](int index)
{
    switch(index){
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z; 
        case 3:
            return w;
    }
    return -1.0f;
}


vec4 vec4::operator*(mat4 mat)
{
    vec4 new_vec = vec3();

    new_vec.x = (x * mat.array[0]) + (y * mat.array[4]) + (z * mat.array[8]) + (w * mat.array[12]);
    new_vec.y = (x * mat.array[1]) + (y * mat.array[5]) + (z * mat.array[9]) + (w * mat.array[13]);
    new_vec.z = (x * mat.array[2]) + (y * mat.array[6]) + (z * mat.array[10]) + (w * mat.array[14]);
    new_vec.w = (x * mat.array[3]) + (y * mat.array[7]) + (z * mat.array[11]) + (w * mat.array[15]);

    return new_vec;
}
vec4 vec4::operator*(vec4 vec)
{
    return vec4(
        y*vec.z + z*vec.y ,
        z*vec.x + x*vec.z , 
        x*vec.y + y*vec.x ,
        1.0f
    );
}


// linear algebra functions------------------------
float vec4::MagnitudeSq() { return (x*x + y*y + z*z); }
float vec4::Magnitude() { return pow(x*x + y*y + z*z , 0.5); }
float vec4::DistanceFrom(vec4 refPoint)
{
    return pow(
        refPoint.x - x + 
        refPoint.y - y + 
        refPoint.z - z ,
        0.5
    );
}
vec4 vec4::CrossProduct(vec4 vec)
{
    return vec4(
        y*vec.z + z*vec.y ,
        z*vec.x + x*vec.z ,
        x*vec.y + y*vec.x ,
        1.0f
    );
}
float vec4::DotProduct(vec4 vec) { return (x*vec.x + y*vec.y + z*vec.z); }
vec4 vec4::Normalize() { return *this / Magnitude(); }
vec4 vec4::ProjectVec(vec4 ontoVec)
{
    vec4 ontoUnitVec = ontoVec / ontoVec.Magnitude();
    float mag = ontoVec.DotProduct(*this) / ontoVec.Magnitude();
    return ontoUnitVec * mag;
}

// utility functions------------------------
void vec4::PrintVec() { std::cout << '{' << x << ',' << y << ',' << z << '}' << '\n'; } 

// color functions------------------------
vec4 vec4::ReflectColor(vec4 mat_color)
{
    return vec4(
        x*mat_color.x ,
        y*mat_color.y ,
        z*mat_color.z ,
        w*mat_color.w
    );
}
vec4 vec4::FloatToUint()
{
    return vec4(
        round(x * 255.0f),
        round(y * 255.0f),
        round(z * 255.0f),
        round(w * 255.0f)
    );
}
vec4 vec4::UintToFloat()
{
    return vec4(
        x / 255.0f,
        y / 255.0f,
        z / 255.0f,
        w / 255.0f
    );
}