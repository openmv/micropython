/*
 * omvdummy.c
 */

/*
 * These functions don't to do anything.
 * They are here to prevent an error when compiling
 * a frozen module on the openmv platform.
 * They are declared as weak functions and when all compiled
 * objects have been linked, they will overridden by
 * the real 'fb_alloc_mark' and 'fb_alloc_free_till_mark'
 * functions in the 'fb_alloc.c' file.
 */
void __attribute__((weak)) fb_alloc_mark()
{
}
void __attribute__((weak)) fb_alloc_free_till_mark()
{
}
