# This file will describe some of the design choices i made while writing this library and my reasons for doing do

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

3. Matrices and vectors are all stored on the stack
    This allows us to do a lot of time saving stuff like chaining functions together, by copying over objects along with their data, allowing us to return the objects, and the data.

    `la::mat4 new_mat = la::mat4().TranslateMat(...).RotateMat(...)`

    If the data were stored on the heap it would need to be accessed with the use of a pointer,  which hard to use and clunky, plus storing data on the heap means dealing with memory allocation and freeing, which I hope you understand that I did not want to deal with.

4. No error codes
    There is two main ways for a function to communiate errors with the program. Either it will use return statements that can be handled by the user, or it can take in a pointer to an error container object, and write any errors to that object.

    The return values are matrices and vectors, so my only option was to make the user pass an error object for EVERY SINGLEE FUNCTION THAT THEY TRY TO CALL. Instead of making the user do this i simply made errors hard to make with strict typing.

    PrintVec() and PrintMat() functions are provided to allow the user to use print checking for errors themselves, albeit only while writing the program.

5. The relationship between the vec3 and vec4 class.

6. Storage of data
    vectors store their data as individual members while matrices store their data in a member array variable. I just did this for convenience. Indexing the array is painful so vectors just dont bother with array. mat4 has 16 elements, and creating 16 different member variables would be stupid so I used an array.

    Althought the `[]` operator is overloaded for indexing the vectors like an array, if you find that style to be better. This also allows you to loop over the vectors 3 or 4 elements using a for statement.