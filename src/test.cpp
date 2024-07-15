#include "../include/vec.h"
#include "../include/mat.h"

#include <iostream>

void print_test();
void copy_test();
void index_test();
void matmul_test();
void vecmul_test();
void mat_from_vec_test();
void three_four_convert_test();
void lookat_test();

int main(void)
{
    print_test();
    copy_test();
    index_test();
    matmul_test();
    vecmul_test();
    mat_from_vec_test();
    three_four_convert_test();
    lookat_test();
}

void print_test()
{
    la::mat4 new_mat = la::mat4();
    new_mat.PrintMat();
}

void copy_test()
{
    la::mat4 new_mat = la::mat4();
    la::mat4 another_mat = new_mat;
    another_mat.PrintMat();
}

void index_test()
{
    la::mat4 new_mat = la::mat4();
    std::cout << new_mat[3][3] << '\n';
}

void matmul_test()
{
    la::mat4 new_mat = la::mat4();
    la::mat4 another_mat = new_mat;
    (new_mat * another_mat).PrintMat();
}

void vecmul_test()
{
    la::mat4 new_mat = la::mat4();
    la::vec3 new_vec3 = la::vec3();
    la::vec4 new_vec4 = la::vec4();

    (new_vec3 * new_mat).PrintVec();
    (new_vec4 * new_mat).PrintVec();
}

void mat_from_vec_test()
{
    la::vec3 vec3_1 = la::vec3(1.0f , 2.0f , 3.0f);
    la::vec3 vec3_2 = la::vec3(4.0f , 5.0f , 6.0f);
    la::vec3 vec3_3 = la::vec3(7.0f , 8.0f , 9.0f);

    la::vec4 vec4_1 = la::vec4(1.0f , 2.0f , 3.0f , 4.0f);
    la::vec4 vec4_2 = la::vec4(5.0f , 6.0f , 7.0f , 8.0f);
    la::vec4 vec4_3 = la::vec4(9.0f , 10.0f , 11.0f , 12.0f);


    la::mat4 mat1 = la::mat4(vec3_1 , vec3_2 , vec3_3);
    la::mat4 mat2 = la::mat4(vec4_1 , vec4_2 , vec4_3);

    mat1.PrintMat();
    mat2.PrintMat();
}

void three_four_convert_test()
{
    la::vec3 v31 = la::vec3(1.0f , 2.0f , 3.0f);
    la::vec4 v41 = la::vec4(v31);
    v41.PrintVec();

    la::vec4 v42 = la::vec4(1.0f , 2.0f , 3.0f , 4.0f);
    la::vec3 v32 = la::vec3(v42);
    v32.PrintVec();
}

void lookat_test()
{
    la::vec3 pos = la::vec3(0.0f , 0.0f , 4.0f);
    la::vec3 aim = la::vec3(0.0f , 0.0f , 0.0f);
    la::vec3 world_up = la::vec3(0.0f , 1.0f , 0.0f);

    la::mat4 new_mat = la::mat4();
    (new_mat.LookAt(pos , aim , world_up)).PrintMat();
}