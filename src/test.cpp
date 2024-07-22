#include "../include/vec.h"
#include "../include/mat.h"

#include <iostream>

void print_test();
void copy_test();
void index_test();
void cross_prod_test();
void matmul_test();
void vecmul_test();
void mat_from_vec_test();
void three_four_convert_test();
void lookat_test();
void perspective_projection_test();

int main(void)
{
    print_test();
    copy_test();
    index_test();
    cross_prod_test();
    matmul_test();
    vecmul_test();
    mat_from_vec_test();
    three_four_convert_test();
    lookat_test();
    perspective_projection_test();
}

void print_test()
{
    std::cout << "print_test()\n";
    la::mat4 new_mat = la::mat4();
    new_mat.PrintMat();
}

void copy_test()
{
    std::cout << "copy_test()\n";
    la::mat4 new_mat = la::mat4();
    la::mat4 another_mat = new_mat;
    another_mat.PrintMat();
}

void index_test()
{
    std::cout << "index_test()\n";
    la::mat4 new_mat = la::mat4();
    std::cout << new_mat[3][3] << '\n';
}

void cross_prod_test()
{
    std::cout << "cross_prod_test()\n";
    la::vec3 v1 = la::vec3(1.0f , 2.0f , 3.0f);
    la::vec3 v2 = la::vec3(4.0f , 5.0f , 6.0f);
    (v1 * v2).PrintVec();

    la::vec4 v3 = la::vec4(v1);
    la::vec4 v4 = la::vec4(v2);
    (v3 * v4).PrintVec();
}

void matmul_test()
{
    std::cout << "matmul_test()\n";
    la::mat4 new_mat = la::mat4();
    la::mat4 another_mat = new_mat;
    (new_mat * another_mat).PrintMat();
}

void vecmul_test()
{
    std::cout << "vecmul_test()\n";
    la::mat4 new_mat = la::mat4();
    la::vec3 new_vec3 = la::vec3();
    la::vec4 new_vec4 = la::vec4();

    (new_vec3 * new_mat).PrintVec();
    (new_vec4 * new_mat).PrintVec();
}

void mat_from_vec_test()
{
    std::cout << "mat_from_vec_test()\n";
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
    std::cout << "three_four_convert_test()\n";
    la::vec3 v31 = la::vec3(1.0f , 2.0f , 3.0f);
    la::vec4 v41 = la::vec4(v31);
    v41.PrintVec();

    la::vec4 v42 = la::vec4(1.0f , 2.0f , 3.0f , 4.0f);
    la::vec3 v32 = la::vec3(v42);
    v32.PrintVec();
}

void lookat_test()
{
    std::cout << "lookat_test()\n";
    la::vec3 pos = la::vec3(0.0f , 0.0f , 4.0f);
    la::vec3 aim = la::vec3(0.0f , 0.0f , 0.0f);
    la::vec3 world_up = la::vec3(0.0f , 1.0f , 0.0f);

    la::mat4 new_mat = la::mat4();
    (new_mat.LookAt(pos , aim , world_up)).PrintMat();
}

void perspective_projection_test()
{
    std::cout << "perspective_projection_test()\n";
    la::mat4 proj_mat = la::mat4().PerspectiveMat(la::radians(60.0f) , 0.1f , 100.0f);

    proj_mat.PrintMat();
}