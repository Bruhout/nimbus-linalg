#include "../include/vec.h"
#include "../include/mat.h"

#include <iostream>
#include <math.h>

// unit test helper functions
bool vec3_equality_test(la::vec3 v1 , la::vec3 v2);
bool vec4_equality_test(la::vec4 v1 , la::vec4 v2);
bool mat4_equality_test(la::mat4 m1 , la::mat4 m2);

// vec method unit tests
void test_operator_sub_vec3();
void test_operator_add_vec3();
void test_operator_mul_vec3();
void test_operator_div_vec3();
void test_operator_index_vec3();
void test_operator_matmul_vec3();
void test_operator_cross_vec3();
void test_magnitude_sq_vec3();
void test_magnitude_vec3();
void test_distance_from_vec3();
void test_cross_product_vec3();
void test_dot_product_vec3();
void test_normalize_vec3();
void test_project_vec_vec3();
void test_mutliply_vec_mat_vec3();
void test_viewport_transform_vec3();
void test_reflect_color_vec3();
void test_float_to_uint_vec3();
void test_uint_to_float_vec3();

void test_operator_sub_vec4();
void test_operator_add_vec4();
void test_operator_mul_vec4();
void test_operator_div_vec4();
void test_operator_index_vec4();
void test_operator_matmul_vec4();
void test_operator_matmul_equal_vec4();
void test_operator_cross_vec4();
void test_magnitude_sq_vec4();
void test_magnitude_vec4();
void test_distance_from_vec4();
void test_cross_product_vec4();
void test_dot_product_vec4();
void test_normalize_vec4();
void test_project_vec_vec4();
void test_mutliply_vec_mat_vec4();
void test_viewport_transform_vec4();
void test_reflect_color_vec4();
void test_float_to_uint_vec4();
void test_uint_to_float_vec4();


// mat method unit tests
void test_operator_index();
void test_operator_matmul();
void test_multiply_matrices();
void test_translate_mat();
void test_rotate_mat();
void test_look_at();
void test_perspective_mat();
void test_transpose();


// inline functions, macro tests
void test_radians();
void test_degrees();

int main(void)
{
    // vec3 method unit tests
    test_operator_sub_vec3();
    test_operator_add_vec3();
    test_operator_mul_vec3();
    test_operator_div_vec3();
    test_operator_index_vec3();
    test_operator_matmul_vec3();
    test_operator_cross_vec3();
    test_magnitude_sq_vec3();
    test_magnitude_vec3();
    test_distance_from_vec3();
    test_cross_product_vec3();
    test_dot_product_vec3();
    test_normalize_vec3();
    test_project_vec_vec3();
    test_mutliply_vec_mat_vec3();
    test_viewport_transform_vec3();
    test_reflect_color_vec3();
    test_float_to_uint_vec3();
    test_uint_to_float_vec3();

    // vec4 method unit tests
    test_operator_sub_vec4();
    test_operator_add_vec4();
    test_operator_mul_vec4();
    test_operator_div_vec4();
    test_operator_index_vec4();
    test_operator_matmul_vec4();
    test_operator_cross_vec4();
    test_magnitude_sq_vec4();
    test_magnitude_vec4();
    test_distance_from_vec4();
    test_cross_product_vec4();
    test_dot_product_vec4();
    test_normalize_vec4();
    test_project_vec_vec4();
    test_mutliply_vec_mat_vec4();
    test_viewport_transform_vec4();
    test_reflect_color_vec4();
    test_float_to_uint_vec4();
    test_uint_to_float_vec4();

    // mat method unit tests
    test_operator_index();
    test_operator_matmul();
    test_multiply_matrices();
    test_translate_mat();
    test_rotate_mat();
    test_look_at();
    test_perspective_mat();
    test_transpose();

    test_radians();
    test_degrees();
}

// unit test helper functions------------------------------------------
bool vec3_equality_test(la::vec3 v1 , la::vec3 v2)
{
    for (int i=0 ; i<3 ; i++) {
        if (v1[i] != v2[i]) {
            return false;
        }
    }

    return true;
}
bool vec4_equality_test(la::vec4 v1 , la::vec4 v2)
{
    for (int i=0 ; i<4 ; i++) {
        if (v1[i] != v2[i]) {
            return false;
        }
    }

    return true;
}
bool mat4_equality_test(la::mat4 m1 , la::mat4 m2)
{
    for (int i=0 ; i<16 ; i++) {
        if (m1.array[i] != m2.array[i]) {
            return false;
        }
    }

    return true;
}

// vec3 method unit tests------------------------------------------
void test_operator_sub_vec3()
{
    la::vec3 test = la::vec3();
    if ( vec3_equality_test(test - test , la::vec3(0,0,0)) ) {
        std::cout << "test_operator_sub_vec3: true" << std::endl; 
    } else {
        std::cout << "test_operator_sub_vec3: false ";
        (test - test).PrintVec();
    }
}
void test_operator_add_vec3()
{
    la::vec3 test = la::vec3();
    if ( vec3_equality_test(test + test , la::vec3(2.0f,2.0f,2.0f)) ) {
        std::cout << "test_operator_add_vec3: true" << std::endl; 
    } else {
        std::cout << "test_operator_add_vec3: false ";
        (test + test).PrintVec();
    }
}
void test_operator_mul_vec3()
{
    la::vec3 test = la::vec3();
    if ( vec3_equality_test(test * 2.0f , la::vec3(2.0f,2.0f,2.0f)) ) {
        std::cout << "test_operator_mul_vec3: true" << std::endl; 
    } else {
        std::cout << "test_operator_mul_vec3: false ";
        (test * 2.0f).PrintVec();
    }
}
void test_operator_div_vec3()
{
    la::vec3 test = la::vec3();
    if ( vec3_equality_test(test / 0.5f , la::vec3(2.0f,2.0f,2.0f)) ) {
        std::cout << "test_operator_div_vec3: true" << std::endl; 
    } else {
        std::cout << "test_operator_div_vec3: false ";
        (test / 0.5f).PrintVec();
    }
}
void test_operator_index_vec3()
{
    la::vec3 test = la::vec3();
    if (test[0] == 1.0f) { std::cout << "test_operator_index_vec3: true" << std::endl; }
    else { std::cout << "test_operator_index_vec3: false " << test[0] << std::endl; }
}
void test_operator_matmul_vec3()
{
    la::vec3 test = la::vec3(1.0f , 2.0f , 3.0f);
    la::mat4 test_mat = la::mat4();

    if ( vec3_equality_test(test * test_mat , test) ) { std::cout << "test_operator_matmul_vec3: true" << std::endl; }
    else { std::cout << "test_operator_matmul_vec3: true" << std::endl; }
}
void test_operator_cross_vec3()
{
    la::vec3 test = la::vec3(1.0f , 0.0f , 0.0f);
    la::vec3 test2 = la::vec3(0.0f , 1.0f , 0.0f);

    if ( vec3_equality_test(test * test2 , la::vec3(0.0f , 0.0f , 1.0f)) ) {
        std::cout << "test_operator_cross_vec3: true" << std::endl;
    } else {
        std::cout << "test_operator_cross_vec3: false ";
        (test * test2).PrintVec();
    }
}
void test_magnitude_sq_vec3()
{
    la::vec3 test = la::vec3();
    if (test.MagnitudeSq() == 3.0f) { std::cout << "test_magnitude_sq_vec3: true " << std::endl; }
    else { std::cout << "test_magnitude_sq_vec3: false" << test.MagnitudeSq() << std::endl; }
}
void test_magnitude_vec3()
{
    la::vec3 test = la::vec3();
    if (test.Magnitude() == pow(3.0f , 0.5f)) { std::cout << "test_magnitude_vec3: true " << std::endl; }
    else { std::cout << "test_magnitude_vec3: false" << test.Magnitude() << std::endl; }
}
void test_distance_from_vec3()
{
    la::vec3 test = la::vec3();
    la::vec3 origin = la::vec3(0.0f , 0.0f , 0.0f);
    if (test.DistanceFrom(origin) == pow(3.0f , 0.5f)) { std::cout << "test_distance_from_vec3: true " << std::endl; }
    else { std::cout << "test_distance_from_vec3: false" << test.DistanceFrom(origin) << std::endl; }
}
void test_cross_product_vec3()
{
    la::vec3 test = la::vec3(1.0f , 0.0f , 0.0f);
    la::vec3 test2 = la::vec3(0.0f , 1.0f , 0.0f);

    if ( vec3_equality_test(test.CrossProduct(test2) , la::vec3(0.0f , 0.0f , 1.0f)) ) {
        std::cout << "test_operator_cross_vec3: true" << std::endl;
    } else {
        std::cout << "test_operator_cross_vec3: false ";
        (test * test2).PrintVec();
    }
}
void test_dot_product_vec3()
{
    la::vec3 test = la::vec3(1.0f , 2.0f , 3.0f);
    la::vec3 test2 = la::vec3(4.0f , 5.0f , 6.0f);

    if (test.DotProduct(test2) == 32.0f) { std::cout << "test_dot_product_vec3: true" << std::endl; }
    else { std::cout << "test_dot_product_vec3: false " << test.DotProduct(test2) << std::endl; }
}
void test_normalize_vec3()
{
    la::vec3 test = la::vec3 (5.0f , 0.0f , 0.0f);

    if ( vec3_equality_test(test.Normalize() , la::vec3(1.0f , 0.0f , 0.0f)) ) {
        std::cout << "test_normalize_vec3: true" << std::endl;
    } else {
        std::cout << "test_normalize_vec3: false ";
        (test.Normalize()).PrintVec();
    }
}
void test_project_vec_vec3()
{
    la::vec3 test = la::vec3(1.0f , 1.0f , 1.0f);
    la::vec3 test2 = la::vec3(5.0f , 0.0f , 0.0f);

    if ( vec3_equality_test(test.ProjectVec(test2) , la::vec3(1.0f , 0.0f , 0.0f)) ) {
        std::cout << "test_project_vec_vec3: true" << std::endl;
    } else {
        std::cout << "test_project_vec_vec3: false ";
        (test.ProjectVec(test2)).PrintVec();
    }
}
void test_mutliply_vec_mat_vec3()
{
    la::vec3 test = la::vec3(1.0f , 1.0f , 1.0f);
    la::mat4 test_mat = la::mat4();

    if ( vec3_equality_test(test.MultiplyVecMat(test_mat) , test) ) {
        std::cout << "test_multiply_vec_mat_vec3: true" << std::endl;
    } else {
        std::cout << "test_multiply_vec_mat_mat3: false ";
        (test.MultiplyVecMat(test_mat)).PrintVec();
    }
}
void test_viewport_transform_vec3()
{
    la::vec3 test = la::vec3();

    if ( vec3_equality_test(test.ViewportTransform(512 , 512) , la::vec3(256 , 256 , 1.0f)) ) {
        std::cout << "test_viewport_transform_vec3: true" << std::endl;
        (test.ViewportTransform(512 , 512)).PrintVec();
    }
}
void test_reflect_color_vec3()
{
    la::vec3 test = la::vec3(1.0f , 0.5f , 1.0f);
    la::vec3 test2 = la::vec3(0.1f , 0.2f , 0.3f);

    if ( vec3_equality_test(test.ReflectColor(test2) , la::vec3(0.1f , 0.1f , 0.3f)) ) {
        std::cout << "test_reflect_color_vec3: true" << std::endl;
    } else {
        std::cout << "test_reflect_color_vec3: false ";
        (test.ReflectColor(test2)).PrintVec();
    }
}
void test_float_to_uint_vec3()
{
    la::vec3 test = la::vec3(1.0f , 1.0f , 1.0f);
    
    if ( vec3_equality_test(test.FloatToUint() , la::vec3(255 , 255 , 255)) ) {
        std::cout << "test_float_to_uint_vec3: true" << std::endl;
    } else {
        std::cout << "test_float_to_uint_vec3: false" ;
        (test.FloatToUint()).PrintVec();
    }
}
void test_uint_to_float_vec3()
{
    la::vec3 test = la::vec3(255 , 255 , 255);
    
    if ( vec3_equality_test(test.UintToFloat() , la::vec3(1.0f , 1.0f , 1.0f)) ) {
        std::cout << "test_uint_to_float_vec3: true" << std::endl;
    } else {
        std::cout << "test_uint_to_float_vec3: false ";
        (test.UintToFloat()).PrintVec();
    }
}





// vec4 method unit tests------------------------------------------
void test_operator_sub_vec4()
{
    la::vec4 test = la::vec4();
    if ( vec4_equality_test(test - test , la::vec4(0.0f , 0.0f , 0.0f , 1.0f)) ) {
        std::cout << "test_operator_sub_vec4: true" << std::endl; 
    } else {
        std::cout << "test_operator_sub_vec4: false ";
        (test - test).PrintVec();
    }
}
void test_operator_add_vec4()
{
    la::vec4 test = la::vec4();
    if ( vec4_equality_test(test + test , la::vec4(2.0f , 2.0f , 2.0f , 1.0f)) ) {
        std::cout << "test_operator_add_vec4: true" << std::endl; 
    } else {
        std::cout << "test_operator_add_vec4: false ";
        (test + test).PrintVec();
    }
}
void test_operator_mul_vec4()
{
    la::vec4 test = la::vec4();
    if ( vec4_equality_test(test * 2.0f , la::vec4(2.0f , 2.0f , 2.0f , 1.0f)) ) {
        std::cout << "test_operator_mul_vec4: true" << std::endl; 
    } else {
        std::cout << "test_operator_mul_vec4: false ";
        (test * 2.0f).PrintVec();
    }
}
void test_operator_div_vec4()
{
    la::vec4 test = la::vec4();
    if ( vec4_equality_test(test / 0.5f , la::vec4(2.0f , 2.0f , 2.0f , 1.0f)) ) {
        std::cout << "test_operator_div_vec4: true" << std::endl; 
    } else {
        std::cout << "test_operator_div_vec4: false ";
        (test / 0.5f).PrintVec();
    }
}
void test_operator_index_vec4()
{
    la::vec4 test = la::vec4();
    if (test[0] == 1.0f) { std::cout << "test_operator_index_vec4: true" << std::endl; }
    else { std::cout << "test_operator_index_vec4: false " << test[0] << std::endl; }
}
void test_operator_matmul_vec4()
{
    la::vec4 test = la::vec4(1.0f , 2.0f , 3.0f , 4.0f);
    la::mat4 test_mat = la::mat4();

    if ( vec4_equality_test(test * test_mat , test) ) { std::cout << "test_operator_matmul_vec4: true" << std::endl; }
    else { std::cout << "test_operator_matmul_vec4: true" << std::endl; }
}
void test_operator_cross_vec4()
{
    la::vec4 test = la::vec4(1.0f , 0.0f , 0.0f , 1.0f);
    la::vec4 test2 = la::vec4(0.0f , 1.0f , 0.0f , 1.0f);

    if ( vec4_equality_test(test * test2 , la::vec4(0.0f , 0.0f , 1.0f , 1.0f)) ) {
        std::cout << "test_operator_cross_vec4: true" << std::endl;
    } else {
        std::cout << "test_operator_cross_vec4: false ";
        (test * test2).PrintVec();
    }
}
void test_magnitude_sq_vec4()
{
    la::vec4 test = la::vec4();
    if (test.MagnitudeSq() == 3.0f) { std::cout << "test_magnitude_sq_vec4: true " << std::endl; }
    else { std::cout << "test_magnitude_sq_vec4: false " << test.MagnitudeSq() << std::endl; }
}
void test_magnitude_vec4()
{
    la::vec4 test = la::vec4();
    if (test.Magnitude() == pow(3.0f , 0.5f)) { std::cout << "test_magnitude_vec4: true " << std::endl; }
    else { std::cout << "test_magnitude_vec4: false " << test.Magnitude() << std::endl; }
}
void test_distance_from_vec4()
{
    la::vec4 test = la::vec4(1.0f , 1.0f , 1.0f , 1.0f);
    la::vec4 ref_point = la::vec4(-1.0f , -1.0f , -1.0f , 1.0f);
    if (test.DistanceFrom(ref_point) == pow(12.0f , 0.5f)) { std::cout << "test_distance_from_vec4: true " << std::endl; }
    else { std::cout << "test_distance_from_vec4: false " << test.DistanceFrom(ref_point) << std::endl; }
}
void test_cross_product_vec4()
{
    la::vec4 test = la::vec4(1.0f , 0.0f , 0.0f , 1.0f);
    la::vec4 test2 = la::vec4(0.0f , 1.0f , 0.0f , 1.0f);

    if ( vec4_equality_test(test.CrossProduct(test2) , la::vec4(0.0f , 0.0f , 1.0f , 1.0f)) ) {
        std::cout << "test_operator_cross_vec4: true" << std::endl;
    } else {
        std::cout << "test_operator_cross_vec4: false ";
        (test * test2).PrintVec();
    }
}
void test_dot_product_vec4()
{
    la::vec4 test = la::vec4(1.0f , 2.0f , 3.0f , 1.0f);
    la::vec4 test2 = la::vec4(4.0f , 5.0f , 6.0f , 1.0f);

    if (test.DotProduct(test2) == 32.0f) { std::cout << "test_dot_product_vec4: true" << std::endl; }
    else { std::cout << "test_dot_product_vec4: false " << test.DotProduct(test2) << std::endl; }
}
void test_normalize_vec4()
{
    la::vec4 test = la::vec4(5.0f , 0.0f , 0.0f , 1.0f);

    if ( vec4_equality_test(test.Normalize() , la::vec4(1.0f , 0.0f , 0.0f , 1.0f)) ) {
        std::cout << "test_normalize_vec4: true" << std::endl;
    } else {
        std::cout << "test_normalize_vec4: false ";
        (test.Normalize()).PrintVec();
    }
}
void test_project_vec_vec4()
{
    la::vec4 test = la::vec4(1.0f , 1.0f , 1.0f , 1.0f);
    la::vec4 test2 = la::vec4(5.0f , 0.0f , 0.0f , 1.0f);

    if ( vec4_equality_test(test.ProjectVec(test2) , la::vec4(1.0f , 0.0f , 0.0f , 1.0f)) ) {
        std::cout << "test_project_vec_vec4: true" << std::endl;
    } else {
        std::cout << "test_project_vec_vec4: false ";
        (test.ProjectVec(test2)).PrintVec();
    }
}
void test_mutliply_vec_mat_vec4()
{
    la::vec4 test = la::vec4(1.0f , 2.0f , 3.0f , 4.0f);
    la::mat4 test_mat = la::mat4();

    if ( vec4_equality_test(test.MultiplyVecMat(test_mat) , test) ) {
        std::cout << "test_multiply_vec_mat_vec4: true" << std::endl;
    } else {
        std::cout << "test_multiply_vec_mat_mat3: false ";
        (test.MultiplyVecMat(test_mat)).PrintVec();
    }
}
void test_viewport_transform_vec4()
{
    la::vec4 test = la::vec4();

    if ( vec4_equality_test(test.ViewportTransform(512 , 512) , la::vec4(256 , 256 , 1.0f , 1.0f)) ) {
        std::cout << "test_viewport_transform_vec4: true" << std::endl;
        (test.ViewportTransform(512 , 512)).PrintVec();
    }
}
void test_reflect_color_vec4()
{
    la::vec4 test = la::vec4(1.0f , 0.5f , 1.0f , 0.5f);
    la::vec4 test2 = la::vec4(0.1f , 0.2f , 0.3f , 0.5f);

    if ( vec4_equality_test(test.ReflectColor(test2) , la::vec4(0.1f , 0.1f , 0.3f , 0.25f)) ) {
        std::cout << "test_reflect_color_vec4: true" << std::endl;
    } else {
        std::cout << "test_reflect_color_vec4: false ";
        (test.ReflectColor(test2)).PrintVec();
    }
}
void test_float_to_uint_vec4()
{
    la::vec4 test = la::vec4(1.0f , 1.0f , 1.0f , 1.0f);
    
    if ( vec4_equality_test(test.FloatToUint() , la::vec4(255 , 255 , 255 , 255)) ) {
        std::cout << "test_float_to_uint_vec4: true" << std::endl;
    } else {
        std::cout << "test_float_to_uint_vec4: false" ;
        (test.FloatToUint()).PrintVec();
    }
}
void test_uint_to_float_vec4()
{
    la::vec4 test = la::vec4(255 , 255 , 255 , 255);
    
    if ( vec4_equality_test(test.UintToFloat() , la::vec4(1.0f , 1.0f , 1.0f , 1.0f)) ) {
        std::cout << "test_uint_to_float_vec4: true" << std::endl;
    } else {
        std::cout << "test_uint_to_float_vec4: false ";
        (test.UintToFloat()).PrintVec();
    }
}


// mat method unit tests
void test_operator_index()
{
    la::mat4 test = la::mat4();
    if ( vec4_equality_test(test[0] , la::vec4(1.0f , 0.0f , 0.0f , 0.0f)) ) {
        std::cout << "test_operator_index: true" << std::endl;
    } else {
        std::cout << "test_operator_index: false \n";
        test[0].PrintVec();
    }
}
void test_operator_matmul()
{
    la::mat4 test1 = la::mat4();
    la::mat4 test2 = la::mat4();

    if ( mat4_equality_test(test1 * test2 , test1) ) {
        std::cout << "test_operator_matmul: true" << std::endl;
    } else {
        std::cout << "test_operator_matmul: false \n";
        (test1 * test2).PrintMat();
    }
}
void test_multiply_matrices()
{
    la::mat4 test1 = la::mat4();
    la::mat4 test2 = la::mat4();

    if ( mat4_equality_test(test1.MultiplyMatrices(test2) , test1) ) {
        std::cout << "test_operator_matmul: true" << std::endl;
    } else {
        std::cout << "test_operator_matmul: false \n";
        (test1.MultiplyMatrices(test2)).PrintMat();
    }
}
void test_translate_mat()
{
    la::vec3 test_vec = la::vec3(2.0f , 2.0f , 2.0f);
    la::mat4 test1 = la::mat4();
    float test2_array[] = {
        1.0f , 0.0f , 0.0f , 0.0f ,
        0.0f , 1.0f , 0.0f , 0.0f ,
        0.0f , 0.0f , 1.0f , 0.0f ,
        2.0f , 2.0f , 2.0f , 1.0f
    };
    la::mat4 test2 = la::mat4(test2_array);

    if ( mat4_equality_test(test1.TranslateMat(test_vec) , test2) ) {
        std::cout << "test_translate_mat: true" << std::endl;
    } else {
        std::cout << "test_translate_mat: false \n";
        (test1.TranslateMat(test_vec)).PrintMat();
    }
}
void test_rotate_mat()
{
    float pitch = la::radians(60.0f);
    float yaw = la::radians(120.0f);
    float roll = la::radians(180.0f);

    la::mat4 new_mat = la::mat4();

    std::cout << "test_rotate_mat:\n";
    (new_mat.RotateMat(pitch , yaw , roll)).PrintMat();
}
void test_look_at()
{
    la::vec3 cam_pos = la::vec3(0.0f , 0.0f , -4.0f);
    la::vec3 cam_aim = la::vec3(0.0f , 0.0f , 0.0f);
    la::vec3 world_up = la::vec3(0.0f , 1.0f , 0.0f);

    std::cout << "test_look_at:\n";
    la::mat4 new_mat = la::mat4();

    (new_mat.LookAt(cam_pos , cam_aim , world_up)).PrintMat();
}
void test_perspective_mat()
{
    float fov = la::radians(60.0f);

    la::mat4 new_mat = la::mat4();

    std::cout << "test_perspective_mat:\n";
    (new_mat.PerspectiveMat(fov , 0.1f , 10.0f)).PrintMat();
}
void test_transpose()
{
    la::mat4 test = la::mat4();

    if ( mat4_equality_test(test.Transpose() , test) ) {
        std::cout << "test_transpose: true" << std::endl;
    } else {
        std::cout << "test_transpose: false ";
        (test.Transpose()).PrintMat();
    }
}


// inline functions, macro tests------------------------------------------
void test_radians()
{
    if (la::radians(180.0f) == la::PI) { std::cout << "test_radians: true" << std::endl; }
    else { std::cout << "test_radians: " << la::radians(180.0f) << " false" << std::endl; }
}
void test_degrees()
{
    if (la::degrees(la::PI) == 180.0f) { std::cout << "test_degrees: true" << std::endl; }
    else { std::cout << "test_degrees: " << la::degrees(la::PI) << " false" << std::endl; }
}