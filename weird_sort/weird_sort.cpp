#include <cstdio> // TODO: put in a header file.
#include <string.h> // TODO: put in a header file.

// TODO: Put in a header file.
#define VERIFY(data, data_copy, len, fail)          \
    if (fail) {                                     \
        printf("Case with %lu elements failed\n", (len)); \
        printf("Input: ");                          \
        print_array((data_copy), (len));            \
        printf("Output: ");                         \
        print_array((data), (len));                 \
        break;                                      \
    }

// TODO: Add any needed lines in the header file.
// TODO: Fix any memory leak found in this file.

void sort_even_elements(int *data, size_t len, long &num_comparison) {
    /*
     * TODO: this function sorts the values in the given array that are at even indices in the ascending (small to large) order.
     *  For example, data[0], data[2], data[4]....will be sorted.
     *  And data[1], data[3], data[5] will not be modified.
     *  This is to be done by modifying the bubble sort algorithm.
     *  The commented code in this function when you get it from the teacher is just plain bubble sort for explanation purpose.
     *  The SPACE complexity for this is required to be O(1).
     *  A bonus goal for this is to achieve the least amount of comparison which happens on the line illustrated below.
     */

    /*
    if (data == nullptr || len < 2) {
        return;
    }

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (data[j] > data[j + 1]) {    // this is where comparison happens
                swap(data, j, j + 1);
            }
        }
    }
    */
}

void unit_test(); // TODO: Put this in a header file.

int main() {
    unit_test();
}

void unit_test() {
    for (size_t len = 1; len < 500; len++) {
        int *data = new int[len];
        long num_of_comparison = 0;

        /*
         * Some sample inputs. One case per line.
         *
         * 1
         * 2 1
         * 3 2 1
         * 4 3 2 1
         * 5 4 3 2 1
         * 6 5 4 3 2 1
         *
         * TODO: Given these inputs, what would be the expected outputs?
         *
         */
        for (int j = 0; j < len; ++j) {
            data[j] = (int) (len - j);
        }
        int *data_copy = new int[len];
        copy_array(data_copy, data, len);

        sort_even_elements(data, len, num_of_comparison);

        /*
         * verify the even index number
         */
        bool fail = false;
        int expect = (len % 2 == 0) ? 2 : 1;
        for (int j = 0; j < len; j += 2) {
            if (data[j] != expect) {
                fail = true;
                break;
            }
            expect += 2;
        }
        VERIFY(data, data_copy, len, fail);

        /*
         * verify the odd index number
         */
        fail = false;
        expect = (int) len - 1;
        for (int j = 1; j < len; j += 2) {
            if (data[j] != expect) {
                fail = true;
                break;
            }
            expect -= 2;
        }
        VERIFY(data, data_copy, len, fail);

        // TODO: Compare the number_of_comparison with others.
        //  Optimize it to be as small as possible.
        printf("%ld\t%ld\n", len, num_of_comparison);
    }
}

void print_array(int *data, size_t len) {
    printf("{");
    for (int i = 0; i < len; i++) {
        printf("%d", data[i]);
        if (i != len - 1) {
            printf(", ");
        } else {
            printf("}\n");
        }
    }
}

// TODO: Anything wrong with this function? If yes, fix it.
void copy_array(int *data_dest, int *data_src, size_t len) {
    if (len == 0) {
        return;
    }
    memcpy(data_dest, data_src, len);
}