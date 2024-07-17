#include "../include/vec.h"
#include "../include/mat.h"

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace la;

//===============================================================================================
// constructor functions------------------------
mat4::mat4()
{
    for (int i=0 ; i<4 ; i++) {
        for (int j=0 ; j<4 ; j++) {
            if (i==j) {
                array[i*4 + j] = 1.0f;
            } else {
                array[i*4 + j] = 0.0f;
            }
        }
    }
}
mat4::mat4(float num)
{
    for (int i=0 ; i<16 ; i++) {
        array[i] = num;
    }
}
mat4::mat4(float* array_)
{
    for (int i=0 ; i<16 ; i++) {
        array[i] = array_[i];
    }
}
mat4::mat4(vec3 v1 , vec3 v2 , vec3 v3)
{
    for (int i=0 ; i<16 ; i++) {
        array[i] =- 0.0f;
    }
    array[15] = 1.0f;

    array[0] = v1.x;
    array[1] = v1.y;
    array[2] = v1.z;

    array[4] = v2.x;
    array[5] = v2.y;
    array[6] = v2.z;
    
    array[8] = v3.x;
    array[9] = v3.y;
    array[10] = v3.z;
}
mat4::mat4(vec4 v1 , vec4 v2 , vec4 v3)
{
    for (int i=0 ; i<16 ; i++) {
        array[i] =- 0.0f;
    }
    array[15] = 1.0f;

    array[0] = v1.x;
    array[1] = v1.y;
    array[2] = v1.z;

    array[4] = v2.x;
    array[5] = v2.y;
    array[6] = v2.z;
    
    array[8] = v3.x;
    array[9] = v3.y;
    array[10] = v3.z;
}



// operator overloads------------------------
vec4 mat4::operator[](int index)
{
    return vec4(
        array[index*4 + 0], 
        array[index*4 + 1], 
        array[index*4 + 2], 
        array[index*4 + 3]
    );
}
mat4 mat4::operator*(mat4 mat)
{
    mat4 new_mat;
    for (int i=0 ; i<4 ; i++)
    {
        for (int j=0 ; j<4 ; j++)
        {
            float sum = 0.0f;
            for (int k=0 ; k<4 ; k++)
            {
                sum += array[i*4 + k] * mat.array[k*4 + j];
            }
            new_mat.array[i*4 + j] = sum;
        }
    }

    return new_mat;
}
void mat4::operator*=(mat4 mat)
{
    float new_array[16];
    for (int i=0 ; i<4 ; i++)
    {
        for (int j=0 ; j<4 ; j++)
        {
            float sum = 0.0f;
            for (int k=0 ; k<4 ; k++)
            {
                sum += array[i*4 + k] * mat.array[k*4 + j];
            }
            new_array[i*4 + j] = sum;
        }
    }

    for (int i=0 ; i<6 ; i++) {
        array[i] = new_array[i];
    }
}



// linear algebra functions------------------------
mat4 mat4::MultiplyMatrices(mat4 mat)
{
    mat4 new_mat;
    for (int i=0 ; i<4 ; i++)
    {
        for (int j=0 ; j<4 ; j++)
        {
            float sum = 0.0f;
            for (int k=0 ; k<4 ; k++)
            {
                sum += array[i*4 + k] * mat.array[k*4 + j];
            }
            new_mat.array[i*4 + j] = sum;
        }
    }

    return new_mat;
}
mat4 mat4::TranslateMat(vec3 vec)
{
    mat4 new_mat = *this;
    new_mat.array[12] += vec.x;
    new_mat.array[13] += vec.y;
    new_mat.array[14] += vec.z;

    return new_mat;
}
mat4 mat4::LookAt(vec3 camera_pos,  vec3 camera_aim , vec3 world_up)
{
    vec3 forward = (camera_pos - camera_aim).Normalize();
    vec3 right = (world_up * forward).Normalize();
    vec3 up = (forward * right).Normalize();

    // new system where basis vectors are according to the camera
    return mat4(right , up , forward).TranslateMat(camera_pos * -1);
}
mat4 mat4::ProjectionMat(float fov_rad , float z_near , float z_far)
{
    float p_mat[] = {
        1.0f/tan(fov_rad/2.0f)  ,       0.0f ,                     0.0f ,                0.0f ,
        0.0f ,                   1.0f/tan(fov_rad/2.0f) ,          0.0f ,                0.0f ,
        0.0f ,                          0.0f ,              -1.0f/(z_far - z_near) ,    -1.0f ,
        0.0f ,                          0.0f ,             -z_near/(z_far - z_near) ,    0.0f
    };

    return mat4(p_mat);
}
mat4 mat4::Transpose()
{
    mat4 new_mat = mat4();
    for (int i=0 ; i<4 ; i++) {
        for (int j=0 ; j<4 ; j++) {
            new_mat.array[i*4 + j] = array[j*4 + i];
        }
    }

    return new_mat;
}



// utility functions------------------------
void mat4::PrintMat()
{
    std::cout << "____" << "             " << "____\n";
    std::cout << "|" << std::fixed << std::setprecision(2) << array[0]  << ' ' << array[1] << ' ' << array[2] << ' ' << array[3] << "|\n";
    std::cout << "|" << std::fixed << std::setprecision(2) << array[4]  << ' ' << array[5] << ' ' << array[6] << ' ' << array[7] << "|\n";
    std::cout << "|" << std::fixed << std::setprecision(2) << array[8]  << ' ' << array[9] << ' ' << array[10] << ' ' << array[11] << "|\n";
    std::cout << "|" << std::fixed << std::setprecision(2) << array[12] << ' ' << array[13] << ' ' << array[14] << ' ' << array[15] << "|\n";
    std::cout << "¯¯¯¯" << "             " << "¯¯¯¯\n";
}
