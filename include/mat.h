#ifndef MAT_H
#define MAT_H

namespace la {

class vec3; // just to avoid build errors
class vec4; // ignore these two forward declarations

class mat4
{
public:
    float array[16];

    // constructor functions------------------------
    mat4();
    mat4(float num);
    mat4(float* array_);
    mat4(vec3 v1 , vec3 v2 , vec3 v3); // create transformation matrix based on new basis vectors
    mat4(vec4 v1 , vec4 v2 , vec4 v3);

    // operator overloads------------------------
    vec4 operator[](int index); // get the index-th row of the matrix, as a vector
    mat4 operator*(mat4 mat); // matrix matrix multiplication
    void operator*=(mat4 mat); // matrix matrix multiplication in place

    // linear algebra functions------------------------
    mat4 TranslateMat(vec3 vec);
    mat4 LookAt(vec3 camera_pos , vec3 camera_aim , vec3 world_up);
    mat4 ProjectionMat(float fov_rad , float z_near , float z_far);

    // utility functions------------------------
    void PrintMat();

    // implementation pending------------------------
    mat4 RotateMat(float theta , vec3 axix_vec);
    float* GetArray();
};

}


#endif // MAT_H