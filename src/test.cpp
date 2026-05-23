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
void test_constructor_default_mat4();
void test_constructor_scalar_mat4();
void test_constructor_array_mat4();
void test_constructor_vec3_mat4();
void test_constructor_vec4_mat4();
void test_operator_index();
void test_operator_matmul();
void test_operator_matmul_equal_mat4();
void test_multiply_matrices();
void test_translate_mat();
void test_rotate_mat();
void test_rotate_mat_x();
void test_rotate_mat_y();
void test_rotate_mat_z();
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
    test_operator_matmul_equal_vec4();
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
    test_constructor_default_mat4();
    test_constructor_scalar_mat4();
    test_constructor_array_mat4();
    test_constructor_vec3_mat4();
    test_constructor_vec4_mat4();
    test_operator_index();
    test_operator_matmul();
    test_operator_matmul_equal_mat4();
    test_multiply_matrices();
    test_translate_mat();
    test_rotate_mat();
    test_rotate_mat_x();
    test_rotate_mat_y();
    test_rotate_mat_z();
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
    else { std::cout << "test_operator_matmul_vec3: false "; (test * test_mat).PrintVec(); }
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
    else { std::cout << "test_operator_matmul_vec4: false "; (test * test_mat).PrintVec(); }
}
void test_operator_matmul_equal_vec4()
{
    // vec4 *= identity should leave the vector unchanged
    la::vec4 test = la::vec4(1.0f , 2.0f , 3.0f , 4.0f);
    la::vec4 expected = test;
    la::mat4 test_mat = la::mat4();

    test *= test_mat;

    if ( vec4_equality_test(test , expected) ) { std::cout << "test_operator_matmul_equal_vec4: true" << std::endl; }
    else { std::cout << "test_operator_matmul_equal_vec4: false "; test.PrintVec(); }
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
    // I * I = I
    la::mat4 test1 = la::mat4();
    la::mat4 test2 = la::mat4();

    if ( mat4_equality_test(test1.MultiplyMatrices(test2) , test1) ) {
        std::cout << "test_multiply_matrices: true" << std::endl;
    } else {
        std::cout << "test_multiply_matrices: false \n";
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
    la::mat4 new_mat = la::mat4();

    // rotating by 0 on all axes should return the identity matrix
    la::mat4 result_zero = new_mat.RotateMat(0.0f , 0.0f , 0.0f);
    if ( mat4_equality_test(result_zero , la::mat4()) ) {
        std::cout << "test_rotate_mat (zero rotation = identity): true" << std::endl;
    } else {
        std::cout << "test_rotate_mat (zero rotation = identity): false \n";
        result_zero.PrintMat();
    }

    // rotating +X by 90 degrees around Z should give +Y
    la::mat4 rot_z90 = new_mat.RotateMatZ(la::PIBY2);
    la::vec3 x_axis = la::vec3(1.0f , 0.0f , 0.0f);
    la::vec3 rotated = x_axis * rot_z90;
    la::vec3 expected = la::vec3(0.0f , 1.0f , 0.0f);
    bool x_ne = fabs(rotated.x - expected.x) < 1e-4f;
    bool y_ne = fabs(rotated.y - expected.y) < 1e-4f;
    bool z_ne = fabs(rotated.z - expected.z) < 1e-4f;
    if ( x_ne && y_ne && z_ne ) {
        std::cout << "test_rotate_mat (rotZ 90: X->Y): true" << std::endl;
    } else {
        std::cout << "test_rotate_mat (rotZ 90: X->Y): false ";
        rotated.PrintVec();
    }

    // rotating +Y by 90 degrees around X should give +Z
    la::mat4 rot_x90 = new_mat.RotateMatX(la::PIBY2);
    la::vec3 y_axis = la::vec3(0.0f , 1.0f , 0.0f);
    la::vec3 rotated_x = y_axis * rot_x90;
    la::vec3 expected_x = la::vec3(0.0f , 0.0f , 1.0f);
    bool x_ne2 = fabs(rotated_x.x - expected_x.x) < 1e-4f;
    bool y_ne2 = fabs(rotated_x.y - expected_x.y) < 1e-4f;
    bool z_ne2 = fabs(rotated_x.z - expected_x.z) < 1e-4f;
    if ( x_ne2 && y_ne2 && z_ne2 ) {
        std::cout << "test_rotate_mat (rotX 90: Y->Z): true" << std::endl;
    } else {
        std::cout << "test_rotate_mat (rotX 90: Y->Z): false ";
        rotated_x.PrintVec();
    }

    // rotating +Z by 90 degrees around Y should give +X
    la::mat4 rot_y90 = new_mat.RotateMatY(la::PIBY2);
    la::vec3 z_axis = la::vec3(0.0f , 0.0f , 1.0f);
    la::vec3 rotated_y = z_axis * rot_y90;
    la::vec3 expected_y = la::vec3(1.0f , 0.0f , 0.0f);
    bool x_ne3 = fabs(rotated_y.x - expected_y.x) < 1e-4f;
    bool y_ne3 = fabs(rotated_y.y - expected_y.y) < 1e-4f;
    bool z_ne3 = fabs(rotated_y.z - expected_y.z) < 1e-4f;
    if ( x_ne3 && y_ne3 && z_ne3 ) {
        std::cout << "test_rotate_mat (rotY 90: Z->X): true" << std::endl;
    } else {
        std::cout << "test_rotate_mat (rotY 90: Z->X): false ";
        rotated_y.PrintVec();
    }
}
void test_look_at()
{
    la::vec3 cam_pos  = la::vec3(0.0f , 0.0f , -4.0f);
    la::vec3 cam_aim  = la::vec3(0.0f , 0.0f ,  0.0f);
    la::vec3 world_up = la::vec3(0.0f , 1.0f ,  0.0f);

    la::mat4 new_mat = la::mat4();
    la::mat4 view = new_mat.LookAt(cam_pos , cam_aim , world_up);

    // camera is on the -Z axis looking toward origin, so:
    // right axis (row 0) should be +X: {1, 0, 0}
    // up    axis (row 1) should be +Y: {0, 1, 0}
    // back  axis (row 2) should be -Z: {0, 0,-1}
    bool right_ok = fabs(view.array[0] - 1.0f) < 1e-4f &&
                    fabs(view.array[1] - 0.0f) < 1e-4f &&
                    fabs(view.array[2] - 0.0f) < 1e-4f;
    bool up_ok    = fabs(view.array[4] - 0.0f) < 1e-4f &&
                    fabs(view.array[5] - 1.0f) < 1e-4f &&
                    fabs(view.array[6] - 0.0f) < 1e-4f;
    bool back_ok  = fabs(view.array[8]  - 0.0f) < 1e-4f &&
                    fabs(view.array[9]  - 0.0f) < 1e-4f &&
                    fabs(view.array[10] - (-1.0f)) < 1e-4f;

    if (right_ok) { std::cout << "test_look_at (right axis): true"  << std::endl; }
    else          { std::cout << "test_look_at (right axis): false\n"; view.PrintMat(); }

    if (up_ok)    { std::cout << "test_look_at (up axis): true"     << std::endl; }
    else          { std::cout << "test_look_at (up axis): false\n";   view.PrintMat(); }

    if (back_ok)  { std::cout << "test_look_at (back axis): true"   << std::endl; }
    else          { std::cout << "test_look_at (back axis): false\n"; view.PrintMat(); }

    // a point at the origin should map to (0, 0, -4) in view space
    la::vec3 origin = la::vec3(0.0f , 0.0f , 0.0f);
    la::vec3 view_space = origin * view;
    bool trans_ok = fabs(view_space.x - 0.0f)  < 1e-4f &&
                    fabs(view_space.y - 0.0f)  < 1e-4f &&
                    fabs(view_space.z - (-4.0f)) < 1e-4f;
    if (trans_ok) { std::cout << "test_look_at (origin in view space = {0,0,-4}): true"  << std::endl; }
    else          { std::cout << "test_look_at (origin in view space = {0,0,-4}): false "; view_space.PrintVec(); }
}
void test_perspective_mat()
{
    float fov    = la::radians(60.0f);
    float z_near = 0.1f;
    float z_far  = 10.0f;

    la::mat4 new_mat = la::mat4();
    la::mat4 proj = new_mat.PerspectiveMat(fov , z_near , z_far);

    // [0][0] and [1][1] should equal 1/tan(fov/2)
    float expected_scale = 1.0f / tan(fov / 2.0f);
    if ( fabs(proj.array[0]  - expected_scale) < 1e-4f ) {
        std::cout << "test_perspective_mat (x scale): true" << std::endl;
    } else {
        std::cout << "test_perspective_mat (x scale): false " << proj.array[0] << std::endl;
    }
    if ( fabs(proj.array[5]  - expected_scale) < 1e-4f ) {
        std::cout << "test_perspective_mat (y scale): true" << std::endl;
    } else {
        std::cout << "test_perspective_mat (y scale): false " << proj.array[5] << std::endl;
    }

    // [2][2] should equal -1/(z_far - z_near)
    float expected_zz = -1.0f / (z_far - z_near);
    if ( fabs(proj.array[10] - expected_zz) < 1e-4f ) {
        std::cout << "test_perspective_mat (z depth scale): true" << std::endl;
    } else {
        std::cout << "test_perspective_mat (z depth scale): false " << proj.array[10] << std::endl;
    }

    // [3][2] should equal -z_near/(z_far - z_near)
    float expected_tz = -z_near / (z_far - z_near);
    if ( fabs(proj.array[14] - expected_tz) < 1e-4f ) {
        std::cout << "test_perspective_mat (z translation): true" << std::endl;
    } else {
        std::cout << "test_perspective_mat (z translation): false " << proj.array[14] << std::endl;
    }

    // [2][3] should be -1 (the w divide that enables perspective)
    if ( fabs(proj.array[11] - (-1.0f)) < 1e-4f ) {
        std::cout << "test_perspective_mat (w divide): true" << std::endl;
    } else {
        std::cout << "test_perspective_mat (w divide): false " << proj.array[11] << std::endl;
    }
}
void test_transpose()
{
    // transposing the identity should give back the identity
    la::mat4 test = la::mat4();
    if ( mat4_equality_test(test.Transpose() , test) ) {
        std::cout << "test_transpose (identity): true" << std::endl;
    } else {
        std::cout << "test_transpose (identity): false \n";
        (test.Transpose()).PrintMat();
    }

    // transposing a known matrix should swap rows and columns
    float arr[] = {
        1.0f , 2.0f , 3.0f , 4.0f ,
        5.0f , 6.0f , 7.0f , 8.0f ,
        9.0f , 10.0f , 11.0f , 12.0f ,
        13.0f , 14.0f , 15.0f , 16.0f
    };
    float arr_T[] = {
        1.0f , 5.0f , 9.0f  , 13.0f ,
        2.0f , 6.0f , 10.0f , 14.0f ,
        3.0f , 7.0f , 11.0f , 15.0f ,
        4.0f , 8.0f , 12.0f , 16.0f
    };
    la::mat4 m(arr);
    la::mat4 m_T_expected(arr_T);
    if ( mat4_equality_test(m.Transpose() , m_T_expected) ) {
        std::cout << "test_transpose (known matrix): true" << std::endl;
    } else {
        std::cout << "test_transpose (known matrix): false \n";
        m.Transpose().PrintMat();
    }

    // double transpose should recover the original
    if ( mat4_equality_test(m.Transpose().Transpose() , m) ) {
        std::cout << "test_transpose (double transpose = original): true" << std::endl;
    } else {
        std::cout << "test_transpose (double transpose = original): false \n";
        m.Transpose().Transpose().PrintMat();
    }
}



// mat4 constructor tests------------------------------------------
void test_constructor_default_mat4()
{
    la::mat4 m;
    // diagonal must be 1
    bool diag_ok = m.array[0]==1.0f && m.array[5]==1.0f && m.array[10]==1.0f && m.array[15]==1.0f;
    // every off-diagonal must be 0
    bool off_ok = true;
    for (int i=0 ; i<16 ; i++) {
        if (i==0 || i==5 || i==10 || i==15) continue;
        if (m.array[i] != 0.0f) { off_ok = false; break; }
    }
    if (diag_ok && off_ok) { std::cout << "test_constructor_default_mat4: true" << std::endl; }
    else { std::cout << "test_constructor_default_mat4: false\n"; m.PrintMat(); }
}
void test_constructor_scalar_mat4()
{
    la::mat4 m(3.0f);
    bool ok = true;
    for (int i=0 ; i<16 ; i++) { if (m.array[i] != 3.0f) { ok = false; break; } }
    if (ok) { std::cout << "test_constructor_scalar_mat4: true" << std::endl; }
    else    { std::cout << "test_constructor_scalar_mat4: false\n"; m.PrintMat(); }
}
void test_constructor_array_mat4()
{
    float arr[] = {1,2,3,4, 5,6,7,8, 9,10,11,12, 13,14,15,16};
    la::mat4 m(arr);
    bool ok = true;
    for (int i=0 ; i<16 ; i++) { if (m.array[i] != arr[i]) { ok = false; break; } }
    if (ok) { std::cout << "test_constructor_array_mat4: true" << std::endl; }
    else    { std::cout << "test_constructor_array_mat4: false\n"; m.PrintMat(); }
}
void test_constructor_vec3_mat4()
{
    la::vec3 r(1.0f , 2.0f , 3.0f);
    la::vec3 u(4.0f , 5.0f , 6.0f);
    la::vec3 b(7.0f , 8.0f , 9.0f);
    la::mat4 m(r , u , b);

    // rows 0/1/2 should hold the xyz of each vector; row 3 is translation (0,0,0,1)
    bool row0 = m.array[0]==r.x && m.array[1]==r.y && m.array[2]==r.z && m.array[3]==0.0f;
    bool row1 = m.array[4]==u.x && m.array[5]==u.y && m.array[6]==u.z && m.array[7]==0.0f;
    bool row2 = m.array[8]==b.x && m.array[9]==b.y && m.array[10]==b.z && m.array[11]==0.0f;
    bool row3 = m.array[12]==0.0f && m.array[13]==0.0f && m.array[14]==0.0f && m.array[15]==1.0f;
    if (row0 && row1 && row2 && row3) { std::cout << "test_constructor_vec3_mat4: true" << std::endl; }
    else { std::cout << "test_constructor_vec3_mat4: false\n"; m.PrintMat(); }
}
void test_constructor_vec4_mat4()
{
    la::vec4 r(1.0f , 2.0f , 3.0f , 0.0f);
    la::vec4 u(4.0f , 5.0f , 6.0f , 0.0f);
    la::vec4 b(7.0f , 8.0f , 9.0f , 0.0f);
    la::mat4 m(r , u , b);

    // same layout as vec3 constructor — only xyz is read from each vec4
    bool row0 = m.array[0]==r.x && m.array[1]==r.y && m.array[2]==r.z && m.array[3]==0.0f;
    bool row1 = m.array[4]==u.x && m.array[5]==u.y && m.array[6]==u.z && m.array[7]==0.0f;
    bool row2 = m.array[8]==b.x && m.array[9]==b.y && m.array[10]==b.z && m.array[11]==0.0f;
    bool row3 = m.array[12]==0.0f && m.array[13]==0.0f && m.array[14]==0.0f && m.array[15]==1.0f;
    if (row0 && row1 && row2 && row3) { std::cout << "test_constructor_vec4_mat4: true" << std::endl; }
    else { std::cout << "test_constructor_vec4_mat4: false\n"; m.PrintMat(); }
}

// mat4 operator *= test------------------------------------------
void test_operator_matmul_equal_mat4()
{
    // M *= I should leave M unchanged
    float arr[] = {1,2,3,4, 5,6,7,8, 9,10,11,12, 13,14,15,16};
    la::mat4 m(arr);
    la::mat4 original(arr);
    la::mat4 id;
    m *= id;
    if ( mat4_equality_test(m , original) ) { std::cout << "test_operator_matmul_equal_mat4 (M*=I=M): true" << std::endl; }
    else { std::cout << "test_operator_matmul_equal_mat4 (M*=I=M): false\n"; m.PrintMat(); }
}

// individual axis rotation tests------------------------------------------
void test_rotate_mat_x()
{
    la::mat4 id;
    la::mat4 r = id.RotateMatX(la::PIBY2);

    // +Y should become +Z after 90-degree rotation around X
    la::vec3 y_axis(0.0f , 1.0f , 0.0f);
    la::vec3 result = y_axis * r;
    bool ok = fabs(result.x - 0.0f) < 1e-4f &&
              fabs(result.y - 0.0f) < 1e-4f &&
              fabs(result.z - 1.0f) < 1e-4f;
    if (ok) { std::cout << "test_rotate_mat_x (Y->Z): true" << std::endl; }
    else    { std::cout << "test_rotate_mat_x (Y->Z): false "; result.PrintVec(); }

    // zero rotation should be identity
    la::mat4 r0 = id.RotateMatX(0.0f);
    if ( mat4_equality_test(r0 , id) ) { std::cout << "test_rotate_mat_x (zero=identity): true" << std::endl; }
    else { std::cout << "test_rotate_mat_x (zero=identity): false\n"; r0.PrintMat(); }
}
void test_rotate_mat_y()
{
    la::mat4 id;
    la::mat4 r = id.RotateMatY(la::PIBY2);

    // +Z should become +X after 90-degree rotation around Y
    la::vec3 z_axis(0.0f , 0.0f , 1.0f);
    la::vec3 result = z_axis * r;
    bool ok = fabs(result.x - 1.0f) < 1e-4f &&
              fabs(result.y - 0.0f) < 1e-4f &&
              fabs(result.z - 0.0f) < 1e-4f;
    if (ok) { std::cout << "test_rotate_mat_y (Z->X): true" << std::endl; }
    else    { std::cout << "test_rotate_mat_y (Z->X): false "; result.PrintVec(); }

    // zero rotation should be identity
    la::mat4 r0 = id.RotateMatY(0.0f);
    if ( mat4_equality_test(r0 , id) ) { std::cout << "test_rotate_mat_y (zero=identity): true" << std::endl; }
    else { std::cout << "test_rotate_mat_y (zero=identity): false\n"; r0.PrintMat(); }
}
void test_rotate_mat_z()
{
    la::mat4 id;
    la::mat4 r = id.RotateMatZ(la::PIBY2);

    // +X should become +Y after 90-degree rotation around Z
    la::vec3 x_axis(1.0f , 0.0f , 0.0f);
    la::vec3 result = x_axis * r;
    bool ok = fabs(result.x - 0.0f) < 1e-4f &&
              fabs(result.y - 1.0f) < 1e-4f &&
              fabs(result.z - 0.0f) < 1e-4f;
    if (ok) { std::cout << "test_rotate_mat_z (X->Y): true" << std::endl; }
    else    { std::cout << "test_rotate_mat_z (X->Y): false "; result.PrintVec(); }

    // zero rotation should be identity
    la::mat4 r0 = id.RotateMatZ(0.0f);
    if ( mat4_equality_test(r0 , id) ) { std::cout << "test_rotate_mat_z (zero=identity): true" << std::endl; }
    else { std::cout << "test_rotate_mat_z (zero=identity): false\n"; r0.PrintMat(); }
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