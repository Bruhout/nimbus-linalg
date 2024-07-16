#ifndef VEC_H
#define VEC_H

#include "mat.h"

namespace la {

class vec4;

class vec3 
{
public:
    float x , y , z;

    // constructor functions------------------------
    vec3();
    vec3(float X , float Y , float Z); 
    vec3(vec4 vec); // convert from vec4 to vec3

    // operator overloads------------------------
    vec3 operator-(vec3 vec); // sum
    vec3 operator+(vec3 vec); // diff
    vec3 operator*(float factor); // scale
    vec3 operator/(float factor); // scale

    void operator-=(vec3 vec); // sum in place
    void operator+=(vec3 vec); // diff in place
    void operator*=(float factor); // scale in place
    void operator/=(float factor); // scale in place

    float operator[](int index); // index

    vec3 operator*(mat4 mat); // vector matrix multiplication
    void operator*=(mat4 mat); // vector matrix multiplication in place
    vec3 operator*(vec3 vec); // cross product

    // linear algebra functions------------------------
    float MagnitudeSq();
    float Magnitude();
    float DistanceFrom(vec3 refPoint);
    vec3 CrossProduct(vec3 vec);
    float DotProduct(vec3 vec);
    vec3 Normalize();
    vec3 ProjectVec(vec3 ontoVec);
    vec3 MultiplyVecMat(mat4 mat);

    // utility functions------------------------
    void PrintVec();

    // color vector functions------------------------
    // this library allows you to use the vector objects to store RBG / RGBA color values with the supporting functions
    // NOTE: RBGA values must be given as floats between 0 and 1
    vec3 ReflectColor(vec3 mat_color);
    vec3 FloatToUint();
    vec3 UintToFloat();

    // implemention pending------------------------
    vec3 ViewportTransform();
};

class vec4 
{
public:
    float x , y , z , w;

    // constuctor functions------------------------
    vec4();
    vec4(float X , float Y , float Z , float W);
    vec4(vec3 vec); // convert from vec3 to vec4
    vec4(vec3 vec , float w); // convert from vec3 to vec4

    // operator overloads ------------------------
    vec4 operator-(vec4 vec); // sum
    vec4 operator+(vec4 vec); // diff
    vec4 operator*(float factor); // scale
    vec4 operator/(float factor); // scale

    void operator-=(vec4 vec); // sum in place
    void operator+=(vec4 vec); // diff in place
    void operator*=(float factor); // scale in place
    void operator/=(float factor); // scale in place
    
    float operator[](int index); // index

    vec4 operator*(mat4 mat); // vector matrix multiplication
    void operator*=(mat4 mat); // vector matrix multiplication in place
    vec4 operator*(vec4 vec); // cross product

    // linear algebra functions------------------------
    float MagnitudeSq();
    float Magnitude();
    float DistanceFrom(vec4 refPoint);
    vec4 CrossProduct(vec4 vec);
    float DotProduct(vec4 vec);
    vec4 Normalize();
    vec4 ProjectVec(vec4 ontoVec);
    vec4 MultiplyVecMat(mat4 mat);

    // utility functions------------------------
    void PrintVec();

    // color vector functions
    // this library allows you to use the vector objects to store RBG / RGBA color values with the supporting functions
    // NOTE: RBGA values must be given as floats between 0 and 1
    vec4 ReflectColor(vec4 mat_color);
    vec4 FloatToUint();
    vec4 UintToFloat();

    // implemention pending------------------------
    vec4 ViewportTransform();
};

}


#endif // VEC_H