#include "../include/vec.h"
#include "../include/mat.h"

#include <iostream>
#include <iomanip>
#include <math.h>
#include <cstring>

using namespace la;

//===============================================================================================
// getters and setters -------------------------
float* mat4::get_array() { return array; }
void mat4::set_array(float* Array) { memcpy(array, Array, 16 * sizeof(float)); }

// constructor functions------------------------
mat4::mat4()
{
    memset(array, 0, sizeof(array));
    array[0] = array[5] = array[10] = array[15] = 1.0f;
}
mat4::mat4(float num)
{
    array[ 0]=num; array[ 1]=num; array[ 2]=num; array[ 3]=num;
    array[ 4]=num; array[ 5]=num; array[ 6]=num; array[ 7]=num;
    array[ 8]=num; array[ 9]=num; array[10]=num; array[11]=num;
    array[12]=num; array[13]=num; array[14]=num; array[15]=num;
}
mat4::mat4(float* Array)
{
    memcpy(array, Array, 16 * sizeof(float));
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
mat4 mat4::RotateMat(float pitch , float yaw , float roll)
{
    mat4 new_mat = *this;
    
    new_mat = new_mat.RotateMatX(pitch);
    new_mat = new_mat.RotateMatY(yaw);
    new_mat = new_mat.RotateMatZ(roll);

    return new_mat;
}
mat4 mat4::RotateMatX(float pitch)
{
    mat4 new_mat = *this;
    
    float array[] = {
        1.0f ,    0.0f     ,     0.0f   , 0.0f ,
        0.0f ,  cos(pitch) , sin(pitch) , 0.0f ,
        0.0f , -sin(pitch) , cos(pitch) , 0.0f ,
        0.0f ,    0.0f     ,     0.0f   , 1.0f
    };
    mat4 rot_mat = mat4(array);

    return rot_mat * new_mat;
}
mat4 mat4::RotateMatY(float yaw)
{
    mat4 new_mat = *this;

    float array[] = {
         cos(yaw) , 0.0f , sin(yaw)  , 0.0f ,
        0.0f     , 1.0f ,   0.0f    , 0.0f ,
        -sin(yaw) , 0.0f , cos(yaw)  , 0.0f ,
        0.0f     , 0.0f ,   0.0f    , 1.0f
    };
    mat4 rot_mat = mat4(array);

    return rot_mat * new_mat;
}
mat4 mat4::RotateMatZ(float roll)
{
    mat4 new_mat = *this;

    float array[] = {
        cos(roll)  , sin(roll) , 0.0f , 0.0f ,
        -sin(roll) , cos(roll) , 0.0f , 0.0f ,
        0.0f       ,   0.0f    , 1.0f , 0.0f ,
        0.0f       ,   0.0f    , 0.0f , 1.0f
    };
    mat4 rot_mat = mat4(array);

    return rot_mat * new_mat;
}
mat4 mat4::LookAt(vec3 camera_pos,  vec3 camera_aim , vec3 world_up)
{
    vec3 backward = (camera_pos - camera_aim).Normalize();
    vec3 right = (world_up * backward).Normalize();
    vec3 up = (backward * right).Normalize();

    // new system where basis vectors are according to the camera
    return mat4(right , up , backward).TranslateMat(camera_pos * -1);
}
mat4 mat4::PerspectiveMat(float fov_rad , float z_near , float z_far)
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
    for (int i=0 ; i<4 ; i++)
    {
        std::cout << "| ";
        for (int j=0 ; j<4 ; j++)
        {
            if (array[i*4 + j] > 0.0f && array[i*4 + j] != 0.0f) { std::cout << " "; }
            std::cout << std::fixed << std::setprecision(2) << array[i*4 + j];
            std::cout << " ";
        }
        std::cout << "|\n";
    }

    std::cout << std::endl;
}
