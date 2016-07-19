#include <bstrlib.h>
#include "minunit.h"
#include <string.h>

bstring str = NULL;
char* words = "The quick brown fox jumped over the lazy dog.";

char* test_bfromcstr() {
    str = bfromcstr(words);
    char* data = bdata(str);

    mu_assert(str != NULL, "Creation from C string failed.");
    mu_assert(strcmp(data, words) == 0, "Creation from c string result incorrect. \
           NOTE: Test assumes bdata() is functioning correctly.");

    bdestroy(str);
    return NULL;
}

char* test_blk2bstr() {
    str = blk2bstr(words, 13);
    char* data = bdata(str);

    mu_assert(str != NULL, "Creation from blk failed.");
    mu_assert(strcmp(data, "The quick bro") == 0, "Creation from blk result incorrect.");

    bdestroy(str);
    return NULL;
}

char* test_bstrcpy() {
    str = bfromcstr(words);
    bstring cpy = bstrcpy(str);
    char* data = bdata(cpy);

    mu_assert(str != NULL, "Creation from C string failed.");
    mu_assert(cpy != NULL, "bstring copy failed.");
    mu_assert(strcmp(data, words) == 0, "String copy result incorrect.");

    bdestroy(str);
    bdestroy(cpy);
    return NULL;
}

char* test_bassign() {
    str = bfromcstr(words);
    bstring new = bfromcstr("");
    int rc = bassign(new, str);

    mu_assert(rc == BSTR_OK, "Assign failed.");
    mu_assert(new != NULL, "Empty creation from C string failed.");
    mu_assert(strcmp(bdata(new), words) == 0, "String assign result incorrect.");

    bdestroy(str);
    bdestroy(new);
    return NULL;
}

char* test_bassigncstr() {
    bstring new = bfromcstr("");
    int rc = bassigncstr(new, words);

    mu_assert(rc == BSTR_OK, "Assign failed.");
    mu_assert(new != NULL, "Empty creation from C string failed.");
    mu_assert(strcmp(bdata(new), words) == 0, "String assign result incorrect.");

    bdestroy(new);
    return NULL;
}

char* test_bassignblk() {
    bstring new = bfromcstr("");
    int rc = bassignblk(new, words, 13);

    mu_assert(rc == BSTR_OK, "Assign failed.");
    mu_assert(new != NULL, "Empty creation from C string failed.");
    mu_assert(strcmp(bdata(new), "The quick bro") == 0, "blk assign result incorrect.");

    bdestroy(new);
    return NULL;
}

char* test_bdestroy() {
    str = bfromcstr(words);
    int rc = bdestroy(str);

    mu_assert(rc == BSTR_OK, "bdestroy failed.");

    return NULL;
}

char* test_bconcat() {
    bstring str1 = bfromcstr("Hello,");
    bstring str2 = bfromcstr(" world");
    int rc = bconcat(str1, str2);

    mu_assert(str1 != NULL && str2 != NULL, "Creation from C string failed.");
    mu_assert(rc == BSTR_OK, "Concat failed.");
    mu_assert(strcmp(bdata(str1), "Hello, world") == 0, "Concat result incorrect.");

    bdestroy(str1);
    bdestroy(str2);
    return NULL;
}

char* test_bstricmp() {
    bstring str1 = bfromcstr("Hello, World");
    bstring str2 = bfromcstr("hello, world");
    int rc = bstricmp(str1, str2);

    mu_assert(str1 != NULL && str2 != NULL, "Creation from C string failed.");
    mu_assert(rc == 0, "bstricmp returned non-zero for equal strings.");

    str2 = bfromcstr("wassup, world");
    rc = bstricmp(str1, str2);

    mu_assert(rc != 0, "bstricmp returned false match.");

    bdestroy(str1);
    bdestroy(str2);
    return NULL;
}

char* test_biseq() {
    bstring str1 = bfromcstr("Hello, World");
    bstring str2 = bfromcstr("Hello, World");
    int rc = biseq(str1, str2);

    mu_assert(rc != -1, "biseq failed.");
    mu_assert(rc == 1, "biseq returned non-zero for equal strings.");

    str2 = bfromcstr("wassup, World");
    rc = biseq(str1, str2);

    mu_assert(rc != -1, "biseq failed.");
    mu_assert(rc == 0, "biseq returned false match.");

    bdestroy(str1);
    bdestroy(str2);
    return NULL;
}

char* test_binstr() {
    return NULL;
}

char* test_bfindreplace() {
    return NULL;
}

char* test_bsplit() {
    return NULL;
}

char* test_bformat() {
    return NULL;
}

char* test_blength() {
    return NULL;
}

char* test_bdata() {
    return NULL;
}

char* test_bchar() {
    return NULL;
}

char* all_tests() {
    mu_suite_start();

    mu_run_test(test_bfromcstr);
    mu_run_test(test_blk2bstr);
    mu_run_test(test_bstrcpy);
    mu_run_test(test_bassign);
    mu_run_test(test_bassigncstr);
    mu_run_test(test_bassignblk);
    mu_run_test(test_bdestroy);
    mu_run_test(test_bconcat);
    mu_run_test(test_bstricmp);
    mu_run_test(test_biseq);
    mu_run_test(test_binstr);
    mu_run_test(test_bfindreplace);
    mu_run_test(test_bsplit);
    mu_run_test(test_bformat);
    mu_run_test(test_blength);
    mu_run_test(test_bdata);
    mu_run_test(test_bchar);

    return NULL;
}

RUN_TESTS(all_tests);
