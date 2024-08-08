# This file will describe some of the design choices i made while writing this library and my reasons for doing do

## VERY VERY IMPORTANT DETAIL
The only way to edit the `w` compontent of the `vec4` class after initialization is to do so manully by accessing the attribute.

Almost none of the methods in the `vec4` class affect the `w` component of the vector. The `w` component is used to store data for later use in the rendering pipeline. Altering it is not recommended.

For eg. 
    > functions like `Magnitude()` and `Normalize()` only take into consideration the x , y , z components. For a `vec4`, its magnitude will be the same as a `vec3` having the same main components, no matter what the `w` of the vec4 is.
    > functions like `CrossProduct()` which take 2 `vec4` and return another `vec4` will simply return the `w` component of the first vector (the vector you call the function upon), as the `w` component of the output vector.
    > vector Matrix Multiplication with a `mat4` will work just like normal, and thus will include the `w` coordinate of the vector.
    > Color related methods like reflection will also include the `w` component in their computations.

In this sense, there is almost no reason to use the `vec4` class before the perspective divide step, but the functions are still available to you if you wish to do something else.

1. Object Oriented everything:
    Object oriented programming just reduces a lot of syntax and make code much more readble. Something like `glm` doesnt make much use of OOP. For example creating a new tranlation matrix in glm will have you pass a matrix to a translate functions
    
    `glm::mat4 new_mat = glm::translate_mat(glm::mat4(...) , glm::vec3(...);`

    versus in this library

    `la::mat4 new_mat = la::mat4().TranslateMat(...);`

    i find the second approach to be a litte bit more readable

    as a result of this, even functions like LookAt, which are actually just creating completely new matrices, and are not affected by any existing matrices, are called on some matrix. like this

    `la::mat4 view_mat = la::mat4().LookAt(...);`

    this does not make as much sense as what something like glm would do, but that is purely synatitical. Functionally I didnt find there to be much difference.

2. Functions create new matrices instead of editing existing ones
    Since nimbus linalg matrices live on the stack and not the heap, it is very fast to just create new matrices. Also, memory is automatically managed due to the 
    
    LIFO nature of the stack. But most importantly, editing existing matrices would not allow us to chain function calls together like you can by returning a new matrix. It adds a lot of code for the used to write, kind of like taking all the cons of storing the matrix on the stack without any of the benefits that come with it. Bad idea.

3. Matrices and vectors are all stored on the stack
    This allows us to do a lot of time saving stuff like chaining functions together, by copying over objects along with their data, allowing us to return the objects, and the data.

    `la::mat4 new_mat = la::mat4().TranslateMat(...).RotateMat(...)`

    If the data were stored on the heap it would need to be accessed with the use of a pointer,  which hard to use and clunky, plus storing data on the heap means dealing with memory allocation and freeing, which I hope you understand that I did not want to deal with.

    It is very quick to create new memory on the stack, and memory is automatically managed due to the LIFO nature of data on the stack.

4. No error codes
    There is two main ways for a function to communiate errors with the program. Either it will use return statements that can be handled by the user, or it can take in a pointer to an error container object, and write any errors to that object.

    The return values are matrices and vectors, so my only option was to make the user pass an error object for EVERY SINGLEE FUNCTION THAT THEY TRY TO CALL. Instead of making the user do this i simply made errors hard to make with strict typing.

    PrintVec() and PrintMat() functions are provided to allow the user to use print checking for errors themselves, albeit only while writing the program.

5. The relationship between the vec3 and vec4 class.
    currently there is almost nothing that the `vec3` and `vec4` class have to do with each other. Nimbus linalg encourages you to make use of `vec3` and not `vec4` for general purpose linear algebra stuff in 3d like 3d tranfomrations.
    
    Even translations are built into the `vec3` type so you don't need to use the `vec4` as you traditionally would. The library will convert from `vec3` to `vec4`, applies any translations and then converts back to `vec3` whereever there might be any tranlsation transformation possible.
    
    Really the only use of the `vec4` is to store an alpha value for an RGBA color or a W value with will have the Z coordinate for the perspective divide. For this, conversions functions are provided to go from `vec3` to `vec4` and vice versa. When given a choice between the two, the library chooses `vec3` and so should you.

    This is why I avoided building an inheritance tree with a base vector class and deriving `vec3` and `vec4` from it, or maybe deriving `vec4` from `vec3` because they do share a lot of functions. It was not worth the added complexity.

6. Storage of data
    vectors store their data as individual members while matrices store their data in a member array variable. I just did this for convenience. Indexing the array is painful so vectors just dont bother with array. mat4 has 16 elements, and creating 16 different member variables would be stupid so I used an array.

    Althought the `[]` operator is overloaded for indexing the vectors like an array, if you find that style to be better. This also allows you to loop over the vectors 3 or 4 elements using a for statement.
